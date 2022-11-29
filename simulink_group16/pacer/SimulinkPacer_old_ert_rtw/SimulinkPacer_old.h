/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer_old.h
 *
 * Code generated for Simulink model 'SimulinkPacer_old'.
 *
 * Model version                  : 5.93
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 28 23:01:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SimulinkPacer_old_h_
#define RTW_HEADER_SimulinkPacer_old_h_
#ifndef SimulinkPacer_old_COMMON_INCLUDES_
#define SimulinkPacer_old_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#endif                                 /* SimulinkPacer_old_COMMON_INCLUDES_ */

#include "SimulinkPacer_old_types.h"
#include <stddef.h>
#include "echo_params_old.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[11];
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
  uint8_T mode;                        /* '<Root>/Chart1' */
  uint8_T lrl_in;                      /* '<Root>/Chart1' */
} B_SimulinkPacer_old_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Simul_T obj; /* '<S5>/Digital Read1' */
  freedomk64f_DigitalRead_Simul_T obj_e;/* '<S5>/Digital Read' */
  freedomk64f_SCIRead_SimulinkP_T obj_d;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Simulink_T obj_a;/* '<S4>/Serial Transmit' */
  freedomk64f_DigitalWrite_Simu_T obj_o;/* '<S7>/Digital Write2' */
  freedomk64f_DigitalWrite_Simu_T obj_b;/* '<S7>/Digital Write1' */
  freedomk64f_DigitalWrite_Simu_T obj_m;/* '<S7>/Digital Write' */
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
  freedomk64f_PWMOutput_Simulin_T obj_by;/* '<S6>/PWM Output' */
  real_T artificial_pace;              /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c1_SimulinkPacer_old;/* '<S7>/Chart' */
  uint8_T is_c1_SimulinkPacer_old;     /* '<S7>/Chart' */
  uint8_T is_active_c4_SimulinkPacer_old;/* '<Root>/Chart1' */
  uint8_T is_c4_SimulinkPacer_old;     /* '<Root>/Chart1' */
  uint8_T is_active_c3_SimulinkPacer_old;/* '<Root>/Chart' */
  uint8_T is_c3_SimulinkPacer_old;     /* '<Root>/Chart' */
  uint8_T is_VOO;                      /* '<Root>/Chart' */
  uint8_T is_AOO;                      /* '<Root>/Chart' */
  uint8_T is_VVI;                      /* '<Root>/Chart' */
  uint8_T is_AAI;                      /* '<Root>/Chart' */
} DW_SimulinkPacer_old_T;

/* Parameters (default storage) */
struct P_SimulinkPacer_old_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S5>/Digital Read1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T Constant1_Value;              /* Expression: 5
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 5
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T inputV1_Value;                /* Expression: 3
                                        * Referenced by: '<S3>/input V1'
                                        */
  real_T maxV1_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V1'
                                        */
  real_T Multiply3_Gain;               /* Expression: 100
                                        * Referenced by: '<S3>/Multiply3'
                                        */
  real_T inputV2_Value;                /* Expression: 3
                                        * Referenced by: '<S3>/input V2'
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
  real_T upperratelimitinpulsesmin_Value;/* Expression: 120
                                          * Referenced by: '<S3>/upper rate limit in pulses//min'
                                          */
  real_T mintoms1_Value;               /* Expression: 60000
                                        * Referenced by: '<S3>/min to ms1'
                                        */
  real_T Constant5_Value;              /* Expression: 150
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T inputV3_Value;                /* Expression: 3.5
                                        * Referenced by: '<S3>/input V3'
                                        */
  real_T maxV3_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V3'
                                        */
  real_T Multiply_Gain;                /* Expression: 100
                                        * Referenced by: '<S3>/Multiply'
                                        */
  real_T Constant9_Value;              /* Expression: 150
                                        * Referenced by: '<S3>/Constant9'
                                        */
  real_T inputV4_Value;                /* Expression: 3.25
                                        * Referenced by: '<S3>/input V4'
                                        */
  real_T maxV4_Value;                  /* Expression: 5
                                        * Referenced by: '<S3>/max V4'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S3>/Multiply1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimulinkPacer_old_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_SimulinkPacer_old_T SimulinkPacer_old_P;

/* Block signals (default storage) */
extern B_SimulinkPacer_old_T SimulinkPacer_old_B;

/* Block states (default storage) */
extern DW_SimulinkPacer_old_T SimulinkPacer_old_DW;

/* Model entry point functions */
extern void SimulinkPacer_old_initialize(void);
extern void SimulinkPacer_old_step(void);
extern void SimulinkPacer_old_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimulinkPacer_old_T *const SimulinkPacer_old_M;

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
 * '<Root>' : 'SimulinkPacer_old'
 * '<S1>'   : 'SimulinkPacer_old/Chart'
 * '<S2>'   : 'SimulinkPacer_old/Chart1'
 * '<S3>'   : 'SimulinkPacer_old/DCM Inputs'
 * '<S4>'   : 'SimulinkPacer_old/Function-Call Subsystem'
 * '<S5>'   : 'SimulinkPacer_old/Hardware Pins Subsystem Inputs'
 * '<S6>'   : 'SimulinkPacer_old/Hardware Pins Subsystem Outputs'
 * '<S7>'   : 'SimulinkPacer_old/LED Testing'
 * '<S8>'   : 'SimulinkPacer_old/LED Testing/Chart'
 */
#endif                                 /* RTW_HEADER_SimulinkPacer_old_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */