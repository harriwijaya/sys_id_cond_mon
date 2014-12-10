 
//###########################################################################
//
// FILE:   DSP2833x_Examples.h
//
// TITLE:  DSP2833x Device Definitions.
//
 

#ifndef DSP2833x_PROJECT_H
#define DSP2833x_PROJECT_H

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


#ifdef __cplusplus
extern "C" {
#endif

#define	  adcrest (*((volatile  Uint16 *)0x400F))    //外置ADC复位
#define	  adccvt (*((volatile  Uint16 *)0x4010))     //外置ADC启动
#define	  adccs   (*((volatile  Uint16 *)0x4080))      //外置adc chip select

#define	  dacen  (*((volatile  Uint16 *)0x4011))     //DAC输出控制
#define	  daccs1 (*((volatile  Uint16 *)0x4060))
#define	  daccs2 (*((volatile  Uint16 *)0x4061))
#define	  daccs3 (*((volatile  Uint16 *)0x4062))
#define	  daccs4 (*((volatile  Uint16 *)0x4063))


#ifdef __cplusplus
}
#endif /* extern "C" */
#endif // DSP2833x_PROJECT_H
