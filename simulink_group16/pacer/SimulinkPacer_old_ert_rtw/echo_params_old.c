/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_params_old.c
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

#include "SimulinkPacer_old_types.h"
#include "echo_params_old_private.h"
#include "SimulinkPacer_old.h"
#include "echo_params_old.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void SimulinkPacer__SystemCore_setup(freedomk64f_SCIWrite_Simulink_T *obj);
static void SimulinkPacer__SystemCore_setup(freedomk64f_SCIWrite_Simulink_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params_old_Init(void)
{
  /* Start for MATLABSystem: '<S4>/Serial Transmit' */
  SimulinkPacer_old_DW.obj_a.isInitialized = 0;
  SimulinkPacer_old_DW.obj_a.matlabCodegenIsDeleted = false;
  SimulinkPacer__SystemCore_setup(&SimulinkPacer_old_DW.obj_a);
}

/* Output and update for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params_old(void)
{
  uint8_T TxDataLocChar[2];
  uint8_T rtb_TmpSignalConversionAtSerial[2];
  uint8_T status;

  /* SignalConversion generated from: '<S4>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S4>/lrl_echo'
   *  SignalConversion generated from: '<S4>/mode'
   */
  rtb_TmpSignalConversionAtSerial[0] = SimulinkPacer_old_B.mode;
  rtb_TmpSignalConversionAtSerial[1] = SimulinkPacer_old_B.lrl_in;

  /* MATLABSystem: '<S4>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(SimulinkPacer_old_DW.obj_a.MW_SCIHANDLE,
      &TxDataLocChar[0], 2U);
  }

  /* End of MATLABSystem: '<S4>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Function-Call Subsystem' */
void echo_params_old_Term(void)
{
  /* Terminate for MATLABSystem: '<S4>/Serial Transmit' */
  if (!SimulinkPacer_old_DW.obj_a.matlabCodegenIsDeleted) {
    SimulinkPacer_old_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_old_DW.obj_a.isInitialized == 1) &&
        SimulinkPacer_old_DW.obj_a.isSetupComplete) {
      MW_SCI_Close(SimulinkPacer_old_DW.obj_a.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
