/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer.h
 *
 * Code generated for Simulink model 'SimulinkPacer'.
 *
 * Model version                  : 5.80
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 28 22:33:48 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SimulinkPacer_h_
#define RTW_HEADER_SimulinkPacer_h_
#ifndef SimulinkPacer_COMMON_INCLUDES_
#define SimulinkPacer_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#endif                                 /* SimulinkPacer_COMMON_INCLUDES_ */

#include "SimulinkPacer_types.h"
#include <stddef.h>
#include "echo_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[39];
  uint8_T RxDataLocChar[39];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  real_T green_charge;                 /* '<S7>/Chart' */
  real_T red_pulse;                    /* '<S7>/Chart' */
  real_T blue_refractory;              /* '<S7>/Chart' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Chart' */
  real_T VENT_GND_CTRL;                /* '<Root>/Chart' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Chart' */
  real_T PACE_GND_CTRL;                /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Chart' */
  real_T tomspp;
  real_T Multiply2;
  real32_T id_in;
  real32_T id_in_o;                    /* '<Root>/Chart1' */
  real32_T vent_amp_in;                /* '<Root>/Chart1' */
  real32_T vent_sensitivity_in;        /* '<Root>/Chart1' */
  real32_T VRP_in;                     /* '<Root>/Chart1' */
  real32_T atr_amp_in;                 /* '<Root>/Chart1' */
  real32_T atr_sensitivity_in;         /* '<Root>/Chart1' */
  uint16_T ARP_in;                     /* '<Root>/Chart1' */
  uint8_T BytePack[4];                 /* '<S4>/Byte Pack' */
  uint8_T mode;                        /* '<Root>/Chart1' */
  uint8_T lrl_in;                      /* '<Root>/Chart1' */
  uint8_T vent_pw_in;                  /* '<Root>/Chart1' */
  uint8_T atr_pw_in;                   /* '<Root>/Chart1' */
} B_SimulinkPacer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Simul_T obj; /* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Simul_T obj_e;/* '<S5>/Digital Read' */
  freedomk64f_SCIRead_SimulinkP_T obj_c;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Simulink_T obj_p;/* '<S4>/Serial Transmit' */
  freedomk64f_DigitalWrite_Simu_T obj_k;/* '<S7>/Digital Write2' */
  freedomk64f_DigitalWrite_Simu_T obj_l;/* '<S7>/Digital Write1' */
  freedomk64f_DigitalWrite_Simu_T obj_d;/* '<S7>/Digital Write' */
  freedomk64f_DigitalWrite_Simu_T obj_g;/* '<S6>/Digital Write8' */
  freedomk64f_DigitalWrite_Simu_T obj_gj;/* '<S6>/Digital Write7' */
  freedomk64f_DigitalWrite_Simu_T obj_gm;/* '<S6>/Digital Write6' */
  freedomk64f_DigitalWrite_Simu_T obj_e0;/* '<S6>/Digital Write5' */
  freedomk64f_DigitalWrite_Simu_T obj_gy;/* '<S6>/Digital Write4' */
  freedomk64f_DigitalWrite_Simu_T obj_ec;/* '<S6>/Digital Write3' */
  freedomk64f_DigitalWrite_Simu_T obj_n;/* '<S6>/Digital Write2' */
  freedomk64f_DigitalWrite_Simu_T obj_h;/* '<S6>/Digital Write11' */
  freedomk64f_DigitalWrite_Simu_T obj_j;/* '<S6>/Digital Write10' */
  freedomk64f_PWMOutput_Simulin_T obj_hk;/* '<S6>/PWM Output2' */
  freedomk64f_PWMOutput_Simulin_T obj_jf;/* '<S6>/PWM Output1' */
  freedomk64f_PWMOutput_Simulin_T obj_b;/* '<S6>/PWM Output' */
  real_T artificial_pace;              /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c1_SimulinkPacer;  /* '<S7>/Chart' */
  uint8_T is_c1_SimulinkPacer;         /* '<S7>/Chart' */
  uint8_T is_c2_SimulinkPacer;         /* '<Root>/Chart1' */
  uint8_T is_active_c3_SimulinkPacer;  /* '<Root>/Chart' */
  uint8_T is_c3_SimulinkPacer;         /* '<Root>/Chart' */
  uint8_T is_VOO;                      /* '<Root>/Chart' */
  uint8_T is_AOO;                      /* '<Root>/Chart' */
  uint8_T is_VVI;                      /* '<Root>/Chart' */
  uint8_T is_AAI;                      /* '<Root>/Chart' */
} DW_SimulinkPacer_T;

/* Parameters (default storage) */
struct P_SimulinkPacer_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T maxV1_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V1'
                                        */
  real_T Multiply3_Gain;               /* Expression: 100
                                        * Referenced by: '<S3>/Multiply3'
                                        */
  real_T maxV2_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V2'
                                        */
  real_T Multiply2_Gain;               /* Expression: 100
                                        * Referenced by: '<S3>/Multiply2'
                                        */
  real_T mintoms_Value;                /* Expression: 60000
                                        * Referenced by: '<S3>/min to ms'
                                        */
  real_T mintoms1_Value;               /* Expression: 60000
                                        * Referenced by: '<S3>/min to ms1'
                                        */
  real_T maxV3_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V3'
                                        */
  real_T Multiply_Gain;                /* Expression: 100
                                        * Referenced by: '<S3>/Multiply'
                                        */
  real_T maxV4_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V4'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S3>/Multiply1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimulinkPacer_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_SimulinkPacer_T SimulinkPacer_P;

/* Block signals (default storage) */
extern B_SimulinkPacer_T SimulinkPacer_B;

/* Block states (default storage) */
extern DW_SimulinkPacer_T SimulinkPacer_DW;

/* Model entry point functions */
extern void SimulinkPacer_initialize(void);
extern void SimulinkPacer_step(void);
extern void SimulinkPacer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimulinkPacer_T *const SimulinkPacer_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SimulinkPacer'
 * '<S1>'   : 'SimulinkPacer/Chart'
 * '<S2>'   : 'SimulinkPacer/Chart1'
 * '<S3>'   : 'SimulinkPacer/DCM Inputs'
 * '<S4>'   : 'SimulinkPacer/Function-Call Subsystem'
 * '<S5>'   : 'SimulinkPacer/Hardware Pins Subsystem Inputs'
 * '<S6>'   : 'SimulinkPacer/Hardware Pins Subsystem Outputs'
 * '<S7>'   : 'SimulinkPacer/LED Testing'
 * '<S8>'   : 'SimulinkPacer/LED Testing/Chart'
 */
#endif                                 /* RTW_HEADER_SimulinkPacer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
