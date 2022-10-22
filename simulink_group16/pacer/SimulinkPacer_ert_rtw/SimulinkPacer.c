/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer.c
 *
 * Code generated for Simulink model 'SimulinkPacer'.
 *
 * Model version                  : 5.43
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 22 17:44:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimulinkPacer.h"
#include "rtwtypes.h"
#include <math.h>
#include "SimulinkPacer_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SimulinkPacer_IN_AAI_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_AAI_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_AAI_Refractory ((uint8_T)3U)
#define SimulinkPacer_IN_AOO_Charging  ((uint8_T)4U)
#define SimulinkPacer_IN_AOO_Pacing    ((uint8_T)5U)
#define SimulinkPacer_IN_ModeSelect    ((uint8_T)6U)
#define SimulinkPacer_IN_VOO_Charging  ((uint8_T)7U)
#define SimulinkPacer_IN_VOO_Pacing    ((uint8_T)8U)
#define SimulinkPacer_IN_VVI_Charging  ((uint8_T)9U)
#define SimulinkPacer_IN_VVI_Pacing    ((uint8_T)10U)
#define SimulinkPacer_IN_VVI_Refractory ((uint8_T)11U)

/* Named constants for Chart: '<S5>/Chart' */
#define SimulinkP_IN_Refractory_Setting ((uint8_T)3U)
#define SimulinkPacer_IN_Charge_Setting ((uint8_T)1U)
#define SimulinkPacer_IN_Pulse_Setting ((uint8_T)2U)
#define SimulinkPacer_IN_Start         ((uint8_T)4U)

/* Block signals (default storage) */
B_SimulinkPacer_T SimulinkPacer_B;

/* Block states (default storage) */
DW_SimulinkPacer_T SimulinkPacer_DW;

/* Real-time model */
static RT_MODEL_SimulinkPacer_T SimulinkPacer_M_;
RT_MODEL_SimulinkPacer_T *const SimulinkPacer_M = &SimulinkPacer_M_;

/* Forward declaration for local functions */
static void Simul_enter_atomic_VVI_Charging(void);
static void Sim_enter_atomic_AAI_Refractory(void);
static void Simul_enter_atomic_AAI_Charging(void);
static void Simul_enter_atomic_AOO_Charging(void);
static void Simul_enter_atomic_VOO_Charging(void);
static void Sim_enter_atomic_VVI_Refractory(void);
static void SimulinkPacer_VVI_Charging(const real_T *tomspp, const boolean_T
  *DigitalRead1);

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_VVI_Charging(void)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S2>/Constant' */
  SimulinkPacer_B.VENT_CMP_REF_PWM = SimulinkPacer_P.Constant_Value;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant4' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Sim_enter_atomic_AAI_Refractory(void)
{
  SimulinkPacer_B.State = 2.0;
  SimulinkPacer_B.PACE_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant2' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;

  /* Constant: '<S2>/Constant7' */
  SimulinkPacer_B.VENT_CMP_REF_PWM = SimulinkPacer_P.Constant7_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_AAI_Charging(void)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant2' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;
  SimulinkPacer_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S2>/Constant7' */
  SimulinkPacer_B.ATR_CMP_REF_PWM = SimulinkPacer_P.Constant7_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_AOO_Charging(void)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant2' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_VOO_Charging(void)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant4' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Sim_enter_atomic_VVI_Refractory(void)
{
  SimulinkPacer_B.State = 2.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;

  /* Constant: '<S2>/Constant' */
  SimulinkPacer_B.VENT_CMP_REF_PWM = SimulinkPacer_P.Constant_Value;
  SimulinkPacer_B.PACE_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 0.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<S2>/Constant4' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void SimulinkPacer_VVI_Charging(const real_T *tomspp, const boolean_T
  *DigitalRead1)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.FRONTEND_CTRL = 1.0;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(*tomspp)) {
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI_Pacing;
    SimulinkPacer_DW.temporalCounter_i1 = 0U;
    SimulinkPacer_B.State = 1.0;

    /* Constant: '<S2>/Constant' */
    SimulinkPacer_B.VENT_CMP_REF_PWM = SimulinkPacer_P.Constant_Value;
    SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
    SimulinkPacer_B.VENT_GND_CTRL = 0.0;
    SimulinkPacer_B.VENT_PACE_CTRL = 1.0;

    /* Constant: '<S2>/Constant4' */
    SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
  } else if (*DigitalRead1) {
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI_Refractory;
    SimulinkPacer_DW.temporalCounter_i1 = 0U;
    Sim_enter_atomic_VVI_Refractory();
  }
}

/* Model step function */
void SimulinkPacer_step(void)
{
  real_T tomspp;
  boolean_T DigitalRead1;
  boolean_T tmp;

  /* Math: '<S2>/to mspp ' incorporates:
   *  Constant: '<S2>/lower rate limit in pulses//min'
   *  Constant: '<S2>/min to ms'
   *  Product: '<S2>/ppm to ppms'
   *
   * About '<S2>/to mspp ':
   *  Operator: reciprocal
   */
  tomspp = 1.0 / (SimulinkPacer_P.lowerratelimitinpulsesmin_Value /
                  SimulinkPacer_P.mintoms_Value);

  /* MATLABSystem: '<S3>/Digital Read' */
  if (SimulinkPacer_DW.obj_e.SampleTime !=
      SimulinkPacer_P.DigitalRead_SampleTime) {
    SimulinkPacer_DW.obj_e.SampleTime = SimulinkPacer_P.DigitalRead_SampleTime;
  }

  tmp = MW_digitalIO_read(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S3>/Digital Read1' */
  if (SimulinkPacer_DW.obj.SampleTime != SimulinkPacer_P.DigitalRead1_SampleTime)
  {
    SimulinkPacer_DW.obj.SampleTime = SimulinkPacer_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S3>/Digital Read1' */
  DigitalRead1 = MW_digitalIO_read(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant9'
   *  MATLABSystem: '<S3>/Digital Read'
   */
  if (SimulinkPacer_DW.temporalCounter_i1 < MAX_uint32_T) {
    SimulinkPacer_DW.temporalCounter_i1++;
  }

  if (SimulinkPacer_DW.is_active_c3_SimulinkPacer == 0U) {
    SimulinkPacer_DW.is_active_c3_SimulinkPacer = 1U;
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
  } else {
    switch (SimulinkPacer_DW.is_c3_SimulinkPacer) {
     case SimulinkPacer_IN_AAI_Charging:
      SimulinkPacer_B.State = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.FRONTEND_CTRL = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(tomspp)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.State = 1.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
        SimulinkPacer_B.ATR_GND_CTRL = 0.0;
        SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;
        SimulinkPacer_B.ATR_CMP_REF_PWM = SimulinkPacer_P.Constant7_Value;
      } else if (tmp) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI_Refractory;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Sim_enter_atomic_AAI_Refractory();
      }
      break;

     case SimulinkPacer_IN_AAI_Pacing:
      SimulinkPacer_B.State = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.FRONTEND_CTRL = 1.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI_Refractory;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Sim_enter_atomic_AAI_Refractory();
      }
      break;

     case SimulinkPacer_IN_AAI_Refractory:
      SimulinkPacer_B.State = 2.0;
      SimulinkPacer_B.PACE_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant9_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AAI_Charging();
      }
      break;

     case SimulinkPacer_IN_AOO_Charging:
      SimulinkPacer_B.State = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(tomspp -
           SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.State = 1.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
        SimulinkPacer_B.ATR_GND_CTRL = 0.0;
        SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;
      }
      break;

     case SimulinkPacer_IN_AOO_Pacing:
      SimulinkPacer_B.State = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 1.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AOO_Charging();
      }
      break;

     case SimulinkPacer_IN_ModeSelect:
      if (SimulinkPacer_P.Constant6_Value == 1.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VOO_Charging();
      } else if (SimulinkPacer_P.Constant6_Value == 2.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AOO_Charging();
      } else if (SimulinkPacer_P.Constant6_Value == 3.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VVI_Charging();
      } else if (SimulinkPacer_P.Constant6_Value == 4.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AAI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AAI_Charging();
      }
      break;

     case SimulinkPacer_IN_VOO_Charging:
      SimulinkPacer_B.State = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil(tomspp -
           SimulinkPacer_P.Constant1_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.State = 1.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
        SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
      }
      break;

     case SimulinkPacer_IN_VOO_Pacing:
      SimulinkPacer_B.State = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant1_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VOO_Charging();
      }
      break;

     case SimulinkPacer_IN_VVI_Charging:
      SimulinkPacer_VVI_Charging(&tomspp, &DigitalRead1);
      break;

     case SimulinkPacer_IN_VVI_Pacing:
      SimulinkPacer_B.State = 1.0;
      SimulinkPacer_B.FRONTEND_CTRL = 1.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 1.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant1_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI_Refractory;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Sim_enter_atomic_VVI_Refractory();
      }
      break;

     default:
      /* case IN_VVI_Refractory: */
      SimulinkPacer_B.State = 2.0;
      SimulinkPacer_B.FRONTEND_CTRL = 0.0;
      SimulinkPacer_B.PACE_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
      SimulinkPacer_B.Z_ATR_CTRL = 0.0;
      SimulinkPacer_B.Z_VENT_CTRL = 0.0;
      SimulinkPacer_B.ATR_GND_CTRL = 0.0;
      SimulinkPacer_B.VENT_GND_CTRL = 0.0;
      SimulinkPacer_B.ATR_PACE_CTRL = 0.0;
      SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant5_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VVI_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VVI_Charging();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_n.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write4' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gy.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write3' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_ec.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_e0.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gm.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_gj.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_g.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_by.MW_PWM_HANDLE,
                      SimulinkPacer_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write11' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S4>/Digital Write10' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S4>/PWM Output1' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE,
                      SimulinkPacer_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/PWM Output2' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE,
                      SimulinkPacer_B.ATR_CMP_REF_PWM);

  /* Chart: '<S5>/Chart' */
  if (SimulinkPacer_DW.is_active_c1_SimulinkPacer == 0U) {
    SimulinkPacer_DW.is_active_c1_SimulinkPacer = 1U;
    SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
  } else {
    switch (SimulinkPacer_DW.is_c1_SimulinkPacer) {
     case SimulinkPacer_IN_Charge_Setting:
      SimulinkPacer_B.green_charge = 1.0;
      SimulinkPacer_B.red_pulse = 0.0;
      SimulinkPacer_B.blue_refractory = 0.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;

     case SimulinkPacer_IN_Pulse_Setting:
      SimulinkPacer_B.green_charge = 0.0;
      SimulinkPacer_B.red_pulse = 1.0;
      SimulinkPacer_B.blue_refractory = 0.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;

     case SimulinkP_IN_Refractory_Setting:
      SimulinkPacer_B.green_charge = 0.0;
      SimulinkPacer_B.red_pulse = 0.0;
      SimulinkPacer_B.blue_refractory = 1.0;
      SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Start;
      break;

     default:
      /* case IN_Start: */
      if (SimulinkPacer_B.State == 1.0) {
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Pulse_Setting;
        SimulinkPacer_B.green_charge = 0.0;
        SimulinkPacer_B.red_pulse = 1.0;
        SimulinkPacer_B.blue_refractory = 0.0;
      } else if (SimulinkPacer_B.State == 2.0) {
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkP_IN_Refractory_Setting;
        SimulinkPacer_B.green_charge = 0.0;
        SimulinkPacer_B.red_pulse = 0.0;
        SimulinkPacer_B.blue_refractory = 1.0;
      } else if (SimulinkPacer_B.State == 0.0) {
        SimulinkPacer_DW.is_c1_SimulinkPacer = SimulinkPacer_IN_Charge_Setting;
        SimulinkPacer_B.green_charge = 1.0;
        SimulinkPacer_B.red_pulse = 0.0;
        SimulinkPacer_B.blue_refractory = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* MATLABSystem: '<S5>/Digital Write' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_m.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.green_charge != 0.0);

  /* MATLABSystem: '<S5>/Digital Write1' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_b.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.blue_refractory != 0.0);

  /* MATLABSystem: '<S5>/Digital Write2' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_o.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.red_pulse != 0.0);
}

/* Model initialize function */
void SimulinkPacer_initialize(void)
{
  {
    freedomk64f_DigitalRead_Simul_T *obj;
    freedomk64f_DigitalWrite_Simu_T *obj_0;
    freedomk64f_PWMOutput_Simulin_T *obj_1;

    /* Start for MATLABSystem: '<S3>/Digital Read' */
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

    /* Start for MATLABSystem: '<S3>/Digital Read1' */
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

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_n.isInitialized = 0;
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_n;
    SimulinkPacer_DW.obj_n.isSetupComplete = false;
    SimulinkPacer_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    SimulinkPacer_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write4' */
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gy.isInitialized = 0;
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gy;
    SimulinkPacer_DW.obj_gy.isSetupComplete = false;
    SimulinkPacer_DW.obj_gy.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    SimulinkPacer_DW.obj_gy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write3' */
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_ec.isInitialized = 0;
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_ec;
    SimulinkPacer_DW.obj_ec.isSetupComplete = false;
    SimulinkPacer_DW.obj_ec.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    SimulinkPacer_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_e0.isInitialized = 0;
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_e0;
    SimulinkPacer_DW.obj_e0.isSetupComplete = false;
    SimulinkPacer_DW.obj_e0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    SimulinkPacer_DW.obj_e0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gm.isInitialized = 0;
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gm;
    SimulinkPacer_DW.obj_gm.isSetupComplete = false;
    SimulinkPacer_DW.obj_gm.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    SimulinkPacer_DW.obj_gm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_gj.isInitialized = 0;
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_gj;
    SimulinkPacer_DW.obj_gj.isSetupComplete = false;
    SimulinkPacer_DW.obj_gj.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    SimulinkPacer_DW.obj_gj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_g.isInitialized = 0;
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_g;
    SimulinkPacer_DW.obj_g.isSetupComplete = false;
    SimulinkPacer_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    SimulinkPacer_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    SimulinkPacer_DW.obj_by.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_by.isInitialized = 0;
    SimulinkPacer_DW.obj_by.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_by;
    SimulinkPacer_DW.obj_by.isSetupComplete = false;
    SimulinkPacer_DW.obj_by.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_by.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_by.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write11' */
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_h.isInitialized = 0;
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_h;
    SimulinkPacer_DW.obj_h.isSetupComplete = false;
    SimulinkPacer_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    SimulinkPacer_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write10' */
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_j.isInitialized = 0;
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_j;
    SimulinkPacer_DW.obj_j.isSetupComplete = false;
    SimulinkPacer_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    SimulinkPacer_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_jf.isInitialized = 0;
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_jf;
    SimulinkPacer_DW.obj_jf.isSetupComplete = false;
    SimulinkPacer_DW.obj_jf.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_jf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_hk.isInitialized = 0;
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = false;
    obj_1 = &SimulinkPacer_DW.obj_hk;
    SimulinkPacer_DW.obj_hk.isSetupComplete = false;
    SimulinkPacer_DW.obj_hk.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_hk.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_m.isInitialized = 0;
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_m;
    SimulinkPacer_DW.obj_m.isSetupComplete = false;
    SimulinkPacer_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    SimulinkPacer_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_b.isInitialized = 0;
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_b;
    SimulinkPacer_DW.obj_b.isSetupComplete = false;
    SimulinkPacer_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    SimulinkPacer_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write2' */
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_o.isInitialized = 0;
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_o;
    SimulinkPacer_DW.obj_o.isSetupComplete = false;
    SimulinkPacer_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    SimulinkPacer_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void SimulinkPacer_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Digital Read' */
  if (!SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_e.isInitialized == 1) &&
        SimulinkPacer_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read1' */
  if (!SimulinkPacer_DW.obj.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj.isInitialized == 1) &&
        SimulinkPacer_DW.obj.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  if (!SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_n.isInitialized == 1) &&
        SimulinkPacer_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write4' */
  if (!SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gy.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gy.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gy.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gy.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write3' */
  if (!SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_ec.isInitialized == 1) &&
        SimulinkPacer_DW.obj_ec.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_ec.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_e0.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_e0.isInitialized == 1) &&
        SimulinkPacer_DW.obj_e0.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_e0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  if (!SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gm.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gm.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gm.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gm.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  if (!SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_gj.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_gj.isInitialized == 1) &&
        SimulinkPacer_DW.obj_gj.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_gj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  if (!SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_g.isInitialized == 1) &&
        SimulinkPacer_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!SimulinkPacer_DW.obj_by.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_by.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_by.isInitialized == 1) &&
        SimulinkPacer_DW.obj_by.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_by.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_by.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write11' */
  if (!SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_h.isInitialized == 1) &&
        SimulinkPacer_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write11' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write10' */
  if (!SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_j.isInitialized == 1) &&
        SimulinkPacer_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  if (!SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_jf.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_jf.isInitialized == 1) &&
        SimulinkPacer_DW.obj_jf.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_jf.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  if (!SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_hk.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_hk.isInitialized == 1) &&
        SimulinkPacer_DW.obj_hk.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_hk.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_m.isInitialized == 1) &&
        SimulinkPacer_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  if (!SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_b.isInitialized == 1) &&
        SimulinkPacer_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write2' */
  if (!SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_o.isInitialized == 1) &&
        SimulinkPacer_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
