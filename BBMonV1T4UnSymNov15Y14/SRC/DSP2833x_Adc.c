// TI File $Revision: /main/4 $
// Checkin $Date: July 30, 2007   14:15:53 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

long double i = 0;
#define DELAY_ADC_POWERUP  0xffff

//---------------------------------------------------------------------------
// InitAdc: 
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
{
     for(i = 0;i<DELAY_ADC_POWERUP;i++){asm(" NOP ");} //Power Up Delay by Nopping First
 	 AdcRegs.ADCTRL1.bit.RESET=1;//Reset the ADC Module, Delay of at least 3 CPU Clocks is Necessary, it is shown below by For-Loop
	 for(i=0;i<10000;i++)	{asm(" 	NOP ");}
	 AdcRegs.ADCTRL1.bit.RESET=0; //Clear Reset
	 AdcRegs.ADCTRL1.bit.SUSMOD=3; //SUSMOD1:0 determines Actions at Breaking-Point
	 ////HSPCLK = SYSCLKOUT/2
	 AdcRegs.ADCTRL1.bit.ACQ_PS=0; //ADC SOC Period = [ACQ_PS(3~0)+1]*ADCCLK
	 AdcRegs.ADCTRL1.bit.CPS=0; //CPS=0, use CLK/1; CPS=1, use CLK/2 (CLK=HSPCLK)
	 AdcRegs.ADCTRL1.bit.CONT_RUN=0; //Start-Stop Mode, ADC Smapling is done Manually by Setting Each time
	 AdcRegs.ADCTRL1.bit.SEQ_OVRD=0; //Disable ADC Sequential OverRide
	 AdcRegs.ADCTRL1.bit.SEQ_CASC=1; //SEQ_CASC=1 Selects the 16-Channel Cascaded Series Sampling Mode
	 //Configure ADC RefVoltage Register and ADC Offset Trim Register(-256~255)
     //Should it be Configured Here ? Before the ADCBGRFDN and ADCPWDN ??
	 AdcRegs.ADCREFSEL.all=0x0000; //Choose Internal Voltage Reference(00)
	 AdcRegs.ADCOFFTRIM.all=0x0000; //Offset inside ADC Before AD Conversion to save add/sub calculation
	 
	 for(i = 0;i<15;i++){asm("  	NOP ");}
	 AdcRegs.ADCTRL3.bit.ADCBGRFDN = 3;  //Power up bandgap/reference circuity
	 for(i = 0;i<DELAY_ADC_POWERUP;i++){asm("  	NOP ");}  //Delay defore powering up rest of ADC
	 AdcRegs.ADCTRL3.bit.ADCPWDN = 1;
	 AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;  //ADC_CLK = hspclk/(2*ADCCLKPS)/(CPS+1)
	 for(i = 0;i<DELAY_ADC_POWERUP;i++){asm("  	NOP ");} 
	 AdcRegs.ADCTRL3.bit.SMODE_SEL=0; //Selects Seriesly Sampling Mode
	 
	 AdcRegs.ADCST.bit.INT_SEQ1_CLR=1; //Write 1 to INT_SEQx_CLR to clear the Interrupt Flag
	 AdcRegs.ADCST.bit.INT_SEQ2_CLR=1;
	 
	 AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ=1; //Allow EV_SOCB to Trigger ADC_SOC In Cascaded Mode
	 AdcRegs.ADCTRL2.bit.RST_SEQ1=1; //Immediately Resets SEQ1 to Conv00 State !!
	 AdcRegs.ADCTRL2.bit.SOC_SEQ1=0; //Clear a Suspending SEQ
     AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1=0; //Disable Interrupt Request Triggered by INT_SEQ1 !!!
	 AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1=0; //INT_SEQ1 is Set at the End of Every SEQ1 Sequence
	 AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1=1; //Allows SEQ1 to be Started by EPWM_SOCA Trigger (Eva Previously)!!!
	 AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1=0; //Doesn't Allow the External Source to Start SEQ1
	 AdcRegs.ADCTRL2.bit.RST_SEQ2=1; //Immediately Resets SEQ2 to Conv07 State !!
	 AdcRegs.ADCTRL2.bit.SOC_SEQ2=0; //Clears a Pending SOC trigger
	 AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2=0; //Disable Interrrupt Request of SEQ2 !!!
	 AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2=0; //INT_SEQ2 is Set at the End of Every SEQ2 Sequence
	 AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2=0; //No Need to Allow SEQ2 to be Started by EPWM_SOCB Trigger (Eva Previously)!!!
     
	 AdcRegs.ADCMAXCONV.all = 0x0001;  ////Sets the Number of ADC Channels for Each SEQ!! Here 2 for Each Sequence,because each time only I1 and V1
	////If not reset, the next ADC_SEQ starts at the end of last time's stop. Only In ISR, Reset the SEQ!!
    ////!!!! ADCINA0=ADCINA2=ADCINA4=ADCINA6 Pins All Connected to Current Read; ADCINA1=ADCINA3=ADCINA5=ADCINA7 Pins All Connected to Voltage Read
	 AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0; ////ADCINA0 ==>EPwm2_SOCA Trigger
     AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1; ////ADCINA1 ==>EPwm2_SOCA Trigger
     AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2; ////ADCINA2 ==>EPwm1_SOCA Trigger
     AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 0x3; ////ADCINA3 ==>EPwm1_SOCA Trigger
     AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 0x4; ////ADCINA4 ==>EPwm2_SOCB Trigger
     AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0x5; ////ADCINA5 ==>EPwm2_SOCB Trigger
	 AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 0x6; ////ADCINA6 ==>EPwm1_SOCB Trigger
     AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 0x7; ////ADCINA7 ==>EPwm1_SOCB Trigger

}

//===========================================================================
// End of file.
//===========================================================================
