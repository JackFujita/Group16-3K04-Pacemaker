/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer.h
 *
 * Code generated for Simulink model 'SimulinkPacer'.
 *
 * Model version                  : 5.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 17 10:59:07 2022
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
#endif                                 /* SimulinkPacer_COMMON_INCLUDES_ */

#include "SimulinkPacer_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T State;                        /* '<Root>/Chart' */
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
} B_SimulinkPacer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_Simu_T obj; /* '<Root>/Digital Write8' */
  freedomk64f_DigitalWrite_Simu_T obj_b;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_Simu_T obj_h;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_Simu_T obj_l;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Simu_T obj_j;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Simu_T obj_p;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_Simu_T obj_e;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_Simu_T obj_m;/* '<Root>/Digital Write11' */
  freedomk64f_DigitalWrite_Simu_T obj_o;/* '<Root>/Digital Write10' */
  freedomk64f_DigitalWrite_Simu_T obj_i;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_Simu_T obj_mo;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_Simulin_T obj_c;/* '<Root>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_SimulinkPacer;  /* '<Root>/Chart' */
  uint8_T is_c3_SimulinkPacer;         /* '<Root>/Chart' */
} DW_SimulinkPacer_T;

/* Parameters (default storage) */
struct P_SimulinkPacer_T_ {
  real_T Constant3_Value;              /* Expression: 20
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 75
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 75
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: 750
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant1_Value;              /* Expression: 750
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
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
 */
#endif                                 /* RTW_HEADER_SimulinkPacer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
