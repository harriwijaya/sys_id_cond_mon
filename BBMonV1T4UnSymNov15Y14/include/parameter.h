// Basic Control Program of Buck-Boost Converter PI Regulation (Parameter and Constants Definition)
// Date: December, 6, 2014  20:18 pm
// Operator : Zhang Xi Nan

#ifndef PARAMETER_H
#define PARAMETER_H

// 1. Constants used in the main file
#ifndef TRUE
#define FALSE 0
#define TRUE  1
#endif
////Current and Voltage Low-pass-filter coefficients
////LPFConst1 = (a-1), where a=2t/Ts; t=1/(2*PI*Fcutoff), Ts is Sampling Period (2000Hz Cutoff)
////LPFConst2 = 1/(a+1)
#define LPF2K_Coe1  0.591549431  //Coefficient1 = a-1 for 2KHz Current LPF
#define LPF2K_Coe2  0.3858695451 //Coefficient2 = 1/(a+1) for 2KHz Current LPF
#define LPF100_Coe1  30.830989 ////a-1; a=2*1/(2*pi*100)/(1/10e3)=100/pi
#define LPF100_Coe2  0.0304590276 ////1/(a+1)
////ADC Scaling and Offsets
#define IL_SL_Cnst  0.007356 ////Origin : 0.00931875
#define Vout_SL_Cnst 0.0083425795  ////Origin : 0.00644
#define IL_OS_Cnst  -1620.0 ////Origin : -1680.5
#define Vout_OS_Cnst  -6.0 ////Origin : -1310.0
//// 2. Circuit parameters 
#define Ls  0.002  //Inductor 2mH
#define Cout  0.000004  //Output Capacitor 4uF
//// 3. PI Control parameters used in the main file
#define Vout_Ref_Init   18	////Suppose an Input of Vin=16V
#define Vout_Ref1  24  ////
#define Vout_Ref2  28  ////
#define Vout_Ref3  32  ////
#define Vout_Ref4  36  ////
//// 1)Parameters of Output Voltage PI Controller
#define Kp_Volt      1.0  ////Kp=1.2
#define Ki_Volt      0.2  ////Ki=0.1;0.6
#define VoltPI_PosSat   4.6	//// Positive Saturation Limit for Voltage PI = 5A
#define VoltPI_NegSat   -4.6 //// Negative Saturation Limit for Voltage PI = -5A
//// 2)Parameters of Inductor Current PI Controller
#define Kp_Cur      0.000015 ////Kp=0.12; 0.0006; 0.00012
#define Ki_Cur      0.00015  ////Ki=0.06; 0.002; 0.0025
#define CurPI_PosSat   0.72	//// Positive Saturation Limit for Current PI = 0.9
#define CurPI_NegSat   0	//// Negative Saturation Limit for Current PI = 0
////3) PWM Counter Gain
#define BB_PWMSLCnst  3749 ////1==>3750-1 Based on ePWM Configuration of Up-Mode Asymmetrical Carrier; CNT_max=3750-1=BB_PWMSLCnst
#define Interval  40 ////Delta_T=40*TB_CLK ==>Can't be 25 Because 37.5MHz/25=1.5MHz>1.25MHz(Max ADC)
////#define TB40_Cnst  0.00000106667 ////TB40_Cnst=40*1/37.5MHz=1066.67ns
#define TB40_Cnst  0.000013333375 ////TB40_Cnst*12.5=40*1/37.5MHz*12.5
////#define TB40_Cnst  0.00000336001 ////TB40_Cnst*40=40*1/37.5MHz*40
//// 4. Parameters for Condition Monitoring
#define OneDivRL    -0.04484304932735 //// 1/Rload=OneDivRL ~=1/22.3=0.0448
#define OneDivRLPos 0.04484304932735 //// 1/Rload=OneDivRL ~=1/22.3=0.0448
#define Den_PosMin  0.001
#define Den_NegMin  -0.001
#define C_nom_est  0.00047 ////470uF=0.000 470F
#define Cest_UpLim  0.00094 ////470uF*2
#define Cest_LowLim  0.000094 ////470uF*0.2
#define Resr_UpLim  0.02
#define Resr_LowLim  0.001

#endif  // end of PARAMETER.H definition
