/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_example_modify.c
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

#include "Serial_example_modify.h"
#include "Serial_example_modify_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "send_parameters.h"
#include "send_parameters_private.h"

/* Named constants for Chart: '<Root>/COM_IN' */
#define Serial_example_mo_IN_ECHO_PARAM ((uint8_T)1U)
#define Serial_example_modif_IN_INITIAL ((uint8_T)2U)
#define Serial_example_modif_IN_STANDBY ((uint8_T)3U)

/* Block signals (default storage) */
B_Serial_example_modify_T Serial_example_modify_B;

/* Block states (default storage) */
DW_Serial_example_modify_T Serial_example_modify_DW;

/* Real-time model */
static RT_MODEL_Serial_example_modif_T Serial_example_modify_M_;
RT_MODEL_Serial_example_modif_T *const Serial_example_modify_M =
  &Serial_example_modify_M_;

/* Forward declaration for local functions */
static void Serial_examp_SystemCore_setup_k(freedomk64f_SCIRead_Serial_ex_T *obj);
static void Serial_examp_SystemCore_setup_k(freedomk64f_SCIRead_Serial_ex_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T SCIModuleLoc;
  uint32_T TxPinLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void Serial_example_modify_step(void)
{
  uint8_T RxData[11];
  uint8_T RxDataLocChar[11];
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Serial_example_modify_DW.obj.SampleTime !=
      Serial_example_modify_P.SerialReceive_SampleTime) {
    Serial_example_modify_DW.obj.SampleTime =
      Serial_example_modify_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Serial_example_modify_DW.obj.MW_SCIHANDLE,
    &RxDataLocChar[0], 11U);
  memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (uint32_T)((size_t)11 *
          sizeof(uint8_T)));

  /* Chart: '<Root>/COM_IN' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Serial_example_modify_DW.is_active_c3_Serial_example_mod == 0U) {
    Serial_example_modify_DW.is_active_c3_Serial_example_mod = 1U;
    Serial_example_modify_DW.is_c3_Serial_example_modify =
      Serial_example_modif_IN_INITIAL;
  } else {
    switch (Serial_example_modify_DW.is_c3_Serial_example_modify) {
     case Serial_example_mo_IN_ECHO_PARAM:
      Serial_example_modify_DW.is_c3_Serial_example_modify =
        Serial_example_modif_IN_STANDBY;
      break;

     case Serial_example_modif_IN_INITIAL:
      Serial_example_modify_DW.is_c3_Serial_example_modify =
        Serial_example_modif_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (RxData[6] == 1) {
          Serial_example_modify_DW.is_c3_Serial_example_modify =
            Serial_example_mo_IN_ECHO_PARAM;
          Serial_example_modify_B.pkmode_h[0] = RxData[2];
          Serial_example_modify_B.pkmode_h[1] = RxData[3];
          Serial_example_modify_B.pkmode_h[2] = RxData[4];
          Serial_example_modify_B.pkmode_h[3] = RxData[5];
          send_parameters();
        } else {
          Serial_example_modify_DW.is_c3_Serial_example_modify =
            Serial_example_modif_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/COM_IN' */
}

/* Model initialize function */
void Serial_example_modify_initialize(void)
{
  /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  send_parameters_Init();

  /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

  /* Start for MATLABSystem: '<Root>/Serial Receive' */
  Serial_example_modify_DW.obj.isInitialized = 0;
  Serial_example_modify_DW.obj.matlabCodegenIsDeleted = false;
  Serial_example_modify_DW.obj.SampleTime =
    Serial_example_modify_P.SerialReceive_SampleTime;
  Serial_examp_SystemCore_setup_k(&Serial_example_modify_DW.obj);
}

/* Model terminate function */
void Serial_example_modify_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Serial_example_modify_DW.obj.matlabCodegenIsDeleted) {
    Serial_example_modify_DW.obj.matlabCodegenIsDeleted = true;
    if ((Serial_example_modify_DW.obj.isInitialized == 1) &&
        Serial_example_modify_DW.obj.isSetupComplete) {
      MW_SCI_Close(Serial_example_modify_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  send_parameters_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
