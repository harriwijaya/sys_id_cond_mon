// TI File $Revision: /main/1 $
// Checkin $Date: August 23, 2014   13:46:19 $
//###########################################################################
//
// FILE:   DSP2833x_EPwm.c
//
// TITLE:  DSP2833x ePWM Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: August 23, 2014 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitEPwm: 
//---------------------------------------------------------------------------
// This function initializes the ePWM(s) to a known state.
//
void InitEPwm(void)
{
   ////Initialize ePWM1A, ePWM1B
   EPwm1Regs.TBCTL.all=0x24B0; ////TBCLK=SysCLKOUT/2/2; Up-Count Asymmetrical Mode; Re-load when TBCNT=0; Shadow Used
   EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; ////For Synchronization of EPwm_N modules with EPwm1 as the Head
   EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
   EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
   EPwm1Regs.TBSTS.all=0;
   EPwm1Regs.TBPHS.half.TBPHS=0; ////No Phase Shift Used
   EPwm1Regs.TBCTR=0; ////Clear Counter

   EPwm1Regs.TBPRD=0x0EA5; ////TBCLK=37.5MHz => Duty_DTC=10KHz; PRD=37.5M/10K - 1 =3750-1=SP (Up-Zero-Up-Zero)
   EPwm1Regs.AQCTLA.all=0x0012; ////CBD=CBU=00 and CAD=00, CAU=01; PRD=00, ZRO=10(Set-High At the Beginning)
   EPwm1Regs.AQCTLB.all=0x0000; ////EPWM1B is not working. Since Only One Switch
   EPwm1Regs.CMPA.half.CMPA=0x03A9; ////SP/4 generates a 25% duty
   EPwm1Regs.CMPB=0x0E9C; ////CNT_Max-10=3750-10=3740
   EPwm1Regs.CMPCTL.all=0x0000; ////Shadow Mode is Used(Set to Shadow in TBCTL!!), Shadow Reg loaded both at CNT==ZRO! One-Cycle Delayed!
 
   EPwm1Regs.AQSFRC.all=0;
   EPwm1Regs.AQCSFRC.all=0;
   
   EPwm1Regs.DBCTL.all=0x000B; ////EPWM1A is the Source for both Rising&Falling Edge DeadTime Gen; DB totally Enabled
   EPwm1Regs.DBRED=0x0002; ////20ns delay=2/37.5MHz
   EPwm1Regs.DBFED=0x0002; ////20ns delay=2/37.5MHz
   ////Configure Event-Trigger Registers
   ////Enable Both SOC_A and SOC_B ADC Trigger && Interrupt ==> EPWM 2/3 Interrupts Shouldn't be Enabled
   EPwm1Regs.ETSEL.all=0xEC0A; ////Event At(Counter==CMPB when timer is incrementing) and (Counter==CMPA when timer is incrementing); Interrupt At (TBCTR=TBPRD)
   EPwm1Regs.ETPS.all=0x5505; ////Only EPWM1 Interrupt is generated on the first occur of Event; Both SOC_A/B on First Event
   
   PieCtrlRegs.PIEIER3.bit.INTx1=1; ////Enable T1PINT
   EPwm1Regs.ETCLR.bit.INT=1;
   EPwm1Regs.ETCLR.bit.SOCA=1;
   EPwm1Regs.ETFLG.bit.INT=0;
   ////Initialize ePWM2A, ePWM2B
   EPwm2Regs.TBCTL.all=0x24B0; ////TBCLK=SysCLKOUT/2/2; Up-Count Asymmetrical Mode; Re-load when TBCNT=0; Shadow Used
   EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;
   EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
   EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
   EPwm2Regs.TBSTS.all=0;
   EPwm2Regs.TBPHS.half.TBPHS=0; ////No Phase Shift Used
   EPwm2Regs.TBCTR=0; ////Clear Counter

   EPwm2Regs.TBPRD=0x0EA5; ////TBCLK=37.5MHz => Duty_DTC=10KHz; PRD=37.5M/10K - 1 =3750-1=SP (Up-Zero-Up-Zero)
   EPwm2Regs.AQCTLA.all=0x0000; ////EPWM2A is not working. Only for ADC SOC Generation!!
   EPwm2Regs.AQCTLB.all=0x0000; ////EPWM2B is not working. Only for ADC SOC Generation!!
   EPwm2Regs.CMPA.half.CMPA=0x03A9; ////SP/4 generates a 25% duty
   EPwm2Regs.CMPB=0x0E74; ////CNT_Max-10=3750-10 - 25 = 3715 ==>This is Because EPwm2_CMPB is Collaborating with EPwm1_CMPB
   EPwm2Regs.CMPCTL.all=0x0000; ////Shadow Mode is Used(Set to Shadow in TBCTL!!), Shadow Reg loaded both at CNT==ZRO! One-Cycle Delayed!
   EPwm2Regs.AQSFRC.all=0;
   EPwm2Regs.AQCSFRC.all=0;
   EPwm2Regs.DBCTL.all=0x000B; ////EPWM1A is the Source for both Rising&Falling Edge DeadTime Gen; DB totally Enabled
   EPwm2Regs.DBRED=0x0002; ////20ns delay=2/37.5MHz
   EPwm2Regs.DBFED=0x0002; ////20ns delay=2/37.5MHz

   ////Configure Event-Trigger Registers
   ////Enable Both SOC_A and SOC_B ADC Trigger(Not Interrupt) ==> EPWM 2/3 Interrupts Shouldn't be Enabled
   EPwm2Regs.ETSEL.all=0xEC00; ////Event Generated when (Counter==CMPB when timer is incrementing) and (Counter==CMPA when timer is incrementing); Int Disabled!!
   EPwm2Regs.ETPS.all=0x550C; ////SOC_A/B are Generated on the First Event of ET; No Interrupt is generated !!!

}

//---------------------------------------------------------------------------
// Example: InitEPwmGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 

void InitEPwmGpio(void)
{
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();
#if DSP28_EPWM4
   InitEPwm4Gpio();
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5    
   InitEPwm5Gpio();
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
   InitEPwm6Gpio();
#endif // endif DSP28_EPWM6 
}

void InitEPwm1Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)   
   
/* Configure ePWM-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM1 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
   
    EDIS;
}

void InitEPwm2Gpio(void)
{
   EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)

/* Configure ePWM-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM2 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
   
    EDIS;
}

void InitEPwm3Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM3 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
	
    EDIS;
}


#if DSP28_EPWM4
void InitEPwm4Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;    // Enable pull-up on GPIO7 (EPWM4B)

/* Configure ePWM-4 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM4 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
	
    EDIS;
}
#endif // endif DSP28_EPWM4  


#if DSP28_EPWM5
void InitEPwm5Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)

/* Configure ePWM-5 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
	
    EDIS;
}
#endif // endif DSP28_EPWM5


#if DSP28_EPWM6
void InitEPwm6Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up on GPIO11 (EPWM6B)

/* Configure ePWM-6 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B
	
    EDIS;
}
#endif // endif DSP28_EPWM6  

//---------------------------------------------------------------------------
// Example: InitEPwmSyncGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM Synch pins
//

void InitEPwmSyncGpio(void)
{

   EALLOW;

/* Configure EPWMSYNCI  */
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pull-up on GPIO32 (EPWMSYNCI)    

/* Set qualification for selected pins to asynch only */
// This will select synch to SYSCLKOUT for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;   // Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;  // Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)    

/* Configure EPwmSync pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be EPwmSync functional pins.
// Comment out other unwanted lines.   

   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2;   // Enable pull-up on GPIO32 (EPWMSYNCI)    



/* Configure EPWMSYNC0  */

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

// GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pull-up on GPIO33 (EPWMSYNC0)    

// GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;   // Enable pull-up on GPIO33 (EPWMSYNC0)    

}



//---------------------------------------------------------------------------
// Example: InitTzGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as Trip Zone (TZ) pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 

void InitTzGpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up on GPIO12 (TZ1)
//   GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;    // Enable pull-up on GPIO13 (TZ2)
//   GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up on GPIO14 (TZ3)
//   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up on GPIO15 (TZ4)

//   GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;    // Enable pull-up on GPIO16 (TZ5)
// GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up on GPIO28 (TZ5)

//   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;    // Enable pull-up on GPIO17 (TZ6) 
// GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up on GPIO29 (TZ6)  
   
/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3;  // Asynch input GPIO12 (TZ1)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3;  // Asynch input GPIO13 (TZ2)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;  // Asynch input GPIO14 (TZ3)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (TZ4)

//   GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;  // Asynch input GPIO16 (TZ5)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (TZ5)

//   GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;  // Asynch input GPIO17 (TZ6) 
// GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;  // Asynch input GPIO29 (TZ6)  

   
/* Configure TZ pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be TZ functional pins.
// Comment out other unwanted lines.   
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as TZ1
//   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // Configure GPIO13 as TZ2
//   GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;  // Configure GPIO14 as TZ3
//   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;  // Configure GPIO15 as TZ4

//   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;  // Configure GPIO16 as TZ5
// GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // Configure GPIO28 as TZ5

//   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;  // Configure GPIO17 as TZ6               
// GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // Configure GPIO29 as TZ6  

   EDIS;
}



//===========================================================================
// End of file.
//===========================================================================
