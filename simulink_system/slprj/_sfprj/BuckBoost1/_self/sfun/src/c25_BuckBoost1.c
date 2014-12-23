/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c25_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c25_debug_family_names[7] = { "Tsimulation", "CNT_Ts",
  "nargin", "nargout", "Ts", "TimeCNT_k1", "TimeCNT_k" };

/* Function Declarations */
static void initialize_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance);
static void disable_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance);
static void c25_update_debugger_state_c25_BuckBoost1
  (SFc25_BuckBoost1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_BuckBoost1
  (SFc25_BuckBoost1InstanceStruct *chartInstance);
static void set_sim_state_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_st);
static void finalize_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance);
static void sf_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance);
static void initSimStructsc25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c25_TimeCNT_k, const char_T *c25_identifier);
static real_T c25_b_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_c_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_d_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_BuckBoost1, const char_T
  *c25_identifier);
static uint8_T c25_e_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void init_dsm_address_info(SFc25_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c25_is_active_c25_BuckBoost1 = 0U;
}

static void initialize_params_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c25_update_debugger_state_c25_BuckBoost1
  (SFc25_BuckBoost1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c25_BuckBoost1
  (SFc25_BuckBoost1InstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  real_T c25_hoistedGlobal;
  real_T c25_u;
  const mxArray *c25_b_y = NULL;
  uint8_T c25_b_hoistedGlobal;
  uint8_T c25_b_u;
  const mxArray *c25_c_y = NULL;
  real_T *c25_TimeCNT_k;
  c25_TimeCNT_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellarray(2), FALSE);
  c25_hoistedGlobal = *c25_TimeCNT_k;
  c25_u = c25_hoistedGlobal;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_b_hoistedGlobal = chartInstance->c25_is_active_c25_BuckBoost1;
  c25_b_u = c25_b_hoistedGlobal;
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", &c25_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c25_y, 1, c25_c_y);
  sf_mex_assign(&c25_st, c25_y, FALSE);
  return c25_st;
}

static void set_sim_state_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_st)
{
  const mxArray *c25_u;
  real_T *c25_TimeCNT_k;
  c25_TimeCNT_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c25_doneDoubleBufferReInit = TRUE;
  c25_u = sf_mex_dup(c25_st);
  *c25_TimeCNT_k = c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c25_u, 0)), "TimeCNT_k");
  chartInstance->c25_is_active_c25_BuckBoost1 = c25_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 1)),
     "is_active_c25_BuckBoost1");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_BuckBoost1(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void sf_c25_BuckBoost1(SFc25_BuckBoost1InstanceStruct *chartInstance)
{
  real_T c25_hoistedGlobal;
  real_T c25_b_hoistedGlobal;
  real_T c25_Ts;
  real_T c25_TimeCNT_k1;
  uint32_T c25_debug_family_var_map[7];
  real_T c25_Tsimulation;
  real_T c25_CNT_Ts;
  real_T c25_nargin = 2.0;
  real_T c25_nargout = 1.0;
  real_T c25_TimeCNT_k;
  real_T c25_A;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_y;
  real_T *c25_b_TimeCNT_k1;
  real_T *c25_b_Ts;
  real_T *c25_b_TimeCNT_k;
  c25_b_TimeCNT_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_b_TimeCNT_k1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c25_b_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c25_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c25_b_Ts, 0U);
  _SFD_DATA_RANGE_CHECK(*c25_b_TimeCNT_k1, 1U);
  _SFD_DATA_RANGE_CHECK(*c25_b_TimeCNT_k, 2U);
  chartInstance->c25_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c25_sfEvent);
  c25_hoistedGlobal = *c25_b_Ts;
  c25_b_hoistedGlobal = *c25_b_TimeCNT_k1;
  c25_Ts = c25_hoistedGlobal;
  c25_TimeCNT_k1 = c25_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c25_debug_family_names,
    c25_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c25_Tsimulation, 0U, c25_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c25_CNT_Ts, 1U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c25_nargin, 2U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c25_nargout, 3U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c25_Ts, 4U, c25_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c25_TimeCNT_k1, 5U, c25_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c25_TimeCNT_k, 6U,
    c25_sf_marshallOut, c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 3);
  c25_Tsimulation = 1.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 4);
  c25_A = c25_Ts;
  c25_x = c25_A;
  c25_b_x = c25_x;
  c25_y = c25_b_x / 1.0E-5;
  c25_CNT_Ts = c25_y - 1.0;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c25_TimeCNT_k1 >= c25_CNT_Ts)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 7);
    c25_TimeCNT_k = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 9);
    c25_TimeCNT_k = c25_TimeCNT_k1 + 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c25_b_TimeCNT_k = c25_TimeCNT_k;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c25_sfEvent);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc25_BuckBoost1(SFc25_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber)
{
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc25_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, FALSE);
  return c25_mxArrayOutData;
}

static real_T c25_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c25_TimeCNT_k, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_TimeCNT_k),
    &c25_thisId);
  sf_mex_destroy(&c25_TimeCNT_k);
  return c25_y;
}

static real_T c25_b_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_TimeCNT_k;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc25_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c25_TimeCNT_k = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_TimeCNT_k),
    &c25_thisId);
  sf_mex_destroy(&c25_TimeCNT_k);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo;
  c25_ResolvedFunctionInfo c25_info[3];
  c25_ResolvedFunctionInfo (*c25_b_info)[3];
  const mxArray *c25_m0 = NULL;
  int32_T c25_i0;
  c25_ResolvedFunctionInfo *c25_r0;
  c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  c25_b_info = (c25_ResolvedFunctionInfo (*)[3])c25_info;
  (*c25_b_info)[0].context = "";
  (*c25_b_info)[0].name = "mrdivide";
  (*c25_b_info)[0].dominantType = "double";
  (*c25_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c25_b_info)[0].fileTimeLo = 1342789344U;
  (*c25_b_info)[0].fileTimeHi = 0U;
  (*c25_b_info)[0].mFileTimeLo = 1319708366U;
  (*c25_b_info)[0].mFileTimeHi = 0U;
  (*c25_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c25_b_info)[1].name = "rdivide";
  (*c25_b_info)[1].dominantType = "double";
  (*c25_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c25_b_info)[1].fileTimeLo = 1286797244U;
  (*c25_b_info)[1].fileTimeHi = 0U;
  (*c25_b_info)[1].mFileTimeLo = 0U;
  (*c25_b_info)[1].mFileTimeHi = 0U;
  (*c25_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c25_b_info)[2].name = "eml_div";
  (*c25_b_info)[2].dominantType = "double";
  (*c25_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c25_b_info)[2].fileTimeLo = 1313326210U;
  (*c25_b_info)[2].fileTimeHi = 0U;
  (*c25_b_info)[2].mFileTimeLo = 0U;
  (*c25_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c25_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c25_i0 = 0; c25_i0 < 3; c25_i0++) {
    c25_r0 = &c25_info[c25_i0];
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c25_r0->context)), "context", "nameCaptureInfo",
                    c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c25_r0->name)), "name", "nameCaptureInfo", c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo",
      c25_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c25_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", c25_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c25_r0->resolved)), "resolved",
                    "nameCaptureInfo", c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", &c25_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo", &c25_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo",
      &c25_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c25_i0);
    sf_mex_addfield(c25_m0, sf_mex_create("nameCaptureInfo",
      &c25_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c25_i0);
  }

  sf_mex_assign(&c25_nameCaptureInfo, c25_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c25_nameCaptureInfo);
  return c25_nameCaptureInfo;
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc25_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, FALSE);
  return c25_mxArrayOutData;
}

static int32_T c25_c_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i1;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i1, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i1;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc25_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_d_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_BuckBoost1, const char_T
  *c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_BuckBoost1), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_BuckBoost1);
  return c25_y;
}

static uint8_T c25_e_emlrt_marshallIn(SFc25_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void init_dsm_address_info(SFc25_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c25_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1151654355U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1465901815U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(312290761U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2068377232U);
}

mxArray *sf_c25_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lpnlO8BtiXYSmZyCjlZFp");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c25_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"TimeCNT_k\",},{M[8],M[0],T\"is_active_c25_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc25_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           25,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_BuckBoost1MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_BuckBoost1MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_BuckBoost1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ts");
          _SFD_SET_DATA_PROPS(1,1,1,0,"TimeCNT_k1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"TimeCNT_k");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,209);
        _SFD_CV_INIT_EML_IF(0,1,0,126,148,166,204);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)c25_sf_marshallIn);

        {
          real_T *c25_Ts;
          real_T *c25_TimeCNT_k1;
          real_T *c25_TimeCNT_k;
          c25_TimeCNT_k = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c25_TimeCNT_k1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c25_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c25_Ts);
          _SFD_SET_DATA_VALUE_PTR(1U, c25_TimeCNT_k1);
          _SFD_SET_DATA_VALUE_PTR(2U, c25_TimeCNT_k);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_BuckBoost1MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "FQTxDORiBn40nYcim4GFOF";
}

static void sf_opaque_initialize_c25_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c25_BuckBoost1(void *chartInstanceVar)
{
  enable_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_BuckBoost1(void *chartInstanceVar)
{
  disable_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c25_BuckBoost1(void *chartInstanceVar)
{
  sf_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c25_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c25_BuckBoost1
    ((SFc25_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c25_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c25_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c25_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c25_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c25_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c25_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c25_BuckBoost1((SFc25_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,25,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3340803943U));
  ssSetChecksum1(S,(789118912U));
  ssSetChecksum2(S,(300216974U));
  ssSetChecksum3(S,(1788406872U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_BuckBoost1(SimStruct *S)
{
  SFc25_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc25_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc25_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c25_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c25_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c25_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c25_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c25_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c25_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c25_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c25_BuckBoost1;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c25_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
