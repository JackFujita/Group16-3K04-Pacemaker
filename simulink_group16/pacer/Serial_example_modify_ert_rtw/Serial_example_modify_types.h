/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_example_modify_types.h
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

#ifndef RTW_HEADER_Serial_example_modify_types_h_
#define RTW_HEADER_Serial_example_modify_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S2>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_Serial_T
#define typedef_b_freedomk64f_Hardware_Serial_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_Serial_T;

#endif                             /* typedef_b_freedomk64f_Hardware_Serial_T */

#ifndef struct_tag_GV9UedAE1zOVNNbkXknChB
#define struct_tag_GV9UedAE1zOVNNbkXknChB

struct tag_GV9UedAE1zOVNNbkXknChB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Serial_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_GV9UedAE1zOVNNbkXknChB */

#ifndef typedef_freedomk64f_SCIWrite_Serial_e_T
#define typedef_freedomk64f_SCIWrite_Serial_e_T

typedef struct tag_GV9UedAE1zOVNNbkXknChB freedomk64f_SCIWrite_Serial_e_T;

#endif                             /* typedef_freedomk64f_SCIWrite_Serial_e_T */

#ifndef struct_tag_214cR1nKZWaoqoq0FTtOUH
#define struct_tag_214cR1nKZWaoqoq0FTtOUH

struct tag_214cR1nKZWaoqoq0FTtOUH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Serial_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_214cR1nKZWaoqoq0FTtOUH */

#ifndef typedef_freedomk64f_SCIRead_Serial_ex_T
#define typedef_freedomk64f_SCIRead_Serial_ex_T

typedef struct tag_214cR1nKZWaoqoq0FTtOUH freedomk64f_SCIRead_Serial_ex_T;

#endif                             /* typedef_freedomk64f_SCIRead_Serial_ex_T */

/* Parameters (default storage) */
typedef struct P_Serial_example_modify_T_ P_Serial_example_modify_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Serial_example_modify_T RT_MODEL_Serial_example_modif_T;

#endif                           /* RTW_HEADER_Serial_example_modify_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
