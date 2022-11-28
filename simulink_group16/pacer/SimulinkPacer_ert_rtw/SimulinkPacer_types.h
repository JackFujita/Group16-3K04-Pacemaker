/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SimulinkPacer_types.h
 *
 * Code generated for Simulink model 'SimulinkPacer'.
 *
 * Model version                  : 5.93
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 28 17:12:09 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SimulinkPacer_types_h_
#define RTW_HEADER_SimulinkPacer_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S4>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_Simuli_T
#define typedef_b_freedomk64f_Hardware_Simuli_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_Simuli_T;

#endif                             /* typedef_b_freedomk64f_Hardware_Simuli_T */

#ifndef struct_tag_GV9UedAE1zOVNNbkXknChB
#define struct_tag_GV9UedAE1zOVNNbkXknChB

struct tag_GV9UedAE1zOVNNbkXknChB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Simuli_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_GV9UedAE1zOVNNbkXknChB */

#ifndef typedef_freedomk64f_SCIWrite_Simulink_T
#define typedef_freedomk64f_SCIWrite_Simulink_T

typedef struct tag_GV9UedAE1zOVNNbkXknChB freedomk64f_SCIWrite_Simulink_T;

#endif                             /* typedef_freedomk64f_SCIWrite_Simulink_T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Simuli_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_Simul_T
#define typedef_freedomk64f_DigitalRead_Simul_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_Simul_T;

#endif                             /* typedef_freedomk64f_DigitalRead_Simul_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Simuli_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_Simu_T
#define typedef_freedomk64f_DigitalWrite_Simu_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_Simu_T;

#endif                             /* typedef_freedomk64f_DigitalWrite_Simu_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Simuli_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_Simulin_T
#define typedef_freedomk64f_PWMOutput_Simulin_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_Simulin_T;

#endif                             /* typedef_freedomk64f_PWMOutput_Simulin_T */

#ifndef struct_tag_214cR1nKZWaoqoq0FTtOUH
#define struct_tag_214cR1nKZWaoqoq0FTtOUH

struct tag_214cR1nKZWaoqoq0FTtOUH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Simuli_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_214cR1nKZWaoqoq0FTtOUH */

#ifndef typedef_freedomk64f_SCIRead_SimulinkP_T
#define typedef_freedomk64f_SCIRead_SimulinkP_T

typedef struct tag_214cR1nKZWaoqoq0FTtOUH freedomk64f_SCIRead_SimulinkP_T;

#endif                             /* typedef_freedomk64f_SCIRead_SimulinkP_T */

/* Parameters (default storage) */
typedef struct P_SimulinkPacer_T_ P_SimulinkPacer_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_SimulinkPacer_T RT_MODEL_SimulinkPacer_T;

#endif                                 /* RTW_HEADER_SimulinkPacer_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
