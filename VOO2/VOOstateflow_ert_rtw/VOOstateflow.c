<<<<<<< HEAD
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOOstateflow.c
 *
 * Code generated for Simulink model 'VOOstateflow'.
 *
 * Model version                  : 5.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 17 10:44:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VOOstateflow.h"
#include "rtwtypes.h"
#include <math.h>
#include "VOOstateflow_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define VOOstateflow_IN_AOO_Charging   ((uint8_T)1U)
#define VOOstateflow_IN_AOO_Pacing     ((uint8_T)2U)
#define VOOstateflow_IN_ModeSelect     ((uint8_T)3U)
#define VOOstateflow_IN_VOO_Charging   ((uint8_T)4U)
#define VOOstateflow_IN_VOO_Pacing     ((uint8_T)5U)

/* Block signals (default storage) */
B_VOOstateflow_T VOOstateflow_B;

/* Block states (default storage) */
DW_VOOstateflow_T VOOstateflow_DW;

/* Real-time model */
static RT_MODEL_VOOstateflow_T VOOstateflow_M_;
RT_MODEL_VOOstateflow_T *const VOOstateflow_M = &VOOstateflow_M_;

/* Forward declaration for local functions */
static void VOOst_enter_atomic_VOO_Charging(void);
static void VOOst_enter_atomic_AOO_Charging(void);

/* Function for Chart: '<Root>/Chart' */
static void VOOst_enter_atomic_VOO_Charging(void)
{
  VOOstateflow_B.State = 0.0;
  VOOstateflow_B.PACE_GND_CTRL = 1.0;
  VOOstateflow_B.VENT_PACE_CTRL = 0.0;
  VOOstateflow_B.Z_ATR_CTRL = 0.0;
  VOOstateflow_B.Z_VENT_CTRL = 0.0;
  VOOstateflow_B.ATR_GND_CTRL = 0.0;
  VOOstateflow_B.VENT_GND_CTRL = 1.0;
  VOOstateflow_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<Root>/Constant4' */
  VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant4_Value;
  VOOstateflow_B.PACE_CHARGE_CTRL = 1.0;
  VOOstateflow_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void VOOst_enter_atomic_AOO_Charging(void)
{
  VOOstateflow_B.State = 0.0;
  VOOstateflow_B.PACE_GND_CTRL = 1.0;
  VOOstateflow_B.VENT_PACE_CTRL = 0.0;
  VOOstateflow_B.Z_ATR_CTRL = 0.0;
  VOOstateflow_B.Z_VENT_CTRL = 0.0;
  VOOstateflow_B.ATR_GND_CTRL = 1.0;
  VOOstateflow_B.VENT_GND_CTRL = 0.0;
  VOOstateflow_B.ATR_PACE_CTRL = 0.0;

  /* Constant: '<Root>/Constant2' */
  VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant2_Value;
  VOOstateflow_B.PACE_CHARGE_CTRL = 1.0;
  VOOstateflow_B.FRONTEND_CTRL = 0.0;
}

/* Model step function */
void VOOstateflow_step(void)
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
  if (VOOstateflow_DW.temporalCounter_i1 < MAX_uint32_T) {
    VOOstateflow_DW.temporalCounter_i1++;
  }

  if (VOOstateflow_DW.is_active_c3_VOOstateflow == 0U) {
    VOOstateflow_DW.is_active_c3_VOOstateflow = 1U;
    VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_ModeSelect;
  } else {
    switch (VOOstateflow_DW.is_c3_VOOstateflow) {
     case VOOstateflow_IN_AOO_Charging:
      VOOstateflow_B.State = 0.0;
      VOOstateflow_B.PACE_GND_CTRL = 1.0;
      VOOstateflow_B.VENT_PACE_CTRL = 0.0;
      VOOstateflow_B.Z_ATR_CTRL = 0.0;
      VOOstateflow_B.Z_VENT_CTRL = 0.0;
      VOOstateflow_B.ATR_GND_CTRL = 1.0;
      VOOstateflow_B.VENT_GND_CTRL = 0.0;
      VOOstateflow_B.ATR_PACE_CTRL = 0.0;
      VOOstateflow_B.PACE_CHARGE_CTRL = 1.0;
      VOOstateflow_B.FRONTEND_CTRL = 0.0;
      if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
          (VOOstateflow_P.Constant1_Value - VOOstateflow_P.Constant_Value)) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_AOO_Pacing;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOstateflow_B.State = 1.0;
        VOOstateflow_B.PACE_CHARGE_CTRL = 0.0;
        VOOstateflow_B.ATR_PACE_CTRL = 1.0;
        VOOstateflow_B.ATR_GND_CTRL = 0.0;
        VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant2_Value;
      }
      break;

     case VOOstateflow_IN_AOO_Pacing:
      VOOstateflow_B.State = 1.0;
      VOOstateflow_B.PACE_CHARGE_CTRL = 0.0;
      VOOstateflow_B.PACE_GND_CTRL = 1.0;
      VOOstateflow_B.ATR_PACE_CTRL = 1.0;
      VOOstateflow_B.ATR_GND_CTRL = 0.0;
      VOOstateflow_B.Z_ATR_CTRL = 0.0;
      VOOstateflow_B.Z_VENT_CTRL = 0.0;
      VOOstateflow_B.VENT_GND_CTRL = 0.0;
      VOOstateflow_B.VENT_PACE_CTRL = 0.0;
      VOOstateflow_B.FRONTEND_CTRL = 0.0;
      if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
          (VOOstateflow_P.Constant_Value)) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_AOO_Charging;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOst_enter_atomic_AOO_Charging();
      }
      break;

     case VOOstateflow_IN_ModeSelect:
      if (VOOstateflow_P.Constant6_Value == 1.0) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_VOO_Charging;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOst_enter_atomic_VOO_Charging();
      } else if (VOOstateflow_P.Constant6_Value == 2.0) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_AOO_Charging;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOst_enter_atomic_AOO_Charging();
      }
      break;

     case VOOstateflow_IN_VOO_Charging:
      VOOstateflow_B.State = 0.0;
      VOOstateflow_B.PACE_GND_CTRL = 1.0;
      VOOstateflow_B.VENT_PACE_CTRL = 0.0;
      VOOstateflow_B.Z_ATR_CTRL = 0.0;
      VOOstateflow_B.Z_VENT_CTRL = 0.0;
      VOOstateflow_B.ATR_GND_CTRL = 0.0;
      VOOstateflow_B.VENT_GND_CTRL = 1.0;
      VOOstateflow_B.ATR_PACE_CTRL = 0.0;
      VOOstateflow_B.PACE_CHARGE_CTRL = 1.0;
      VOOstateflow_B.FRONTEND_CTRL = 0.0;
      if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
          (VOOstateflow_P.Constant5_Value - VOOstateflow_P.Constant3_Value)) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_VOO_Pacing;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOstateflow_B.State = 1.0;
        VOOstateflow_B.PACE_CHARGE_CTRL = 0.0;
        VOOstateflow_B.VENT_GND_CTRL = 0.0;
        VOOstateflow_B.VENT_PACE_CTRL = 1.0;
        VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant4_Value;
      }
      break;

     default:
      /* case IN_VOO_Pacing: */
      VOOstateflow_B.State = 1.0;
      VOOstateflow_B.PACE_CHARGE_CTRL = 0.0;
      VOOstateflow_B.PACE_GND_CTRL = 1.0;
      VOOstateflow_B.ATR_PACE_CTRL = 0.0;
      VOOstateflow_B.ATR_GND_CTRL = 0.0;
      VOOstateflow_B.Z_ATR_CTRL = 0.0;
      VOOstateflow_B.Z_VENT_CTRL = 0.0;
      VOOstateflow_B.VENT_GND_CTRL = 0.0;
      VOOstateflow_B.VENT_PACE_CTRL = 1.0;
      VOOstateflow_B.FRONTEND_CTRL = 0.0;
      if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
          (VOOstateflow_P.Constant3_Value)) {
        VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_VOO_Charging;
        VOOstateflow_DW.temporalCounter_i1 = 0U;
        VOOst_enter_atomic_VOO_Charging();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Logic: '<Root>/NOT'
   */
  MW_digitalIO_write(VOOstateflow_DW.obj_mo.MW_DIGITALIO_HANDLE,
                     !(VOOstateflow_B.State != 0.0));

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VOOstateflow_DW.obj_i.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.State != 0.0);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(VOOstateflow_DW.obj_o.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write11' */
  MW_digitalIO_write(VOOstateflow_DW.obj_m.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VOOstateflow_DW.obj_e.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(VOOstateflow_DW.obj_p.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VOOstateflow_DW.obj_j.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(VOOstateflow_DW.obj_l.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(VOOstateflow_DW.obj_h.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VOOstateflow_DW.obj_b.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(VOOstateflow_DW.obj.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(VOOstateflow_DW.obj_c.MW_PWM_HANDLE,
                      VOOstateflow_B.PACING_REF_PWM);
}

/* Model initialize function */
void VOOstateflow_initialize(void)
{
  {
    freedomk64f_DigitalWrite_VOOs_T *obj;
    freedomk64f_PWMOutput_VOOstat_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    VOOstateflow_DW.obj_mo.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_mo.isInitialized = 0;
    VOOstateflow_DW.obj_mo.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_mo;
    VOOstateflow_DW.obj_mo.isSetupComplete = false;
    VOOstateflow_DW.obj_mo.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    VOOstateflow_DW.obj_mo.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_i.isInitialized = 0;
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_i;
    VOOstateflow_DW.obj_i.isSetupComplete = false;
    VOOstateflow_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    VOOstateflow_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_o.isInitialized = 0;
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_o;
    VOOstateflow_DW.obj_o.isSetupComplete = false;
    VOOstateflow_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    VOOstateflow_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write11' */
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_m.isInitialized = 0;
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_m;
    VOOstateflow_DW.obj_m.isSetupComplete = false;
    VOOstateflow_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    VOOstateflow_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_e.isInitialized = 0;
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_e;
    VOOstateflow_DW.obj_e.isSetupComplete = false;
    VOOstateflow_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VOOstateflow_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    VOOstateflow_DW.obj_p.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_p.isInitialized = 0;
    VOOstateflow_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_p;
    VOOstateflow_DW.obj_p.isSetupComplete = false;
    VOOstateflow_DW.obj_p.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VOOstateflow_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_j.isInitialized = 0;
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_j;
    VOOstateflow_DW.obj_j.isSetupComplete = false;
    VOOstateflow_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VOOstateflow_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_l.isInitialized = 0;
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_l;
    VOOstateflow_DW.obj_l.isSetupComplete = false;
    VOOstateflow_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VOOstateflow_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_h.isInitialized = 0;
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_h;
    VOOstateflow_DW.obj_h.isSetupComplete = false;
    VOOstateflow_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VOOstateflow_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_b.isInitialized = 0;
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_b;
    VOOstateflow_DW.obj_b.isSetupComplete = false;
    VOOstateflow_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VOOstateflow_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj.isInitialized = 0;
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj;
    VOOstateflow_DW.obj.isSetupComplete = false;
    VOOstateflow_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    VOOstateflow_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    VOOstateflow_DW.obj_c.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_c.isInitialized = 0;
    VOOstateflow_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &VOOstateflow_DW.obj_c;
    VOOstateflow_DW.obj_c.isSetupComplete = false;
    VOOstateflow_DW.obj_c.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(VOOstateflow_DW.obj_c.MW_PWM_HANDLE);
    VOOstateflow_DW.obj_c.isSetupComplete = true;
  }
}

/* Model terminate function */
void VOOstateflow_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VOOstateflow_DW.obj_mo.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_mo.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_mo.isInitialized == 1) &&
        VOOstateflow_DW.obj_mo.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_mo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VOOstateflow_DW.obj_i.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_i.isInitialized == 1) &&
        VOOstateflow_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  if (!VOOstateflow_DW.obj_o.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_o.isInitialized == 1) &&
        VOOstateflow_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write10' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write11' */
  if (!VOOstateflow_DW.obj_m.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_m.isInitialized == 1) &&
        VOOstateflow_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write11' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VOOstateflow_DW.obj_e.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_e.isInitialized == 1) &&
        VOOstateflow_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!VOOstateflow_DW.obj_p.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_p.isInitialized == 1) &&
        VOOstateflow_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VOOstateflow_DW.obj_j.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_j.isInitialized == 1) &&
        VOOstateflow_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!VOOstateflow_DW.obj_l.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_l.isInitialized == 1) &&
        VOOstateflow_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!VOOstateflow_DW.obj_h.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_h.isInitialized == 1) &&
        VOOstateflow_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VOOstateflow_DW.obj_b.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_b.isInitialized == 1) &&
        VOOstateflow_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!VOOstateflow_DW.obj.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj.isInitialized == 1) &&
        VOOstateflow_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!VOOstateflow_DW.obj_c.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_c.isInitialized == 1) &&
        VOOstateflow_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(VOOstateflow_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(VOOstateflow_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
=======
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VOOstateflow.c
 *
 * Code generated for Simulink model 'VOOstateflow'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 16 23:28:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VOOstateflow.h"
#include "rtwtypes.h"
#include <math.h>
#include "VOOstateflow_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define VOOstateflo_IN_DischargingHeart ((uint8_T)2U)
#define VOOstateflow_IN_ChargingHeart  ((uint8_T)1U)

/* Block signals (default storage) */
B_VOOstateflow_T VOOstateflow_B;

/* Block states (default storage) */
DW_VOOstateflow_T VOOstateflow_DW;

/* Real-time model */
static RT_MODEL_VOOstateflow_T VOOstateflow_M_;
RT_MODEL_VOOstateflow_T *const VOOstateflow_M = &VOOstateflow_M_;

/* Model step function */
void VOOstateflow_step(void)
{
  int32_T rtb_PACE_CHARGE_CTRL;
  int32_T rtb_State;
  int32_T rtb_VENT_GND_CTRL;
  int32_T rtb_VENT_PACE_CTRL;

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  if (VOOstateflow_DW.temporalCounter_i1 < MAX_uint32_T) {
    VOOstateflow_DW.temporalCounter_i1++;
  }

  if (VOOstateflow_DW.is_active_c3_VOOstateflow == 0U) {
    VOOstateflow_DW.is_active_c3_VOOstateflow = 1U;
    VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflo_IN_DischargingHeart;
    VOOstateflow_DW.temporalCounter_i1 = 0U;
    rtb_State = 0;
    rtb_PACE_CHARGE_CTRL = 1;
    rtb_VENT_PACE_CTRL = 0;
    rtb_VENT_GND_CTRL = 1;
    VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant4_Value;
  } else if (VOOstateflow_DW.is_c3_VOOstateflow == VOOstateflow_IN_ChargingHeart)
  {
    rtb_State = 1;
    rtb_PACE_CHARGE_CTRL = 0;
    rtb_VENT_PACE_CTRL = 1;
    rtb_VENT_GND_CTRL = 0;
    if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
        (VOOstateflow_P.Constant5_Value - VOOstateflow_P.Constant3_Value)) {
      VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflo_IN_DischargingHeart;
      VOOstateflow_DW.temporalCounter_i1 = 0U;
      rtb_State = 0;
      rtb_PACE_CHARGE_CTRL = 1;
      rtb_VENT_PACE_CTRL = 0;
      rtb_VENT_GND_CTRL = 1;
      VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant4_Value;
    }
  } else {
    /* case IN_DischargingHeart: */
    rtb_State = 0;
    rtb_PACE_CHARGE_CTRL = 1;
    rtb_VENT_PACE_CTRL = 0;
    rtb_VENT_GND_CTRL = 1;
    if (VOOstateflow_DW.temporalCounter_i1 >= (uint32_T)ceil
        (VOOstateflow_P.Constant3_Value)) {
      VOOstateflow_DW.is_c3_VOOstateflow = VOOstateflow_IN_ChargingHeart;
      VOOstateflow_DW.temporalCounter_i1 = 0U;
      rtb_State = 1;
      rtb_PACE_CHARGE_CTRL = 0;
      rtb_VENT_PACE_CTRL = 1;
      rtb_VENT_GND_CTRL = 0;
      VOOstateflow_B.PACING_REF_PWM = VOOstateflow_P.Constant4_Value;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Logic: '<Root>/NOT'
   */
  MW_digitalIO_write(VOOstateflow_DW.obj_m.MW_DIGITALIO_HANDLE, rtb_State == 0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(VOOstateflow_DW.obj_i.MW_DIGITALIO_HANDLE, rtb_State != 0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(VOOstateflow_DW.obj_e.MW_DIGITALIO_HANDLE,
                     rtb_PACE_CHARGE_CTRL != 0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(VOOstateflow_DW.obj_n.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(VOOstateflow_DW.obj_j.MW_DIGITALIO_HANDLE,
                     rtb_VENT_PACE_CTRL != 0);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(VOOstateflow_DW.obj_l.MW_DIGITALIO_HANDLE,
                     rtb_VENT_GND_CTRL != 0);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(VOOstateflow_DW.obj_h.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(VOOstateflow_DW.obj_b.MW_DIGITALIO_HANDLE, true);

  /* MATLABSystem: '<Root>/Digital Write8' */
  MW_digitalIO_write(VOOstateflow_DW.obj_o.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(VOOstateflow_DW.obj.MW_DIGITALIO_HANDLE,
                     VOOstateflow_B.PACING_REF_PWM != 0.0);
}

/* Model initialize function */
void VOOstateflow_initialize(void)
{
  {
    freedomk64f_DigitalWrite_VOOs_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_m.isInitialized = 0;
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_m;
    VOOstateflow_DW.obj_m.isSetupComplete = false;
    VOOstateflow_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    VOOstateflow_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_i.isInitialized = 0;
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_i;
    VOOstateflow_DW.obj_i.isSetupComplete = false;
    VOOstateflow_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    VOOstateflow_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_e.isInitialized = 0;
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_e;
    VOOstateflow_DW.obj_e.isSetupComplete = false;
    VOOstateflow_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VOOstateflow_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    VOOstateflow_DW.obj_n.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_n.isInitialized = 0;
    VOOstateflow_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_n;
    VOOstateflow_DW.obj_n.isSetupComplete = false;
    VOOstateflow_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VOOstateflow_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_j.isInitialized = 0;
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_j;
    VOOstateflow_DW.obj_j.isSetupComplete = false;
    VOOstateflow_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VOOstateflow_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_l.isInitialized = 0;
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_l;
    VOOstateflow_DW.obj_l.isSetupComplete = false;
    VOOstateflow_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VOOstateflow_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_h.isInitialized = 0;
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_h;
    VOOstateflow_DW.obj_h.isSetupComplete = false;
    VOOstateflow_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VOOstateflow_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_b.isInitialized = 0;
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_b;
    VOOstateflow_DW.obj_b.isSetupComplete = false;
    VOOstateflow_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VOOstateflow_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write8' */
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj_o.isInitialized = 0;
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj_o;
    VOOstateflow_DW.obj_o.isSetupComplete = false;
    VOOstateflow_DW.obj_o.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    VOOstateflow_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = true;
    VOOstateflow_DW.obj.isInitialized = 0;
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = false;
    obj = &VOOstateflow_DW.obj;
    VOOstateflow_DW.obj.isSetupComplete = false;
    VOOstateflow_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(5U, 1);
    VOOstateflow_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void VOOstateflow_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!VOOstateflow_DW.obj_m.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_m.isInitialized == 1) &&
        VOOstateflow_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!VOOstateflow_DW.obj_i.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_i.isInitialized == 1) &&
        VOOstateflow_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!VOOstateflow_DW.obj_e.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_e.isInitialized == 1) &&
        VOOstateflow_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!VOOstateflow_DW.obj_n.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_n.isInitialized == 1) &&
        VOOstateflow_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!VOOstateflow_DW.obj_j.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_j.isInitialized == 1) &&
        VOOstateflow_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  if (!VOOstateflow_DW.obj_l.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_l.isInitialized == 1) &&
        VOOstateflow_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write5' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  if (!VOOstateflow_DW.obj_h.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_h.isInitialized == 1) &&
        VOOstateflow_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write6' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  if (!VOOstateflow_DW.obj_b.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_b.isInitialized == 1) &&
        VOOstateflow_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write7' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write8' */
  if (!VOOstateflow_DW.obj_o.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj_o.isInitialized == 1) &&
        VOOstateflow_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write8' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  if (!VOOstateflow_DW.obj.matlabCodegenIsDeleted) {
    VOOstateflow_DW.obj.matlabCodegenIsDeleted = true;
    if ((VOOstateflow_DW.obj.isInitialized == 1) &&
        VOOstateflow_DW.obj.isSetupComplete) {
      MW_digitalIO_close(VOOstateflow_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write9' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
>>>>>>> 502f796c626dd7d5643fde44c22cb31f95d2ef01
