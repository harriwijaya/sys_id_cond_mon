/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c1_BuckBoost1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[25] = { "beta", "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel",
  "OFFSET_OFF_END_abs", "N", "w", "x", "rms", "nargin", "nargout", "start", "t",
  "duty", "v_out", "i_in", "w0_fb", "w1_fb", "Capin", "Capout", "w0", "w1", "y",
  "e" };

/* Function Declarations */
static void initialize_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void disable_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void sf_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void c1_chartstep_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static void initSimStructsc1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_e, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[29]);
static real_T c1_mpower(SFc1_BuckBoost1InstanceStruct *chartInstance, real_T
  c1_a);
static void c1_eml_scalar_eg(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void c1_check_forloop_overflow_error(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_BuckBoost1 = 0U;
}

static void initialize_params_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_Capout;
  real_T *c1_e;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_h_y;
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_h_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6), FALSE);
  c1_hoistedGlobal = *c1_Capout;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_e;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_w0;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_w1;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_h_y;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_c1_BuckBoost1;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Capout;
  real_T *c1_e;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_y;
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Capout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Capout");
  *c1_e = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "e");
  *c1_w0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "w0");
  *c1_w1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "w1");
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "y");
  chartInstance->c1_is_active_c1_BuckBoost1 = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
     "is_active_c1_BuckBoost1");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_BuckBoost1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
  real_T *c1_start;
  real_T *c1_t;
  real_T *c1_duty;
  real_T *c1_Capout;
  real_T *c1_v_out;
  real_T *c1_i_in;
  real_T *c1_w0_fb;
  real_T *c1_w1_fb;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_y;
  real_T *c1_e;
  real_T *c1_Capin;
  c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_w1_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_w0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_start, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_t, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_duty, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_Capout, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_v_out, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_i_in, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_w0_fb, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_w1_fb, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_w0, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_w1, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_y, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_e, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_Capin, 12U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_BuckBoost1(chartInstance);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_start;
  real_T c1_t;
  real_T c1_duty;
  real_T c1_v_out;
  real_T c1_i_in;
  real_T c1_w0_fb;
  real_T c1_w1_fb;
  real_T c1_Capin;
  uint32_T c1_debug_family_var_map[25];
  real_T c1_beta;
  real_T c1_offset;
  real_T c1_OFFSET_ON_START_abs;
  real_T c1_OFFSET_ON_END_rel;
  real_T c1_OFFSET_OFF_START_rel;
  real_T c1_OFFSET_OFF_END_abs;
  real_T c1_N;
  real_T c1_w[2];
  real_T c1_x[2];
  real_T c1_rms;
  real_T c1_nargin = 8.0;
  real_T c1_nargout = 5.0;
  real_T c1_Capout;
  real_T c1_w0;
  real_T c1_w1;
  real_T c1_y;
  real_T c1_e;
  int32_T c1_i0;
  int32_T c1_i1;
  real_T c1_A;
  real_T c1_b_x;
  real_T c1_c_x;
  int32_T c1_i2;
  real_T c1_a[2];
  int32_T c1_i3;
  real_T c1_b[2];
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_b_a;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T c1_B;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_d_x;
  real_T c1_e_y;
  real_T c1_e_x;
  real_T c1_f_y;
  real_T c1_g_y;
  real_T c1_c_A;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_y;
  real_T c1_c_a;
  real_T c1_i_y;
  real_T c1_d_a;
  real_T *c1_b_start;
  real_T *c1_b_t;
  real_T *c1_b_duty;
  real_T *c1_b_v_out;
  real_T *c1_b_i_in;
  real_T *c1_b_w0_fb;
  real_T *c1_b_w1_fb;
  real_T *c1_b_Capin;
  real_T *c1_b_Capout;
  real_T *c1_b_w0;
  real_T *c1_b_w1;
  real_T *c1_j_y;
  real_T *c1_b_e;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c1_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_j_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_w1_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_w0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_start;
  c1_b_hoistedGlobal = *c1_b_t;
  c1_c_hoistedGlobal = *c1_b_duty;
  c1_d_hoistedGlobal = *c1_b_v_out;
  c1_e_hoistedGlobal = *c1_b_i_in;
  c1_f_hoistedGlobal = *c1_b_w0_fb;
  c1_g_hoistedGlobal = *c1_b_w1_fb;
  c1_h_hoistedGlobal = *c1_b_Capin;
  c1_start = c1_hoistedGlobal;
  c1_t = c1_b_hoistedGlobal;
  c1_duty = c1_c_hoistedGlobal;
  c1_v_out = c1_d_hoistedGlobal;
  c1_i_in = c1_e_hoistedGlobal;
  c1_w0_fb = c1_f_hoistedGlobal;
  c1_w1_fb = c1_g_hoistedGlobal;
  c1_Capin = c1_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_beta, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_offset, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_ON_START_abs, 2U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_ON_END_rel, 3U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_OFF_START_rel, 4U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_OFF_END_abs, 5U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_N, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_x, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_rms, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_start, 12U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t, 13U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_duty, 14U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_v_out, 15U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_i_in, 16U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w0_fb, 17U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w1_fb, 18U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Capin, 19U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_Capout, 20U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w0, 21U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w1, 22U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 23U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_e, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_beta = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_offset = c1_t - c1_duty;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_Capout = c1_Capin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_N = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_w[c1_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_w[0] = c1_w0_fb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_w[1] = c1_w1_fb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_w0 = c1_w0_fb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_w1 = c1_w1_fb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_x[c1_i1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_x[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_x[1] = c1_t;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  if (CV_EML_IF(0, 1, 0, c1_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c1_t > c1_OFFSET_ON_START_abs)) {
      if (CV_EML_COND(0, 1, 1, c1_offset < c1_OFFSET_ON_END_rel)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
        c1_A = c1_mpower(chartInstance, c1_x[0]) + c1_mpower(chartInstance,
          c1_x[1]);
        c1_b_x = c1_A;
        c1_c_x = c1_b_x;
        c1_rms = c1_c_x / 2.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
        for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
          c1_a[c1_i2] = c1_w[c1_i2];
        }

        for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
          c1_b[c1_i3] = c1_x[c1_i3];
        }

        c1_b_eml_scalar_eg(chartInstance);
        c1_b_eml_scalar_eg(chartInstance);
        c1_y = 0.0;
        c1_check_forloop_overflow_error(chartInstance);
        for (c1_k = 1; c1_k < 3; c1_k++) {
          c1_b_k = c1_k;
          c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 2, 1, 0) - 1] *
            c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 2, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
        c1_e = c1_v_out - c1_y;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
        c1_b_b = c1_e;
        c1_b_y = 0.5 * c1_b_b;
        c1_b_a = c1_b_y;
        for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
          c1_b[c1_i4] = c1_x[c1_i4];
        }

        for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
          c1_b[c1_i5] *= c1_b_a;
        }

        c1_B = c1_rms;
        c1_c_y = c1_B;
        c1_d_y = c1_c_y;
        for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
          c1_b[c1_i6] /= c1_d_y;
        }

        for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
          c1_w[c1_i7] += c1_b[c1_i7];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
        c1_w0 = c1_w[0];
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
        c1_w1 = c1_w[1];
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
      if (CV_EML_IF(0, 1, 2, c1_offset >= c1_OFFSET_ON_END_rel)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
        c1_b_A = -c1_w0;
        c1_b_B = c1_w1;
        c1_d_x = c1_b_A;
        c1_e_y = c1_b_B;
        c1_e_x = c1_d_x;
        c1_f_y = c1_e_y;
        c1_g_y = c1_e_x / c1_f_y;
        c1_c_A = c1_g_y;
        c1_f_x = c1_c_A;
        c1_g_x = c1_f_x;
        c1_h_y = c1_g_x / 30.0;
        c1_c_a = c1_h_y;
        c1_i_y = c1_c_a * 1.0E-6;
        c1_d_a = c1_i_y;
        c1_Capout = c1_d_a * 1000.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
        guard2 = FALSE;
        if (CV_EML_COND(0, 1, 2, c1_offset > c1_OFFSET_OFF_START_rel)) {
          if (CV_EML_COND(0, 1, 3, c1_t < c1_OFFSET_OFF_END_abs)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
            CV_EML_IF(0, 1, 4, c1_t == c1_OFFSET_OFF_END_abs - 1.0);
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          CV_EML_MCDC(0, 1, 1, FALSE);
          CV_EML_IF(0, 1, 3, FALSE);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -56);
  sf_debug_symbol_scope_pop();
  *c1_b_Capout = c1_Capout;
  *c1_b_w0 = c1_w0;
  *c1_b_w1 = c1_w1;
  *c1_j_y = c1_y;
  *c1_b_e = c1_e;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_e, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e), &c1_thisId);
  sf_mex_destroy(&c1_e);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_e;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_e = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_e), &c1_thisId);
  sf_mex_destroy(&c1_e);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i8;
  real_T c1_b_inData[2];
  int32_T c1_i9;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_b_inData[c1_i8] = (*(real_T (*)[2])c1_inData)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
    c1_u[c1_i9] = c1_b_inData[c1_i9];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv0[2];
  int32_T c1_i10;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    c1_y[c1_i10] = c1_dv0[c1_i10];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_x;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i11;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_x = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_x), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_x);
  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    (*(real_T (*)[2])c1_outData)[c1_i11] = c1_y[c1_i11];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[29];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i12;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c1_i12 = 0; c1_i12 < 29; c1_i12++) {
    c1_r0 = &c1_info[c1_i12];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i12);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i12);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[29])
{
  c1_info[0].context = "";
  c1_info[0].name = "mpower";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[0].fileTimeLo = 1286797242U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1336500496U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286797196U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1330583234U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[4].fileTimeLo = 1286797142U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[5].name = "eml_scalar_floor";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[5].fileTimeLo = 1286797126U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "mrdivide";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[6].fileTimeLo = 1342789344U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 1319708366U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[7].name = "rdivide";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].fileTimeLo = 1286797244U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[8].name = "eml_div";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[8].fileTimeLo = 1313326210U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289494492U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "eml_index_class";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[10].fileTimeLo = 1323145378U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286797196U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].name = "eml_xdotu";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[12].fileTimeLo = 1299051572U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[13].name = "eml_blas_inline";
  c1_info[13].dominantType = "";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[13].fileTimeLo = 1299051568U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[14].name = "eml_xdot";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[14].fileTimeLo = 1299051572U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[15].name = "eml_blas_inline";
  c1_info[15].dominantType = "";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[15].fileTimeLo = 1299051568U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323145378U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[17].name = "eml_refblas_xdot";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[17].fileTimeLo = 1299051572U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[18].name = "eml_refblas_xdotx";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[18].fileTimeLo = 1299051574U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[19].name = "eml_scalar_eg";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[19].fileTimeLo = 1286797196U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[20].name = "eml_index_class";
  c1_info[20].dominantType = "";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[20].fileTimeLo = 1323145378U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[21].name = "eml_index_minus";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[21].fileTimeLo = 1286797178U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[22].name = "eml_index_class";
  c1_info[22].dominantType = "";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[22].fileTimeLo = 1323145378U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[23].name = "eml_index_times";
  c1_info[23].dominantType = "coder.internal.indexInt";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[23].fileTimeLo = 1286797180U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[24].name = "eml_index_class";
  c1_info[24].dominantType = "";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[24].fileTimeLo = 1323145378U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[25].name = "eml_index_plus";
  c1_info[25].dominantType = "coder.internal.indexInt";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[25].fileTimeLo = 1286797178U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[26].name = "eml_index_class";
  c1_info[26].dominantType = "";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[26].fileTimeLo = 1323145378U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[27].name = "eml_int_forloop_overflow_check";
  c1_info[27].dominantType = "";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[27].fileTimeLo = 1332143472U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[28].name = "intmax";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[28].fileTimeLo = 1311233716U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
}

static real_T c1_mpower(SFc1_BuckBoost1InstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_eml_scalar_eg(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c1_check_forloop_overflow_error(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i13;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i13, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i13;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_BuckBoost1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_BuckBoost1);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(989820355U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2103609750U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2670167940U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1094884300U);
}

mxArray *sf_c1_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mitZZF4sFrJ8VV3LrVGKKG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"Capout\",},{M[1],M[15],T\"e\",},{M[1],M[12],T\"w0\",},{M[1],M[13],T\"w1\",},{M[1],M[14],T\"y\",},{M[8],M[0],T\"is_active_c1_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc1_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           1,
           1,
           1,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"start");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"duty");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(4,1,1,0,"v_out");
          _SFD_SET_DATA_PROPS(5,1,1,0,"i_in");
          _SFD_SET_DATA_PROPS(6,1,1,0,"w0_fb");
          _SFD_SET_DATA_PROPS(7,1,1,0,"w1_fb");
          _SFD_SET_DATA_PROPS(8,2,0,1,"w0");
          _SFD_SET_DATA_PROPS(9,2,0,1,"w1");
          _SFD_SET_DATA_PROPS(10,2,0,1,"y");
          _SFD_SET_DATA_PROPS(11,2,0,1,"e");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Capin");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1519);
        _SFD_CV_INIT_EML_IF(0,1,0,617,629,1477,1517);
        _SFD_CV_INIT_EML_IF(0,1,1,634,691,1175,1210);
        _SFD_CV_INIT_EML_IF(0,1,2,1175,1210,1263,1476);
        _SFD_CV_INIT_EML_IF(0,1,3,1263,1326,-1,1326);
        _SFD_CV_INIT_EML_IF(0,1,4,1391,1425,-1,1468);

        {
          static int condStart[] = { 637, 664 };

          static int condEnd[] = { 660, 690 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,637,690,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1270, 1303 };

          static int condEnd[] = { 1299, 1325 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1270,1325,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_start;
          real_T *c1_t;
          real_T *c1_duty;
          real_T *c1_Capout;
          real_T *c1_v_out;
          real_T *c1_i_in;
          real_T *c1_w0_fb;
          real_T *c1_w1_fb;
          real_T *c1_w0;
          real_T *c1_w1;
          real_T *c1_y;
          real_T *c1_e;
          real_T *c1_Capin;
          c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_w1_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_w0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_start);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_duty);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Capout);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_v_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_i_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_w0_fb);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_w1_fb);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_w0);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_w1);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_e);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_Capin);
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
  return "NOpn68PndKZkm9ZoCrwAwH";
}

static void sf_opaque_initialize_c1_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_BuckBoost1(void *chartInstanceVar)
{
  enable_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_BuckBoost1(void *chartInstanceVar)
{
  disable_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_BuckBoost1(void *chartInstanceVar)
{
  sf_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_BuckBoost1
    ((SFc1_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c1_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c1_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c1_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_BuckBoost1((SFc1_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1427864384U));
  ssSetChecksum1(S,(2052318912U));
  ssSetChecksum2(S,(686716946U));
  ssSetChecksum3(S,(2603450808U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_BuckBoost1(SimStruct *S)
{
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc1_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_BuckBoost1;
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

void c1_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
