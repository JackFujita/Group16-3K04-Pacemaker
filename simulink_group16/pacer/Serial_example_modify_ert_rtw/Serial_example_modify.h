/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_example_modify.h
 *
 * Code generated for Simulink model 'Serial_example_modify'.
 *
 * Model version                  : 3.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 25 23:31:09 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Serial_example_modify_h_
#define RTW_HEADER_Serial_example_modify_h_
#ifndef Serial_example_modify_COMMON_INCLUDES_
#define Serial_example_modify_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#endif                              /* Serial_example_modify_COMMON_INCLUDES_ */

#include "Serial_example_modify_types.h"
#include <stddef.h>
#include "send_parameters.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T pkmode[4];
  uint8_T BytePack1[4];                /* '<S2>/Byte Pack1' */
  uint8_T pkmode_h[4];                 /* '<Root>/COM_IN' */
} B_Serial_example_modify_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_SCIRead_Serial_ex_T obj; /* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Serial_e_T obj_g;/* '<S2>/Serial Transmit' */
  uint8_T is_active_c3_Serial_example_mod;/* '<Root>/COM_IN' */
  uint8_T is_c3_Serial_example_modify; /* '<Root>/COM_IN' */
} DW_Serial_example_modify_T;

/* Parameters (default storage) */
struct P_Serial_example_modify_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Serial_example_modify_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Serial_example_modify_T Serial_example_modify_P;

/* Block signals (default storage) */
extern B_Serial_example_modify_T Serial_example_modify_B;

/* Block states (default storage) */
extern DW_Serial_example_modify_T Serial_example_modify_DW;

/* Model entry point functions */
extern void Serial_example_modify_initialize(void);
extern void Serial_example_modify_step(void);
extern void Serial_example_modify_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Serial_example_modif_T *const Serial_example_modify_M;

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
 * '<Root>' : 'Serial_example_modify'
 * '<S1>'   : 'Serial_example_modify/COM_IN'
 * '<S2>'   : 'Serial_example_modify/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_Serial_example_modify_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
