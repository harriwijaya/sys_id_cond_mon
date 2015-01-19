/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c6_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[45] = { "sampling_time_base", "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel",
  "OFFSET_OFF_END_abs", "STEPS", "SP_Num", "SP_ON_min", "SP_ON_max",
  "SP_ON_list", "SP_OFF_max", "SP_OFF_min", "SP_OFF_list", "sampling_time",
  "del_v", "del_t", "slope_v", "d", "u", "del_i", "slope_i", "nargin", "nargout",
  "start", "t", "duty", "v_out", "i_in", "vk", "ik", "Capin", "ESRin", "t0in",
  "cntin", "cntin1", "tk", "vkout", "ikout", "Capout", "ESRout", "t0", "cnt",
  "cnt1", "tkout" };

/* Function Declarations */
static void initialize_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance);
static void disable_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance);
static void sf_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance);
static void c6_chartstep_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance);
static void initSimStructsc6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_tkout, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[35]);
static void c6_realmax(SFc6_BuckBoost1InstanceStruct *chartInstance);
static boolean_T c6_any(SFc6_BuckBoost1InstanceStruct *chartInstance, boolean_T
  c6_x[4]);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_BuckBoost1, const char_T
  *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_BuckBoost1 = 0U;
}

static void initialize_params_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_c_hoistedGlobal;
  real_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T c6_d_hoistedGlobal;
  real_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  real_T c6_e_hoistedGlobal;
  real_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  real_T c6_f_hoistedGlobal;
  real_T c6_f_u;
  const mxArray *c6_g_y = NULL;
  real_T c6_g_hoistedGlobal;
  real_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  real_T c6_h_hoistedGlobal;
  real_T c6_h_u;
  const mxArray *c6_i_y = NULL;
  uint8_T c6_i_hoistedGlobal;
  uint8_T c6_i_u;
  const mxArray *c6_j_y = NULL;
  real_T *c6_Capout;
  real_T *c6_ESRout;
  real_T *c6_cnt;
  real_T *c6_cnt1;
  real_T *c6_ikout;
  real_T *c6_t0;
  real_T *c6_tkout;
  real_T *c6_vkout;
  c6_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c6_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c6_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c6_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c6_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(9), FALSE);
  c6_hoistedGlobal = *c6_Capout;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_ESRout;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = *c6_cnt;
  c6_c_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = *c6_cnt1;
  c6_d_u = c6_d_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = *c6_ikout;
  c6_e_u = c6_e_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_f_hoistedGlobal = *c6_t0;
  c6_f_u = c6_f_hoistedGlobal;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_g_hoistedGlobal = *c6_tkout;
  c6_g_u = c6_g_hoistedGlobal;
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_h_hoistedGlobal = *c6_vkout;
  c6_h_u = c6_h_hoistedGlobal;
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &c6_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 7, c6_i_y);
  c6_i_hoistedGlobal = chartInstance->c6_is_active_c6_BuckBoost1;
  c6_i_u = c6_i_hoistedGlobal;
  c6_j_y = NULL;
  sf_mex_assign(&c6_j_y, sf_mex_create("y", &c6_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 8, c6_j_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_Capout;
  real_T *c6_ESRout;
  real_T *c6_cnt;
  real_T *c6_cnt1;
  real_T *c6_ikout;
  real_T *c6_t0;
  real_T *c6_tkout;
  real_T *c6_vkout;
  c6_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c6_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c6_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c6_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c6_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_Capout = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    0)), "Capout");
  *c6_ESRout = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    1)), "ESRout");
  *c6_cnt = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
    "cnt");
  *c6_cnt1 = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    3)), "cnt1");
  *c6_ikout = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    4)), "ikout");
  *c6_t0 = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 5)),
    "t0");
  *c6_tkout = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    6)), "tkout");
  *c6_vkout = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    7)), "vkout");
  chartInstance->c6_is_active_c6_BuckBoost1 = c6_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 8)),
     "is_active_c6_BuckBoost1");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_BuckBoost1(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
  real_T *c6_vkout;
  real_T *c6_ikout;
  real_T *c6_start;
  real_T *c6_t;
  real_T *c6_duty;
  real_T *c6_v_out;
  real_T *c6_i_in;
  real_T *c6_vk;
  real_T *c6_ik;
  real_T *c6_Capin;
  real_T *c6_ESRin;
  real_T *c6_t0in;
  real_T *c6_cntin;
  real_T *c6_cntin1;
  real_T *c6_tk;
  real_T *c6_Capout;
  real_T *c6_ESRout;
  real_T *c6_t0;
  real_T *c6_cnt;
  real_T *c6_cnt1;
  real_T *c6_tkout;
  c6_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c6_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c6_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c6_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c6_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c6_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c6_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c6_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c6_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c6_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c6_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c6_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_vkout, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_ikout, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_start, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_t, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_duty, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_v_out, 5U);
  _SFD_DATA_RANGE_CHECK(*c6_i_in, 6U);
  _SFD_DATA_RANGE_CHECK(*c6_vk, 7U);
  _SFD_DATA_RANGE_CHECK(*c6_ik, 8U);
  _SFD_DATA_RANGE_CHECK(*c6_Capin, 9U);
  _SFD_DATA_RANGE_CHECK(*c6_ESRin, 10U);
  _SFD_DATA_RANGE_CHECK(*c6_t0in, 11U);
  _SFD_DATA_RANGE_CHECK(*c6_cntin, 12U);
  _SFD_DATA_RANGE_CHECK(*c6_cntin1, 13U);
  _SFD_DATA_RANGE_CHECK(*c6_tk, 14U);
  _SFD_DATA_RANGE_CHECK(*c6_Capout, 15U);
  _SFD_DATA_RANGE_CHECK(*c6_ESRout, 16U);
  _SFD_DATA_RANGE_CHECK(*c6_t0, 17U);
  _SFD_DATA_RANGE_CHECK(*c6_cnt, 18U);
  _SFD_DATA_RANGE_CHECK(*c6_cnt1, 19U);
  _SFD_DATA_RANGE_CHECK(*c6_tkout, 20U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_BuckBoost1(chartInstance);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_e_hoistedGlobal;
  real_T c6_f_hoistedGlobal;
  real_T c6_g_hoistedGlobal;
  real_T c6_h_hoistedGlobal;
  real_T c6_i_hoistedGlobal;
  real_T c6_j_hoistedGlobal;
  real_T c6_k_hoistedGlobal;
  real_T c6_l_hoistedGlobal;
  real_T c6_m_hoistedGlobal;
  real_T c6_start;
  real_T c6_t;
  real_T c6_duty;
  real_T c6_v_out;
  real_T c6_i_in;
  real_T c6_vk;
  real_T c6_ik;
  real_T c6_Capin;
  real_T c6_ESRin;
  real_T c6_t0in;
  real_T c6_cntin;
  real_T c6_cntin1;
  real_T c6_tk;
  uint32_T c6_debug_family_var_map[45];
  real_T c6_sampling_time_base;
  real_T c6_offset;
  real_T c6_OFFSET_ON_START_abs;
  real_T c6_OFFSET_ON_END_rel;
  real_T c6_OFFSET_OFF_START_rel;
  real_T c6_OFFSET_OFF_END_abs;
  real_T c6_STEPS;
  real_T c6_SP_Num;
  real_T c6_SP_ON_min;
  real_T c6_SP_ON_max;
  real_T c6_SP_ON_list[4];
  real_T c6_SP_OFF_max;
  real_T c6_SP_OFF_min;
  real_T c6_SP_OFF_list[4];
  real_T c6_sampling_time;
  real_T c6_del_v;
  real_T c6_del_t;
  real_T c6_slope_v;
  real_T c6_d;
  real_T c6_u;
  real_T c6_del_i;
  real_T c6_slope_i;
  real_T c6_nargin = 13.0;
  real_T c6_nargout = 8.0;
  real_T c6_vkout;
  real_T c6_ikout;
  real_T c6_Capout;
  real_T c6_ESRout;
  real_T c6_t0;
  real_T c6_cnt;
  real_T c6_cnt1;
  real_T c6_tkout;
  int32_T c6_i0;
  int32_T c6_i1;
  int32_T c6_i2;
  boolean_T c6_b_t[4];
  real_T c6_a;
  real_T c6_A;
  real_T c6_B;
  real_T c6_x;
  real_T c6_y;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_b_A;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_c_y;
  real_T c6_c_A;
  real_T c6_b_B;
  real_T c6_e_x;
  real_T c6_d_y;
  real_T c6_f_x;
  real_T c6_e_y;
  int32_T c6_i3;
  boolean_T c6_c_t[4];
  real_T c6_b_a;
  real_T c6_d_A;
  real_T c6_c_B;
  real_T c6_g_x;
  real_T c6_f_y;
  real_T c6_h_x;
  real_T c6_g_y;
  real_T c6_e_A;
  real_T c6_d_B;
  real_T c6_i_x;
  real_T c6_h_y;
  real_T c6_j_x;
  real_T c6_i_y;
  real_T c6_f_A;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_j_y;
  real_T c6_g_A;
  real_T c6_e_B;
  real_T c6_m_x;
  real_T c6_k_y;
  real_T c6_n_x;
  real_T c6_l_y;
  real_T c6_m_y;
  real_T c6_h_A;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_n_y;
  real_T c6_i_A;
  real_T c6_f_B;
  real_T c6_q_x;
  real_T c6_o_y;
  real_T c6_r_x;
  real_T c6_p_y;
  real_T *c6_b_tkout;
  real_T *c6_b_cnt1;
  real_T *c6_b_cnt;
  real_T *c6_b_t0;
  real_T *c6_b_ESRout;
  real_T *c6_b_Capout;
  real_T *c6_b_ikout;
  real_T *c6_b_vkout;
  real_T *c6_b_tk;
  real_T *c6_b_cntin1;
  real_T *c6_b_cntin;
  real_T *c6_b_t0in;
  real_T *c6_b_ESRin;
  real_T *c6_b_Capin;
  real_T *c6_b_ik;
  real_T *c6_b_vk;
  real_T *c6_b_i_in;
  real_T *c6_b_v_out;
  real_T *c6_b_duty;
  real_T *c6_d_t;
  real_T *c6_b_start;
  c6_b_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c6_b_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c6_b_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c6_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c6_b_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c6_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_b_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c6_b_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c6_b_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c6_b_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c6_b_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c6_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c6_b_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c6_b_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_d_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_b_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_start;
  c6_b_hoistedGlobal = *c6_d_t;
  c6_c_hoistedGlobal = *c6_b_duty;
  c6_d_hoistedGlobal = *c6_b_v_out;
  c6_e_hoistedGlobal = *c6_b_i_in;
  c6_f_hoistedGlobal = *c6_b_vk;
  c6_g_hoistedGlobal = *c6_b_ik;
  c6_h_hoistedGlobal = *c6_b_Capin;
  c6_i_hoistedGlobal = *c6_b_ESRin;
  c6_j_hoistedGlobal = *c6_b_t0in;
  c6_k_hoistedGlobal = *c6_b_cntin;
  c6_l_hoistedGlobal = *c6_b_cntin1;
  c6_m_hoistedGlobal = *c6_b_tk;
  c6_start = c6_hoistedGlobal;
  c6_t = c6_b_hoistedGlobal;
  c6_duty = c6_c_hoistedGlobal;
  c6_v_out = c6_d_hoistedGlobal;
  c6_i_in = c6_e_hoistedGlobal;
  c6_vk = c6_f_hoistedGlobal;
  c6_ik = c6_g_hoistedGlobal;
  c6_Capin = c6_h_hoistedGlobal;
  c6_ESRin = c6_i_hoistedGlobal;
  c6_t0in = c6_j_hoistedGlobal;
  c6_cntin = c6_k_hoistedGlobal;
  c6_cntin1 = c6_l_hoistedGlobal;
  c6_tk = c6_m_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 45U, 45U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_sampling_time_base, 0U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_offset, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_OFFSET_ON_START_abs, 2U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_OFFSET_ON_END_rel, 3U,
    c6_sf_marshallOut, c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_OFFSET_OFF_START_rel, 4U,
    c6_sf_marshallOut, c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_OFFSET_OFF_END_abs, 5U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_STEPS, 6U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_SP_Num, 7U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_SP_ON_min, 8U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_SP_ON_max, 9U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_SP_ON_list, 10U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_SP_OFF_max, 11U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_SP_OFF_min, 12U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_SP_OFF_list, 13U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_sampling_time, 14U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_del_v, 15U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_del_t, 16U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_slope_v, 17U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_d, 18U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_u, 19U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_del_i, 20U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_slope_i, 21U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 22U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 23U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_start, 24U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_t, 25U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_duty, 26U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_v_out, 27U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_i_in, 28U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_vk, 29U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_ik, 30U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Capin, 31U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_ESRin, 32U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_t0in, 33U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_cntin, 34U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_cntin1, 35U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_tk, 36U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_vkout, 37U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_ikout, 38U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_Capout, 39U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_ESRout, 40U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_t0, 41U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_cnt, 42U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_cnt1, 43U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_tkout, 44U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_sampling_time_base = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_offset = c6_t - c6_duty;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  c6_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  c6_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_Capout = c6_Capin;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  c6_ESRout = c6_ESRin;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 23);
  c6_t0 = c6_t0in;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  c6_tkout = c6_tk;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  c6_vkout = c6_vk;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
  c6_ikout = c6_ik;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 33);
  c6_cnt = c6_cntin;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 33);
  c6_cnt1 = c6_cntin1;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 36);
  c6_STEPS = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 39);
  c6_SP_Num = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 41);
  c6_SP_ON_min = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 42);
  c6_SP_ON_max = 21.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 43);
  c6_realmax(chartInstance);
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_SP_ON_list[c6_i0] = 6.0 + 5.0 * (real_T)c6_i0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 45);
  c6_SP_OFF_max = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 46);
  c6_SP_OFF_min = 80.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 47);
  c6_realmax(chartInstance);
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    c6_SP_OFF_list[c6_i1] = 80.0 + 5.0 * (real_T)c6_i1;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 50);
  c6_sampling_time = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 54);
  if (CV_EML_IF(0, 1, 0, c6_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 57);
    for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
      c6_b_t[c6_i2] = (c6_t == c6_SP_ON_list[c6_i2]);
    }

    if (CV_EML_IF(0, 1, 1, c6_any(chartInstance, c6_b_t))) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 64);
      if (CV_EML_IF(0, 1, 2, c6_t == c6_SP_ON_min)) {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 65);
        c6_vkout = c6_v_out;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 66);
        c6_tkout = c6_t;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 81);
        c6_del_v = c6_v_out - c6_vk;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 82);
        c6_a = c6_t - c6_tk;
        c6_del_t = c6_a * 1.0E-6;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 83);
        c6_A = c6_del_v;
        c6_B = c6_del_t;
        c6_x = c6_A;
        c6_y = c6_B;
        c6_b_x = c6_x;
        c6_b_y = c6_y;
        c6_slope_v = c6_b_x / c6_b_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 85);
        c6_d = c6_slope_v;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 86);
        c6_u = c6_v_out;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 88);
        c6_b_A = -c6_u;
        c6_c_x = c6_b_A;
        c6_d_x = c6_c_x;
        c6_c_y = c6_d_x / 30.0;
        c6_c_A = c6_c_y;
        c6_b_B = c6_d;
        c6_e_x = c6_c_A;
        c6_d_y = c6_b_B;
        c6_f_x = c6_e_x;
        c6_e_y = c6_d_y;
        c6_Capout = c6_f_x / c6_e_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 91);
        c6_vkout = c6_v_out;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 92);
        c6_tkout = c6_t;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 105);
    for (c6_i3 = 0; c6_i3 < 4; c6_i3++) {
      c6_c_t[c6_i3] = (c6_t == c6_SP_OFF_list[c6_i3]);
    }

    if (CV_EML_IF(0, 1, 3, c6_any(chartInstance, c6_c_t))) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 108);
      if (CV_EML_IF(0, 1, 4, c6_t == c6_SP_OFF_min)) {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 109);
        c6_vkout = c6_v_out;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 110);
        c6_ikout = c6_i_in;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 111);
        c6_tkout = c6_t;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 126);
        c6_del_v = c6_v_out - c6_vk;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, MAX_int8_T);
        c6_del_i = c6_i_in - c6_ik;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 128U);
        c6_b_a = c6_t - c6_tk;
        c6_del_t = c6_b_a * 1.0E-6;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 129U);
        c6_d_A = c6_del_v;
        c6_c_B = c6_del_t;
        c6_g_x = c6_d_A;
        c6_f_y = c6_c_B;
        c6_h_x = c6_g_x;
        c6_g_y = c6_f_y;
        c6_slope_v = c6_h_x / c6_g_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 130U);
        c6_e_A = c6_del_i;
        c6_d_B = c6_del_t;
        c6_i_x = c6_e_A;
        c6_h_y = c6_d_B;
        c6_j_x = c6_i_x;
        c6_i_y = c6_h_y;
        c6_slope_i = c6_j_x / c6_i_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 132U);
        c6_f_A = c6_v_out;
        c6_k_x = c6_f_A;
        c6_l_x = c6_k_x;
        c6_j_y = c6_l_x / 30.0;
        c6_g_A = c6_i_in - c6_j_y;
        c6_e_B = c6_Capin;
        c6_m_x = c6_g_A;
        c6_k_y = c6_e_B;
        c6_n_x = c6_m_x;
        c6_l_y = c6_k_y;
        c6_m_y = c6_n_x / c6_l_y;
        c6_d = c6_slope_v - c6_m_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 133U);
        c6_h_A = c6_slope_v;
        c6_o_x = c6_h_A;
        c6_p_x = c6_o_x;
        c6_n_y = c6_p_x / 30.0;
        c6_u = c6_slope_i - c6_n_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 135U);
        c6_i_A = c6_d;
        c6_f_B = c6_u;
        c6_q_x = c6_i_A;
        c6_o_y = c6_f_B;
        c6_r_x = c6_q_x;
        c6_p_y = c6_o_y;
        c6_ESRout = c6_r_x / c6_p_y;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 138U);
        c6_vkout = c6_v_out;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 139U);
        c6_ikout = c6_i_in;
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 140U);
        c6_tkout = c6_t;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -140);
  sf_debug_symbol_scope_pop();
  *c6_b_vkout = c6_vkout;
  *c6_b_ikout = c6_ikout;
  *c6_b_Capout = c6_Capout;
  *c6_b_ESRout = c6_ESRout;
  *c6_b_t0 = c6_t0;
  *c6_b_cnt = c6_cnt;
  *c6_b_cnt1 = c6_cnt1;
  *c6_b_tkout = c6_tkout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_BuckBoost1(SFc6_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_tkout, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_tkout), &c6_thisId);
  sf_mex_destroy(&c6_tkout);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_tkout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_tkout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_tkout), &c6_thisId);
  sf_mex_destroy(&c6_tkout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i4;
  real_T c6_b_inData[4];
  int32_T c6_i5;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    c6_b_inData[c6_i4] = (*(real_T (*)[4])c6_inData)[c6_i4];
  }

  for (c6_i5 = 0; c6_i5 < 4; c6_i5++) {
    c6_u[c6_i5] = c6_b_inData[c6_i5];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[4])
{
  real_T c6_dv0[4];
  int32_T c6_i6;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c6_i6 = 0; c6_i6 < 4; c6_i6++) {
    c6_y[c6_i6] = c6_dv0[c6_i6];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_SP_OFF_list;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i7;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_SP_OFF_list = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_SP_OFF_list), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_SP_OFF_list);
  for (c6_i7 = 0; c6_i7 < 4; c6_i7++) {
    (*(real_T (*)[4])c6_outData)[c6_i7] = c6_y[c6_i7];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[35];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i8;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 35), FALSE);
  for (c6_i8 = 0; c6_i8 < 35; c6_i8++) {
    c6_r0 = &c6_info[c6_i8];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i8);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i8);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[35])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289494492U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "colon";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[1].fileTimeLo = 1311233718U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c6_info[2].name = "isfinite";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[2].fileTimeLo = 1286797158U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[3].name = "isinf";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[3].fileTimeLo = 1286797160U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[4].name = "isnan";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[4].fileTimeLo = 1286797160U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c6_info[5].name = "floor";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[5].fileTimeLo = 1286797142U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[6].name = "eml_scalar_floor";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[6].fileTimeLo = 1286797126U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c6_info[7].name = "abs";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[7].fileTimeLo = 1286797094U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[8].name = "eml_scalar_abs";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[8].fileTimeLo = 1286797112U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c6_info[9].name = "eps";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[9].fileTimeLo = 1326702796U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[10].name = "eml_mantissa_nbits";
  c6_info[10].dominantType = "char";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c6_info[10].fileTimeLo = 1307629642U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c6_info[11].name = "eml_float_model";
  c6_info[11].dominantType = "char";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[11].fileTimeLo = 1326702796U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[12].name = "eml_realmin";
  c6_info[12].dominantType = "char";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c6_info[12].fileTimeLo = 1307629644U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c6_info[13].name = "eml_float_model";
  c6_info[13].dominantType = "char";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[13].fileTimeLo = 1326702796U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[14].name = "eml_realmin_denormal";
  c6_info[14].dominantType = "char";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c6_info[14].fileTimeLo = 1326702798U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c6_info[15].name = "eml_float_model";
  c6_info[15].dominantType = "char";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[15].fileTimeLo = 1326702796U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[16].name = "abs";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[16].fileTimeLo = 1286797094U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[17].name = "isfinite";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[17].fileTimeLo = 1286797158U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c6_info[18].name = "realmax";
  c6_info[18].dominantType = "char";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c6_info[18].fileTimeLo = 1307629642U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c6_info[19].name = "eml_realmax";
  c6_info[19].dominantType = "char";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c6_info[19].fileTimeLo = 1326702796U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c6_info[20].name = "eml_float_model";
  c6_info[20].dominantType = "char";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[20].fileTimeLo = 1326702796U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c6_info[21].name = "mtimes";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[21].fileTimeLo = 1289494492U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c6_info[22].name = "mrdivide";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[22].fileTimeLo = 1342789344U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 1319708366U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[23].name = "rdivide";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[23].fileTimeLo = 1286797244U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[24].name = "eml_div";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[24].fileTimeLo = 1313326210U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
  c6_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c6_info[25].name = "floor";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[25].fileTimeLo = 1286797142U;
  c6_info[25].fileTimeHi = 0U;
  c6_info[25].mFileTimeLo = 0U;
  c6_info[25].mFileTimeHi = 0U;
  c6_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c6_info[26].name = "eml_index_class";
  c6_info[26].dominantType = "";
  c6_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[26].fileTimeLo = 1323145378U;
  c6_info[26].fileTimeHi = 0U;
  c6_info[26].mFileTimeLo = 0U;
  c6_info[26].mFileTimeHi = 0U;
  c6_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c6_info[27].name = "intmax";
  c6_info[27].dominantType = "char";
  c6_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[27].fileTimeLo = 1311233716U;
  c6_info[27].fileTimeHi = 0U;
  c6_info[27].mFileTimeLo = 0U;
  c6_info[27].mFileTimeHi = 0U;
  c6_info[28].context = "";
  c6_info[28].name = "any";
  c6_info[28].dominantType = "logical";
  c6_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c6_info[28].fileTimeLo = 1286797234U;
  c6_info[28].fileTimeHi = 0U;
  c6_info[28].mFileTimeLo = 0U;
  c6_info[28].mFileTimeHi = 0U;
  c6_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c6_info[29].name = "eml_all_or_any";
  c6_info[29].dominantType = "char";
  c6_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[29].fileTimeLo = 1286797094U;
  c6_info[29].fileTimeHi = 0U;
  c6_info[29].mFileTimeLo = 0U;
  c6_info[29].mFileTimeHi = 0U;
  c6_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[30].name = "isequal";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[30].fileTimeLo = 1286797158U;
  c6_info[30].fileTimeHi = 0U;
  c6_info[30].mFileTimeLo = 0U;
  c6_info[30].mFileTimeHi = 0U;
  c6_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[31].name = "eml_isequal_core";
  c6_info[31].dominantType = "double";
  c6_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c6_info[31].fileTimeLo = 1286797186U;
  c6_info[31].fileTimeHi = 0U;
  c6_info[31].mFileTimeLo = 0U;
  c6_info[31].mFileTimeHi = 0U;
  c6_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[32].name = "eml_const_nonsingleton_dim";
  c6_info[32].dominantType = "logical";
  c6_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c6_info[32].fileTimeLo = 1286797096U;
  c6_info[32].fileTimeHi = 0U;
  c6_info[32].mFileTimeLo = 0U;
  c6_info[32].mFileTimeHi = 0U;
  c6_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c6_info[33].name = "isnan";
  c6_info[33].dominantType = "logical";
  c6_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[33].fileTimeLo = 1286797160U;
  c6_info[33].fileTimeHi = 0U;
  c6_info[33].mFileTimeLo = 0U;
  c6_info[33].mFileTimeHi = 0U;
  c6_info[34].context = "";
  c6_info[34].name = "mrdivide";
  c6_info[34].dominantType = "double";
  c6_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[34].fileTimeLo = 1342789344U;
  c6_info[34].fileTimeHi = 0U;
  c6_info[34].mFileTimeLo = 1319708366U;
  c6_info[34].mFileTimeHi = 0U;
}

static void c6_realmax(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
}

static boolean_T c6_any(SFc6_BuckBoost1InstanceStruct *chartInstance, boolean_T
  c6_x[4])
{
  boolean_T c6_y;
  int32_T c6_k;
  real_T c6_b_k;
  boolean_T c6_b0;
  boolean_T exitg1;
  c6_y = FALSE;
  c6_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c6_k < 4)) {
    c6_b_k = 1.0 + (real_T)c6_k;
    if ((real_T)c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
         ("", c6_b_k), 1, 4, 1, 0) - 1] == 0.0) {
      c6_b0 = TRUE;
    } else {
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c6_b_k), 1, 4, 1, 0);
      c6_b0 = FALSE;
    }

    if (!c6_b0) {
      c6_y = TRUE;
      exitg1 = TRUE;
    } else {
      c6_k++;
    }
  }

  return c6_y;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i9;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i9, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i9;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_BuckBoost1, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_BuckBoost1), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_BuckBoost1);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4157946932U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1358670737U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2398229118U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3843616134U);
}

mxArray *sf_c6_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zhQA5TK0WKmWnnIHuNJdaE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c6_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[34],T\"Capout\",},{M[1],M[83],T\"ESRout\",},{M[1],M[101],T\"cnt\",},{M[1],M[103],T\"cnt1\",},{M[1],M[45],T\"ikout\",},{M[1],M[84],T\"t0\",},{M[1],M[47],T\"tkout\",},{M[1],M[44],T\"vkout\",},{M[8],M[0],T\"is_active_c6_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc6_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           6,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"vkout");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ikout");
          _SFD_SET_DATA_PROPS(2,1,1,0,"start");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
          _SFD_SET_DATA_PROPS(4,1,1,0,"duty");
          _SFD_SET_DATA_PROPS(5,1,1,0,"v_out");
          _SFD_SET_DATA_PROPS(6,1,1,0,"i_in");
          _SFD_SET_DATA_PROPS(7,1,1,0,"vk");
          _SFD_SET_DATA_PROPS(8,1,1,0,"ik");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(10,1,1,0,"ESRin");
          _SFD_SET_DATA_PROPS(11,1,1,0,"t0in");
          _SFD_SET_DATA_PROPS(12,1,1,0,"cntin");
          _SFD_SET_DATA_PROPS(13,1,1,0,"cntin1");
          _SFD_SET_DATA_PROPS(14,1,1,0,"tk");
          _SFD_SET_DATA_PROPS(15,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(16,2,0,1,"ESRout");
          _SFD_SET_DATA_PROPS(17,2,0,1,"t0");
          _SFD_SET_DATA_PROPS(18,2,0,1,"cnt");
          _SFD_SET_DATA_PROPS(19,2,0,1,"cnt1");
          _SFD_SET_DATA_PROPS(20,2,0,1,"tkout");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4473);
        _SFD_CV_INIT_EML_IF(0,1,0,1528,1540,-1,4472);
        _SFD_CV_INIT_EML_IF(0,1,1,1684,1706,-1,2789);
        _SFD_CV_INIT_EML_IF(0,1,2,1906,1925,2053,2772);
        _SFD_CV_INIT_EML_IF(0,1,3,3185,3208,-1,4271);
        _SFD_CV_INIT_EML_IF(0,1,4,3257,3276,3365,4254);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_vkout;
          real_T *c6_ikout;
          real_T *c6_start;
          real_T *c6_t;
          real_T *c6_duty;
          real_T *c6_v_out;
          real_T *c6_i_in;
          real_T *c6_vk;
          real_T *c6_ik;
          real_T *c6_Capin;
          real_T *c6_ESRin;
          real_T *c6_t0in;
          real_T *c6_cntin;
          real_T *c6_cntin1;
          real_T *c6_tk;
          real_T *c6_Capout;
          real_T *c6_ESRout;
          real_T *c6_t0;
          real_T *c6_cnt;
          real_T *c6_cnt1;
          real_T *c6_tkout;
          c6_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c6_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c6_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c6_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c6_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c6_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c6_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c6_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c6_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c6_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c6_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c6_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c6_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c6_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c6_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c6_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c6_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_vkout);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_ikout);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_start);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_duty);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_v_out);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_i_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c6_vk);
          _SFD_SET_DATA_VALUE_PTR(8U, c6_ik);
          _SFD_SET_DATA_VALUE_PTR(9U, c6_Capin);
          _SFD_SET_DATA_VALUE_PTR(10U, c6_ESRin);
          _SFD_SET_DATA_VALUE_PTR(11U, c6_t0in);
          _SFD_SET_DATA_VALUE_PTR(12U, c6_cntin);
          _SFD_SET_DATA_VALUE_PTR(13U, c6_cntin1);
          _SFD_SET_DATA_VALUE_PTR(14U, c6_tk);
          _SFD_SET_DATA_VALUE_PTR(15U, c6_Capout);
          _SFD_SET_DATA_VALUE_PTR(16U, c6_ESRout);
          _SFD_SET_DATA_VALUE_PTR(17U, c6_t0);
          _SFD_SET_DATA_VALUE_PTR(18U, c6_cnt);
          _SFD_SET_DATA_VALUE_PTR(19U, c6_cnt1);
          _SFD_SET_DATA_VALUE_PTR(20U, c6_tkout);
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
  return "6RKw4nc60RwcrjxYl7AsDC";
}

static void sf_opaque_initialize_c6_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_BuckBoost1(void *chartInstanceVar)
{
  enable_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_BuckBoost1(void *chartInstanceVar)
{
  disable_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_BuckBoost1(void *chartInstanceVar)
{
  sf_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_BuckBoost1
    ((SFc6_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c6_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c6_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c6_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_BuckBoost1((SFc6_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
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
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,8);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3157964376U));
  ssSetChecksum1(S,(1956297795U));
  ssSetChecksum2(S,(1869450811U));
  ssSetChecksum3(S,(4088747054U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_BuckBoost1(SimStruct *S)
{
  SFc6_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc6_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc6_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_BuckBoost1;
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

void c6_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
