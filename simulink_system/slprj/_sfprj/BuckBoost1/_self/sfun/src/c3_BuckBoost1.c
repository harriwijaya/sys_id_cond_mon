/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c3_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[35] = { "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel",
  "OFFSET_OFF_END_abs", "lambda", "delta", "N", "w", "P", "u", "k", "nargin",
  "nargout", "start", "t", "duty", "v_out", "i_in", "w0in", "w1in", "P11in",
  "P12in", "P21in", "P22in", "Capin", "y", "e", "w0", "w1", "P11", "P12", "P21",
  "P22", "Capout" };

/* Function Declarations */
static void initialize_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void disable_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void sf_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_chartstep_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static void initSimStructsc3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_Capout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[50]);
static void c3_check_forloop_overflow_error(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static void c3_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_b_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_c_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_d_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_BuckBoost1, const char_T
  *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_BuckBoost1 = 0U;
}

static void initialize_params_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T *c3_Capout;
  real_T *c3_P11;
  real_T *c3_P12;
  real_T *c3_P21;
  real_T *c3_P22;
  real_T *c3_e;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_l_y;
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_l_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(10), FALSE);
  c3_hoistedGlobal = *c3_Capout;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_P11;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_P12;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_P21;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_P22;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_e;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *c3_w0;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *c3_w1;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *c3_l_y;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = chartInstance->c3_is_active_c3_BuckBoost1;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_Capout;
  real_T *c3_P11;
  real_T *c3_P12;
  real_T *c3_P21;
  real_T *c3_P22;
  real_T *c3_e;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_y;
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_Capout = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "Capout");
  *c3_P11 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "P11");
  *c3_P12 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "P12");
  *c3_P21 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "P21");
  *c3_P22 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
    "P22");
  *c3_e = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
    "e");
  *c3_w0 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
    "w0");
  *c3_w1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
    "w1");
  *c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)),
    "y");
  chartInstance->c3_is_active_c3_BuckBoost1 = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
     "is_active_c3_BuckBoost1");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_BuckBoost1(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
  real_T *c3_y;
  real_T *c3_e;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_P11;
  real_T *c3_P12;
  real_T *c3_P21;
  real_T *c3_P22;
  real_T *c3_Capout;
  real_T *c3_start;
  real_T *c3_t;
  real_T *c3_duty;
  real_T *c3_v_out;
  real_T *c3_i_in;
  real_T *c3_w0in;
  real_T *c3_w1in;
  real_T *c3_P11in;
  real_T *c3_P12in;
  real_T *c3_P21in;
  real_T *c3_P22in;
  real_T *c3_Capin;
  c3_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_y, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_e, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_w0, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_w1, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_P11, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_P12, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_P21, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_P22, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_Capout, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_start, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_t, 10U);
  _SFD_DATA_RANGE_CHECK(*c3_duty, 11U);
  _SFD_DATA_RANGE_CHECK(*c3_v_out, 12U);
  _SFD_DATA_RANGE_CHECK(*c3_i_in, 13U);
  _SFD_DATA_RANGE_CHECK(*c3_w0in, 14U);
  _SFD_DATA_RANGE_CHECK(*c3_w1in, 15U);
  _SFD_DATA_RANGE_CHECK(*c3_P11in, 16U);
  _SFD_DATA_RANGE_CHECK(*c3_P12in, 17U);
  _SFD_DATA_RANGE_CHECK(*c3_P21in, 18U);
  _SFD_DATA_RANGE_CHECK(*c3_P22in, 19U);
  _SFD_DATA_RANGE_CHECK(*c3_Capin, 20U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_BuckBoost1(chartInstance);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_k_hoistedGlobal;
  real_T c3_l_hoistedGlobal;
  real_T c3_start;
  real_T c3_t;
  real_T c3_duty;
  real_T c3_v_out;
  real_T c3_i_in;
  real_T c3_w0in;
  real_T c3_w1in;
  real_T c3_P11in;
  real_T c3_P12in;
  real_T c3_P21in;
  real_T c3_P22in;
  real_T c3_Capin;
  uint32_T c3_debug_family_var_map[35];
  real_T c3_offset;
  real_T c3_OFFSET_ON_START_abs;
  real_T c3_OFFSET_ON_END_rel;
  real_T c3_OFFSET_OFF_START_rel;
  real_T c3_OFFSET_OFF_END_abs;
  real_T c3_lambda;
  real_T c3_delta;
  real_T c3_N;
  real_T c3_w[2];
  real_T c3_P[4];
  real_T c3_u[2];
  real_T c3_k[2];
  real_T c3_nargin = 12.0;
  real_T c3_nargout = 9.0;
  real_T c3_y;
  real_T c3_e;
  real_T c3_w0;
  real_T c3_w1;
  real_T c3_P11;
  real_T c3_P12;
  real_T c3_P21;
  real_T c3_P22;
  real_T c3_Capout;
  int32_T c3_i0;
  int32_T c3_i1;
  static real_T c3_dv0[4] = { 100.0, 0.0, 0.0, 100.0 };

  int32_T c3_i2;
  int32_T c3_i3;
  real_T c3_a[4];
  int32_T c3_i4;
  real_T c3_b[2];
  int32_T c3_i5;
  real_T c3_b_y[2];
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  real_T c3_b_a[2];
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  real_T c3_c_y[2];
  int32_T c3_i12;
  int32_T c3_i13;
  real_T c3_d_y;
  int32_T c3_b_k;
  int32_T c3_c_k;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_e_y;
  real_T c3_B;
  real_T c3_f_y;
  real_T c3_g_y;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_d_k;
  int32_T c3_e_k;
  int32_T c3_i18;
  real_T c3_b_b;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_h_y[4];
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  real_T c3_i_y[4];
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_c_x;
  real_T c3_j_y;
  real_T c3_d_x;
  real_T c3_k_y;
  real_T c3_l_y;
  real_T c3_c_A;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_m_y;
  real_T c3_c_a;
  real_T c3_n_y;
  real_T c3_d_a;
  real_T *c3_b_start;
  real_T *c3_b_t;
  real_T *c3_b_duty;
  real_T *c3_b_v_out;
  real_T *c3_b_i_in;
  real_T *c3_b_w0in;
  real_T *c3_b_w1in;
  real_T *c3_b_P11in;
  real_T *c3_b_P12in;
  real_T *c3_b_P21in;
  real_T *c3_b_P22in;
  real_T *c3_b_Capin;
  real_T *c3_o_y;
  real_T *c3_b_e;
  real_T *c3_b_w0;
  real_T *c3_b_w1;
  real_T *c3_b_P11;
  real_T *c3_b_P12;
  real_T *c3_b_P21;
  real_T *c3_b_P22;
  real_T *c3_b_Capout;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c3_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_b_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_b_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_b_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_b_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_b_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_b_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_o_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_start;
  c3_b_hoistedGlobal = *c3_b_t;
  c3_c_hoistedGlobal = *c3_b_duty;
  c3_d_hoistedGlobal = *c3_b_v_out;
  c3_e_hoistedGlobal = *c3_b_i_in;
  c3_f_hoistedGlobal = *c3_b_w0in;
  c3_g_hoistedGlobal = *c3_b_w1in;
  c3_h_hoistedGlobal = *c3_b_P11in;
  c3_i_hoistedGlobal = *c3_b_P12in;
  c3_j_hoistedGlobal = *c3_b_P21in;
  c3_k_hoistedGlobal = *c3_b_P22in;
  c3_l_hoistedGlobal = *c3_b_Capin;
  c3_start = c3_hoistedGlobal;
  c3_t = c3_b_hoistedGlobal;
  c3_duty = c3_c_hoistedGlobal;
  c3_v_out = c3_d_hoistedGlobal;
  c3_i_in = c3_e_hoistedGlobal;
  c3_w0in = c3_f_hoistedGlobal;
  c3_w1in = c3_g_hoistedGlobal;
  c3_P11in = c3_h_hoistedGlobal;
  c3_P12in = c3_i_hoistedGlobal;
  c3_P21in = c3_j_hoistedGlobal;
  c3_P22in = c3_k_hoistedGlobal;
  c3_Capin = c3_l_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 35U, 35U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_offset, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_ON_START_abs, 1U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_ON_END_rel, 2U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_OFF_START_rel, 3U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_OFF_END_abs, 4U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_lambda, 5U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_delta, 6U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_N, 7U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_w, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_P, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_u, 10U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_k, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_start, 14U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_t, 15U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_duty, 16U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_v_out, 17U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_i_in, 18U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_w0in, 19U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_w1in, 20U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_P11in, 21U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_P12in, 22U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_P21in, 23U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_P22in, 24U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Capin, 25U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_y, 26U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_e, 27U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w0, 28U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w1, 29U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_P11, 30U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_P12, 31U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_P21, 32U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_P22, 33U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Capout, 34U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_offset = c3_t - c3_duty;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  c3_lambda = 0.6;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_delta = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_N = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    c3_w[c3_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_w[0] = c3_w0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_w[1] = c3_w1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_P[c3_i1] = c3_dv0[c3_i1];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_P[0] = c3_P11in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_P[2] = c3_P12in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_P[1] = c3_P21in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_P[3] = c3_P22in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_u[c3_i2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_u[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  c3_u[1] = c3_t;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_P11 = c3_P11in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_P12 = c3_P12in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  c3_P21 = c3_P21in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  c3_P22 = c3_P22in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  c3_Capout = c3_Capin;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
  c3_w0 = c3_w0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
  c3_w1 = c3_w1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
  if (CV_EML_IF(0, 1, 0, c3_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c3_t > c3_OFFSET_ON_START_abs)) {
      if (CV_EML_COND(0, 1, 1, c3_offset < c3_OFFSET_ON_END_rel)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
        for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
          c3_a[c3_i3] = c3_P[c3_i3];
        }

        for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
          c3_b[c3_i4] = c3_u[c3_i4];
        }

        c3_eml_scalar_eg(chartInstance);
        c3_eml_scalar_eg(chartInstance);
        for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
          c3_b_y[c3_i5] = 0.0;
          c3_i6 = 0;
          for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
            c3_b_y[c3_i5] += c3_a[c3_i6 + c3_i5] * c3_b[c3_i7];
            c3_i6 += 2;
          }
        }

        for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
          c3_b_a[c3_i8] = c3_u[c3_i8];
        }

        for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
          c3_a[c3_i9] = c3_P[c3_i9];
        }

        c3_b_eml_scalar_eg(chartInstance);
        c3_b_eml_scalar_eg(chartInstance);
        c3_i10 = 0;
        for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
          c3_c_y[c3_i11] = 0.0;
          for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
            c3_c_y[c3_i11] += c3_b_a[c3_i12] * c3_a[c3_i12 + c3_i10];
          }

          c3_i10 += 2;
        }

        for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
          c3_b[c3_i13] = c3_u[c3_i13];
        }

        c3_c_eml_scalar_eg(chartInstance);
        c3_c_eml_scalar_eg(chartInstance);
        c3_d_y = 0.0;
        c3_check_forloop_overflow_error(chartInstance);
        for (c3_b_k = 1; c3_b_k < 3; c3_b_k++) {
          c3_c_k = c3_b_k;
          c3_d_y += c3_c_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_c_k), 1, 2, 1, 0) - 1] *
            c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_c_k), 1, 2, 1, 0) - 1];
        }

        c3_A = c3_d_y;
        c3_x = c3_A;
        c3_b_x = c3_x;
        c3_e_y = c3_b_x / 0.6;
        c3_B = 1.0 + c3_e_y;
        c3_f_y = c3_B;
        c3_g_y = c3_f_y;
        for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
          c3_b_y[c3_i14] /= c3_g_y;
        }

        for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
          c3_k[c3_i15] = c3_b_y[c3_i15] / 0.6;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
        for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
          c3_b_a[c3_i16] = c3_w[c3_i16];
        }

        for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
          c3_b[c3_i17] = c3_u[c3_i17];
        }

        c3_c_eml_scalar_eg(chartInstance);
        c3_c_eml_scalar_eg(chartInstance);
        c3_y = 0.0;
        c3_check_forloop_overflow_error(chartInstance);
        for (c3_d_k = 1; c3_d_k < 3; c3_d_k++) {
          c3_e_k = c3_d_k;
          c3_y += c3_b_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_e_k), 1, 2, 1, 0) - 1] *
            c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_e_k), 1, 2, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
        c3_e = c3_v_out - c3_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
        for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
          c3_b[c3_i18] = c3_k[c3_i18];
        }

        c3_b_b = c3_e;
        for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
          c3_b[c3_i19] *= c3_b_b;
        }

        for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
          c3_w[c3_i20] += c3_b[c3_i20];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
        c3_w0 = c3_w[0];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
        c3_w1 = c3_w[1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
        for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
          c3_b[c3_i21] = c3_k[c3_i21];
        }

        for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
          c3_b_a[c3_i22] = c3_u[c3_i22];
        }

        for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
          c3_i24 = 0;
          for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
            c3_h_y[c3_i24 + c3_i23] = c3_b[c3_i23] * c3_b_a[c3_i25];
            c3_i24 += 2;
          }
        }

        for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
          c3_a[c3_i26] = c3_P[c3_i26];
        }

        c3_d_eml_scalar_eg(chartInstance);
        c3_d_eml_scalar_eg(chartInstance);
        for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
          c3_i28 = 0;
          for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
            c3_i_y[c3_i28 + c3_i27] = 0.0;
            c3_i30 = 0;
            for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
              c3_i_y[c3_i28 + c3_i27] += c3_h_y[c3_i30 + c3_i27] * c3_a[c3_i31 +
                c3_i28];
              c3_i30 += 2;
            }

            c3_i28 += 2;
          }
        }

        for (c3_i32 = 0; c3_i32 < 4; c3_i32++) {
          c3_i_y[c3_i32] = c3_P[c3_i32] - c3_i_y[c3_i32];
        }

        for (c3_i33 = 0; c3_i33 < 4; c3_i33++) {
          c3_P[c3_i33] = c3_i_y[c3_i33] / 0.6;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
        c3_P11 = c3_P[0];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
        c3_P12 = c3_P[2];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
        c3_P21 = c3_P[1];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
        c3_P22 = c3_P[3];
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
      if (CV_EML_IF(0, 1, 2, c3_offset >= c3_OFFSET_ON_END_rel)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
        c3_b_A = -c3_w0;
        c3_b_B = c3_w1;
        c3_c_x = c3_b_A;
        c3_j_y = c3_b_B;
        c3_d_x = c3_c_x;
        c3_k_y = c3_j_y;
        c3_l_y = c3_d_x / c3_k_y;
        c3_c_A = c3_l_y;
        c3_e_x = c3_c_A;
        c3_f_x = c3_e_x;
        c3_m_y = c3_f_x / 30.0;
        c3_c_a = c3_m_y;
        c3_n_y = c3_c_a * 1.0E-6;
        c3_d_a = c3_n_y;
        c3_Capout = c3_d_a * 1000.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
        guard2 = FALSE;
        if (CV_EML_COND(0, 1, 2, c3_offset > c3_OFFSET_OFF_START_rel)) {
          if (CV_EML_COND(0, 1, 3, c3_t < c3_OFFSET_OFF_END_abs)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
            CV_EML_IF(0, 1, 4, c3_t == c3_OFFSET_OFF_END_abs - 1.0);
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

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -66);
  sf_debug_symbol_scope_pop();
  *c3_o_y = c3_y;
  *c3_b_e = c3_e;
  *c3_b_w0 = c3_w0;
  *c3_b_w1 = c3_w1;
  *c3_b_P11 = c3_P11;
  *c3_b_P12 = c3_P12;
  *c3_b_P21 = c3_P21;
  *c3_b_P22 = c3_P22;
  *c3_b_Capout = c3_Capout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_Capout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Capout), &c3_thisId);
  sf_mex_destroy(&c3_Capout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Capout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_Capout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Capout), &c3_thisId);
  sf_mex_destroy(&c3_Capout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i34;
  real_T c3_b_inData[2];
  int32_T c3_i35;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    c3_b_inData[c3_i34] = (*(real_T (*)[2])c3_inData)[c3_i34];
  }

  for (c3_i35 = 0; c3_i35 < 2; c3_i35++) {
    c3_u[c3_i35] = c3_b_inData[c3_i35];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i36;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i36 = 0; c3_i36 < 2; c3_i36++) {
    c3_y[c3_i36] = c3_dv1[c3_i36];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_k;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i37;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_k = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_k), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_k);
  for (c3_i37 = 0; c3_i37 < 2; c3_i37++) {
    (*(real_T (*)[2])c3_outData)[c3_i37] = c3_y[c3_i37];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  real_T c3_b_inData[4];
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
    for (c3_i40 = 0; c3_i40 < 2; c3_i40++) {
      c3_b_inData[c3_i40 + c3_i38] = (*(real_T (*)[4])c3_inData)[c3_i40 + c3_i38];
    }

    c3_i38 += 2;
  }

  c3_i41 = 0;
  for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
    for (c3_i43 = 0; c3_i43 < 2; c3_i43++) {
      c3_u[c3_i43 + c3_i41] = c3_b_inData[c3_i43 + c3_i41];
    }

    c3_i41 += 2;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv2[4];
  int32_T c3_i44;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c3_i44 = 0; c3_i44 < 4; c3_i44++) {
    c3_y[c3_i44] = c3_dv2[c3_i44];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_P;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_P = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_P), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_P);
  c3_i45 = 0;
  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
      (*(real_T (*)[4])c3_outData)[c3_i47 + c3_i45] = c3_y[c3_i47 + c3_i45];
    }

    c3_i45 += 2;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[50];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i48;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 50), FALSE);
  for (c3_i48 = 0; c3_i48 < 50; c3_i48++) {
    c3_r0 = &c3_info[c3_i48];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i48);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i48);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[50])
{
  c3_info[0].context = "";
  c3_info[0].name = "mrdivide";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[0].fileTimeLo = 1342789344U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 1319708366U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].name = "rdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[1].fileTimeLo = 1286797244U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].name = "eml_div";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[2].fileTimeLo = 1313326210U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "eye";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c3_info[3].fileTimeLo = 1286797088U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[4].name = "eml_assert_valid_size_arg";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[4].fileTimeLo = 1286797094U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c3_info[5].name = "isinf";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[5].fileTimeLo = 1286797160U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c3_info[6].name = "mtimes";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].fileTimeLo = 1289494492U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[7].name = "eml_index_class";
  c3_info[7].dominantType = "";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[7].fileTimeLo = 1323145378U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[8].name = "intmax";
  c3_info[8].dominantType = "char";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[8].fileTimeLo = 1311233716U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[9].name = "eml_is_float_class";
  c3_info[9].dominantType = "char";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[9].fileTimeLo = 1286797182U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[10].name = "min";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[10].fileTimeLo = 1311233718U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[11].name = "eml_min_or_max";
  c3_info[11].dominantType = "char";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[11].fileTimeLo = 1334049890U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[12].name = "eml_scalar_eg";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[12].fileTimeLo = 1286797196U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[13].name = "eml_scalexp_alloc";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[13].fileTimeLo = 1330583234U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[14].name = "eml_index_class";
  c3_info[14].dominantType = "";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[14].fileTimeLo = 1323145378U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c3_info[15].name = "eml_scalar_eg";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[15].fileTimeLo = 1286797196U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[16].name = "eml_index_class";
  c3_info[16].dominantType = "";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[16].fileTimeLo = 1323145378U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[17].name = "eml_int_forloop_overflow_check";
  c3_info[17].dominantType = "";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[17].fileTimeLo = 1332143472U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[18].name = "intmax";
  c3_info[18].dominantType = "char";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[18].fileTimeLo = 1311233716U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "mtimes";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[19].fileTimeLo = 1289494492U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[20].name = "eml_index_class";
  c3_info[20].dominantType = "";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[20].fileTimeLo = 1323145378U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[21].name = "eml_scalar_eg";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[21].fileTimeLo = 1286797196U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[22].name = "eml_xgemm";
  c3_info[22].dominantType = "char";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[22].fileTimeLo = 1299051572U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[23].name = "eml_blas_inline";
  c3_info[23].dominantType = "";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[23].fileTimeLo = 1299051568U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[24].name = "mtimes";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[24].fileTimeLo = 1289494492U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[25].name = "eml_index_class";
  c3_info[25].dominantType = "";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[25].fileTimeLo = 1323145378U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[26].name = "eml_scalar_eg";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[26].fileTimeLo = 1286797196U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[27].name = "eml_refblas_xgemm";
  c3_info[27].dominantType = "char";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[27].fileTimeLo = 1299051574U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[28].name = "eml_xdotu";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[28].fileTimeLo = 1299051572U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[29].name = "eml_blas_inline";
  c3_info[29].dominantType = "";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[29].fileTimeLo = 1299051568U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[30].name = "eml_xdot";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[30].fileTimeLo = 1299051572U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[31].name = "eml_blas_inline";
  c3_info[31].dominantType = "";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[31].fileTimeLo = 1299051568U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[32].name = "eml_index_class";
  c3_info[32].dominantType = "";
  c3_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[32].fileTimeLo = 1323145378U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[33].name = "eml_refblas_xdot";
  c3_info[33].dominantType = "double";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[33].fileTimeLo = 1299051572U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[34].name = "eml_refblas_xdotx";
  c3_info[34].dominantType = "char";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[34].fileTimeLo = 1299051574U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[35].name = "eml_scalar_eg";
  c3_info[35].dominantType = "double";
  c3_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[35].fileTimeLo = 1286797196U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[36].name = "eml_index_class";
  c3_info[36].dominantType = "";
  c3_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[36].fileTimeLo = 1323145378U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[37].name = "eml_index_minus";
  c3_info[37].dominantType = "double";
  c3_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[37].fileTimeLo = 1286797178U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[38].name = "eml_index_class";
  c3_info[38].dominantType = "";
  c3_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[38].fileTimeLo = 1323145378U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[39].name = "eml_index_times";
  c3_info[39].dominantType = "coder.internal.indexInt";
  c3_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[39].fileTimeLo = 1286797180U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[40].name = "eml_index_class";
  c3_info[40].dominantType = "";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[40].fileTimeLo = 1323145378U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[41].name = "eml_index_plus";
  c3_info[41].dominantType = "coder.internal.indexInt";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[41].fileTimeLo = 1286797178U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[42].name = "eml_index_class";
  c3_info[42].dominantType = "";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[42].fileTimeLo = 1323145378U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[43].name = "eml_int_forloop_overflow_check";
  c3_info[43].dominantType = "";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[43].fileTimeLo = 1332143472U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context = "";
  c3_info[44].name = "mpower";
  c3_info[44].dominantType = "double";
  c3_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[44].fileTimeLo = 1286797242U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[45].name = "power";
  c3_info[45].dominantType = "double";
  c3_info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[45].fileTimeLo = 1336500496U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[46].name = "eml_scalar_eg";
  c3_info[46].dominantType = "double";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[46].fileTimeLo = 1286797196U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[47].name = "eml_scalexp_alloc";
  c3_info[47].dominantType = "double";
  c3_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[47].fileTimeLo = 1330583234U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[48].name = "floor";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[48].fileTimeLo = 1286797142U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[49].name = "eml_scalar_floor";
  c3_info[49].dominantType = "double";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[49].fileTimeLo = 1286797126U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
}

static void c3_check_forloop_overflow_error(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void c3_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c3_b_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c3_c_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c3_d_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i49;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i49, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i49;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_BuckBoost1, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_BuckBoost1), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_BuckBoost1);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(269332921U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2549505258U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2781186786U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(598636979U);
}

mxArray *sf_c3_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3TrCNJBAFLS0TtIbUzr6uB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[17],T\"Capout\",},{M[1],M[21],T\"P11\",},{M[1],M[22],T\"P12\",},{M[1],M[23],T\"P21\",},{M[1],M[24],T\"P22\",},{M[1],M[20],T\"e\",},{M[1],M[18],T\"w0\",},{M[1],M[19],T\"w1\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc3_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           3,
           1,
           1,
           21,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,2,0,1,"e");
          _SFD_SET_DATA_PROPS(2,2,0,1,"w0");
          _SFD_SET_DATA_PROPS(3,2,0,1,"w1");
          _SFD_SET_DATA_PROPS(4,2,0,1,"P11");
          _SFD_SET_DATA_PROPS(5,2,0,1,"P12");
          _SFD_SET_DATA_PROPS(6,2,0,1,"P21");
          _SFD_SET_DATA_PROPS(7,2,0,1,"P22");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(9,1,1,0,"start");
          _SFD_SET_DATA_PROPS(10,1,1,0,"t");
          _SFD_SET_DATA_PROPS(11,1,1,0,"duty");
          _SFD_SET_DATA_PROPS(12,1,1,0,"v_out");
          _SFD_SET_DATA_PROPS(13,1,1,0,"i_in");
          _SFD_SET_DATA_PROPS(14,1,1,0,"w0in");
          _SFD_SET_DATA_PROPS(15,1,1,0,"w1in");
          _SFD_SET_DATA_PROPS(16,1,1,0,"P11in");
          _SFD_SET_DATA_PROPS(17,1,1,0,"P12in");
          _SFD_SET_DATA_PROPS(18,1,1,0,"P21in");
          _SFD_SET_DATA_PROPS(19,1,1,0,"P22in");
          _SFD_SET_DATA_PROPS(20,1,1,0,"Capin");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1643);
        _SFD_CV_INIT_EML_IF(0,1,0,831,843,1600,1640);
        _SFD_CV_INIT_EML_IF(0,1,1,848,905,1298,1333);
        _SFD_CV_INIT_EML_IF(0,1,2,1298,1333,1386,1599);
        _SFD_CV_INIT_EML_IF(0,1,3,1386,1449,-1,1449);
        _SFD_CV_INIT_EML_IF(0,1,4,1514,1548,-1,1591);

        {
          static int condStart[] = { 851, 878 };

          static int condEnd[] = { 874, 904 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,851,904,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1393, 1426 };

          static int condEnd[] = { 1422, 1448 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1393,1448,2,2,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_y;
          real_T *c3_e;
          real_T *c3_w0;
          real_T *c3_w1;
          real_T *c3_P11;
          real_T *c3_P12;
          real_T *c3_P21;
          real_T *c3_P22;
          real_T *c3_Capout;
          real_T *c3_start;
          real_T *c3_t;
          real_T *c3_duty;
          real_T *c3_v_out;
          real_T *c3_i_in;
          real_T *c3_w0in;
          real_T *c3_w1in;
          real_T *c3_P11in;
          real_T *c3_P12in;
          real_T *c3_P21in;
          real_T *c3_P22in;
          real_T *c3_Capin;
          c3_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c3_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c3_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c3_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c3_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c3_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c3_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c3_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_e);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_w0);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_w1);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_P11);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_P12);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_P21);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_P22);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_Capout);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_start);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_duty);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_v_out);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_i_in);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_w0in);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_w1in);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_P11in);
          _SFD_SET_DATA_VALUE_PTR(17U, c3_P12in);
          _SFD_SET_DATA_VALUE_PTR(18U, c3_P21in);
          _SFD_SET_DATA_VALUE_PTR(19U, c3_P22in);
          _SFD_SET_DATA_VALUE_PTR(20U, c3_Capin);
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
  return "GRO60pB54t5AWouTGxpEKD";
}

static void sf_opaque_initialize_c3_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_BuckBoost1(void *chartInstanceVar)
{
  enable_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_BuckBoost1(void *chartInstanceVar)
{
  disable_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_BuckBoost1(void *chartInstanceVar)
{
  sf_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_BuckBoost1
    ((SFc3_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c3_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c3_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c3_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_BuckBoost1((SFc3_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
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
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,12);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,9);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(393553338U));
  ssSetChecksum1(S,(2994296147U));
  ssSetChecksum2(S,(778131680U));
  ssSetChecksum3(S,(2158721429U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_BuckBoost1(SimStruct *S)
{
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc3_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_BuckBoost1;
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

void c3_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}