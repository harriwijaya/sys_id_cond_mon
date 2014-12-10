// TI File $Revision: /main/7 $
// Checkin $Date: September 20, 2007   13:30:31 $
//###########################################################################
//
// FILE:   DSP2833x_Cap_Init.c
//
// TITLE:  DSP2833x Device System Control Initialization & Support Functions.
//
// DESCRIPTION:
//
//         Example initialization of system resources.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################


#include "DSP2833x_Device.h"     // Headerfile Include File
#include "DSP2833x_Examples.h"   // Examples Include File

// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped to a load and
// run address using the linker cmd file.

 #pragma CODE_SECTION(InitFlash, "ramfuncs");

//---------------------------------------------------------------------------
// InitSysCtrl:
//---------------------------------------------------------------------------
// This function initializes the System Control registers to a known state.
// - Disables the watchdog
// - Set the PLLCR for proper SYSCLKOUT frequency
// - Set the pre-scaler for the high and low frequency peripheral clocks
// - Enable the clocks to the peripherals

void InitCap(void)
{
   EALLOW;
  ///Enable ECap Funtion at the CPU Control Register
   SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK=1; //Enable clock to Cap1 
  // Enable internal pull-up for the selected pins
  // Pull-ups can be enabled or disabled by the user.
  // This will enable the pullups for the specified pins.
   GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0; // Enable pull-up on GPIO24 (CAP1)
  //eCAP1 and eQEP1A will be configured using the same GPIO24 APGMUX2 Control Register ??? How to ???
   GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1; // Configure GPIO24 as eCAP1 (eQEP2A is not used Because eQEP1A/B/I is used)
   EDIS;
   
  //Configure eCAP1 for Capturing Enc_A's Rising_Edge
   ECap1Regs.ECCTL1.all=0x0C102; //EC_Rising; Reset on CEVT1 Only; By-pass Enc_A Edge Prescaling; Enable CAP1-4 loads at CEVTs
//   ECap1Regs.ECCTL2.bit.CAP_APWM=0; //eCAP works in CAP Mode
//   ECap1Regs.ECCTL2.bit.CONT_ONESHT=0; //Continuous Mode is Selected (1 for OneShot Mode)
//   ECap1Regs.ECCTL2.bit.SYNCO_SEL=2; //Disable Output Synchronization
//   ECap1Regs.ECCTL2.bit.SYNCI_EN=0; //Disable Input Synchronization
//   ECap1Regs.ECCTL2.bit.TSCTRSTOP=1; // Allow TSCTR to run (Free Run)
   ECap1Regs.ECCTL2.all=0x0090;
  //eCAP Interrupt Enable and Flags
   ECap1Regs.ECEINT.all=0x0000; //Disable All Interrupts First
   ECap1Regs.ECCLR.all=0xFFFF; //Clear all Interrupt flags
   ECap1Regs.ECEINT.bit.CEVT1=1; // Enable cevt1 Interrupt
  //ECap1Regs.ECEINT.bit.CTROVF=1; //Enable Counter OverFlow Interrupt 
  //Do not use eCAP2
}


//===========================================================================
// End of file.
//===========================================================================
