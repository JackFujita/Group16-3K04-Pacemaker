/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer.c
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

#include "SimulinkPacer.h"
#include "rtwtypes.h"
#include "SimulinkPacer_types.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "echo_params.h"
#include "echo_params_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SimulinkPace_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SimulinkPacer_IN_AAI           ((uint8_T)1U)
#define SimulinkPacer_IN_AAI_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_AAI_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_AAI_Refractory ((uint8_T)3U)
#define SimulinkPacer_IN_AOO           ((uint8_T)2U)
#define SimulinkPacer_IN_AOO_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_AOO_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_ModeSelect    ((uint8_T)3U)
#define SimulinkPacer_IN_VOO           ((uint8_T)4U)
#define SimulinkPacer_IN_VOO_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_VOO_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_VVI           ((uint8_T)5U)
#define SimulinkPacer_IN_VVI_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_VVI_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_VVI_Refractory ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Chart1' */
#define SimulinkPacer_IN_ECHO_PARAM    ((uint8_T)1U)
#define SimulinkPacer_IN_INITIAL       ((uint8_T)2U)
#define SimulinkPacer_IN_SET_PARAM     ((uint8_T)3U)
#define SimulinkPacer_IN_STANDBY       ((uint8_T)4U)

/* Named constants for Chart: '<S7>/Chart' */
#define SimulinkPacer_IN_AOO_h         ((uint8_T)1U)
#define SimulinkPacer_IN_Start         ((uint8_T)2U)
#define SimulinkPacer_IN_VOO_k         ((uint8_T)3U)
#define SimulinkPacer_IN_VVI_c         ((uint8_T)4U)

/* Block signals (default storage) */
B_SimulinkPacer_T SimulinkPacer_B;

/* Block states (default storage) */
DW_SimulinkPacer_T SimulinkPacer_DW;

/* Real-time model */
static RT_MODEL_SimulinkPacer_T SimulinkPacer_M_;
RT_MODEL_SimulinkPacer_T *const SimulinkPacer_M = &SimulinkPacer_M_;

/* Forward declaration for local functions */
static void Simul_enter_atomic_VVI_Charging(const real_T *Multiply3, const
  real_T *Multiply);
static void Sim_enter_atomic_VVI_Refractory(const real_T *Multiply3, const
  real_T *Multiply);
static void SimulinkPacer_VVI(const real_T *tomspp, const real_T *Multiply3,
  const real_T *Divide, const real_T *Multiply, const boolean_T *DigitalRead1);
static void Simul_enter_atomic_AAI_Charging(const real_T *Multiply2, const
  real_T *Multiply1);
static void Sim_enter_atomic_AAI_Refractory(const real_T *Multiply2, const
  real_T *Multiply1);
static void Simul_enter_atomic_AOO_Charging(const real_T *Multiply2);
static void Simul_enter_atomic_VOO_Charging(const real_T *Multiply3);
static void SimulinkPace_SystemCore_setup_f(freedomk64f_SCIRead_SimulinkP_T *obj);

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_VVI_Charging(const real_T *Multiply3, const
  real_T *Multiply)
{
  SimulinkPacer_B.FRONTEND_CTRL = 1.0;
  SimulinkPacer_B.VENT_CMP_REF_PWM = *Multiply;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply3;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Sim_enter_atomic_VVI_Refractory(const real_T *Multiply3, const
  real_T *Multiply)
{
  SimulinkPacer_B.VENT_CMP_REF_PWM = *Multiply;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply3;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void SimulinkPacer_VVI(const real_T *tomspp, const real_T *Multiply3,
  const real_T *Divide, const real_T *Multiply, const boolean_T *DigitalRead1)
{
  if (SimulinkPacer_B.mode != 3) {
    SimulinkPacer_DW.is_VVI = SimulinkPace_IN_NO_ACTIVE_CHILD;
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
  } else {
    switch (SimulinkPacer_DW.is_VVI) {
     case SimulinkPacer_IN_VVI_Charging:
      SimulinkPacer_B.FRONTEND_CTRL = 1.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
      if (*DigitalRead1) {
        SimulinkPacer_DW.artificial_pace = 0.0;
        SimulinkPacer_DW.is_VVI = SimulinkPacer_IN_VVI_Refractory;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Sim_enter_atomic_VVI_Refractory(Multiply3, Multiply);
      } else if (SimulinkPacer_DW.temporalCounter_i1 >= (real32_T)(*tomspp -
                  *Divide * SimulinkPacer_DW.artificial_pace) -
                 SimulinkPacer_B.VRP_in) {
        SimulinkPacer_DW.is_VVI = SimulinkPacer_IN_VVI_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.VENT_CMP_REF_PWM = *Multiply;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
        SimulinkPacer_B.PACING_REF_PWM = *Multiply3;
      }
      break;

     case SimulinkPacer_IN_VVI_Pacing:
      SimulinkPacer_B.FRONTEND_CTRL = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(*Divide)) {
        SimulinkPacer_DW.artificial_pace = 1.0;
        SimulinkPacer_DW.is_VVI = SimulinkPacer_IN_VVI_Refractory;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Sim_enter_atomic_VVI_Refractory(Multiply3, Multiply);
      }
      break;

     default:
      /* case IN_VVI_Refractory: */
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= SimulinkPacer_B.VRP_in) {
        SimulinkPacer_DW.is_VVI = SimulinkPacer_IN_VVI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VVI_Charging(Multiply3, Multiply);
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_AAI_Charging(const real_T *Multiply2, const
  real_T *Multiply1)
{
  SimulinkPacer_B.FRONTEND_CTRL = 1.0;
  SimulinkPacer_B.ATR_CMP_REF_PWM = *Multiply1;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply2;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Sim_enter_atomic_AAI_Refractory(const real_T *Multiply2, const
  real_T *Multiply1)
{
  SimulinkPacer_B.ATR_CMP_REF_PWM = *Multiply1;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply2;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_AOO_Charging(const real_T *Multiply2)
{
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply2;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_VOO_Charging(const real_T *Multiply3)
{
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACING_REF_PWM = *Multiply3;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

static void SimulinkPace_SystemCore_setup_f(freedomk64f_SCIRead_SimulinkP_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  SimulinkPacer_B.TxPinLoc = MW_UNDEFINED_VALUE;
  SimulinkPacer_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SimulinkPacer_B.SCIModuleLoc, false, 10U,
    SimulinkPacer_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  SimulinkPacer_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        SimulinkPacer_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void SimulinkPacer_step(void)
{
  real_T Divide;
  real_T Divide1;
  real_T Multiply;
  real_T Multiply1;
  real_T Multiply3;
  uint16_T tmp_0;
  uint8_T status;
  boolean_T DigitalRead1;
  boolean_T tmp;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (SimulinkPacer_DW.obj_c.SampleTime !=
      SimulinkPacer_P.SerialReceive_SampleTime) {
    SimulinkPacer_DW.obj_c.SampleTime = SimulinkPacer_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(SimulinkPacer_DW.obj_c.MW_SCIHANDLE,
    &SimulinkPacer_B.RxDataLocChar[0], 39U);
  memcpy((void *)&SimulinkPacer_B.RxData[0], (void *)
         &SimulinkPacer_B.RxDataLocChar[0], (uint32_T)((size_t)39 * sizeof
          (uint8_T)));

  /* Chart: '<Root>/Chart1' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  switch (SimulinkPacer_DW.is_c2_SimulinkPacer) {
   case SimulinkPacer_IN_ECHO_PARAM:
    break;

   case SimulinkPacer_IN_INITIAL:
    SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_STANDBY;
    break;

   case SimulinkPacer_IN_SET_PARAM:
    SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_STANDBY;
    break;

   default:
    /* case IN_STANDBY: */
    if (status == 0) {
      if (SimulinkPacer_B.RxData[0] == 22) {
        switch (SimulinkPacer_B.RxData[1]) {
         case 85:
          SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_SET_PARAM;
          memcpy((void *)&SimulinkPacer_B.id_in_o, (void *)
                 &SimulinkPacer_B.RxData[2], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          SimulinkPacer_B.mode = SimulinkPacer_B.RxData[6];
          SimulinkPacer_B.lrl_in = SimulinkPacer_B.RxData[7];
          SimulinkPacer_B.vent_pw_in = SimulinkPacer_B.RxData[9];
          memcpy((void *)&SimulinkPacer_B.vent_amp_in, (void *)
                 &SimulinkPacer_B.RxData[10], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&SimulinkPacer_B.vent_sensitivity_in, (void *)
                 &SimulinkPacer_B.RxData[14], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&SimulinkPacer_B.VRP_in, (void *)
                 &SimulinkPacer_B.RxData[18], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          SimulinkPacer_B.atr_pw_in = SimulinkPacer_B.RxData[22];
          memcpy((void *)&SimulinkPacer_B.atr_amp_in, (void *)
                 &SimulinkPacer_B.RxData[23], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&SimulinkPacer_B.atr_sensitivity_in, (void *)
                 &SimulinkPacer_B.RxData[27], (uint32_T)((size_t)1 * sizeof
                  (real32_T)));
          memcpy((void *)&SimulinkPacer_B.ARP_in, (void *)
                 &SimulinkPacer_B.RxData[31], (uint32_T)((size_t)1 * sizeof
                  (uint16_T)));
          break;

         case 34:
          SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_ECHO_PARAM;
          echo_params();
          break;

         default:
          SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_STANDBY;
          break;
        }
      } else {
        SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_STANDBY;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Divide = (real_T)SimulinkPacer_B.vent_pw_in / SimulinkPacer_P.Constant_Value;

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  Divide1 = (real_T)SimulinkPacer_B.atr_pw_in / SimulinkPacer_P.Constant1_Value;

  /* Gain: '<S3>/Multiply3' incorporates:
   *  Constant: '<S3>/max V1'
   *  Product: '<S3>/vent amp gain'
   */
  Multiply3 = SimulinkPacer_B.vent_amp_in / SimulinkPacer_P.maxV1_Value *
    SimulinkPacer_P.Multiply3_Gain;

  /* Gain: '<S3>/Multiply2' incorporates:
   *  Constant: '<S3>/max V2'
   *  Product: '<S3>/atr amp gain'
   */
  SimulinkPacer_B.Multiply2 = SimulinkPacer_B.atr_amp_in /
    SimulinkPacer_P.maxV2_Value * SimulinkPacer_P.Multiply2_Gain;

  /* Math: '<S3>/to mspp ' incorporates:
   *  Constant: '<S3>/min to ms'
   *  Product: '<S3>/ppm to ppms'
   *
   * About '<S3>/to mspp ':
   *  Operator: reciprocal
   */
  SimulinkPacer_B.tomspp = 1.0 / ((real_T)SimulinkPacer_B.lrl_in /
    SimulinkPacer_P.mintoms_Value);

  /* MATLABSystem: '<S5>/Digital Read' */
  if (SimulinkPacer_DW.obj_e.SampleTime !=
      SimulinkPacer_P.DigitalRead_SampleTime) {
    SimulinkPacer_DW.obj_e.SampleTime = SimulinkPacer_P.DigitalRead_SampleTime;
  }

  tmp = MW_digitalIO_read(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S5>/Digital Read1' */
  if (SimulinkPacer_DW.obj.SampleTime != SimulinkPacer_P.DigitalRead1_SampleTime)
  {
    SimulinkPacer_DW.obj.SampleTime = SimulinkPacer_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S5>/Digital Read1' */
  DigitalRead1 = MW_digitalIO_read(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE);

  /* Gain: '<S3>/Multiply' incorporates:
   *  Constant: '<S3>/max V3'
   *  Product: '<S3>/vent sens gain'
   */
  Multiply = SimulinkPacer_B.vent_sensitivity_in / SimulinkPacer_P.maxV3_Value *
    SimulinkPacer_P.Multiply_Gain;

  /* Gain: '<S3>/Multiply1' incorporates:
   *  Constant: '<S3>/max V4'
   *  Product: '<S3>/atr sens gain'
   */
  Multiply1 = SimulinkPacer_B.atr_sensitivity_in / SimulinkPacer_P.maxV4_Value *
    SimulinkPacer_P.Multiply1_Gain;

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<S5>/Digital Read'
   */
  if (SimulinkPacer_DW.temporalCounter_i1 < MAX_uint32_T) {
    SimulinkPacer_DW.temporalCounter_i1++;
  }

  if (SimulinkPacer_DW.is_active_c3_SimulinkPacer == 0U) {
    SimulinkPacer_DW.is_active_c3_SimulinkPacer = 1U;
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
  } else {
    switch (SimulinkPacer_DW.is_c3_SimulinkPacer) {
     case SimulinkPacer_IN_AAI:
      if (SimulinkPacer_B.mode != 4) {
        SimulinkPacer_DW.is_AAI = SimulinkPace_IN_NO_ACTIVE_CHILD;
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
      } else {
        switch (SimulinkPacer_DW.is_AAI) {
         case SimulinkPacer_IN_AAI_Charging:
          SimulinkPacer_B.FRONTEND_CTRL = 1.0;
          SimulinkPacer_B.PACE_GND_CTRL = 1.0;
          SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
          SimulinkPacer_B.Z_ATR_CTRL = 0.0;
          SimulinkPacer_B.Z_VENT_CTRL = 0.0;
          SimulinkPacer_B.ATR_GND_CTRL = 1.0;
          SimulinkPacer_B.VENT_GND_CTRL = 0.0;
          SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
          SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
          if (tmp) {
            SimulinkPacer_DW.artificial_pace = 0.0;
            SimulinkPacer_DW.is_AAI = SimulinkPacer_IN_AAI_Refractory;
            SimulinkPacer_DW.temporalCounter_i1 = 0U;
            Sim_enter_atomic_AAI_Refractory(&SimulinkPacer_B.Multiply2,
              &Multiply1);
          } else {
            Divide = rt_roundd_snf((SimulinkPacer_B.tomspp - Divide1 *
              SimulinkPacer_DW.artificial_pace) - (real_T)SimulinkPacer_B.ARP_in);
            if (Divide < 65536.0) {
              if (Divide >= 0.0) {
                tmp_0 = (uint16_T)Divide;
              } else {
                tmp_0 = 0U;
              }
            } else {
              tmp_0 = MAX_uint16_T;
            }

            if (SimulinkPacer_DW.temporalCounter_i1 >= tmp_0) {
              SimulinkPacer_DW.is_AAI = SimulinkPacer_IN_AAI_Pacing;
              SimulinkPacer_DW.temporalCounter_i1 = 0U;
              SimulinkPacer_B.ATR_CMP_REF_PWM = Multiply1;
              SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
              SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
              SimulinkPacer_B.ATR_GND_CTRL = 0.0;
              SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_B.Multiply2;
            }
          }
          break;

         case SimulinkPacer_IN_AAI_Pacing:
          SimulinkPacer_B.FRONTEND_CTRL = 1.0;
          SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
          SimulinkPacer_B.PACE_GND_CTRL = 1.0;
          SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
          SimulinkPacer_B.ATR_GND_CTRL = 0.0;
          SimulinkPacer_B.Z_ATR_CTRL = 0.0;
          SimulinkPacer_B.Z_VENT_CTRL = 0.0;
          SimulinkPacer_B.VENT_GND_CTRL = 0.0;
          SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
          if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide1)) {
            SimulinkPacer_DW.artificial_pace = 1.0;
            SimulinkPacer_DW.is_AAI = SimulinkPacer_IN_AAI_Refractory;
            SimulinkPacer_DW.temporalCounter_i1 = 0U;
            Sim_enter_atomic_AAI_Refractory(&SimulinkPacer_B.Multiply2,
              &Multiply1);
          }
          break;

         default:
          /* case IN_AAI_Refractory: */
          SimulinkPacer_B.PACE_GND_CTRL = 1.0;
          SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
          SimulinkPacer_B.Z_ATR_CTRL = 0.0;
          SimulinkPacer_B.Z_VENT_CTRL = 0.0;
          SimulinkPacer_B.ATR_GND_CTRL = 1.0;
          SimulinkPacer_B.VENT_GND_CTRL = 0.0;
          SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
          SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
          if (SimulinkPacer_DW.temporalCounter_i1 >= SimulinkPacer_B.ARP_in) {
            SimulinkPacer_DW.is_AAI = SimulinkPacer_IN_AAI_Charging;
            SimulinkPacer_DW.temporalCounter_i1 = 0U;
            Simul_enter_atomic_AAI_Charging(&SimulinkPacer_B.Multiply2,
              &Multiply1);
          }
          break;
        }
      }
      break;

     case SimulinkPacer_IN_AOO:
      if (SimulinkPacer_B.mode != 2) {
        SimulinkPacer_DW.is_AOO = SimulinkPace_IN_NO_ACTIVE_CHILD;
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
      } else if (SimulinkPacer_DW.is_AOO == SimulinkPacer_IN_AOO_Charging) {
        SimulinkPacer_B.PACE_GND_CTRL = 1.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
        SimulinkPacer_B.Z_ATR_CTRL = 0.0;
        SimulinkPacer_B.Z_VENT_CTRL = 0.0;
        SimulinkPacer_B.ATR_GND_CTRL = 1.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
        SimulinkPacer_B.FRONTEND_CTRL = 0.0;
        if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
            (SimulinkPacer_B.tomspp - Divide1)) {
          SimulinkPacer_DW.is_AOO = SimulinkPacer_IN_AOO_Pacing;
          SimulinkPacer_DW.temporalCounter_i1 = 0U;
          SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
          SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
          SimulinkPacer_B.ATR_GND_CTRL = 0.0;
          SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_B.Multiply2;
        }
      } else {
        /* case IN_AOO_Pacing: */
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.PACE_GND_CTRL = 1.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
        SimulinkPacer_B.ATR_GND_CTRL = 0.0;
        SimulinkPacer_B.Z_ATR_CTRL = 0.0;
        SimulinkPacer_B.Z_VENT_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
        SimulinkPacer_B.FRONTEND_CTRL = 0.0;
        if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide1)) {
          SimulinkPacer_DW.is_AOO = SimulinkPacer_IN_AOO_Charging;
          SimulinkPacer_DW.temporalCounter_i1 = 0U;
          Simul_enter_atomic_AOO_Charging(&SimulinkPacer_B.Multiply2);
        }
      }
      break;

     case SimulinkPacer_IN_ModeSelect:
      switch (SimulinkPacer_B.mode) {
       case 4:
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI;
        SimulinkPacer_DW.is_AAI = SimulinkPacer_IN_AAI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AAI_Charging(&SimulinkPacer_B.Multiply2, &Multiply1);
        break;

       case 1:
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO;
        SimulinkPacer_DW.is_VOO = SimulinkPacer_IN_VOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VOO_Charging(&Multiply3);
        break;

       case 2:
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO;
        SimulinkPacer_DW.is_AOO = SimulinkPacer_IN_AOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AOO_Charging(&SimulinkPacer_B.Multiply2);
        break;

       case 3:
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI;
        SimulinkPacer_DW.is_VVI = SimulinkPacer_IN_VVI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VVI_Charging(&Multiply3, &Multiply);
        break;
      }
      break;

     case SimulinkPacer_IN_VOO:
      if (SimulinkPacer_B.mode != 1) {
        SimulinkPacer_DW.is_VOO = SimulinkPace_IN_NO_ACTIVE_CHILD;
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
      } else if (SimulinkPacer_DW.is_VOO == SimulinkPacer_IN_VOO_Charging) {
        SimulinkPacer_B.PACE_GND_CTRL = 1.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
        SimulinkPacer_B.Z_ATR_CTRL = 0.0;
        SimulinkPacer_B.Z_VENT_CTRL = 0.0;
        SimulinkPacer_B.ATR_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 1.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
        SimulinkPacer_B.FRONTEND_CTRL = 0.0;
        if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
            (SimulinkPacer_B.tomspp - Divide)) {
          SimulinkPacer_DW.is_VOO = SimulinkPacer_IN_VOO_Pacing;
          SimulinkPacer_DW.temporalCounter_i1 = 0U;
          SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
          SimulinkPacer_B.VENT_GND_CTRL = 0.0;
          SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
          SimulinkPacer_B.PACING_REF_PWM = Multiply3;
        }
      } else {
        /* case IN_VOO_Pacing: */
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.PACE_GND_CTRL = 1.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
        SimulinkPacer_B.ATR_GND_CTRL = 0.0;
        SimulinkPacer_B.Z_ATR_CTRL = 0.0;
        SimulinkPacer_B.Z_VENT_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
        SimulinkPacer_B.FRONTEND_CTRL = 0.0;
        if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide)) {
          SimulinkPacer_DW.is_VOO = SimulinkPacer_IN_VOO_Charging;
          SimulinkPacer_DW.temporalCounter_i1 = 0U;
          Simul_enter_atomic_VOO_Charging(&Multiply3);
        }
      }
      break;

     default:
      /* case IN_VVI: */
      SimulinkPacer_VVI(&SimulinkPacer_B.tomspp, &Multiply3, &Divide, &Multiply,
                        &DigitalRead1);
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S6>/Digital Write2' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_n.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write4' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gy.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write3' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_ec.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write5' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_e0.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write6' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gm.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write7' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gj.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write8' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_g.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S6>/PWM Output' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_b.MW_PWM_HANDLE,
                      SimulinkPacer_B.PACING_REF_PWM);

  /* MATLABSystem: '<S6>/Digital Write11' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S6>/Digital Write10' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S6>/PWM Output1' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE,
                      SimulinkPacer_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S6>/PWM Output2' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE,
                      SimulinkPacer_B.ATR_CMP_REF_PWM);

  /* Chart: '<S7>/Chart' */
  if (SimulinkPacer_DW.is_active_c1_SimulinkPacer == 0U) {
    SimulinkPacer_DW.is_active_c1_SimulinkPacer = 1U;
    SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
  } else {
    switch (SimulinkPacer_DW.is_c1_SimulinkPacer) {
     case SimulinkPacer_IN_AOO_h:
      SimulinkPacer_B.green_charge = 0.0;
      SimulinkPacer_B.red_pulse = 1.0;
      SimulinkPacer_B.blue_refractory = 0.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;

     case SimulinkPacer_IN_Start:
      switch (SimulinkPacer_B.mode) {
       case 2:
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_AOO_h;
        SimulinkPacer_B.green_charge = 0.0;
        SimulinkPacer_B.red_pulse = 1.0;
        SimulinkPacer_B.blue_refractory = 0.0;
        break;

       case 3:
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_VVI_c;
        SimulinkPacer_B.green_charge = 0.0;
        SimulinkPacer_B.red_pulse = 0.0;
        SimulinkPacer_B.blue_refractory = 1.0;
        break;

       case 1:
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_VOO_k;
        SimulinkPacer_B.green_charge = 1.0;
        SimulinkPacer_B.red_pulse = 0.0;
        SimulinkPacer_B.blue_refractory = 0.0;
        break;
      }
      break;

     case SimulinkPacer_IN_VOO_k:
      SimulinkPacer_B.green_charge = 1.0;
      SimulinkPacer_B.red_pulse = 0.0;
      SimulinkPacer_B.blue_refractory = 0.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;

     default:
      /* case IN_VVI: */
      SimulinkPacer_B.green_charge = 0.0;
      SimulinkPacer_B.red_pulse = 0.0;
      SimulinkPacer_B.blue_refractory = 1.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;
    }
  }

  /* End of Chart: '<S7>/Chart' */

  /* MATLABSystem: '<S7>/Digital Write' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_d.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.green_charge != 0.0);

  /* MATLABSystem: '<S7>/Digital Write1' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_l.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.blue_refractory != 0.0);

  /* MATLABSystem: '<S7>/Digital Write2' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_k.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.red_pulse != 0.0);
}

/* Model initialize function */
void SimulinkPacer_initialize(void)
{
  {
    freedomk64f_DigitalRead_Simul_T *obj;
    freedomk64f_DigitalWrite_Simu_T *obj_0;
    freedomk64f_PWMOutput_Simulin_T *obj_1;

    /* Chart: '<Root>/Chart1' */
    SimulinkPacer_DW.is_c2_SimulinkPacer = SimulinkPacer_IN_INITIAL;
    SimulinkPacer_B.mode = 2U;
    SimulinkPacer_B.lrl_in = 60U;
    SimulinkPacer_B.vent_pw_in = 20U;
    SimulinkPacer_B.vent_amp_in = 3.5F;
    SimulinkPacer_B.vent_sensitivity_in = 2.5F;
    SimulinkPacer_B.VRP_in = 320.0F;
    SimulinkPacer_B.atr_pw_in = 20U;
    SimulinkPacer_B.atr_amp_in = 3.5F;
    SimulinkPacer_B.atr_sensitivity_in = 0.75F;
    SimulinkPacer_B.ARP_in = 200U;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    echo_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    SimulinkPacer_DW.obj_c.isInitialized = 0;
    SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted = false;
    SimulinkPacer_DW.obj_c.SampleTime = SimulinkPacer_P.SerialReceive_SampleTime;
    SimulinkPace_SystemCore_setup_f(&SimulinkPacer_DW.obj_c);

    /* Start for MATLABSystem: '<S5>/Digital Read' */
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_e.isInitialized = 0;
    SimulinkPacer_DW.obj_e.SampleTime = -1.0;
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = false;
    SimulinkPacer_DW.obj_e.SampleTime = SimulinkPacer_P.DigitalRead_SampleTime;
    obj = &SimulinkPacer_DW.obj_e;
    SimulinkPacer_DW.obj_e.isSetupComplete = false;
    SimulinkPacer_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    SimulinkPacer_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Read1' */
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj.isInitialized = 0;
    SimulinkPacer_DW.obj.SampleTime = -1.0;
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = false;
    SimulinkPacer_DW.obj.SampleTime = SimulinkPacer_P.DigitalRead1_SampleTime;
    obj = &SimulinkPacer_DW.obj;
    SimulinkPacer_DW.obj.isSetupComplete = false;
    SimulinkPacer_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    SimulinkPacer_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write2' */
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_n.isInitialized = 0;
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_n;
    SimulinkPacer_DW.obj_n.isSetupComplete = false;
    SimulinkPacer_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    SimulinkPacer_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write4' */
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gy.isInitialized = 0;
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gy;
    SimulinkPacer_DW.obj_gy.isSetupComplete = false;
    SimulinkPacer_DW.obj_gy.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    SimulinkPacer_DW.obj_gy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write3' */
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_ec.isInitialized = 0;
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_ec;
    SimulinkPacer_DW.obj_ec.isSetupComplete = false;
    SimulinkPacer_DW.obj_ec.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    SimulinkPacer_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write5' */
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_e0.isInitialized = 0;
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_e0;
    SimulinkPacer_DW.obj_e0.isSetupComplete = false;
    SimulinkPacer_DW.obj_e0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    SimulinkPacer_DW.obj_e0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write6' */
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gm.isInitialized = 0;
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gm;
    SimulinkPacer_DW.obj_gm.isSetupComplete = false;
    SimulinkPacer_DW.obj_gm.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    SimulinkPacer_DW.obj_gm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write7' */
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gj.isInitialized = 0;
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gj;
    SimulinkPacer_DW.obj_gj.isSetupComplete = false;
    SimulinkPacer_DW.obj_gj.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    SimulinkPacer_DW.obj_gj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write8' */
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_g.isInitialized = 0;
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_g;
    SimulinkPacer_DW.obj_g.isSetupComplete = false;
    SimulinkPacer_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    SimulinkPacer_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output' */
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_b.isInitialized = 0;
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_b;
    SimulinkPacer_DW.obj_b.isSetupComplete = false;
    SimulinkPacer_DW.obj_b.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_b.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write11' */
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_h.isInitialized = 0;
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_h;
    SimulinkPacer_DW.obj_h.isSetupComplete = false;
    SimulinkPacer_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    SimulinkPacer_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write10' */
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_j.isInitialized = 0;
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_j;
    SimulinkPacer_DW.obj_j.isSetupComplete = false;
    SimulinkPacer_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    SimulinkPacer_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output1' */
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_jf.isInitialized = 0;
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_jf;
    SimulinkPacer_DW.obj_jf.isSetupComplete = false;
    SimulinkPacer_DW.obj_jf.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_jf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/PWM Output2' */
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_hk.isInitialized = 0;
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_hk;
    SimulinkPacer_DW.obj_hk.isSetupComplete = false;
    SimulinkPacer_DW.obj_hk.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_hk.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Write' */
    SimulinkPacer_DW.obj_d.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_d.isInitialized = 0;
    SimulinkPacer_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_d;
    SimulinkPacer_DW.obj_d.isSetupComplete = false;
    SimulinkPacer_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    SimulinkPacer_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Write1' */
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_l.isInitialized = 0;
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_l;
    SimulinkPacer_DW.obj_l.isSetupComplete = false;
    SimulinkPacer_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    SimulinkPacer_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Write2' */
    SimulinkPacer_DW.obj_k.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_k.isInitialized = 0;
    SimulinkPacer_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_k;
    SimulinkPacer_DW.obj_k.isSetupComplete = false;
    SimulinkPacer_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    SimulinkPacer_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void SimulinkPacer_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_c.isInitialized == 1) &&
        SimulinkPacer_DW.obj_c.isSetupComplete) {
      MW_SCI_Close(SimulinkPacer_DW.obj_c.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  echo_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read' */
  if (!SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_e.isInitialized == 1) &&
        SimulinkPacer_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read' */

  /* Terminate for MATLABSystem: '<S5>/Digital Read1' */
  if (!SimulinkPacer_DW.obj.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj.isInitialized == 1) &&
        SimulinkPacer_DW.obj.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write2' */
  if (!SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_n.isInitialized == 1) &&
        SimulinkPacer_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write4' */
  if (!SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gy.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gy.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gy.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write3' */
  if (!SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_ec.isInitialized == 1) &&
        SimulinkPacer_DW.obj_ec.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_ec.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write5' */
  if (!SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_e0.isInitialized == 1) &&
        SimulinkPacer_DW.obj_e0.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_e0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write6' */
  if (!SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gm.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gm.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gm.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write7' */
  if (!SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gj.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gj.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write8' */
  if (!SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_g.isInitialized == 1) &&
        SimulinkPacer_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output' */
  if (!SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_b.isInitialized == 1) &&
        SimulinkPacer_DW.obj_b.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_b.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_b.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write11' */
  if (!SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_h.isInitialized == 1) &&
        SimulinkPacer_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write11' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write10' */
  if (!SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_j.isInitialized == 1) &&
        SimulinkPacer_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output1' */
  if (!SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_jf.isInitialized == 1) &&
        SimulinkPacer_DW.obj_jf.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S6>/PWM Output2' */
  if (!SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_hk.isInitialized == 1) &&
        SimulinkPacer_DW.obj_hk.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S7>/Digital Write' */
  if (!SimulinkPacer_DW.obj_d.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_d.isInitialized == 1) &&
        SimulinkPacer_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write' */

  /* Terminate for MATLABSystem: '<S7>/Digital Write1' */
  if (!SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_l.isInitialized == 1) &&
        SimulinkPacer_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S7>/Digital Write2' */
  if (!SimulinkPacer_DW.obj_k.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_k.isInitialized == 1) &&
        SimulinkPacer_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
