// Basic Control Program of Buck-Boost Converter PI Regulation (Parameter and Constants Definition)
// Date: December, 262, 2014  20:18 pm
// Operator : Zhang Xi Nan
//###########################################################################
//
// FILE:    BBCtrlV1T1.c (SVM-DTFC Voltage Model Version 1)
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "parameter.h"
#include "DSP2833x_Project.h"
#include  <math.h>

//// Start of Global Variables Definition
//// 1. Variables for Current and Voltage Regulation (SampleTable Array)
Uint16 IL_Fix_A=0, Vout_Fix_A=0, IL_Fix_B=0, Vout_Fix_B=0, IL_Fix_C=0, Vout_Fix_C=0, IL_Fix_D=0, Vout_Fix_D=0;
float32 IL_Flt_A, Vout_Flt_A, IL_Flt_B, Vout_Flt_B, IL_Flt_C, Vout_Flt_C, IL_Flt_D, Vout_Flt_D; //ADC Sampling Registers
float32 IL_Flt_Ave, Vout_Flt_Ave;
float32 ILFlt_k1, VoutFlt_k1, ILLPF_k, VoutLPF_k, ILLPF_k1, VoutLPF_k1; ////ADC Low-Pass-Filter Registers, Set it to 4KH first
float32 Temp_Reg1, Temp_Reg2, Temp_Reg3, Temp_Reg4, Temp_Reg5; //Floating Point Registers for Calc
float32 Temp_Reg6, Temp_Reg7, Temp_Reg8, Temp_Reg9, Temp_RegA; //Floating Point Registers for Calc
float32 Result_Reg1, Result_Reg2, Result_Reg3, Result_Reg4, Result_Reg5, Result_Reg6; //Floating Point Global Variables
float32 Vout_Sat_k, Vout_Sat_k1, Vout_UnSat_k, Vout_UnSat_k1, VoutPISum_k, VoutPISum_k1; //Floating Point Variables for Voltage PI Controller
float32 IL_Sat_k, IL_Sat_k1, IL_UnSat_k, IL_UnSat_k1, ILPISum_k, ILPISum_k1; //Floating Point Variables for Voltage PI Controller
float32 Vout_Ref, Volt_Err, Cur_Err, IL_Ref, Duty_Ref, Duty;
float32 PWM_CNTA;
//// 2. Variables for SCI Communication
Uint16 RXChar, SCIRX_Done, VoutRef_Se;
//// 3. Variables for Condition Monitoring based on Slope Calculation
Uint16 CondMon_CNT1;
float32 Delta_Ton, Delta_Toff, Delta_Von, Delta_Voff, Delta_ILon, Delta_ILoff;
float32 Slope_Von, Slope_Voff, Slope_ILon, Slope_ILoff, Cest_Num, Cest_Den_Temp, Cest_Den, Cest, Resr_Num, Resr_Den_Temp, Resr_Den, Resr;
float32 Cest_Temp, Cest_k1, Cest_LPF_k, Cest_LPF_k1, Resr_Temp, Resr_k1, Resr_LPF_k, Resr_LPF_k1;
float32 Est_Reg1, Est_Reg2, Est_Reg3, Est_Reg4, Est_Reg5, Est_Reg6;

////The following Data Acquization is Only used for DAC Debugging
#define DAC_IG  196.80946; ////This is Current DAC Gain : 0~4095=>-10~10V=> -11.363~11.363A Thus, 4095/22.726
#define DAC_VG  65.6031533; ////Voltage Value is Larger thus, 1/3*DAC_IG
#define DAC_CestA  196809.46; ////This is the Correct Scale 1==>1000 Display
#define DAC_CestB  0.019680946; ////////This is the Correct Scale 10000==>1 Display
#define DAC_CestC  9840.473; ////This is the Correct Scale 1==>50 Display
float32 DAC_Temp1, DAC_Temp2, DAC_Temp3;
//// End of Variables Definition

interrupt void BBPICtrl(void);
interrupt void SCIBRXINT_ISR(void);

 void InitGlbVari(void)
{
   IL_Flt_A=0.0;  Vout_Flt_A=0.0;  IL_Flt_B=0.0;  Vout_Flt_B=0.0;  IL_Flt_C=0.0;  Vout_Flt_C=0.0;
   IL_Flt_D=0.0;  Vout_Flt_D=0.0;  IL_Flt_Ave=0.0; Vout_Flt_Ave=0.0;
   ILFlt_k1=0.0; VoutFlt_k1=0.0; ILLPF_k=0.0; VoutLPF_k=0.0; ILLPF_k1=0.0; VoutLPF_k1=0.0;
   Temp_Reg1=0.0;  Temp_Reg2=0.0;  Temp_Reg3=0.0;  Temp_Reg4=0.0;  Temp_Reg5=0.0;
   Temp_Reg6=0.0;  Temp_Reg7=0.0;  Temp_Reg8=0.0;  Temp_Reg9=0.0;  Temp_RegA=0.0;
   Result_Reg1=0.0;  Result_Reg2=0.0;  Result_Reg3=0.0;  Result_Reg4=0.0;  Result_Reg5=0.0;  Result_Reg6=0.0;
   Vout_Sat_k=0.0;  Vout_Sat_k1=0.0;  Vout_UnSat_k=0.0;  Vout_UnSat_k1=0.0;  VoutPISum_k=0.0;  VoutPISum_k1=0.0;
   IL_Sat_k=0.0;  IL_Sat_k1=0.0;  IL_UnSat_k=0.0;  IL_UnSat_k1=0.0;  ILPISum_k=0.0;  ILPISum_k1=0.0;
   Vout_Ref=Vout_Ref_Init; Volt_Err=0.0;  Cur_Err=0.0;  IL_Ref=0.0;  Duty_Ref=0.0;  Duty=0.0;  PWM_CNTA=0.0;
   VoutRef_Se=0;  CondMon_CNT1=0;
   Delta_Ton=0.0;  Delta_Toff=0.0;  Delta_Von=0.0;  Delta_Voff=0.0;  Delta_ILon=0.0;  Delta_ILoff=0.0;
   Slope_Von=0.0;  Slope_Voff=0.0;  Slope_ILon=0.0;  Slope_ILoff=0.0;  Cest_Num=0.0;  Cest_Den_Temp=0.0;
   Cest_Den=0.0;  Cest=0.0;  Resr_Num=0.0;  Resr_Den_Temp=0.0;  Resr_Den=0.0;  Resr=0.0;
   ////
   Cest_Temp=0.0;  Cest_k1=0.0;  Cest_LPF_k=0.0;  Cest_LPF_k1=0.0;  Resr_Temp=0.0;  Resr_k1=0.0;  Resr_LPF_k=0.0;  Resr_LPF_k1=0.0;
   Est_Reg1=0.0;  Est_Reg2=0.0;  Est_Reg3=0.0;  Est_Reg4=0.0;  Est_Reg5=0.0;  Est_Reg6=0.0;
}

void main(void)
{
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP2833x_SysCtrl.c file.
   InitSysCtrl();

// Step 2. Initalize GPIO:
// This example function is found in the DSP2833x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
   InitGpio(); 

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
   DINT;

// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the DSP2833x_PieCtrl.c file.
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table
// The shell ISR routines are found in DSP2833x_DefaultIsr.c.
// This function is found in DSP2833x_PieVect.c.
   InitPieVectTable();

// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.

// Step 5. User specific code, enable interrupts:
   // Initialize Peripheral Devices ADC, eQEP, ePWM, 
   InitAdc();
   InitSci();
   InitEPwm();
   // Call for the Function of Global Variables Inilization
   InitGlbVari();

    EALLOW;
	PieVectTable.EPWM1_INT = & BBPICtrl;
	PieVectTable.SCIRXINTB = & SCIBRXINT_ISR;
//// !!!QFLG.bit.xxx==1 Never be Used in ISR
////PieVectTable.ECAP1_INT = & UnitPosCNT;
    EDIS;

    PieCtrlRegs.PIEIER3.bit.INTx1=1; //Enable T1PINT for EPWM1
	PieCtrlRegs.PIEIER9.bit.INTx3=1; //Enable SCI Receive Interrupt
    ////Enable the Interrupts for Corresponding Groups
	IER |= M_INT3;
	IER |= M_INT5; ////???? Disable
	IER |= M_INT9;
    ////Enable Global interrupt INTM
	EINT; 
	ERTM; ////Enable Global realtime interrupt DBGM

	ScibRegs.SCITXBUF=68;
    while(1)
   {asm(" NOP ");} //Do-Nothig while waiting for ADC Interrupt
}

////=======================Section 1. ISR for SVMDTFC Control and Encoder Interrupt for Spd&Position Calculation==================
interrupt void BBPICtrl(void)    ////DTFC based on SVM
{
      DINT;
    ////SOC (EPWM1_SOC) Triggered, ADC Samping at a Scale of ADC=4096*(V_adc - 0)/3 ==> maximum usage is 0~2.5V for our case
	////Input Must be Right-Shifted >>4 to Read the Value in ADC Registers !!! 
	  IL_Fix_A = AdcRegs.ADCRESULT0>>4; ////ADC Channel 0 for Inductor Current
      Vout_Fix_A = AdcRegs.ADCRESULT1>>4; ////ADC Channel 1 for Output Voltage
	  IL_Fix_B = AdcRegs.ADCRESULT2>>4; ////ADC Channel 2 for Inductor Current
      Vout_Fix_B = AdcRegs.ADCRESULT3>>4; ////ADC Channel 3 for Output Voltage
	  IL_Fix_C = AdcRegs.ADCRESULT4>>4; ////ADC Channel 4 for Inductor Current
      Vout_Fix_C = AdcRegs.ADCRESULT5>>4; ////ADC Channel 5 for Output Voltage
	  IL_Fix_D = AdcRegs.ADCRESULT6>>4; ////ADC Channel 6 for Inductor Current
      Vout_Fix_D = AdcRegs.ADCRESULT7>>4; ////ADC Channel 7 for Output Voltage
	////Immediately Resets SEQ1 to Conv00 State to Wait for Next Cycle's Event Trigger !!!
	  AdcRegs.ADCTRL2.bit.RST_SEQ1=1;
    ////ADC Offset and Re-Scaling
      IL_Flt_A=IL_Fix_A + IL_OS_Cnst; ////Rescaling of IL
      Vout_Flt_A=Vout_Fix_A + Vout_OS_Cnst; ////Rescaling of Vout
      IL_Flt_A=IL_Flt_A*IL_SL_Cnst; ////Offset Cancellation of IL 
      Vout_Flt_A=Vout_Flt_A*Vout_SL_Cnst; ////Offset Cancellation of Vout

	  IL_Flt_B=IL_Fix_B + IL_OS_Cnst; ////Rescaling of IL
      Vout_Flt_B=Vout_Fix_B + Vout_OS_Cnst; ////Rescaling of Vout
      IL_Flt_B=IL_Flt_B*IL_SL_Cnst; ////Offset Cancellation of IL 
      Vout_Flt_B=Vout_Flt_B*Vout_SL_Cnst; ////Offset Cancellation of Vout

	  IL_Flt_C=IL_Fix_C + IL_OS_Cnst; ////Rescaling of IL
      Vout_Flt_C=Vout_Fix_C + Vout_OS_Cnst; ////Rescaling of Vout
      IL_Flt_C=IL_Flt_C*IL_SL_Cnst; ////Offset Cancellation of IL 
      Vout_Flt_C=Vout_Flt_C*Vout_SL_Cnst; ////Offset Cancellation of Vout

	  IL_Flt_D=IL_Fix_D + IL_OS_Cnst; ////Rescaling of IL
      Vout_Flt_D=Vout_Fix_D + Vout_OS_Cnst; ////Rescaling of Vout
      IL_Flt_D=IL_Flt_D*IL_SL_Cnst; ////Offset Cancellation of IL 
      Vout_Flt_D=Vout_Flt_D*Vout_SL_Cnst; ////Offset Cancellation of Vout
	//// Now, Due to the difference of sampled Values, Must Get the Average IL and Vout for Control
	  IL_Flt_Ave=(IL_Flt_B + IL_Flt_D)*0.5; ////The Average of Sampled IL at EPwm1_SOCA and EPwm1_SOCB
	  Vout_Flt_Ave=(Vout_Flt_B + Vout_Flt_D)*0.5; ////The Average of Sampled Vout at EPwm1_SOCA and EPwm1_SOCB
    ////================The following Program Snnipet is for Debugging Only================
    //// IL, Vout low-pass-filtering : Only IL_Flt_D and Vout_Flt_D are utilized for Control Purpose!!!
      Result_Reg1=IL_Flt_Ave + ILFlt_k1; ////IL_Flt_D
      Result_Reg2=ILLPF_k1*LPF2K_Coe1;
      Result_Reg3=Result_Reg1 + Result_Reg2;
      ILLPF_k=Result_Reg3*LPF2K_Coe2;
      ILLPF_k1=ILLPF_k;
	  ILFlt_k1=IL_Flt_Ave; ////IL_Flt_D
      Result_Reg4=Vout_Flt_Ave + VoutFlt_k1; ////Vout_Flt_D
      Result_Reg5=VoutLPF_k1*LPF2K_Coe1;
	  Result_Reg6=Result_Reg4 + Result_Reg5;
	  VoutLPF_k=Result_Reg6*LPF2K_Coe2;
	  VoutLPF_k1=VoutLPF_k;
	  VoutFlt_k1=Vout_Flt_Ave; ////Vout_Flt_D
	  
      if(SCIRX_Done==0)
	   {
	    Vout_Ref=Vout_Ref_Init;
	   }
	   else
	   { 
	     switch(VoutRef_Se)
		  { case 1 :  Vout_Ref=Vout_Ref1;  break;
		    case 2 :  Vout_Ref=Vout_Ref2;  break;
			case 3 :  Vout_Ref=Vout_Ref3;  break;
			case 4 :  Vout_Ref=Vout_Ref4;  break;
			default :  Vout_Ref=Vout_Ref_Init;  break;	
		  }
	   }
	////Vout_Ref=Vout_Ref_Init;
    ////Voltage PI Control Loop with Anti-Windup
      Volt_Err=Vout_Ref - VoutLPF_k;
	  Temp_Reg1=Volt_Err*Kp_Volt;
      Temp_Reg2=Volt_Err*Ki_Volt;
	  Temp_Reg3=Vout_Sat_k1 - Vout_UnSat_k1;
      Temp_Reg4=Temp_Reg2 + Temp_Reg3;
	  VoutPISum_k=VoutPISum_k1 + Temp_Reg4;
	  Vout_UnSat_k=VoutPISum_k + Temp_Reg1;
      Vout_Sat_k=Vout_UnSat_k; ////Vout_Sat_k = IL_Ref
	  if(Vout_UnSat_k>VoltPI_PosSat)
	     {Vout_Sat_k=VoltPI_PosSat;}
	  if(Vout_UnSat_k<VoltPI_NegSat)
	     {Vout_Sat_k=VoltPI_NegSat;}
	  Vout_Sat_k1=Vout_Sat_k;
      Vout_UnSat_k1=Vout_UnSat_k;
	  VoutPISum_k1=VoutPISum_k;
	  IL_Ref=Vout_Sat_k;
	////Current PI Control Loop with Anti-Windup
	  ////IL_Ref=1.2;
      Cur_Err=IL_Ref - ILLPF_k;
	  Temp_Reg5=Cur_Err*Kp_Cur;
      Temp_Reg6=Cur_Err*Ki_Cur;
	  Temp_Reg7=IL_Sat_k1 - IL_UnSat_k1;
      Temp_Reg8=Temp_Reg6 + Temp_Reg7;
	  ILPISum_k=ILPISum_k1 + Temp_Reg8;
	  IL_UnSat_k=ILPISum_k + Temp_Reg5;
      IL_Sat_k=IL_UnSat_k; ////IL_Sat_k = Duty_Ref
	  if(IL_UnSat_k>CurPI_PosSat)
	     {IL_Sat_k=CurPI_PosSat;}
	  if(IL_UnSat_k<CurPI_NegSat)
	     {IL_Sat_k=CurPI_NegSat;}
	  IL_Sat_k1=IL_Sat_k;
      IL_UnSat_k1=IL_UnSat_k;
	  ILPISum_k1=ILPISum_k;
	  Duty_Ref=IL_Sat_k;
	  if(Duty_Ref>CurPI_PosSat)
	     { Duty=CurPI_PosSat; }
	  else
	     { Duty=Duty_Ref; }
	  if(Duty<0.03)
	     {Duty=0.03;}
    //// Start of Condition Monitoring 
	  ////1) Estimation of Time_Dif for On-State and Off-State 
	  Delta_Ton=TB40_Cnst; ////TB40_Cnst=40*1/37.5MHz=1066.67ns
	  Delta_Toff=TB40_Cnst;
	  ////2) Calculate Volt/Cur Differences : IL_Flt_B, Vout_Flt_B are Sampled by SOC_B Set at CNT==0, they are First Samples. IL_Flt_A, Vout_Flt_A are Second Samples at CNT==CMPA
	  Delta_Von=Vout_Flt_B - Vout_Flt_A;
	  Delta_Voff=Vout_Flt_D - Vout_Flt_C;
	  Delta_ILon=IL_Flt_B - IL_Flt_A;
	  Delta_ILoff=IL_Flt_D - IL_Flt_C;
	  ////3) Calculation of V/I Slopes
	  Slope_Von=Delta_Von/Delta_Ton;
	  Slope_Voff=Delta_Voff/Delta_Toff;
	  Slope_ILon=Delta_ILon/Delta_Ton;
	  Slope_ILoff=Delta_ILoff/Delta_Toff;
	  ////4) Estimation of Capacitance and ESR
	  ////Estimation of Capacitance 'Cest'
	  Cest_Num=OneDivRL*Vout_Flt_B; ////Vout_Flt_B Represents Vout_On !!!
	  Cest_Num=Cest_Num*1.094;
	  Cest_Den_Temp=Slope_Von;
	  if((Cest_Den_Temp>0)&&(Cest_Den_Temp<Den_PosMin))
	     { Cest_Den=Den_PosMin; }
	  else
	     { Cest_Den=Cest_Den_Temp; }
	  if((Cest_Den_Temp<0)&&(Cest_Den_Temp>Den_NegMin))
	     { Cest_Den=Den_NegMin; }
	  else
	     { Cest_Den=Cest_Den_Temp; }
	  Cest_Temp=Cest_Num/Cest_Den;
	  ////Cest=Cest_Temp;
	  
	  if(Cest_Temp>Cest_UpLim)
	     { Cest=Cest_UpLim; }
	  else
	     {
	       if(Cest_Temp<Cest_LowLim)
		      { Cest=Cest_LowLim; }
		   else
		      { Cest=Cest_Temp; }
	     }
	  
      ////Estimation of Resistance 'Resr'
	  Resr_Num=C_nom_est*Slope_Voff - IL_Flt_C + Vout_Flt_C*OneDivRLPos; //// IL_Flt_C Represents IL_Off; Vout_Flt_C Represents Vout_Off !!!
	  Resr_Den_Temp=Slope_ILoff - OneDivRLPos*Slope_Voff;
	  Resr_Den=Resr_Den_Temp*C_nom_est;
	  Resr_Temp=Resr_Num/Resr_Den;
	  Resr=Resr_Temp;
	  /*
	  if(Resr_Temp>Resr_UpLim)
	     { Resr=Resr_UpLim; }
	  else
	     {
	       if(Resr_Temp<Resr_LowLim)
		      { Resr=Resr_LowLim; }
		   else
		      { Resr=Resr_Temp; }
	     }
	  */
	  ////Low-Pass-Filtering of Cest and Resr
	  Est_Reg1=Cest + Cest_k1; ////IL_Flt_D
      Est_Reg2=Cest_LPF_k1*LPF100_Coe1;
      Est_Reg3=Est_Reg1 + Est_Reg2;
      Cest_LPF_k=Est_Reg3*LPF100_Coe2;
      Cest_LPF_k1=Cest_LPF_k;
	  Cest_k1=Cest; ////IL_Flt_D
      Est_Reg4=Resr + Resr_k1; ////Vout_Flt_D
      Est_Reg5=Resr_LPF_k1*LPF100_Coe1;
	  Est_Reg6=Est_Reg4 + Est_Reg5;
	  Resr_LPF_k=Est_Reg6*LPF100_Coe2;
	  Resr_LPF_k1=Resr_LPF_k;
	  Resr_k1=Resr; ////Vout_Flt_D
    //// End of Condition Monitoring
	  ////Duty=0.65; ////
    ////PWM Counter Scale based on Duty Cycle
      PWM_CNTA=Duty*BB_PWMSLCnst;
      ////Transfer the Scaled Duty Cycles of Phase A/B/C to Corresponding Comparators
      EPwm1Regs.CMPA.half.CMPA=PWM_CNTA; ////Only This is Used for Control
      EPwm1Regs.CMPB=0x0E9C; ////CNT_Max-10=3750-10=3740
      EPwm2Regs.CMPB=0x0E74; ////3740 - 40 = 3700
      EPwm2Regs.CMPA.half.CMPA=PWM_CNTA - Interval;
	  ////DAC Observation!!!
	  ////ILLPF_k,VoutLPF_k,Cest,Resr,Cest_LPF_k
      //DAC_Temp1=Cest_LPF_k*DAC_CestA; ////Cest_Num*DAC_IG
	  DAC_Temp1=Cest*DAC_CestA
	  DAC_Temp1=DAC_Temp1 + 2048;
	  //DAC_Temp2=Resr*DAC_CestC; ////VoutLPF_k*DAC_VG, Slope_Von*DAC_CestB;Cest_LPF_k*DAC_CestA
	  DAC_Temp2=Cest_LPF_k*DAC_CestA
	  DAC_Temp2=DAC_Temp2 + 2048;
	  DAC_Temp3=3.0*DAC_IG; ////
	  DAC_Temp3=DAC_Temp3 + 2048;
      dacen = 0xff;
	  daccs1 = DAC_Temp1;
	  daccs2 = DAC_Temp2;
	  daccs3 = DAC_Temp3;
  ////================The End of Debugging Program================
      EPwm1Regs.ETCLR.all=0x000D; //Clear SOCA/B Flag Bits and SOC_Interrupt Flag Bit	  
      //Enables PIE to drive a pulse into the CPU 
	  PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
      EINT;
      return;
}


interrupt void SCIBRXINT_ISR(void)
{
    RXChar=ScibRegs.SCIRXBUF.all;
	VoutRef_Se=RXChar - 48; ////!!! 48 is Important Offset for My Wref Select Law
	//// Send 1==>49; 2==>50; 3==>51 : VoutRef_Se= 1/2/3/4==>Wm_RefPos1/Wm_RefPos2/Wm_RefNeg1/Wm_RefNeg2
	SCIRX_Done=1; //Indicating SCI Comu is finished
	//// !! No Need to Clear Interrupt Flag, it is auto-cleared after CPU Reads its Data !!
	ScibRegs.SCITXBUF=RXChar;
    PieCtrlRegs.PIEACK.all=PIEACK_GROUP9;
	EINT;
    return;
}
////=======================End of Section 2=======================================
