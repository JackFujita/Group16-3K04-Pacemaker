/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_parameters.c
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

#include "Serial_example_modify_types.h"
#include "send_parameters_private.h"
#include "Serial_example_modify.h"
#include "send_parameters.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Serial_example_SystemCore_setup(freedomk64f_SCIWrite_Serial_e_T *obj);
static void Serial_example_SystemCore_setup(freedomk64f_SCIWrite_Serial_e_T *obj)
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
void send_parameters_Init(void)
{
  /* Start for MATLABSystem: '<S2>/Serial Transmit' */
  Serial_example_modify_DW.obj_g.isInitialized = 0;
  Serial_example_modify_DW.obj_g.matlabCodegenIsDeleted = false;
  Serial_example_SystemCore_setup(&Serial_example_modify_DW.obj_g);
}

/* Output and update for Simulink Function: '<Root>/Function-Call Subsystem' */
void send_parameters(void)
{
  uint8_T TxDataLocChar[5];
  uint8_T rtb_TmpSignalConversionAtSerial[5];
  uint8_T status;

  /* SignalConversion generated from: '<S2>/pkmode' */
  Serial_example_modify_B.pkmode[0] = Serial_example_modify_B.pkmode_h[0];
  Serial_example_modify_B.pkmode[1] = Serial_example_modify_B.pkmode_h[1];
  Serial_example_modify_B.pkmode[2] = Serial_example_modify_B.pkmode_h[2];
  Serial_example_modify_B.pkmode[3] = Serial_example_modify_B.pkmode_h[3];

  /* S-Function (any2byte): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  (void) memcpy(&Serial_example_modify_B.BytePack1[0],
                &Serial_example_modify_B.pkmode[0],
                4);

  /* SignalConversion generated from: '<S2>/Serial Transmit' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_TmpSignalConversionAtSerial[0] = Serial_example_modify_B.BytePack1[0];
  rtb_TmpSignalConversionAtSerial[1] = Serial_example_modify_B.BytePack1[1];
  rtb_TmpSignalConversionAtSerial[2] = Serial_example_modify_B.BytePack1[2];
  rtb_TmpSignalConversionAtSerial[3] = Serial_example_modify_B.BytePack1[3];
  rtb_TmpSignalConversionAtSerial[4] = Serial_example_modify_P.Constant_Value;

  /* MATLABSystem: '<S2>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (uint32_T)((size_t)5 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(Serial_example_modify_DW.obj_g.MW_SCIHANDLE,
      &TxDataLocChar[0], 5U);
  }

  /* End of MATLABSystem: '<S2>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Function-Call Subsystem' */
void send_parameters_Term(void)
{
  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  if (!Serial_example_modify_DW.obj_g.matlabCodegenIsDeleted) {
    Serial_example_modify_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Serial_example_modify_DW.obj_g.isInitialized == 1) &&
        Serial_example_modify_DW.obj_g.isSetupComplete) {
      MW_SCI_Close(Serial_example_modify_DW.obj_g.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
