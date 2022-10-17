/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer.c
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

#include "SimulinkPacer.h"
#include "rtwtypes.h"
#include <math.h>
#include "SimulinkPacer_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SimulinkPacer_IN_AOO_Charging  ((uint8_T)1U)
#define SimulinkPacer_IN_AOO_Pacing    ((uint8_T)2U)
#define SimulinkPacer_IN_ModeSelect    ((uint8_T)3U)
#define SimulinkPacer_IN_VII_Charging  ((uint8_T)4U)
#define SimulinkPacer_IN_VII_Pacing    ((uint8_T)5U)
#define SimulinkPacer_IN_VOO_Charging  ((uint8_T)6U)
#define SimulinkPacer_IN_VOO_Pacing    ((uint8_T)7U)

/* Block signals (default storage) */
B_SimulinkPacer_T SimulinkPacer_B;

/* Block states (default storage) */
DW_SimulinkPacer_T SimulinkPacer_DW;

/* Real-time model */
static RT_MODEL_SimulinkPacer_T SimulinkPacer_M_;
RT_MODEL_SimulinkPacer_T *const SimulinkPacer_M = &SimulinkPacer_M_;

/* Forward declaration for local functions */
static void Simul_enter_atomic_VII_Charging(void);
static void Simul_enter_atomic_AOO_Charging(void);

/* Function for Chart: '<Root>/Chart' */
static void Simul_enter_atomic_VII_Charging(void)
{
  SimulinkPacer_B.State = 0.0;
  SimulinkPacer_B.PACE_GND_CTRL = 1.0;
  SimulinkPacer_B.VENT_PACE_CTRL = 0.0;
  SimulinkPacer_B.Z_ATR_CTRL = 0.0;
  SimulinkPacer_B.Z_VENT_CTRL = 0.0;
  SimulinkPacer_B.ATR_GND_CTRL = 0.0;
  SimulinkPacer_B.VENT_GND_CTRL = 1.0;
  SimulinkPacer_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<Root>/Constant4' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
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

  /* Constant: '<Root>/Constant2' */
  SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant2_Value;
  SimulinkPacer_B.PACE_CHARGE_CTRL = 1.0;
  SimulinkPacer_B.FRONTEND_CTRL = 0.0;
}

/* Model step function */
void SimulinkPacer_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   */
  if (SimulinkPacer_DW.temporalCounter_i1 < MAX_uint32_T) {
    SimulinkPacer_DW.temporalCounter_i1++;
  }

  if (SimulinkPacer_DW.is_active_c3_SimulinkPacer == 0U) {
    SimulinkPacer_DW.is_active_c3_SimulinkPacer = 1U;
    SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_ModeSelect;
  } else {
    switch (SimulinkPacer_DW.is_c3_SimulinkPacer) {
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
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant1_Value - SimulinkPacer_P.Constant_Value)) {
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
          (SimulinkPacer_P.Constant_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AOO_Charging();
      }
      break;

     case SimulinkPacer_IN_ModeSelect:
      if (SimulinkPacer_P.Constant6_Value == 1.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VII_Charging();
      } else if (SimulinkPacer_P.Constant6_Value == 2.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_AOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_AOO_Charging();
      } else if (SimulinkPacer_P.Constant6_Value == 3.0) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VII_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VII_Charging();
      }
      break;

     case SimulinkPacer_IN_VII_Charging:
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
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant5_Value - SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VII_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.State = 1.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
        SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
      }
      break;

     case SimulinkPacer_IN_VII_Pacing:
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
          (SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VII_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VII_Charging();
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
      if (SimulinkPacer_DW.temporalCounter_i1 >= (uint32_T)ceil
          (SimulinkPacer_P.Constant5_Value - SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Pacing;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        SimulinkPacer_B.State = 1.0;
        SimulinkPacer_B.PACE_CHARGE_CTRL = 0.0;
        SimulinkPacer_B.VENT_GND_CTRL = 0.0;
        SimulinkPacer_B.VENT_PACE_CTRL = 1.0;
        SimulinkPacer_B.PACING_REF_PWM = SimulinkPacer_P.Constant4_Value;
      }
      break;

     default:
      /* case IN_VOO_Pacing: */
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
          (SimulinkPacer_P.Constant3_Value)) {
        SimulinkPacer_DW.is_c3_SimulinkPacer = SimulinkPacer_IN_VOO_Charging;
        SimulinkPacer_DW.temporalCounter_i1 = 0U;
        Simul_enter_atomic_VII_Charging();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Logic: '<Root>/NOT'
   */
  MW_digitalIO_write(SimulinkPacer_DW.obj_mo.MW_DIGITALIO_HANDLE,
                     !(SimulinkPacer_B.State != 0.0));

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_i.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.State != 0.0);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_o.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_m.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_p.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_l.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(SimulinkPacer_DW.obj_b.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE,
                     SimulinkPacer_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(SimulinkPacer_DW.obj_c.MW_PWM_HANDLE,
                      SimulinkPacer_B.PACING_REF_PWM);
}

/* Model initialize function */
void SimulinkPacer_initialize(void)
{
  {
    freedomk64f_DigitalWrite_Simu_T *obj;
    freedomk64f_PWMOutput_Simulin_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    SimulinkPacer_DW.obj_mo.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_mo.isInitialized = 0;
    SimulinkPacer_DW.obj_mo.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_mo;
    SimulinkPacer_DW.obj_mo.isSetupComplete = false;
    SimulinkPacer_DW.obj_mo.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    SimulinkPacer_DW.obj_mo.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    SimulinkPacer_DW.obj_i.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_i.isInitialized = 0;
    SimulinkPacer_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_i;
    SimulinkPacer_DW.obj_i.isSetupComplete = false;
    SimulinkPacer_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    SimulinkPacer_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_o.isInitialized = 0;
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_o;
    SimulinkPacer_DW.obj_o.isSetupComplete = false;
    SimulinkPacer_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    SimulinkPacer_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_m.isInitialized = 0;
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_m;
    SimulinkPacer_DW.obj_m.isSetupComplete = false;
    SimulinkPacer_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    SimulinkPacer_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_e.isInitialized = 0;
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_e;
    SimulinkPacer_DW.obj_e.isSetupComplete = false;
    SimulinkPacer_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    SimulinkPacer_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    SimulinkPacer_DW.obj_p.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_p.isInitialized = 0;
    SimulinkPacer_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_p;
    SimulinkPacer_DW.obj_p.isSetupComplete = false;
    SimulinkPacer_DW.obj_p.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    SimulinkPacer_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_j.isInitialized = 0;
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_j;
    SimulinkPacer_DW.obj_j.isSetupComplete = false;
    SimulinkPacer_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    SimulinkPacer_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_l.isInitialized = 0;
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_l;
    SimulinkPacer_DW.obj_l.isSetupComplete = false;
    SimulinkPacer_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    SimulinkPacer_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_h.isInitialized = 0;
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_h;
    SimulinkPacer_DW.obj_h.isSetupComplete = false;
    SimulinkPacer_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    SimulinkPacer_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_b.isInitialized = 0;
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj_b;
    SimulinkPacer_DW.obj_b.isSetupComplete = false;
    SimulinkPacer_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    SimulinkPacer_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj.isInitialized = 0;
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = false;
    obj = &SimulinkPacer_DW.obj;
    SimulinkPacer_DW.obj.isSetupComplete = false;
    SimulinkPacer_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    SimulinkPacer_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted = true;
    SimulinkPacer_DW.obj_c.isInitialized = 0;
    SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &SimulinkPacer_DW.obj_c;
    SimulinkPacer_DW.obj_c.isSetupComplete = false;
    SimulinkPacer_DW.obj_c.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(SimulinkPacer_DW.obj_c.MW_PWM_HANDLE);
    SimulinkPacer_DW.obj_c.isSetupComplete = true;
  }
}

/* Model terminate function */
void SimulinkPacer_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!SimulinkPacer_DW.obj_mo.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_mo.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_mo.isInitialized == 1) &&
        SimulinkPacer_DW.obj_mo.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_mo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!SimulinkPacer_DW.obj_i.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_i.isInitialized == 1) &&
        SimulinkPacer_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_o.isInitialized == 1) &&
        SimulinkPacer_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_m.isInitialized == 1) &&
        SimulinkPacer_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_e.isInitialized == 1) &&
        SimulinkPacer_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!SimulinkPacer_DW.obj_p.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_p.isInitialized == 1) &&
        SimulinkPacer_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_j.isInitialized == 1) &&
        SimulinkPacer_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_l.isInitialized == 1) &&
        SimulinkPacer_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_h.isInitialized == 1) &&
        SimulinkPacer_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_b.isInitialized == 1) &&
        SimulinkPacer_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!SimulinkPacer_DW.obj.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj.isInitialized == 1) &&
        SimulinkPacer_DW.obj.isSetupComplete) {
      MW_digitalIO_close(SimulinkPacer_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted) {
    SimulinkPacer_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((SimulinkPacer_DW.obj_c.isInitialized == 1) &&
        SimulinkPacer_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(SimulinkPacer_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(SimulinkPacer_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
