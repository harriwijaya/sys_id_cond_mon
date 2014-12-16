/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c4_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[18] = { "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "nargin", "nargout", "start", "t",
  "duty", "v_out", "i_in", "w0_fb", "w1_fb", "Capin", "t0_fb", "Capout", "w0",
  "w1", "t0" };

/* Function Declarations */
static void initialize_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance);
static void disable_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance);
static void sf_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance);
static void initSimStructsc4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c4_t0, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_BuckBoost1, const char_T
  *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_BuckBoost1 = 0U;
}

static void initialize_params_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_Capout;
  real_T *c4_t0;
  real_T *c4_w0;
  real_T *c4_w1;
  c4_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  c4_hoistedGlobal = *c4_Capout;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_t0;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_w0;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_w1;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_active_c4_BuckBoost1;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_Capout;
  real_T *c4_t0;
  real_T *c4_w0;
  real_T *c4_w1;
  c4_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_Capout = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "Capout");
  *c4_t0 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "t0");
  *c4_w0 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
    "w0");
  *c4_w1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "w1");
  chartInstance->c4_is_active_c4_BuckBoost1 = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
     "is_active_c4_BuckBoost1");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_BuckBoost1(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c4_BuckBoost1(SFc4_BuckBoost1InstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_g_hoistedGlobal;
  real_T c4_h_hoistedGlobal;
  real_T c4_i_hoistedGlobal;
  real_T c4_start;
  real_T c4_t;
  real_T c4_duty;
  real_T c4_v_out;
  real_T c4_i_in;
  real_T c4_w0_fb;
  real_T c4_w1_fb;
  real_T c4_Capin;
  real_T c4_t0_fb;
  uint32_T c4_debug_family_var_map[18];
  real_T c4_offset;
  real_T c4_OFFSET_ON_START_abs;
  real_T c4_OFFSET_ON_END_rel;
  real_T c4_nargin = 9.0;
  real_T c4_nargout = 4.0;
  real_T c4_Capout;
  real_T c4_w0;
  real_T c4_w1;
  real_T c4_t0;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_y;
  real_T c4_c_A;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_a;
  real_T c4_g_y;
  real_T c4_b_a;
  real_T *c4_b_t0;
  real_T *c4_b_w1;
  real_T *c4_b_w0;
  real_T *c4_b_Capout;
  real_T *c4_b_t0_fb;
  real_T *c4_b_Capin;
  real_T *c4_b_w1_fb;
  real_T *c4_b_w0_fb;
  real_T *c4_b_i_in;
  real_T *c4_b_v_out;
  real_T *c4_b_duty;
  real_T *c4_b_t;
  real_T *c4_b_start;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c4_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_t0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c4_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c4_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_w1_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c4_b_w0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_start, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_b_t, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_duty, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Capout, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_v_out, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_i_in, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_b_w0_fb, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_b_w1_fb, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_b_w0, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_b_w1, 9U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Capin, 10U);
  _SFD_DATA_RANGE_CHECK(*c4_b_t0_fb, 11U);
  _SFD_DATA_RANGE_CHECK(*c4_b_t0, 12U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_start;
  c4_b_hoistedGlobal = *c4_b_t;
  c4_c_hoistedGlobal = *c4_b_duty;
  c4_d_hoistedGlobal = *c4_b_v_out;
  c4_e_hoistedGlobal = *c4_b_i_in;
  c4_f_hoistedGlobal = *c4_b_w0_fb;
  c4_g_hoistedGlobal = *c4_b_w1_fb;
  c4_h_hoistedGlobal = *c4_b_Capin;
  c4_i_hoistedGlobal = *c4_b_t0_fb;
  c4_start = c4_hoistedGlobal;
  c4_t = c4_b_hoistedGlobal;
  c4_duty = c4_c_hoistedGlobal;
  c4_v_out = c4_d_hoistedGlobal;
  c4_i_in = c4_e_hoistedGlobal;
  c4_w0_fb = c4_f_hoistedGlobal;
  c4_w1_fb = c4_g_hoistedGlobal;
  c4_Capin = c4_h_hoistedGlobal;
  c4_t0_fb = c4_i_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_offset, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_OFFSET_ON_START_abs, 1U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_OFFSET_ON_END_rel, 2U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_start, 5U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_t, 6U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_duty, 7U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_v_out, 8U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_i_in, 9U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_w0_fb, 10U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_w1_fb, 11U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_Capin, 12U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_t0_fb, 13U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_Capout, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_w0, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_w1, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_t0, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_offset = c4_t - c4_duty;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_Capout = c4_Capin;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_w0 = c4_w0_fb;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_w1 = c4_w1_fb;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  c4_t0 = c4_t0_fb;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  if (CV_EML_IF(0, 1, 0, c4_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c4_t >= c4_OFFSET_ON_START_abs)) {
      guard1 = TRUE;
    } else if (CV_EML_COND(0, 1, 1, c4_t <= c4_OFFSET_ON_START_abs - 2.0)) {
      guard1 = TRUE;
    } else {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
      guard2 = FALSE;
      if (CV_EML_COND(0, 1, 2, c4_offset <= c4_OFFSET_ON_END_rel - 1.0)) {
        guard2 = TRUE;
      } else if (CV_EML_COND(0, 1, 3, c4_offset >= c4_OFFSET_ON_END_rel)) {
        guard2 = TRUE;
      } else {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 2, FALSE);
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 1, TRUE);
        CV_EML_IF(0, 1, 2, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
        c4_A = c4_v_out - c4_w0;
        c4_B = c4_t - c4_t0;
        c4_x = c4_A;
        c4_y = c4_B;
        c4_b_x = c4_x;
        c4_b_y = c4_y;
        c4_w1 = c4_b_x / c4_b_y;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
        c4_b_A = -c4_w0;
        c4_b_B = c4_w1;
        c4_c_x = c4_b_A;
        c4_c_y = c4_b_B;
        c4_d_x = c4_c_x;
        c4_d_y = c4_c_y;
        c4_e_y = c4_d_x / c4_d_y;
        c4_c_A = c4_e_y;
        c4_e_x = c4_c_A;
        c4_f_x = c4_e_x;
        c4_f_y = c4_f_x / 30.0;
        c4_a = c4_f_y;
        c4_g_y = c4_a * 1.0E-6;
        c4_b_a = c4_g_y;
        c4_Capout = c4_b_a * 1000.0;
      }
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
      c4_w0 = c4_v_out;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
      c4_t0 = c4_t;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -28);
  sf_debug_symbol_scope_pop();
  *c4_b_Capout = c4_Capout;
  *c4_b_w0 = c4_w0;
  *c4_b_w1 = c4_w1;
  *c4_b_t0 = c4_t0;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_BuckBoost1(SFc4_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc4_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c4_t0, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_t0), &c4_thisId);
  sf_mex_destroy(&c4_t0);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_t0;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc4_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c4_t0 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_t0), &c4_thisId);
  sf_mex_destroy(&c4_t0);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[10];
  c4_ResolvedFunctionInfo (*c4_b_info)[10];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[10])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mrdivide";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[0].fileTimeLo = 1342789344U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 1319708366U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].name = "rdivide";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[1].fileTimeLo = 1286797244U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].name = "eml_div";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[2].fileTimeLo = 1313326210U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context = "";
  (*c4_b_info)[3].name = "mpower";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c4_b_info)[3].fileTimeLo = 1286797242U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c4_b_info)[4].name = "power";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c4_b_info)[4].fileTimeLo = 1336500496U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c4_b_info)[5].name = "eml_scalar_eg";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c4_b_info)[5].fileTimeLo = 1286797196U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 0U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c4_b_info)[6].name = "eml_scalexp_alloc";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c4_b_info)[6].fileTimeLo = 1330583234U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  (*c4_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c4_b_info)[7].name = "floor";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[7].fileTimeLo = 1286797142U;
  (*c4_b_info)[7].fileTimeHi = 0U;
  (*c4_b_info)[7].mFileTimeLo = 0U;
  (*c4_b_info)[7].mFileTimeHi = 0U;
  (*c4_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c4_b_info)[8].name = "eml_scalar_floor";
  (*c4_b_info)[8].dominantType = "double";
  (*c4_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c4_b_info)[8].fileTimeLo = 1286797126U;
  (*c4_b_info)[8].fileTimeHi = 0U;
  (*c4_b_info)[8].mFileTimeLo = 0U;
  (*c4_b_info)[8].mFileTimeHi = 0U;
  (*c4_b_info)[9].context = "";
  (*c4_b_info)[9].name = "mtimes";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[9].fileTimeLo = 1289494492U;
  (*c4_b_info)[9].fileTimeHi = 0U;
  (*c4_b_info)[9].mFileTimeLo = 0U;
  (*c4_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c4_i0 = 0; c4_i0 < 10; c4_i0++) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc4_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc4_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_BuckBoost1, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_BuckBoost1), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_BuckBoost1);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(859292377U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1251413196U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(978050670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(517683938U);
}

mxArray *sf_c4_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3MkXAfifGe4Na5xz0vVtlD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"Capout\",},{M[1],M[18],T\"t0\",},{M[1],M[12],T\"w0\",},{M[1],M[13],T\"w1\",},{M[8],M[0],T\"is_active_c4_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc4_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(10,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(11,1,1,0,"t0_fb");
          _SFD_SET_DATA_PROPS(12,2,0,1,"t0");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,829);
        _SFD_CV_INIT_EML_IF(0,1,0,512,524,787,827);
        _SFD_CV_INIT_EML_IF(0,1,1,529,585,626,694);
        _SFD_CV_INIT_EML_IF(0,1,2,626,694,-1,694);

        {
          static int condStart[] = { 532, 560 };

          static int condEnd[] = { 556, 584 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,532,584,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 633, 666 };

          static int condEnd[] = { 662, 693 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,633,693,2,2,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_start;
          real_T *c4_t;
          real_T *c4_duty;
          real_T *c4_Capout;
          real_T *c4_v_out;
          real_T *c4_i_in;
          real_T *c4_w0_fb;
          real_T *c4_w1_fb;
          real_T *c4_w0;
          real_T *c4_w1;
          real_T *c4_Capin;
          real_T *c4_t0_fb;
          real_T *c4_t0;
          c4_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_t0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c4_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c4_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_w1_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c4_w0_fb = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c4_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_start);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_t);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_duty);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_Capout);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_v_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_i_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_w0_fb);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_w1_fb);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_w0);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_w1);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_Capin);
          _SFD_SET_DATA_VALUE_PTR(11U, c4_t0_fb);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_t0);
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
  return "3kpC1mtGTW5k6uCHDSYdrF";
}

static void sf_opaque_initialize_c4_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_BuckBoost1(void *chartInstanceVar)
{
  enable_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_BuckBoost1(void *chartInstanceVar)
{
  disable_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_BuckBoost1(void *chartInstanceVar)
{
  sf_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_BuckBoost1
    ((SFc4_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c4_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c4_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c4_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_BuckBoost1((SFc4_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1588316606U));
  ssSetChecksum1(S,(3994570555U));
  ssSetChecksum2(S,(2125597066U));
  ssSetChecksum3(S,(4107297461U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_BuckBoost1(SimStruct *S)
{
  SFc4_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc4_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc4_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_BuckBoost1;
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

void c4_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
