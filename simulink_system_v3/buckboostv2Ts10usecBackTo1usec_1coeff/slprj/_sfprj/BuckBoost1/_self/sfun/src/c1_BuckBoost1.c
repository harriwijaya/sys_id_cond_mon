/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c1_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[52] = { "sampling_time", "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel",
  "OFFSET_OFF_END_abs", "lambda", "SAMPLE_1t_abs", "SAMPLE_2t_rel",
  "SAMPLE_3t_rel", "SAMPLE_4t_abs", "del_v", "del_t", "slope_v", "d", "u",
  "kden", "knom", "k", "del_i", "slope_i", "nargin", "nargout", "start", "t",
  "duty", "v_out", "i_in", "vk", "ik", "win", "woin", "Pk", "Capin", "ESRin",
  "t0in", "cntin", "cntin1", "tk", "vkout", "ikout", "y", "e", "w", "wo", "P",
  "Capout", "ESRout", "t0", "cnt", "cnt1", "tkout" };

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
  const mxArray *c1_tkout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
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
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  uint8_T c1_n_hoistedGlobal;
  uint8_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T *c1_Capout;
  real_T *c1_ESRout;
  real_T *c1_P;
  real_T *c1_cnt;
  real_T *c1_cnt1;
  real_T *c1_e;
  real_T *c1_ikout;
  real_T *c1_t0;
  real_T *c1_tkout;
  real_T *c1_vkout;
  real_T *c1_w;
  real_T *c1_wo;
  real_T *c1_p_y;
  c1_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_p_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(14), FALSE);
  c1_hoistedGlobal = *c1_Capout;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_ESRout;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_P;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_cnt;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_cnt1;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_e;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_ikout;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = *c1_t0;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = *c1_tkout;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = *c1_vkout;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = *c1_w;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = *c1_wo;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = *c1_p_y;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = chartInstance->c1_is_active_c1_BuckBoost1;
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Capout;
  real_T *c1_ESRout;
  real_T *c1_P;
  real_T *c1_cnt;
  real_T *c1_cnt1;
  real_T *c1_e;
  real_T *c1_ikout;
  real_T *c1_t0;
  real_T *c1_tkout;
  real_T *c1_vkout;
  real_T *c1_w;
  real_T *c1_wo;
  real_T *c1_y;
  c1_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Capout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Capout");
  *c1_ESRout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "ESRout");
  *c1_P = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "P");
  *c1_cnt = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "cnt");
  *c1_cnt1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "cnt1");
  *c1_e = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
    "e");
  *c1_ikout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    6)), "ikout");
  *c1_t0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
    "t0");
  *c1_tkout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    8)), "tkout");
  *c1_vkout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    9)), "vkout");
  *c1_w = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 10)),
    "w");
  *c1_wo = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 11)),
    "wo");
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
    "y");
  chartInstance->c1_is_active_c1_BuckBoost1 = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 13)),
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
  real_T *c1_vkout;
  real_T *c1_ikout;
  real_T *c1_start;
  real_T *c1_t;
  real_T *c1_duty;
  real_T *c1_v_out;
  real_T *c1_i_in;
  real_T *c1_vk;
  real_T *c1_ik;
  real_T *c1_win;
  real_T *c1_woin;
  real_T *c1_Pk;
  real_T *c1_Capin;
  real_T *c1_ESRin;
  real_T *c1_y;
  real_T *c1_e;
  real_T *c1_w;
  real_T *c1_wo;
  real_T *c1_P;
  real_T *c1_Capout;
  real_T *c1_ESRout;
  real_T *c1_t0in;
  real_T *c1_t0;
  real_T *c1_cntin;
  real_T *c1_cnt;
  real_T *c1_cntin1;
  real_T *c1_cnt1;
  real_T *c1_tk;
  real_T *c1_tkout;
  c1_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_Pk = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_woin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_vkout, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_ikout, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_start, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_t, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_duty, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_v_out, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_i_in, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_vk, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_ik, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_woin, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_Pk, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_Capin, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_ESRin, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_y, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_e, 15U);
  _SFD_DATA_RANGE_CHECK(*c1_w, 16U);
  _SFD_DATA_RANGE_CHECK(*c1_wo, 17U);
  _SFD_DATA_RANGE_CHECK(*c1_P, 18U);
  _SFD_DATA_RANGE_CHECK(*c1_Capout, 19U);
  _SFD_DATA_RANGE_CHECK(*c1_ESRout, 20U);
  _SFD_DATA_RANGE_CHECK(*c1_t0in, 21U);
  _SFD_DATA_RANGE_CHECK(*c1_t0, 22U);
  _SFD_DATA_RANGE_CHECK(*c1_cntin, 23U);
  _SFD_DATA_RANGE_CHECK(*c1_cnt, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_cntin1, 25U);
  _SFD_DATA_RANGE_CHECK(*c1_cnt1, 26U);
  _SFD_DATA_RANGE_CHECK(*c1_tk, 27U);
  _SFD_DATA_RANGE_CHECK(*c1_tkout, 28U);
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
  real_T c1_i_hoistedGlobal;
  real_T c1_j_hoistedGlobal;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_hoistedGlobal;
  real_T c1_m_hoistedGlobal;
  real_T c1_n_hoistedGlobal;
  real_T c1_o_hoistedGlobal;
  real_T c1_p_hoistedGlobal;
  real_T c1_start;
  real_T c1_t;
  real_T c1_duty;
  real_T c1_v_out;
  real_T c1_i_in;
  real_T c1_vk;
  real_T c1_ik;
  real_T c1_win;
  real_T c1_woin;
  real_T c1_Pk;
  real_T c1_Capin;
  real_T c1_ESRin;
  real_T c1_t0in;
  real_T c1_cntin;
  real_T c1_cntin1;
  real_T c1_tk;
  uint32_T c1_debug_family_var_map[52];
  real_T c1_sampling_time;
  real_T c1_offset;
  real_T c1_OFFSET_ON_START_abs;
  real_T c1_OFFSET_ON_END_rel;
  real_T c1_OFFSET_OFF_START_rel;
  real_T c1_OFFSET_OFF_END_abs;
  real_T c1_lambda;
  real_T c1_SAMPLE_1t_abs;
  real_T c1_SAMPLE_2t_rel;
  real_T c1_SAMPLE_3t_rel;
  real_T c1_SAMPLE_4t_abs;
  real_T c1_del_v;
  real_T c1_del_t;
  real_T c1_slope_v;
  real_T c1_d;
  real_T c1_u;
  real_T c1_kden;
  real_T c1_knom;
  real_T c1_k;
  real_T c1_del_i;
  real_T c1_slope_i;
  real_T c1_nargin = 16.0;
  real_T c1_nargout = 13.0;
  real_T c1_vkout;
  real_T c1_ikout;
  real_T c1_y;
  real_T c1_e;
  real_T c1_w;
  real_T c1_wo;
  real_T c1_P;
  real_T c1_Capout;
  real_T c1_ESRout;
  real_T c1_t0;
  real_T c1_cnt;
  real_T c1_cnt1;
  real_T c1_tkout;
  real_T c1_a;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_b_y;
  real_T c1_b_x;
  real_T c1_c_y;
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_d_y;
  real_T c1_c_a;
  real_T c1_b_b;
  real_T c1_e_y;
  real_T c1_d_a;
  real_T c1_c_b;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_c_x;
  real_T c1_f_y;
  real_T c1_d_x;
  real_T c1_g_y;
  real_T c1_e_a;
  real_T c1_d_b;
  real_T c1_f_a;
  real_T c1_e_b;
  real_T c1_h_y;
  real_T c1_g_a;
  real_T c1_f_b;
  real_T c1_i_y;
  real_T c1_h_a;
  real_T c1_g_b;
  real_T c1_j_y;
  real_T c1_c_A;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_B;
  real_T c1_k_y;
  real_T c1_l_y;
  real_T c1_i_a;
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_g_x;
  real_T c1_m_y;
  real_T c1_h_x;
  real_T c1_n_y;
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_i_x;
  real_T c1_o_y;
  real_T c1_j_x;
  real_T c1_p_y;
  real_T c1_f_A;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_q_y;
  real_T c1_g_A;
  real_T c1_f_B;
  real_T c1_m_x;
  real_T c1_r_y;
  real_T c1_n_x;
  real_T c1_s_y;
  real_T c1_t_y;
  real_T c1_h_A;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_u_y;
  real_T c1_j_a;
  real_T c1_h_b;
  real_T c1_v_y;
  real_T c1_k_a;
  real_T c1_i_b;
  real_T c1_w_y;
  real_T c1_l_a;
  real_T c1_j_b;
  real_T c1_i_A;
  real_T c1_g_B;
  real_T c1_q_x;
  real_T c1_x_y;
  real_T c1_r_x;
  real_T c1_y_y;
  real_T c1_m_a;
  real_T c1_k_b;
  real_T c1_n_a;
  real_T c1_l_b;
  real_T c1_ab_y;
  real_T c1_o_a;
  real_T c1_m_b;
  real_T c1_bb_y;
  real_T c1_p_a;
  real_T c1_n_b;
  real_T c1_cb_y;
  real_T c1_j_A;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T *c1_b_tkout;
  real_T *c1_b_cnt1;
  real_T *c1_b_cnt;
  real_T *c1_b_t0;
  real_T *c1_b_ESRout;
  real_T *c1_b_Capout;
  real_T *c1_b_P;
  real_T *c1_b_wo;
  real_T *c1_b_w;
  real_T *c1_b_e;
  real_T *c1_db_y;
  real_T *c1_b_ikout;
  real_T *c1_b_vkout;
  real_T *c1_b_tk;
  real_T *c1_b_cntin1;
  real_T *c1_b_cntin;
  real_T *c1_b_t0in;
  real_T *c1_b_ESRin;
  real_T *c1_b_Capin;
  real_T *c1_b_Pk;
  real_T *c1_b_woin;
  real_T *c1_b_win;
  real_T *c1_b_ik;
  real_T *c1_b_vk;
  real_T *c1_b_i_in;
  real_T *c1_b_v_out;
  real_T *c1_b_duty;
  real_T *c1_b_t;
  real_T *c1_b_start;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  c1_b_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_b_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_b_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_b_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_b_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_b_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_b_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_b_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_b_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_b_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_b_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_db_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_b_Pk = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_woin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_start;
  c1_b_hoistedGlobal = *c1_b_t;
  c1_c_hoistedGlobal = *c1_b_duty;
  c1_d_hoistedGlobal = *c1_b_v_out;
  c1_e_hoistedGlobal = *c1_b_i_in;
  c1_f_hoistedGlobal = *c1_b_vk;
  c1_g_hoistedGlobal = *c1_b_ik;
  c1_h_hoistedGlobal = *c1_b_win;
  c1_i_hoistedGlobal = *c1_b_woin;
  c1_j_hoistedGlobal = *c1_b_Pk;
  c1_k_hoistedGlobal = *c1_b_Capin;
  c1_l_hoistedGlobal = *c1_b_ESRin;
  c1_m_hoistedGlobal = *c1_b_t0in;
  c1_n_hoistedGlobal = *c1_b_cntin;
  c1_o_hoistedGlobal = *c1_b_cntin1;
  c1_p_hoistedGlobal = *c1_b_tk;
  c1_start = c1_hoistedGlobal;
  c1_t = c1_b_hoistedGlobal;
  c1_duty = c1_c_hoistedGlobal;
  c1_v_out = c1_d_hoistedGlobal;
  c1_i_in = c1_e_hoistedGlobal;
  c1_vk = c1_f_hoistedGlobal;
  c1_ik = c1_g_hoistedGlobal;
  c1_win = c1_h_hoistedGlobal;
  c1_woin = c1_i_hoistedGlobal;
  c1_Pk = c1_j_hoistedGlobal;
  c1_Capin = c1_k_hoistedGlobal;
  c1_ESRin = c1_l_hoistedGlobal;
  c1_t0in = c1_m_hoistedGlobal;
  c1_cntin = c1_n_hoistedGlobal;
  c1_cntin1 = c1_o_hoistedGlobal;
  c1_tk = c1_p_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 52U, 52U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_sampling_time, 0U, c1_sf_marshallOut);
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
  sf_debug_symbol_scope_add_eml(&c1_lambda, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_SAMPLE_1t_abs, 7U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_SAMPLE_2t_rel, 8U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_SAMPLE_3t_rel, 9U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_SAMPLE_4t_abs, 10U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_del_v, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_del_t, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_slope_v, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_d, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_u, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_kden, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_knom, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_k, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_del_i, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_slope_i, 20U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 21U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 22U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_start, 23U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t, 24U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_duty, 25U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_v_out, 26U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_i_in, 27U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_vk, 28U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_ik, 29U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_win, 30U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_woin, 31U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pk, 32U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Capin, 33U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_ESRin, 34U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t0in, 35U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_cntin, 36U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_cntin1, 37U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_tk, 38U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_vkout, 39U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ikout, 40U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 41U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_e, 42U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w, 43U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wo, 44U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_P, 45U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Capout, 46U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ESRout, 47U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_t0, 48U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_cnt, 49U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_cnt1, 50U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_tkout, 51U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_sampling_time = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_offset = c1_t - c1_duty;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_lambda = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
  c1_w = c1_win;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_wo = c1_woin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
  c1_P = c1_Pk;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  c1_Capout = c1_Capin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  c1_ESRout = c1_ESRin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
  c1_t0 = c1_t0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_tkout = c1_tk;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  c1_vkout = c1_vk;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  c1_ikout = c1_ik;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  c1_cnt = c1_cntin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  c1_cnt1 = c1_cntin1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
  c1_SAMPLE_1t_abs = c1_OFFSET_ON_START_abs + 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
  c1_SAMPLE_2t_rel = c1_OFFSET_ON_END_rel - 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
  c1_SAMPLE_3t_rel = c1_OFFSET_OFF_START_rel + 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
  c1_SAMPLE_4t_abs = c1_OFFSET_OFF_END_abs - 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
  if (CV_EML_IF(0, 1, 0, c1_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 65);
    guard6 = FALSE;
    if (CV_EML_COND(0, 1, 0, c1_t > c1_OFFSET_ON_START_abs)) {
      if (CV_EML_COND(0, 1, 1, c1_offset < c1_OFFSET_ON_END_rel)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
        if (CV_EML_IF(0, 1, 2, c1_t < c1_t0)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
          c1_cnt = 0.0;
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 75);
        guard7 = FALSE;
        if (CV_EML_COND(0, 1, 2, c1_t > c1_SAMPLE_1t_abs)) {
          if (CV_EML_COND(0, 1, 3, c1_t <= c1_SAMPLE_1t_abs + 2.0)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
            c1_cnt = c1_cntin + 1.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 78);
            c1_vkout = c1_v_out;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 79);
            c1_tkout = c1_t;
          } else {
            guard7 = TRUE;
          }
        } else {
          guard7 = TRUE;
        }

        if (guard7 == TRUE) {
          CV_EML_MCDC(0, 1, 1, FALSE);
          CV_EML_IF(0, 1, 3, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
          guard8 = FALSE;
          if (CV_EML_COND(0, 1, 4, c1_offset > c1_SAMPLE_2t_rel)) {
            if (CV_EML_COND(0, 1, 5, c1_offset <= c1_SAMPLE_2t_rel + 2.0)) {
              CV_EML_MCDC(0, 1, 2, TRUE);
              CV_EML_IF(0, 1, 4, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
              c1_cnt = c1_cntin + 1.0;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 83);
              c1_del_v = c1_v_out - c1_vk;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 84);
              c1_a = c1_t - c1_tk;
              c1_del_t = c1_a * 1.0E-6;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 85);
              c1_A = c1_del_v;
              c1_B = c1_del_t;
              c1_x = c1_A;
              c1_b_y = c1_B;
              c1_b_x = c1_x;
              c1_c_y = c1_b_y;
              c1_slope_v = c1_b_x / c1_c_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 87);
              c1_d = c1_slope_v;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 88);
              c1_u = c1_v_out;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 91);
              c1_b_a = c1_u;
              c1_b = c1_P;
              c1_d_y = c1_b_a * c1_b;
              c1_c_a = c1_d_y;
              c1_b_b = c1_u;
              c1_e_y = c1_c_a * c1_b_b;
              c1_kden = c1_lambda + c1_e_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
              c1_d_a = c1_P;
              c1_c_b = c1_u;
              c1_knom = c1_d_a * c1_c_b;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 93);
              c1_b_A = c1_knom;
              c1_b_B = c1_kden;
              c1_c_x = c1_b_A;
              c1_f_y = c1_b_B;
              c1_d_x = c1_c_x;
              c1_g_y = c1_f_y;
              c1_k = c1_d_x / c1_g_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 95);
              c1_e_a = c1_w;
              c1_d_b = c1_u;
              c1_y = c1_e_a * c1_d_b;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 96);
              c1_e = c1_d - c1_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
              c1_f_a = c1_k;
              c1_e_b = c1_e;
              c1_h_y = c1_f_a * c1_e_b;
              c1_w += c1_h_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 100);
              c1_g_a = c1_k;
              c1_f_b = c1_u;
              c1_i_y = c1_g_a * c1_f_b;
              c1_h_a = c1_i_y;
              c1_g_b = c1_P;
              c1_j_y = c1_h_a * c1_g_b;
              c1_c_A = c1_P - c1_j_y;
              c1_e_x = c1_c_A;
              c1_f_x = c1_e_x;
              c1_P = c1_f_x / 0.01;
            } else {
              guard8 = TRUE;
            }
          } else {
            guard8 = TRUE;
          }

          if (guard8 == TRUE) {
            CV_EML_MCDC(0, 1, 2, FALSE);
            CV_EML_IF(0, 1, 4, FALSE);
          }
        }
      } else {
        guard6 = TRUE;
      }
    } else {
      guard6 = TRUE;
    }

    if (guard6 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 105);
    guard5 = FALSE;
    if (CV_EML_COND(0, 1, 6, c1_offset >= c1_OFFSET_ON_END_rel)) {
      if (CV_EML_COND(0, 1, 7, c1_offset <= c1_OFFSET_ON_END_rel + 1.0)) {
        CV_EML_MCDC(0, 1, 3, TRUE);
        CV_EML_IF(0, 1, 5, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 107);
        c1_c_B = c1_win;
        c1_k_y = c1_c_B;
        c1_l_y = c1_k_y;
        c1_Capout = -0.033333333333333333 / c1_l_y;
      } else {
        guard5 = TRUE;
      }
    } else {
      guard5 = TRUE;
    }

    if (guard5 == TRUE) {
      CV_EML_MCDC(0, 1, 3, FALSE);
      CV_EML_IF(0, 1, 5, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 112);
    guard2 = FALSE;
    if (CV_EML_COND(0, 1, 8, c1_offset > c1_OFFSET_OFF_START_rel)) {
      if (CV_EML_COND(0, 1, 9, c1_t < c1_OFFSET_OFF_END_abs)) {
        CV_EML_MCDC(0, 1, 4, TRUE);
        CV_EML_IF(0, 1, 6, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 115);
        if (CV_EML_IF(0, 1, 7, c1_t < c1_t0)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 116);
          c1_cnt = 0.0;
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 119);
        guard3 = FALSE;
        if (CV_EML_COND(0, 1, 10, c1_offset > c1_SAMPLE_3t_rel)) {
          if (CV_EML_COND(0, 1, 11, c1_offset <= c1_SAMPLE_3t_rel + 2.0)) {
            CV_EML_MCDC(0, 1, 5, TRUE);
            CV_EML_IF(0, 1, 8, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 120);
            c1_cnt = c1_cntin + 1.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 122);
            c1_vkout = c1_v_out;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 123);
            c1_ikout = c1_i_in;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 124);
            c1_tkout = c1_t;
          } else {
            guard3 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }

        if (guard3 == TRUE) {
          CV_EML_MCDC(0, 1, 5, FALSE);
          CV_EML_IF(0, 1, 8, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 125);
          guard4 = FALSE;
          if (CV_EML_COND(0, 1, 12, c1_t > c1_SAMPLE_4t_abs)) {
            if (CV_EML_COND(0, 1, 13, c1_t <= c1_SAMPLE_4t_abs + 2.0)) {
              CV_EML_MCDC(0, 1, 6, TRUE);
              CV_EML_IF(0, 1, 9, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
              c1_cnt = c1_cntin + 1.0;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 128U);
              c1_del_v = c1_v_out - c1_vk;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 129U);
              c1_del_i = c1_i_in - c1_ik;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 130U);
              c1_i_a = c1_t - c1_tk;
              c1_del_t = c1_i_a * 1.0E-6;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 131U);
              c1_d_A = c1_del_v;
              c1_d_B = c1_del_t;
              c1_g_x = c1_d_A;
              c1_m_y = c1_d_B;
              c1_h_x = c1_g_x;
              c1_n_y = c1_m_y;
              c1_slope_v = c1_h_x / c1_n_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 132U);
              c1_e_A = c1_del_i;
              c1_e_B = c1_del_t;
              c1_i_x = c1_e_A;
              c1_o_y = c1_e_B;
              c1_j_x = c1_i_x;
              c1_p_y = c1_o_y;
              c1_slope_i = c1_j_x / c1_p_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 134U);
              c1_f_A = c1_v_out;
              c1_k_x = c1_f_A;
              c1_l_x = c1_k_x;
              c1_q_y = c1_l_x / 30.0;
              c1_g_A = c1_i_in - c1_q_y;
              c1_f_B = c1_Capin;
              c1_m_x = c1_g_A;
              c1_r_y = c1_f_B;
              c1_n_x = c1_m_x;
              c1_s_y = c1_r_y;
              c1_t_y = c1_n_x / c1_s_y;
              c1_d = c1_slope_v - c1_t_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 135U);
              c1_h_A = c1_slope_v;
              c1_o_x = c1_h_A;
              c1_p_x = c1_o_x;
              c1_u_y = c1_p_x / 30.0;
              c1_u = c1_slope_i - c1_u_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 138U);
              c1_j_a = c1_u;
              c1_h_b = c1_P;
              c1_v_y = c1_j_a * c1_h_b;
              c1_k_a = c1_v_y;
              c1_i_b = c1_u;
              c1_w_y = c1_k_a * c1_i_b;
              c1_kden = c1_lambda + c1_w_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 139U);
              c1_l_a = c1_P;
              c1_j_b = c1_u;
              c1_knom = c1_l_a * c1_j_b;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 140U);
              c1_i_A = c1_knom;
              c1_g_B = c1_kden;
              c1_q_x = c1_i_A;
              c1_x_y = c1_g_B;
              c1_r_x = c1_q_x;
              c1_y_y = c1_x_y;
              c1_k = c1_r_x / c1_y_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 142U);
              c1_m_a = c1_wo;
              c1_k_b = c1_u;
              c1_y = c1_m_a * c1_k_b;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 143U);
              c1_e = c1_d - c1_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 145U);
              c1_n_a = c1_k;
              c1_l_b = c1_e;
              c1_ab_y = c1_n_a * c1_l_b;
              c1_wo += c1_ab_y;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 147U);
              c1_o_a = c1_k;
              c1_m_b = c1_u;
              c1_bb_y = c1_o_a * c1_m_b;
              c1_p_a = c1_bb_y;
              c1_n_b = c1_P;
              c1_cb_y = c1_p_a * c1_n_b;
              c1_j_A = c1_P - c1_cb_y;
              c1_s_x = c1_j_A;
              c1_t_x = c1_s_x;
              c1_P = c1_t_x / 0.01;
            } else {
              guard4 = TRUE;
            }
          } else {
            guard4 = TRUE;
          }

          if (guard4 == TRUE) {
            CV_EML_MCDC(0, 1, 6, FALSE);
            CV_EML_IF(0, 1, 9, FALSE);
          }
        }
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 4, FALSE);
      CV_EML_IF(0, 1, 6, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 152U);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 14, c1_t >= c1_OFFSET_OFF_END_abs)) {
      if (CV_EML_COND(0, 1, 15, c1_t <= c1_OFFSET_OFF_END_abs + 1.0)) {
        CV_EML_MCDC(0, 1, 7, TRUE);
        CV_EML_IF(0, 1, 10, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 153U);
        c1_ESRout = c1_wo;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 7, FALSE);
      CV_EML_IF(0, 1, 10, FALSE);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -153);
  sf_debug_symbol_scope_pop();
  *c1_b_vkout = c1_vkout;
  *c1_b_ikout = c1_ikout;
  *c1_db_y = c1_y;
  *c1_b_e = c1_e;
  *c1_b_w = c1_w;
  *c1_b_wo = c1_wo;
  *c1_b_P = c1_P;
  *c1_b_Capout = c1_Capout;
  *c1_b_ESRout = c1_ESRout;
  *c1_b_t0 = c1_t0;
  *c1_b_cnt = c1_cnt;
  *c1_b_cnt1 = c1_cnt1;
  *c1_b_tkout = c1_tkout;
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
  const mxArray *c1_tkout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_tkout), &c1_thisId);
  sf_mex_destroy(&c1_tkout);
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
  const mxArray *c1_tkout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_tkout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_tkout), &c1_thisId);
  sf_mex_destroy(&c1_tkout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[4];
  c1_ResolvedFunctionInfo (*c1_b_info)[4];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[4])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289494492U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "mrdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].fileTimeLo = 1342789344U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 1319708366U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[2].name = "rdivide";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].fileTimeLo = 1286797244U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[3].name = "eml_div";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[3].fileTimeLo = 1313326210U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
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

static int32_T c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_BuckBoost1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_BuckBoost1);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2582749913U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3995113135U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1705622098U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3535177523U);
}

mxArray *sf_c1_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("P0Xkl1rDJUzkgQV8qaHyiE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[34],T\"Capout\",},{M[1],M[106],T\"ESRout\",},{M[1],M[112],T\"P\",},{M[1],M[101],T\"cnt\",},{M[1],M[103],T\"cnt1\",},{M[1],M[29],T\"e\",},{M[1],M[45],T\"ikout\",},{M[1],M[84],T\"t0\",},{M[1],M[108],T\"tkout\",},{M[1],M[44],T\"vkout\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[93],T\"w\",},{M[1],M[110],T\"wo\",},{M[1],M[28],T\"y\",},{M[8],M[0],T\"is_active_c1_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
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
           29,
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
          _SFD_SET_DATA_PROPS(9,1,1,0,"win");
          _SFD_SET_DATA_PROPS(10,1,1,0,"woin");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Pk");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(13,1,1,0,"ESRin");
          _SFD_SET_DATA_PROPS(14,2,0,1,"y");
          _SFD_SET_DATA_PROPS(15,2,0,1,"e");
          _SFD_SET_DATA_PROPS(16,2,0,1,"w");
          _SFD_SET_DATA_PROPS(17,2,0,1,"wo");
          _SFD_SET_DATA_PROPS(18,2,0,1,"P");
          _SFD_SET_DATA_PROPS(19,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(20,2,0,1,"ESRout");
          _SFD_SET_DATA_PROPS(21,1,1,0,"t0in");
          _SFD_SET_DATA_PROPS(22,2,0,1,"t0");
          _SFD_SET_DATA_PROPS(23,1,1,0,"cntin");
          _SFD_SET_DATA_PROPS(24,2,0,1,"cnt");
          _SFD_SET_DATA_PROPS(25,1,1,0,"cntin1");
          _SFD_SET_DATA_PROPS(26,2,0,1,"cnt1");
          _SFD_SET_DATA_PROPS(27,1,1,0,"tk");
          _SFD_SET_DATA_PROPS(28,2,0,1,"tkout");
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
        _SFD_CV_INIT_EML(0,1,1,11,0,0,0,0,0,16,8);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4507);
        _SFD_CV_INIT_EML_IF(0,1,0,1690,1702,-1,4506);
        _SFD_CV_INIT_EML_IF(0,1,1,1783,1840,-1,2887);
        _SFD_CV_INIT_EML_IF(0,1,2,2029,2040,-1,2073);
        _SFD_CV_INIT_EML_IF(0,1,3,2091,2136,2237,2298);
        _SFD_CV_INIT_EML_IF(0,1,4,2237,2298,-1,2298);
        _SFD_CV_INIT_EML_IF(0,1,5,2892,2956,-1,3042);
        _SFD_CV_INIT_EML_IF(0,1,6,3204,3263,-1,4311);
        _SFD_CV_INIT_EML_IF(0,1,7,3316,3327,-1,3360);
        _SFD_CV_INIT_EML_IF(0,1,8,3378,3433,3560,3611);
        _SFD_CV_INIT_EML_IF(0,1,9,3560,3611,-1,3611);
        _SFD_CV_INIT_EML_IF(0,1,10,4316,4372,-1,4401);

        {
          static int condStart[] = { 1786, 1813 };

          static int condEnd[] = { 1809, 1839 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1786,1839,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2096, 2117 };

          static int condEnd[] = { 2113, 2135 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,2096,2135,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2246, 2272 };

          static int condEnd[] = { 2268, 2297 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,2246,2297,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2895, 2926 };

          static int condEnd[] = { 2922, 2955 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,2895,2955,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3207, 3240 };

          static int condEnd[] = { 3236, 3262 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,3207,3262,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3383, 3409 };

          static int condEnd[] = { 3405, 3432 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,5,3383,3432,2,10,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3569, 3590 };

          static int condEnd[] = { 3586, 3610 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,6,3569,3610,2,12,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4319, 4346 };

          static int condEnd[] = { 4342, 4371 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,7,4319,4371,2,14,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_vkout;
          real_T *c1_ikout;
          real_T *c1_start;
          real_T *c1_t;
          real_T *c1_duty;
          real_T *c1_v_out;
          real_T *c1_i_in;
          real_T *c1_vk;
          real_T *c1_ik;
          real_T *c1_win;
          real_T *c1_woin;
          real_T *c1_Pk;
          real_T *c1_Capin;
          real_T *c1_ESRin;
          real_T *c1_y;
          real_T *c1_e;
          real_T *c1_w;
          real_T *c1_wo;
          real_T *c1_P;
          real_T *c1_Capout;
          real_T *c1_ESRout;
          real_T *c1_t0in;
          real_T *c1_t0;
          real_T *c1_cntin;
          real_T *c1_cnt;
          real_T *c1_cntin1;
          real_T *c1_cnt1;
          real_T *c1_tk;
          real_T *c1_tkout;
          c1_tkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c1_tk = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c1_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c1_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c1_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c1_P = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_Pk = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_woin = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_win = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_ik = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_vk = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_ikout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_vkout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_vkout);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_ikout);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_start);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_duty);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_v_out);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_i_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_vk);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_ik);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_win);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_woin);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_Pk);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_Capin);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_ESRin);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_e);
          _SFD_SET_DATA_VALUE_PTR(16U, c1_w);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_wo);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_P);
          _SFD_SET_DATA_VALUE_PTR(19U, c1_Capout);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_ESRout);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_t0in);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_t0);
          _SFD_SET_DATA_VALUE_PTR(23U, c1_cntin);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_cnt);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_cntin1);
          _SFD_SET_DATA_VALUE_PTR(26U, c1_cnt1);
          _SFD_SET_DATA_VALUE_PTR(27U, c1_tk);
          _SFD_SET_DATA_VALUE_PTR(28U, c1_tkout);
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
  return "Kkmb4YplQWxSgEP7HJ0gkE";
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
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,16);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,13);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(801937755U));
  ssSetChecksum1(S,(1630007930U));
  ssSetChecksum2(S,(2686743978U));
  ssSetChecksum3(S,(2006933919U));
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
