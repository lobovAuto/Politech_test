/*
 * File: max6691.c
 *
 *
 *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
 *
 *   This file is an S-function produced by the S-Function
 *   Builder which only recognizes certain fields.  Changes made
 *   outside these fields will be lost the next time the block is
 *   used to load, edit, and resave this file. This file will be overwritten
 *   by the S-function Builder block. If you want to edit this file by hand,
 *   you must change it only in the area defined as:
 *
 *        %%%-SFUNWIZ_defines_Changes_BEGIN
 *        #define NAME 'replacement text'
 *        %%% SFUNWIZ_defines_Changes_END
 *
 *   DO NOT change NAME--Change the 'replacement text' only.
 *
 *   For better compatibility with the Simulink Coder, the
 *   "wrapper" S-function technique is used.  This is discussed
 *   in the Simulink Coder's Manual in the Chapter titled,
 *   "Wrapper S-functions".
 *
 *  -------------------------------------------------------------------------
 * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
 *  -------------------------------------------------------------------------
 *
 * Created: Mon Feb 20 11:02:21 2023
 */

#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                max6691

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS                     1

/* Input Port  0 */
#define IN_PORT_0_NAME                 inputDelta
#define INPUT_0_WIDTH                  1
#define INPUT_DIMS_0_COL               1
#define INPUT_0_DTYPE                  uint32_T
#define INPUT_0_COMPLEX                COMPLEX_NO
#define IN_0_FRAME_BASED               FRAME_NO
#define IN_0_BUS_BASED                 0
#define IN_0_BUS_NAME
#define IN_0_DIMS                      1-D
#define INPUT_0_FEEDTHROUGH            1
#define IN_0_ISSIGNED                  0
#define IN_0_WORDLENGTH                8
#define IN_0_FIXPOINTSCALING           1
#define IN_0_FRACTIONLENGTH            9
#define IN_0_BIAS                      0
#define IN_0_SLOPE                     0.125
#define NUM_OUTPUTS                    5

/* Output Port  0 */
#define OUT_PORT_0_NAME                SM
#define OUTPUT_0_WIDTH                 1
#define OUTPUT_DIMS_0_COL              1
#define OUTPUT_0_DTYPE                 uint8_T
#define OUTPUT_0_COMPLEX               COMPLEX_NO
#define OUT_0_FRAME_BASED              FRAME_NO
#define OUT_0_BUS_BASED                0
#define OUT_0_BUS_NAME
#define OUT_0_DIMS                     1-D
#define OUT_0_ISSIGNED                 1
#define OUT_0_WORDLENGTH               8
#define OUT_0_FIXPOINTSCALING          1
#define OUT_0_FRACTIONLENGTH           3
#define OUT_0_BIAS                     0
#define OUT_0_SLOPE                    0.125

/* Output Port  1 */
#define OUT_PORT_1_NAME                inStruct
#define OUTPUT_1_WIDTH                 1
#define OUTPUT_DIMS_1_COL              1
#define OUTPUT_1_DTYPE                 real_T
#define OUTPUT_1_COMPLEX               COMPLEX_NO
#define OUT_1_FRAME_BASED              FRAME_NO
#define OUT_1_BUS_BASED                1
#define OUT_1_BUS_NAME                 maxHLstruct
#define OUT_1_DIMS                     1-D
#define OUT_1_ISSIGNED                 1
#define OUT_1_WORDLENGTH               8
#define OUT_1_FIXPOINTSCALING          1
#define OUT_1_FRACTIONLENGTH           3
#define OUT_1_BIAS                     0
#define OUT_1_SLOPE                    0.125

/* Output Port  2 */
#define OUT_PORT_2_NAME                outStruct
#define OUTPUT_2_WIDTH                 1
#define OUTPUT_DIMS_2_COL              1
#define OUTPUT_2_DTYPE                 real_T
#define OUTPUT_2_COMPLEX               COMPLEX_NO
#define OUT_2_FRAME_BASED              FRAME_NO
#define OUT_2_BUS_BASED                1
#define OUT_2_BUS_NAME                 maxTempStruct
#define OUT_2_DIMS                     1-D
#define OUT_2_ISSIGNED                 1
#define OUT_2_WORDLENGTH               8
#define OUT_2_FIXPOINTSCALING          1
#define OUT_2_FRACTIONLENGTH           3
#define OUT_2_BIAS                     0
#define OUT_2_SLOPE                    0.125

/* Output Port  3 */
#define OUT_PORT_3_NAME                timeReady
#define OUTPUT_3_WIDTH                 1
#define OUTPUT_DIMS_3_COL              1
#define OUTPUT_3_DTYPE                 uint8_T
#define OUTPUT_3_COMPLEX               COMPLEX_NO
#define OUT_3_FRAME_BASED              FRAME_NO
#define OUT_3_BUS_BASED                0
#define OUT_3_BUS_NAME
#define OUT_3_DIMS                     1-D
#define OUT_3_ISSIGNED                 1
#define OUT_3_WORDLENGTH               8
#define OUT_3_FIXPOINTSCALING          1
#define OUT_3_FRACTIONLENGTH           3
#define OUT_3_BIAS                     0
#define OUT_3_SLOPE                    0.125

/* Output Port  4 */
#define OUT_PORT_4_NAME                inputTimer
#define OUTPUT_4_WIDTH                 1
#define OUTPUT_DIMS_4_COL              1
#define OUTPUT_4_DTYPE                 uint32_T
#define OUTPUT_4_COMPLEX               COMPLEX_NO
#define OUT_4_FRAME_BASED              FRAME_NO
#define OUT_4_BUS_BASED                0
#define OUT_4_BUS_NAME
#define OUT_4_DIMS                     1-D
#define OUT_4_ISSIGNED                 1
#define OUT_4_WORDLENGTH               8
#define OUT_4_FIXPOINTSCALING          1
#define OUT_4_FRACTIONLENGTH           3
#define OUT_4_BIAS                     0
#define OUT_4_SLOPE                    0.125
#define NPARAMS                        0
#define SAMPLE_TIME_0                  INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES                0
#define DISC_STATES_IC                 [0]
#define NUM_CONT_STATES                0
#define CONT_STATES_IC                 [0]
#define SFUNWIZ_GENERATE_TLC           1
#define SOURCEFILES                    "__SFB__"
#define PANELINDEX                     N/A
#define USE_SIMSTRUCT                  0
#define SHOW_COMPILE_STEPS             0
#define CREATE_DEBUG_MEXFILE           0
#define SAVE_CODE_ONLY                 1
#define SFUNWIZ_REVISION               3.0

/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"
#include "max6691_bus.h"

/*
 * Code Generation Environment flag (simulation or standalone target).
 */
static int_T isSimulationTarget;

/* Utility function prototypes. */
static int_T GetRTWEnvironmentMode(SimStruct *S);

/* Macro used to check if Simulation mode is set to accelerator */
#define isBusDWorkPresent              ( ( ( !ssRTWGenIsCodeGen(S) || isSimulationTarget ) && !ssIsExternalSim(S) ) || ssIsRapidAcceleratorActive(S) )

typedef struct {
  int_T offset;
  int_T elemSize;
  int_T numElems;
} busInfoStruct;

extern void max6691_Outputs_wrapper(const uint32_T *inputDelta,
  uint8_T *SM,
  maxHLstruct *inStruct,
  maxTempStruct *outStruct,
  uint8_T *timeReady,
  uint32_T *inputTimer);

/*====================*
 * S-function methods *
 *====================*/
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
  DECL_AND_INIT_DIMSINFO(inputDimsInfo);
  DECL_AND_INIT_DIMSINFO(outputDimsInfo);
  ssSetNumSFcnParams(S, NPARAMS);
  if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

  ssSetArrayLayoutForCodeGen(S, SS_COLUMN_MAJOR);
  ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);
  ssSetNumContStates(S, NUM_CONT_STATES);
  ssSetNumDiscStates(S, NUM_DISC_STATES);
  if (!ssSetNumInputPorts(S, NUM_INPUTS))
    return;

  /* Input Port 0 */
  ssSetInputPortWidth(S, 0, INPUT_0_WIDTH);
  ssSetInputPortDataType(S, 0, SS_UINT32);
  ssSetInputPortComplexSignal(S, 0, INPUT_0_COMPLEX);
  ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
  ssSetInputPortRequiredContiguous(S, 0, 1);/*direct input signal access*/
  if (!ssSetNumOutputPorts(S, NUM_OUTPUTS))
    return;

  /* Output Port 0 */
  ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
  ssSetOutputPortDataType(S, 0, SS_UINT8);
  ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);

  /* Output Port 1 */

  /* Register maxHLstruct datatype for Output port 1 */
#if defined(MATLAB_MEX_FILE)

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    DTypeId dataTypeIdReg;
    ssRegisterTypeFromNamedObject(S, "maxHLstruct", &dataTypeIdReg);
    if (dataTypeIdReg == INVALID_DTYPE_ID)
      return;
    ssSetOutputPortDataType(S, 1, dataTypeIdReg);
  }

#endif

  ssSetBusOutputObjectName(S, 1, (void *) "maxHLstruct");
  ssSetOutputPortWidth(S, 1, OUTPUT_1_WIDTH);
  ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);
  ssSetBusOutputAsStruct(S, 1,OUT_1_BUS_BASED);
  ssSetOutputPortBusMode(S, 1, SL_BUS_MODE);
  outputDimsInfo.width = OUTPUT_1_WIDTH;
  ssSetOutputPortDimensionInfo(S, 1, &outputDimsInfo);
  ssSetOutputPortMatrixDimensions(S, 1, OUTPUT_1_WIDTH, OUTPUT_DIMS_1_COL);
  ssSetOutputPortFrameData(S, 1, OUT_1_FRAME_BASED);

  /* Output Port 2 */

  /* Register maxTempStruct datatype for Output port 2 */
#if defined(MATLAB_MEX_FILE)

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    DTypeId dataTypeIdReg;
    ssRegisterTypeFromNamedObject(S, "maxTempStruct", &dataTypeIdReg);
    if (dataTypeIdReg == INVALID_DTYPE_ID)
      return;
    ssSetOutputPortDataType(S, 2, dataTypeIdReg);
  }

#endif

  ssSetBusOutputObjectName(S, 2, (void *) "maxTempStruct");
  ssSetOutputPortWidth(S, 2, OUTPUT_2_WIDTH);
  ssSetOutputPortComplexSignal(S, 2, OUTPUT_2_COMPLEX);
  ssSetBusOutputAsStruct(S, 2,OUT_2_BUS_BASED);
  ssSetOutputPortBusMode(S, 2, SL_BUS_MODE);
  outputDimsInfo.width = OUTPUT_2_WIDTH;
  ssSetOutputPortDimensionInfo(S, 2, &outputDimsInfo);
  ssSetOutputPortMatrixDimensions(S, 2, OUTPUT_2_WIDTH, OUTPUT_DIMS_2_COL);
  ssSetOutputPortFrameData(S, 2, OUT_2_FRAME_BASED);

  /* Output Port 3 */
  ssSetOutputPortWidth(S, 3, OUTPUT_3_WIDTH);
  ssSetOutputPortDataType(S, 3, SS_UINT8);
  ssSetOutputPortComplexSignal(S, 3, OUTPUT_3_COMPLEX);

  /* Output Port 4 */
  ssSetOutputPortWidth(S, 4, OUTPUT_4_WIDTH);
  ssSetOutputPortDataType(S, 4, SS_UINT32);
  ssSetOutputPortComplexSignal(S, 4, OUTPUT_4_COMPLEX);
  if (ssRTWGenIsCodeGen(S)) {
    isSimulationTarget = GetRTWEnvironmentMode(S);
    if (isSimulationTarget == -1) {
      ssSetLocalErrorStatus(S,
                            " Unable to determine a valid code generation environment mode");
      return;
    }

    isSimulationTarget |= ssRTWGenIsModelReferenceSimTarget(S);
  }

  /* Set the number of dworks */
  if (!ssSetNumDWork(S, 2))
    return;

  /*
   * Configure the dwork 0 (inStructBUS)
   */
#if defined(MATLAB_MEX_FILE)

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    DTypeId dataTypeIdReg;
    ssRegisterTypeFromNamedObject(S, "maxHLstruct", &dataTypeIdReg);
    if (dataTypeIdReg == INVALID_DTYPE_ID)
      return;
    if (isBusDWorkPresent) {
      ssSetDWorkDataType(S, 0, dataTypeIdReg);
    } else {
      ssSetDWorkDataType(S, 0, SS_POINTER);
    }
  }

#endif

  ssSetDWorkUsageType(S, 0, SS_DWORK_USED_AS_DWORK);
  ssSetDWorkName(S, 0, "inStructBUS");
  ssSetDWorkWidth(S, 0, DYNAMICALLY_SIZED);
  ssSetDWorkComplexSignal(S, 0, COMPLEX_NO);

  /*
   * Configure the dwork 1 (outStructBUS)
   */
#if defined(MATLAB_MEX_FILE)

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    DTypeId dataTypeIdReg;
    ssRegisterTypeFromNamedObject(S, "maxTempStruct", &dataTypeIdReg);
    if (dataTypeIdReg == INVALID_DTYPE_ID)
      return;
    if (isBusDWorkPresent) {
      ssSetDWorkDataType(S, 1, dataTypeIdReg);
    } else {
      ssSetDWorkDataType(S, 1, SS_POINTER);
    }
  }

#endif

  ssSetDWorkUsageType(S, 1, SS_DWORK_USED_AS_DWORK);
  ssSetDWorkName(S, 1, "outStructBUS");
  ssSetDWorkWidth(S, 1, DYNAMICALLY_SIZED);
  ssSetDWorkComplexSignal(S, 1, COMPLEX_NO);
  ssSetNumPWork(S, 0);
  ssSetNumSampleTimes(S, 1);
  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);
  ssSetSimulinkVersionGeneratedIn(S, "10.4");

  /* Take care when specifying exception free code - see sfuntmpl_doc.c */
  ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                   SS_OPTION_USE_TLC_WITH_ACCELERATOR |
                   SS_OPTION_WORKS_WITH_CODE_REUSE));
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, SAMPLE_TIME_0);
  ssSetModelReferenceSampleTimeDefaultInheritance(S);
  ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE

static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
  ssSetInputPortDataType(S, 0, dType);
}

#define MDL_SET_OUTPUT_PORT_DATA_TYPE

static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
  ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES

static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  ssSetInputPortDataType(S, 0, SS_DOUBLE);
  ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)

static void mdlSetWorkWidths(SimStruct *S)
{
  /* Set the width of DWork(s) used for marshalling the IOs */
  if (isBusDWorkPresent) {
    /* Update dwork 0 */
    ssSetDWorkWidth(S, 0, ssGetOutputPortWidth(S, 1));

    /* Update dwork 1 */
    ssSetDWorkWidth(S, 1, ssGetOutputPortWidth(S, 2));
  }
}

#endif

#define MDL_START                                                /* Change to #undef to remove function */
#if defined(MDL_START)

/* Function: mdlStart =======================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
  /* Bus Information */
  slDataTypeAccess *dta = ssGetDataTypeAccess(S);
  const char *bpath = ssGetPath(S);
  DTypeId maxHLstructId = ssGetDataTypeId(S,"maxHLstruct");
  DTypeId maxTempStructId = ssGetDataTypeId(S,"maxTempStruct");
  busInfoStruct *busInfo = (busInfoStruct *)malloc(18*sizeof(busInfoStruct));
  if (busInfo==NULL) {
    ssSetLocalErrorStatus(S, "Memory allocation failure");
    return;
  }

  /*offsets info for all unique bus structures*/
  busInfo[0].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 0);
  busInfo[0].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[0].numElems = 1;
  busInfo[1].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 1);
  busInfo[1].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[1].numElems = 1;
  busInfo[2].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 2);
  busInfo[2].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[2].numElems = 1;
  busInfo[3].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 3);
  busInfo[3].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[3].numElems = 1;
  busInfo[4].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 4);
  busInfo[4].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[4].numElems = 1;
  busInfo[5].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 5);
  busInfo[5].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[5].numElems = 1;
  busInfo[6].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 6);
  busInfo[6].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[6].numElems = 1;
  busInfo[7].offset = dtaGetDataTypeElementOffset(dta, bpath, maxHLstructId, 7);
  busInfo[7].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT32);
  busInfo[7].numElems = 1;
  busInfo[8].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId, 0);
  busInfo[8].elemSize = dtaGetDataTypeSize(dta, bpath, SS_SINGLE);
  busInfo[8].numElems = 1;
  busInfo[9].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId, 1);
  busInfo[9].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT8);
  busInfo[9].numElems = 1;
  busInfo[10].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    2);
  busInfo[10].elemSize = dtaGetDataTypeSize(dta, bpath, SS_SINGLE);
  busInfo[10].numElems = 1;
  busInfo[11].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    3);
  busInfo[11].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT8);
  busInfo[11].numElems = 1;
  busInfo[12].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    4);
  busInfo[12].elemSize = dtaGetDataTypeSize(dta, bpath, SS_SINGLE);
  busInfo[12].numElems = 1;
  busInfo[13].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    5);
  busInfo[13].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT8);
  busInfo[13].numElems = 1;
  busInfo[14].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    6);
  busInfo[14].elemSize = dtaGetDataTypeSize(dta, bpath, SS_SINGLE);
  busInfo[14].numElems = 1;
  busInfo[15].offset = dtaGetDataTypeElementOffset(dta, bpath, maxTempStructId,
    7);
  busInfo[15].elemSize = dtaGetDataTypeSize(dta, bpath, SS_UINT8);
  busInfo[15].numElems = 1;
  busInfo[16].elemSize = dtaGetDataTypeSize(dta, bpath, maxHLstructId);
  busInfo[16].numElems = 1;
  busInfo[17].elemSize = dtaGetDataTypeSize(dta, bpath, maxTempStructId);
  busInfo[17].numElems = 1;
  ssSetUserData(S, busInfo);

  /* Allocate memory for arrays or nested arrays of buses DWork pointers */
}

#endif                                 /*  MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  const uint32_T *inputDelta = (uint32_T *) ssGetInputPortRealSignal(S, 0);
  uint8_T *SM = (uint8_T *) ssGetOutputPortRealSignal(S, 0);
  char *inStruct = (char *) ssGetOutputPortSignal(S, 1);
  char *outStruct = (char *) ssGetOutputPortSignal(S, 2);
  uint8_T *timeReady = (uint8_T *) ssGetOutputPortRealSignal(S, 3);
  uint32_T *inputTimer = (uint32_T *) ssGetOutputPortRealSignal(S, 4);
  busInfoStruct* busInfo = (busInfoStruct *) ssGetUserData(S);

  /* Temporary bus copy declarations */
  maxHLstruct _inStructBUS;
  maxTempStruct _outStructBUS;
  slDataTypeAccess *dta = ssGetDataTypeAccess(S);
  const char *bpath = ssGetPath(S);

  /*Copy from Simulink to bus structure*/
  max6691_Outputs_wrapper(inputDelta, SM, &_inStructBUS, &_outStructBUS,
    timeReady, inputTimer);

  /*Copy from bus structure to Simulink*/

  /*Copy from _inStructBUS to Simulink for Output port 1*/
  *((uint32_T*)((char *) inStruct + busInfo[0].offset)) = (_inStructBUS).t1H;
  *((uint32_T*)((char *) inStruct + busInfo[1].offset)) = (_inStructBUS).t1L;
  *((uint32_T*)((char *) inStruct + busInfo[2].offset)) = (_inStructBUS).t2H;
  *((uint32_T*)((char *) inStruct + busInfo[3].offset)) = (_inStructBUS).t2L;
  *((uint32_T*)((char *) inStruct + busInfo[4].offset)) = (_inStructBUS).t3H;
  *((uint32_T*)((char *) inStruct + busInfo[5].offset)) = (_inStructBUS).t3L;
  *((uint32_T*)((char *) inStruct + busInfo[6].offset)) = (_inStructBUS).t4H;
  *((uint32_T*)((char *) inStruct + busInfo[7].offset)) = (_inStructBUS).t4L;

  /*Copy from _outStructBUS to Simulink for Output port 2*/
  *((real32_T*)((char *) outStruct + busInfo[8].offset)) = (_outStructBUS).t1;
  *((uint8_T*)((char *) outStruct + busInfo[9].offset)) = (_outStructBUS).
    t1_valid;
  *((real32_T*)((char *) outStruct + busInfo[10].offset)) = (_outStructBUS).t2;
  *((uint8_T*)((char *) outStruct + busInfo[11].offset)) = (_outStructBUS).
    t2_valid;
  *((real32_T*)((char *) outStruct + busInfo[12].offset)) = (_outStructBUS).t3;
  *((uint8_T*)((char *) outStruct + busInfo[13].offset)) = (_outStructBUS).
    t3_valid;
  *((real32_T*)((char *) outStruct + busInfo[14].offset)) = (_outStructBUS).t4;
  *((uint8_T*)((char *) outStruct + busInfo[15].offset)) = (_outStructBUS).
    t4_valid;
}

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
  /* Free stored bus information */
  busInfoStruct *busInfo = (busInfoStruct *) ssGetUserData(S);
  if (busInfo != NULL) {
    free(busInfo);
  }

  if (!isBusDWorkPresent) {
  }
}

static int_T GetRTWEnvironmentMode(SimStruct *S)
{
  int_T status = -1;
  mxArray *plhs[1];
  mxArray *prhs[1];
  mxArray * err;

  /*
   * Get the name of the Simulink block diagram
   */
  prhs[0] = mxCreateString(ssGetModelName(ssGetRootSS(S)));
  plhs[0] = NULL;

  /*
   * Call "isSimulationTarget = rtwenvironmentmode(modelName)" in MATLAB
   */
  err = mexCallMATLABWithTrap(1, plhs, 1, prhs, "rtwenvironmentmode");
  mxDestroyArray(prhs[0]);

  /*
   * Set the error status if an error occurred
   */
  if (err) {
    if (plhs[0]) {
      mxDestroyArray(plhs[0]);
      plhs[0] = NULL;
    }

    ssSetLocalErrorStatus(S,
                          "Unknown error during call to 'rtwenvironmentmode'.");
    return -1;
  }

  /*
   * Get the value returned by rtwenvironmentmode(modelName)
   */
  if (plhs[0]) {
    status = (int_T) (mxGetScalar(plhs[0]) != 0);
    mxDestroyArray(plhs[0]);
    plhs[0] = NULL;
  }

  return (status);
}

#ifdef MATLAB_MEX_FILE                 /* Is this file being compiled as a MEX-file? */
#include "simulink.c"                  /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"                   /* Code generation registration function */
#endif
