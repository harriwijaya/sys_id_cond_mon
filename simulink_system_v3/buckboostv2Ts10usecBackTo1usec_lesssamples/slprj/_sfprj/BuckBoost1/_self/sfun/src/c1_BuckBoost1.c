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
static const char * c1_debug_family_names[122] = { "sampling_time_base",
  "splittime1", "splittime2", "offset", "OFFSET_ON_START_abs",
  "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel", "OFFSET_OFF_END_abs", "lambda",
  "delta", "u", "w", "P", "wi", "Pi", "uu", "wu", "Pu", "VnoiseAmp", "InoiseAmp",
  "STEPS", "SP_Num", "SP_ON_min", "SP_ON_max", "SP_ON_list", "SP_OFF_max",
  "SP_OFF_min", "SP_OFF_list", "sampling_time", "local_t", "k", "ku", "wu2real",
  "wu1real", "wu0real", "wi1real", "wi0real", "temp_1", "temp_2", "temp_3", "c",
  "allowedRateChange", "rateChange", "nargin", "nargout", "startrej", "start",
  "t", "duty", "v_out", "i_in", "w0in", "w1in", "P11in", "P12in", "P21in",
  "P22in", "Capin", "wi0in", "wi1in", "Pi11in", "Pi12in", "Pi21in", "Pi22in",
  "wu0in", "wu1in", "wu2in", "Pu11in", "Pu12in", "Pu13in", "Pu21in", "Pu22in",
  "Pu23in", "Pu31in", "Pu32in", "Pu33in", "ESRin", "t0in", "cntin", "cntin1",
  "y", "e", "w0", "w1", "P11", "P12", "P21", "P22", "Capout", "yi", "ei", "wi0",
  "wi1", "Pi11", "Pi12", "Pi21", "Pi22", "yu", "eu", "wu0", "wu1", "wu2", "Pu11",
  "Pu12", "Pu13", "Pu21", "Pu22", "Pu23", "Pu31", "Pu32", "Pu33", "ESRout",
  "Vnoise", "Inoise", "t0", "k0", "k1", "ku0", "ku1", "ku2", "cnt", "cnt1" };

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
  const mxArray *c1_cnt1, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[4], int32_T c1_inData_sizes[2]);
static void c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data[4],
  int32_T c1_y_sizes[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[4],
  int32_T c1_outData_sizes[2]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[110]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[110]);
static void c1_check_forloop_overflow_error(SFc1_BuckBoost1InstanceStruct
  *chartInstance);
static real_T c1_abs(SFc1_BuckBoost1InstanceStruct *chartInstance, real_T c1_x);
static void c1_realmax(SFc1_BuckBoost1InstanceStruct *chartInstance);
static boolean_T c1_any(SFc1_BuckBoost1InstanceStruct *chartInstance, boolean_T
  c1_x[4]);
static real_T c1_rand(SFc1_BuckBoost1InstanceStruct *chartInstance);
static void c1_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_d_state[625]);
static void c1_twister_state_vector(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625]);
static void c1_b_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_r);
static void c1_eml_error(SFc1_BuckBoost1InstanceStruct *chartInstance);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_i_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_j_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier);
static uint32_T c1_k_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_l_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier);
static uint32_T c1_m_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_n_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625]);
static void c1_o_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625]);
static void c1_p_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2]);
static void c1_q_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2]);
static uint8_T c1_r_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier);
static uint8_T c1_s_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_twister_state_vector(SFc1_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed);
static real_T c1_c_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c1_d_state[625]);
static void init_dsm_address_info(SFc1_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_method_not_empty = FALSE;
  chartInstance->c1_state_not_empty = FALSE;
  chartInstance->c1_b_state_not_empty = FALSE;
  chartInstance->c1_c_state_not_empty = FALSE;
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
  real_T c1_n_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_o_hoistedGlobal;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_p_hoistedGlobal;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_q_hoistedGlobal;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_r_hoistedGlobal;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_s_hoistedGlobal;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_ab_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_bb_hoistedGlobal;
  real_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_cb_hoistedGlobal;
  real_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_db_hoistedGlobal;
  real_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_eb_hoistedGlobal;
  real_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  real_T c1_fb_hoistedGlobal;
  real_T c1_fb_u;
  const mxArray *c1_gb_y = NULL;
  real_T c1_gb_hoistedGlobal;
  real_T c1_gb_u;
  const mxArray *c1_hb_y = NULL;
  real_T c1_hb_hoistedGlobal;
  real_T c1_hb_u;
  const mxArray *c1_ib_y = NULL;
  real_T c1_ib_hoistedGlobal;
  real_T c1_ib_u;
  const mxArray *c1_jb_y = NULL;
  real_T c1_jb_hoistedGlobal;
  real_T c1_jb_u;
  const mxArray *c1_kb_y = NULL;
  real_T c1_kb_hoistedGlobal;
  real_T c1_kb_u;
  const mxArray *c1_lb_y = NULL;
  real_T c1_lb_hoistedGlobal;
  real_T c1_lb_u;
  const mxArray *c1_mb_y = NULL;
  real_T c1_mb_hoistedGlobal;
  real_T c1_mb_u;
  const mxArray *c1_nb_y = NULL;
  real_T c1_nb_hoistedGlobal;
  real_T c1_nb_u;
  const mxArray *c1_ob_y = NULL;
  real_T c1_ob_hoistedGlobal;
  real_T c1_ob_u;
  const mxArray *c1_pb_y = NULL;
  real_T c1_pb_hoistedGlobal;
  real_T c1_pb_u;
  const mxArray *c1_qb_y = NULL;
  real_T c1_qb_hoistedGlobal;
  real_T c1_qb_u;
  const mxArray *c1_rb_y = NULL;
  uint32_T c1_rb_hoistedGlobal;
  uint32_T c1_rb_u;
  const mxArray *c1_sb_y = NULL;
  uint32_T c1_sb_hoistedGlobal;
  uint32_T c1_sb_u;
  const mxArray *c1_tb_y = NULL;
  int32_T c1_i0;
  uint32_T c1_tb_u[625];
  const mxArray *c1_ub_y = NULL;
  int32_T c1_i1;
  uint32_T c1_ub_u[2];
  const mxArray *c1_vb_y = NULL;
  uint8_T c1_tb_hoistedGlobal;
  uint8_T c1_vb_u;
  const mxArray *c1_wb_y = NULL;
  real_T *c1_Capout;
  real_T *c1_ESRout;
  real_T *c1_Inoise;
  real_T *c1_P11;
  real_T *c1_P12;
  real_T *c1_P21;
  real_T *c1_P22;
  real_T *c1_Pi11;
  real_T *c1_Pi12;
  real_T *c1_Pi21;
  real_T *c1_Pi22;
  real_T *c1_Pu11;
  real_T *c1_Pu12;
  real_T *c1_Pu13;
  real_T *c1_Pu21;
  real_T *c1_Pu22;
  real_T *c1_Pu23;
  real_T *c1_Pu31;
  real_T *c1_Pu32;
  real_T *c1_Pu33;
  real_T *c1_Vnoise;
  real_T *c1_cnt;
  real_T *c1_cnt1;
  real_T *c1_e;
  real_T *c1_ei;
  real_T *c1_eu;
  real_T *c1_k0;
  real_T *c1_k1;
  real_T *c1_ku0;
  real_T *c1_ku1;
  real_T *c1_ku2;
  real_T *c1_t0;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_wi0;
  real_T *c1_wi1;
  real_T *c1_wu0;
  real_T *c1_wu1;
  real_T *c1_wu2;
  real_T *c1_xb_y;
  real_T *c1_yi;
  real_T *c1_yu;
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 42);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 41);
  c1_ku2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 40);
  c1_ku1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 39);
  c1_ku0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 38);
  c1_k1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 37);
  c1_k0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 36);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 35);
  c1_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 34);
  c1_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 33);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c1_Pu33 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c1_Pu32 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c1_Pu31 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c1_Pu23 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c1_Pu22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c1_Pu21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c1_Pu13 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c1_Pu12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c1_Pu11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c1_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c1_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c1_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c1_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c1_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c1_Pi22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c1_Pi21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c1_Pi12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c1_Pi11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_xb_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(47), FALSE);
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
  c1_c_hoistedGlobal = *c1_Inoise;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_P11;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_P12;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_P21;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_P22;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = *c1_Pi11;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = *c1_Pi12;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = *c1_Pi21;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = *c1_Pi22;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = *c1_Pu11;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = *c1_Pu12;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = *c1_Pu13;
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = *c1_Pu21;
  c1_o_u = c1_o_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_p_hoistedGlobal = *c1_Pu22;
  c1_p_u = c1_p_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_q_hoistedGlobal = *c1_Pu23;
  c1_q_u = c1_q_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_r_hoistedGlobal = *c1_Pu31;
  c1_r_u = c1_r_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_s_hoistedGlobal = *c1_Pu32;
  c1_s_u = c1_s_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_t_hoistedGlobal = *c1_Pu33;
  c1_t_u = c1_t_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_u_hoistedGlobal = *c1_Vnoise;
  c1_u_u = c1_u_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_v_hoistedGlobal = *c1_cnt;
  c1_v_u = c1_v_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_w_hoistedGlobal = *c1_cnt1;
  c1_w_u = c1_w_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_x_hoistedGlobal = *c1_e;
  c1_x_u = c1_x_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_y_hoistedGlobal = *c1_ei;
  c1_y_u = c1_y_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_ab_hoistedGlobal = *c1_eu;
  c1_ab_u = c1_ab_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_bb_hoistedGlobal = *c1_k0;
  c1_bb_u = c1_bb_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_cb_hoistedGlobal = *c1_k1;
  c1_cb_u = c1_cb_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_db_hoistedGlobal = *c1_ku0;
  c1_db_u = c1_db_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_eb_hoistedGlobal = *c1_ku1;
  c1_eb_u = c1_eb_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_fb_hoistedGlobal = *c1_ku2;
  c1_fb_u = c1_fb_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_fb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_gb_hoistedGlobal = *c1_t0;
  c1_gb_u = c1_gb_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_gb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_hb_hoistedGlobal = *c1_w0;
  c1_hb_u = c1_hb_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_hb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_ib_hoistedGlobal = *c1_w1;
  c1_ib_u = c1_ib_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_ib_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_jb_hoistedGlobal = *c1_wi0;
  c1_jb_u = c1_jb_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_jb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_kb_hoistedGlobal = *c1_wi1;
  c1_kb_u = c1_kb_hoistedGlobal;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_kb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_lb_hoistedGlobal = *c1_wu0;
  c1_lb_u = c1_lb_hoistedGlobal;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_lb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  c1_mb_hoistedGlobal = *c1_wu1;
  c1_mb_u = c1_mb_hoistedGlobal;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_mb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 37, c1_nb_y);
  c1_nb_hoistedGlobal = *c1_wu2;
  c1_nb_u = c1_nb_hoistedGlobal;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_nb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 38, c1_ob_y);
  c1_ob_hoistedGlobal = *c1_xb_y;
  c1_ob_u = c1_ob_hoistedGlobal;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_ob_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 39, c1_pb_y);
  c1_pb_hoistedGlobal = *c1_yi;
  c1_pb_u = c1_pb_hoistedGlobal;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_pb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 40, c1_qb_y);
  c1_qb_hoistedGlobal = *c1_yu;
  c1_qb_u = c1_qb_hoistedGlobal;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_qb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 41, c1_rb_y);
  c1_rb_hoistedGlobal = chartInstance->c1_method;
  c1_rb_u = c1_rb_hoistedGlobal;
  c1_sb_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_sb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_sb_y, sf_mex_create("y", &c1_rb_u, 7, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 42, c1_sb_y);
  c1_sb_hoistedGlobal = chartInstance->c1_state;
  c1_sb_u = c1_sb_hoistedGlobal;
  c1_tb_y = NULL;
  if (!chartInstance->c1_state_not_empty) {
    sf_mex_assign(&c1_tb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_tb_y, sf_mex_create("y", &c1_sb_u, 7, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 43, c1_tb_y);
  for (c1_i0 = 0; c1_i0 < 625; c1_i0++) {
    c1_tb_u[c1_i0] = chartInstance->c1_c_state[c1_i0];
  }

  c1_ub_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_ub_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_ub_y, sf_mex_create("y", c1_tb_u, 7, 0U, 1U, 0U, 1, 625),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 44, c1_ub_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_ub_u[c1_i1] = chartInstance->c1_b_state[c1_i1];
  }

  c1_vb_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_vb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_vb_y, sf_mex_create("y", c1_ub_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 45, c1_vb_y);
  c1_tb_hoistedGlobal = chartInstance->c1_is_active_c1_BuckBoost1;
  c1_vb_u = c1_tb_hoistedGlobal;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_vb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 46, c1_wb_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_BuckBoost1(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  uint32_T c1_uv0[625];
  int32_T c1_i2;
  uint32_T c1_uv1[2];
  int32_T c1_i3;
  real_T *c1_Capout;
  real_T *c1_ESRout;
  real_T *c1_Inoise;
  real_T *c1_P11;
  real_T *c1_P12;
  real_T *c1_P21;
  real_T *c1_P22;
  real_T *c1_Pi11;
  real_T *c1_Pi12;
  real_T *c1_Pi21;
  real_T *c1_Pi22;
  real_T *c1_Pu11;
  real_T *c1_Pu12;
  real_T *c1_Pu13;
  real_T *c1_Pu21;
  real_T *c1_Pu22;
  real_T *c1_Pu23;
  real_T *c1_Pu31;
  real_T *c1_Pu32;
  real_T *c1_Pu33;
  real_T *c1_Vnoise;
  real_T *c1_cnt;
  real_T *c1_cnt1;
  real_T *c1_e;
  real_T *c1_ei;
  real_T *c1_eu;
  real_T *c1_k0;
  real_T *c1_k1;
  real_T *c1_ku0;
  real_T *c1_ku1;
  real_T *c1_ku2;
  real_T *c1_t0;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_wi0;
  real_T *c1_wi1;
  real_T *c1_wu0;
  real_T *c1_wu1;
  real_T *c1_wu2;
  real_T *c1_y;
  real_T *c1_yi;
  real_T *c1_yu;
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 42);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 41);
  c1_ku2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 40);
  c1_ku1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 39);
  c1_ku0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 38);
  c1_k1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 37);
  c1_k0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 36);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 35);
  c1_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 34);
  c1_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 33);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c1_Pu33 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c1_Pu32 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c1_Pu31 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c1_Pu23 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c1_Pu22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c1_Pu21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c1_Pu13 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c1_Pu12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c1_Pu11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c1_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c1_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c1_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c1_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c1_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c1_Pi22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c1_Pi21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c1_Pi12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c1_Pi11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Capout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Capout");
  *c1_ESRout = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "ESRout");
  *c1_Inoise = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "Inoise");
  *c1_P11 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "P11");
  *c1_P12 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "P12");
  *c1_P21 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
    "P21");
  *c1_P22 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
    "P22");
  *c1_Pi11 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    7)), "Pi11");
  *c1_Pi12 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    8)), "Pi12");
  *c1_Pi21 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    9)), "Pi21");
  *c1_Pi22 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    10)), "Pi22");
  *c1_Pu11 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    11)), "Pu11");
  *c1_Pu12 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    12)), "Pu12");
  *c1_Pu13 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    13)), "Pu13");
  *c1_Pu21 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    14)), "Pu21");
  *c1_Pu22 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    15)), "Pu22");
  *c1_Pu23 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    16)), "Pu23");
  *c1_Pu31 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    17)), "Pu31");
  *c1_Pu32 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    18)), "Pu32");
  *c1_Pu33 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    19)), "Pu33");
  *c1_Vnoise = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    20)), "Vnoise");
  *c1_cnt = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    21)), "cnt");
  *c1_cnt1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    22)), "cnt1");
  *c1_e = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 23)),
    "e");
  *c1_ei = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 24)),
    "ei");
  *c1_eu = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 25)),
    "eu");
  *c1_k0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 26)),
    "k0");
  *c1_k1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 27)),
    "k1");
  *c1_ku0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    28)), "ku0");
  *c1_ku1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    29)), "ku1");
  *c1_ku2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    30)), "ku2");
  *c1_t0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 31)),
    "t0");
  *c1_w0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 32)),
    "w0");
  *c1_w1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 33)),
    "w1");
  *c1_wi0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    34)), "wi0");
  *c1_wi1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    35)), "wi1");
  *c1_wu0 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    36)), "wu0");
  *c1_wu1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    37)), "wu1");
  *c1_wu2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    38)), "wu2");
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 39)),
    "y");
  *c1_yi = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 40)),
    "yi");
  *c1_yu = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 41)),
    "yu");
  chartInstance->c1_method = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 42)), "method");
  chartInstance->c1_state = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 43)), "state");
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 44)),
                        "state", c1_uv0);
  for (c1_i2 = 0; c1_i2 < 625; c1_i2++) {
    chartInstance->c1_c_state[c1_i2] = c1_uv0[c1_i2];
  }

  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 45)),
                        "state", c1_uv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_b_state[c1_i3] = c1_uv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_BuckBoost1 = c1_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 46)),
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
  real_T *c1_startrej;
  real_T *c1_start;
  real_T *c1_t;
  real_T *c1_duty;
  real_T *c1_v_out;
  real_T *c1_i_in;
  real_T *c1_w0in;
  real_T *c1_w1in;
  real_T *c1_P11in;
  real_T *c1_P12in;
  real_T *c1_P21in;
  real_T *c1_P22in;
  real_T *c1_Capin;
  real_T *c1_y;
  real_T *c1_e;
  real_T *c1_w0;
  real_T *c1_w1;
  real_T *c1_P11;
  real_T *c1_P12;
  real_T *c1_P21;
  real_T *c1_P22;
  real_T *c1_Capout;
  real_T *c1_wi0in;
  real_T *c1_wi1in;
  real_T *c1_Pi11in;
  real_T *c1_Pi12in;
  real_T *c1_Pi21in;
  real_T *c1_Pi22in;
  real_T *c1_wu0in;
  real_T *c1_wu1in;
  real_T *c1_wu2in;
  real_T *c1_Pu11in;
  real_T *c1_Pu12in;
  real_T *c1_Pu13in;
  real_T *c1_Pu21in;
  real_T *c1_Pu22in;
  real_T *c1_Pu23in;
  real_T *c1_Pu31in;
  real_T *c1_Pu32in;
  real_T *c1_Pu33in;
  real_T *c1_ESRin;
  real_T *c1_t0in;
  real_T *c1_yi;
  real_T *c1_ei;
  real_T *c1_wi0;
  real_T *c1_wi1;
  real_T *c1_Pi11;
  real_T *c1_Pi12;
  real_T *c1_Pi21;
  real_T *c1_Pi22;
  real_T *c1_yu;
  real_T *c1_eu;
  real_T *c1_wu0;
  real_T *c1_wu1;
  real_T *c1_wu2;
  real_T *c1_Pu11;
  real_T *c1_Pu12;
  real_T *c1_Pu13;
  real_T *c1_Pu21;
  real_T *c1_Pu22;
  real_T *c1_Pu23;
  real_T *c1_Pu31;
  real_T *c1_Pu32;
  real_T *c1_Pu33;
  real_T *c1_ESRout;
  real_T *c1_Vnoise;
  real_T *c1_Inoise;
  real_T *c1_t0;
  real_T *c1_k0;
  real_T *c1_k1;
  real_T *c1_ku0;
  real_T *c1_ku1;
  real_T *c1_ku2;
  real_T *c1_cntin;
  real_T *c1_cnt;
  real_T *c1_cntin1;
  real_T *c1_cnt1;
  c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 42);
  c1_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
  c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 41);
  c1_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
  c1_ku2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 40);
  c1_ku1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 39);
  c1_ku0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 38);
  c1_k1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 37);
  c1_k0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 36);
  c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 35);
  c1_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 34);
  c1_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 33);
  c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c1_Pu33 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c1_Pu32 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c1_Pu31 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c1_Pu23 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c1_Pu22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c1_Pu21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c1_Pu13 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c1_Pu12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c1_Pu11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c1_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c1_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c1_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c1_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c1_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c1_Pi22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c1_Pi21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c1_Pi12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c1_Pi11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
  c1_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
  c1_Pu33in = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
  c1_Pu32in = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
  c1_Pu31in = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c1_Pu23in = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c1_Pu22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c1_Pu21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c1_Pu13in = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c1_Pu12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c1_Pu11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c1_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c1_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c1_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c1_Pi22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_Pi21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_Pi12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_Pi11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_startrej = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_startrej, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_start, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_t, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_duty, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_v_out, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_i_in, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_w0in, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_w1in, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_P11in, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_P12in, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_P21in, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_P22in, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_Capin, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_y, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_e, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_w0, 15U);
  _SFD_DATA_RANGE_CHECK(*c1_w1, 16U);
  _SFD_DATA_RANGE_CHECK(*c1_P11, 17U);
  _SFD_DATA_RANGE_CHECK(*c1_P12, 18U);
  _SFD_DATA_RANGE_CHECK(*c1_P21, 19U);
  _SFD_DATA_RANGE_CHECK(*c1_P22, 20U);
  _SFD_DATA_RANGE_CHECK(*c1_Capout, 21U);
  _SFD_DATA_RANGE_CHECK(*c1_wi0in, 22U);
  _SFD_DATA_RANGE_CHECK(*c1_wi1in, 23U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi11in, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi12in, 25U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi21in, 26U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi22in, 27U);
  _SFD_DATA_RANGE_CHECK(*c1_wu0in, 28U);
  _SFD_DATA_RANGE_CHECK(*c1_wu1in, 29U);
  _SFD_DATA_RANGE_CHECK(*c1_wu2in, 30U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu11in, 31U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu12in, 32U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu13in, 33U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu21in, 34U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu22in, 35U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu23in, 36U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu31in, 37U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu32in, 38U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu33in, 39U);
  _SFD_DATA_RANGE_CHECK(*c1_ESRin, 40U);
  _SFD_DATA_RANGE_CHECK(*c1_t0in, 41U);
  _SFD_DATA_RANGE_CHECK(*c1_yi, 42U);
  _SFD_DATA_RANGE_CHECK(*c1_ei, 43U);
  _SFD_DATA_RANGE_CHECK(*c1_wi0, 44U);
  _SFD_DATA_RANGE_CHECK(*c1_wi1, 45U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi11, 46U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi12, 47U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi21, 48U);
  _SFD_DATA_RANGE_CHECK(*c1_Pi22, 49U);
  _SFD_DATA_RANGE_CHECK(*c1_yu, 50U);
  _SFD_DATA_RANGE_CHECK(*c1_eu, 51U);
  _SFD_DATA_RANGE_CHECK(*c1_wu0, 52U);
  _SFD_DATA_RANGE_CHECK(*c1_wu1, 53U);
  _SFD_DATA_RANGE_CHECK(*c1_wu2, 54U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu11, 55U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu12, 56U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu13, 57U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu21, 58U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu22, 59U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu23, 60U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu31, 61U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu32, 62U);
  _SFD_DATA_RANGE_CHECK(*c1_Pu33, 63U);
  _SFD_DATA_RANGE_CHECK(*c1_ESRout, 64U);
  _SFD_DATA_RANGE_CHECK(*c1_Vnoise, 65U);
  _SFD_DATA_RANGE_CHECK(*c1_Inoise, 66U);
  _SFD_DATA_RANGE_CHECK(*c1_t0, 67U);
  _SFD_DATA_RANGE_CHECK(*c1_k0, 68U);
  _SFD_DATA_RANGE_CHECK(*c1_k1, 69U);
  _SFD_DATA_RANGE_CHECK(*c1_ku0, 70U);
  _SFD_DATA_RANGE_CHECK(*c1_ku1, 71U);
  _SFD_DATA_RANGE_CHECK(*c1_ku2, 72U);
  _SFD_DATA_RANGE_CHECK(*c1_cntin, 73U);
  _SFD_DATA_RANGE_CHECK(*c1_cnt, 74U);
  _SFD_DATA_RANGE_CHECK(*c1_cntin1, 75U);
  _SFD_DATA_RANGE_CHECK(*c1_cnt1, 76U);
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
  real_T c1_q_hoistedGlobal;
  real_T c1_r_hoistedGlobal;
  real_T c1_s_hoistedGlobal;
  real_T c1_t_hoistedGlobal;
  real_T c1_u_hoistedGlobal;
  real_T c1_v_hoistedGlobal;
  real_T c1_w_hoistedGlobal;
  real_T c1_x_hoistedGlobal;
  real_T c1_y_hoistedGlobal;
  real_T c1_ab_hoistedGlobal;
  real_T c1_bb_hoistedGlobal;
  real_T c1_cb_hoistedGlobal;
  real_T c1_db_hoistedGlobal;
  real_T c1_eb_hoistedGlobal;
  real_T c1_fb_hoistedGlobal;
  real_T c1_gb_hoistedGlobal;
  real_T c1_hb_hoistedGlobal;
  real_T c1_ib_hoistedGlobal;
  real_T c1_jb_hoistedGlobal;
  real_T c1_startrej;
  real_T c1_start;
  real_T c1_t;
  real_T c1_duty;
  real_T c1_v_out;
  real_T c1_i_in;
  real_T c1_w0in;
  real_T c1_w1in;
  real_T c1_P11in;
  real_T c1_P12in;
  real_T c1_P21in;
  real_T c1_P22in;
  real_T c1_Capin;
  real_T c1_wi0in;
  real_T c1_wi1in;
  real_T c1_Pi11in;
  real_T c1_Pi12in;
  real_T c1_Pi21in;
  real_T c1_Pi22in;
  real_T c1_wu0in;
  real_T c1_wu1in;
  real_T c1_wu2in;
  real_T c1_Pu11in;
  real_T c1_Pu12in;
  real_T c1_Pu13in;
  real_T c1_Pu21in;
  real_T c1_Pu22in;
  real_T c1_Pu23in;
  real_T c1_Pu31in;
  real_T c1_Pu32in;
  real_T c1_Pu33in;
  real_T c1_ESRin;
  real_T c1_t0in;
  real_T c1_cntin;
  real_T c1_cntin1;
  uint32_T c1_debug_family_var_map[122];
  real_T c1_sampling_time_base;
  real_T c1_splittime1;
  real_T c1_splittime2;
  real_T c1_offset;
  real_T c1_OFFSET_ON_START_abs;
  real_T c1_OFFSET_ON_END_rel;
  real_T c1_OFFSET_OFF_START_rel;
  real_T c1_OFFSET_OFF_END_abs;
  real_T c1_lambda;
  real_T c1_delta;
  real_T c1_u[2];
  real_T c1_w[2];
  real_T c1_P[4];
  real_T c1_wi[2];
  real_T c1_Pi[4];
  real_T c1_uu[3];
  real_T c1_wu[3];
  real_T c1_Pu[9];
  real_T c1_VnoiseAmp;
  real_T c1_InoiseAmp;
  real_T c1_STEPS;
  real_T c1_SP_Num;
  real_T c1_SP_ON_min;
  real_T c1_SP_ON_max;
  real_T c1_SP_ON_list[4];
  real_T c1_SP_OFF_max;
  real_T c1_SP_OFF_min;
  real_T c1_SP_OFF_list[4];
  real_T c1_sampling_time;
  int32_T c1_local_t_sizes[2];
  real_T c1_local_t_data[4];
  real_T c1_k[2];
  real_T c1_ku[3];
  real_T c1_wu2real;
  real_T c1_wu1real;
  real_T c1_wu0real;
  real_T c1_wi1real;
  real_T c1_wi0real;
  real_T c1_temp_1;
  real_T c1_temp_2;
  real_T c1_temp_3;
  real_T c1_c;
  real_T c1_allowedRateChange;
  real_T c1_rateChange;
  real_T c1_nargin = 35.0;
  real_T c1_nargout = 42.0;
  real_T c1_y;
  real_T c1_e;
  real_T c1_w0;
  real_T c1_w1;
  real_T c1_P11;
  real_T c1_P12;
  real_T c1_P21;
  real_T c1_P22;
  real_T c1_Capout;
  real_T c1_yi;
  real_T c1_ei;
  real_T c1_wi0;
  real_T c1_wi1;
  real_T c1_Pi11;
  real_T c1_Pi12;
  real_T c1_Pi21;
  real_T c1_Pi22;
  real_T c1_yu;
  real_T c1_eu;
  real_T c1_wu0;
  real_T c1_wu1;
  real_T c1_wu2;
  real_T c1_Pu11;
  real_T c1_Pu12;
  real_T c1_Pu13;
  real_T c1_Pu21;
  real_T c1_Pu22;
  real_T c1_Pu23;
  real_T c1_Pu31;
  real_T c1_Pu32;
  real_T c1_Pu33;
  real_T c1_ESRout;
  real_T c1_Vnoise;
  real_T c1_Inoise;
  real_T c1_t0;
  real_T c1_k0;
  real_T c1_k1;
  real_T c1_ku0;
  real_T c1_ku1;
  real_T c1_ku2;
  real_T c1_cnt;
  real_T c1_cnt1;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  static real_T c1_dv0[4] = { 100.0, 0.0, 0.0, 100.0 };

  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_y;
  int32_T c1_i10;
  int32_T c1_i11;
  static real_T c1_dv1[9] = { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0
  };

  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  boolean_T c1_b_t[4];
  int32_T c1_i15;
  boolean_T c1_x[4];
  int32_T c1_idx;
  int32_T c1_i16;
  int32_T c1_ii_sizes[2];
  int32_T c1_ii;
  int32_T c1_b_ii;
  int32_T c1_b_a;
  int32_T c1_ii_data[4];
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  int32_T c1_i17;
  int32_T c1_tmp_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i18;
  int32_T c1_tmp_data[4];
  int32_T c1_iv0[2];
  int32_T c1_b_ii_sizes[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i19;
  int32_T c1_c_loop_ub;
  int32_T c1_i20;
  int32_T c1_b_ii_data[4];
  int32_T c1_d_loop_ub;
  int32_T c1_i21;
  int32_T c1_i_sizes[2];
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_e_loop_ub;
  int32_T c1_i22;
  real_T c1_i_data[4];
  int32_T c1_local_t;
  int32_T c1_b_local_t;
  int32_T c1_f_loop_ub;
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_c_a[4];
  int32_T c1_i25;
  real_T c1_b_b[2];
  int32_T c1_i26;
  real_T c1_c_y[2];
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_d_a[2];
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_d_y[2];
  int32_T c1_i33;
  int32_T c1_i34;
  real_T c1_e_y;
  int32_T c1_b_k;
  int32_T c1_c_k;
  real_T c1_A;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_f_y;
  real_T c1_B;
  real_T c1_g_y;
  real_T c1_h_y;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_d_k;
  int32_T c1_e_k;
  real_T c1_c_b;
  real_T c1_i_y;
  real_T c1_d_b;
  real_T c1_j_y;
  int32_T c1_i39;
  real_T c1_e_b;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  real_T c1_k_y[4];
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  real_T c1_l_y[4];
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_d_x;
  real_T c1_m_y;
  real_T c1_e_x;
  real_T c1_n_y;
  real_T c1_o_y;
  real_T c1_c_A;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_p_y;
  real_T c1_e_a;
  int32_T c1_i55;
  boolean_T c1_c_t[4];
  int32_T c1_i56;
  int32_T c1_b_idx;
  int32_T c1_i57;
  int32_T c1_c_ii;
  int32_T c1_d_ii;
  int32_T c1_f_a;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  int32_T c1_i58;
  int32_T c1_b_tmp_sizes;
  int32_T c1_g_loop_ub;
  int32_T c1_i59;
  int32_T c1_b_tmp_data[4];
  int32_T c1_iv1[2];
  int32_T c1_c_ii_sizes[2];
  int32_T c1_h_loop_ub;
  int32_T c1_i60;
  int32_T c1_i_loop_ub;
  int32_T c1_i61;
  int32_T c1_c_ii_data[4];
  int32_T c1_j_loop_ub;
  int32_T c1_i62;
  int32_T c1_c_i;
  int32_T c1_d_i;
  int32_T c1_k_loop_ub;
  int32_T c1_i63;
  int32_T c1_c_local_t;
  int32_T c1_d_local_t;
  int32_T c1_l_loop_ub;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  real_T c1_q_y;
  int32_T c1_f_k;
  int32_T c1_g_k;
  real_T c1_d_A;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_r_y;
  real_T c1_c_B;
  real_T c1_s_y;
  real_T c1_t_y;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_h_k;
  int32_T c1_i_k;
  real_T c1_f_b;
  real_T c1_u_y;
  real_T c1_g_b;
  real_T c1_v_y;
  int32_T c1_i80;
  real_T c1_h_b;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  real_T c1_g_a;
  real_T c1_i_b;
  real_T c1_w_y;
  int32_T c1_i96;
  real_T c1_h_a[9];
  int32_T c1_i97;
  real_T c1_j_b[3];
  int32_T c1_i98;
  real_T c1_x_y[3];
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  real_T c1_i_a[3];
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  real_T c1_y_y[3];
  int32_T c1_i105;
  int32_T c1_i106;
  real_T c1_ab_y;
  int32_T c1_j_k;
  int32_T c1_k_k;
  real_T c1_e_A;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_bb_y;
  real_T c1_d_B;
  real_T c1_cb_y;
  real_T c1_db_y;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i110;
  int32_T c1_l_k;
  int32_T c1_m_k;
  real_T c1_k_b;
  real_T c1_eb_y;
  real_T c1_l_b;
  real_T c1_fb_y;
  int32_T c1_i111;
  real_T c1_m_b;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_gb_y[9];
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  real_T c1_hb_y[9];
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  real_T c1_f_A;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_g_A;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_h_A;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_n_b;
  real_T c1_ib_y;
  real_T c1_j_a;
  real_T c1_o_b;
  real_T c1_k_a;
  real_T c1_l_a;
  real_T c1_jb_y;
  real_T c1_m_a;
  real_T c1_p_b;
  real_T c1_kb_y;
  real_T c1_i_A;
  real_T c1_e_B;
  real_T c1_r_x;
  real_T c1_lb_y;
  real_T c1_s_x;
  real_T c1_mb_y;
  real_T c1_nb_y;
  real_T c1_n_a;
  real_T c1_q_b;
  real_T c1_ob_y;
  real_T c1_o_a;
  real_T c1_pb_y;
  real_T c1_p_a;
  real_T c1_qb_y;
  real_T c1_q_a;
  real_T c1_r_b;
  real_T c1_rb_y;
  real_T c1_j_A;
  real_T c1_f_B;
  real_T c1_t_x;
  real_T c1_sb_y;
  real_T c1_u_x;
  real_T c1_tb_y;
  real_T c1_k_A;
  real_T c1_g_B;
  real_T c1_v_x;
  real_T c1_ub_y;
  real_T c1_w_x;
  real_T c1_vb_y;
  real_T c1_wb_y;
  real_T c1_r_a;
  real_T c1_l_A;
  real_T c1_h_B;
  real_T c1_x_x;
  real_T c1_xb_y;
  real_T c1_y_x;
  real_T c1_yb_y;
  real_T c1_ac_y;
  real_T c1_s_a;
  real_T *c1_b_startrej;
  real_T *c1_b_start;
  real_T *c1_d_t;
  real_T *c1_b_duty;
  real_T *c1_b_v_out;
  real_T *c1_b_i_in;
  real_T *c1_b_w0in;
  real_T *c1_b_w1in;
  real_T *c1_b_P11in;
  real_T *c1_b_P12in;
  real_T *c1_b_P21in;
  real_T *c1_b_P22in;
  real_T *c1_b_Capin;
  real_T *c1_b_wi0in;
  real_T *c1_b_wi1in;
  real_T *c1_b_Pi11in;
  real_T *c1_b_Pi12in;
  real_T *c1_b_Pi21in;
  real_T *c1_b_Pi22in;
  real_T *c1_b_wu0in;
  real_T *c1_b_wu1in;
  real_T *c1_b_wu2in;
  real_T *c1_b_Pu11in;
  real_T *c1_b_Pu12in;
  real_T *c1_b_Pu13in;
  real_T *c1_b_Pu21in;
  real_T *c1_b_Pu22in;
  real_T *c1_b_Pu23in;
  real_T *c1_b_Pu31in;
  real_T *c1_b_Pu32in;
  real_T *c1_b_Pu33in;
  real_T *c1_b_ESRin;
  real_T *c1_b_t0in;
  real_T *c1_b_cntin;
  real_T *c1_b_cntin1;
  real_T *c1_bc_y;
  real_T *c1_b_e;
  real_T *c1_b_w0;
  real_T *c1_b_w1;
  real_T *c1_b_P11;
  real_T *c1_b_P12;
  real_T *c1_b_P21;
  real_T *c1_b_P22;
  real_T *c1_b_Capout;
  real_T *c1_b_yi;
  real_T *c1_b_ei;
  real_T *c1_b_wi0;
  real_T *c1_b_wi1;
  real_T *c1_b_Pi11;
  real_T *c1_b_Pi12;
  real_T *c1_b_Pi21;
  real_T *c1_b_Pi22;
  real_T *c1_b_yu;
  real_T *c1_b_eu;
  real_T *c1_b_wu0;
  real_T *c1_b_wu1;
  real_T *c1_b_wu2;
  real_T *c1_b_Pu11;
  real_T *c1_b_Pu12;
  real_T *c1_b_Pu13;
  real_T *c1_b_Pu21;
  real_T *c1_b_Pu22;
  real_T *c1_b_Pu23;
  real_T *c1_b_Pu31;
  real_T *c1_b_Pu32;
  real_T *c1_b_Pu33;
  real_T *c1_b_ESRout;
  real_T *c1_b_Vnoise;
  real_T *c1_b_Inoise;
  real_T *c1_b_t0;
  real_T *c1_b_k0;
  real_T *c1_b_k1;
  real_T *c1_b_ku0;
  real_T *c1_b_ku1;
  real_T *c1_b_ku2;
  real_T *c1_b_cnt;
  real_T *c1_b_cnt1;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard11 = FALSE;
  boolean_T guard21 = FALSE;
  c1_b_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 42);
  c1_b_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
  c1_b_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 41);
  c1_b_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
  c1_b_ku2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 40);
  c1_b_ku1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 39);
  c1_b_ku0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 38);
  c1_b_k1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 37);
  c1_b_k0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 36);
  c1_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 35);
  c1_b_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 34);
  c1_b_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 33);
  c1_b_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c1_b_Pu33 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c1_b_Pu32 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c1_b_Pu31 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c1_b_Pu23 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c1_b_Pu22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c1_b_Pu21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c1_b_Pu13 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c1_b_Pu12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c1_b_Pu11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c1_b_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c1_b_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c1_b_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c1_b_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c1_b_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c1_b_Pi22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c1_b_Pi21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c1_b_Pi12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c1_b_Pi11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_b_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_b_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_b_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_b_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_b_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
  c1_b_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
  c1_b_Pu33in = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
  c1_b_Pu32in = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
  c1_b_Pu31in = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c1_b_Pu23in = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c1_b_Pu22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c1_b_Pu21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c1_b_Pu13in = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c1_b_Pu12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c1_b_Pu11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c1_b_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c1_b_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c1_b_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c1_b_Pi22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_b_Pi21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_b_Pi12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_b_Pi11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_b_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_b_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_b_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_b_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_b_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_b_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_bc_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_b_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_b_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_b_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_d_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_startrej = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_startrej;
  c1_b_hoistedGlobal = *c1_b_start;
  c1_c_hoistedGlobal = *c1_d_t;
  c1_d_hoistedGlobal = *c1_b_duty;
  c1_e_hoistedGlobal = *c1_b_v_out;
  c1_f_hoistedGlobal = *c1_b_i_in;
  c1_g_hoistedGlobal = *c1_b_w0in;
  c1_h_hoistedGlobal = *c1_b_w1in;
  c1_i_hoistedGlobal = *c1_b_P11in;
  c1_j_hoistedGlobal = *c1_b_P12in;
  c1_k_hoistedGlobal = *c1_b_P21in;
  c1_l_hoistedGlobal = *c1_b_P22in;
  c1_m_hoistedGlobal = *c1_b_Capin;
  c1_n_hoistedGlobal = *c1_b_wi0in;
  c1_o_hoistedGlobal = *c1_b_wi1in;
  c1_p_hoistedGlobal = *c1_b_Pi11in;
  c1_q_hoistedGlobal = *c1_b_Pi12in;
  c1_r_hoistedGlobal = *c1_b_Pi21in;
  c1_s_hoistedGlobal = *c1_b_Pi22in;
  c1_t_hoistedGlobal = *c1_b_wu0in;
  c1_u_hoistedGlobal = *c1_b_wu1in;
  c1_v_hoistedGlobal = *c1_b_wu2in;
  c1_w_hoistedGlobal = *c1_b_Pu11in;
  c1_x_hoistedGlobal = *c1_b_Pu12in;
  c1_y_hoistedGlobal = *c1_b_Pu13in;
  c1_ab_hoistedGlobal = *c1_b_Pu21in;
  c1_bb_hoistedGlobal = *c1_b_Pu22in;
  c1_cb_hoistedGlobal = *c1_b_Pu23in;
  c1_db_hoistedGlobal = *c1_b_Pu31in;
  c1_eb_hoistedGlobal = *c1_b_Pu32in;
  c1_fb_hoistedGlobal = *c1_b_Pu33in;
  c1_gb_hoistedGlobal = *c1_b_ESRin;
  c1_hb_hoistedGlobal = *c1_b_t0in;
  c1_ib_hoistedGlobal = *c1_b_cntin;
  c1_jb_hoistedGlobal = *c1_b_cntin1;
  c1_startrej = c1_hoistedGlobal;
  c1_start = c1_b_hoistedGlobal;
  c1_t = c1_c_hoistedGlobal;
  c1_duty = c1_d_hoistedGlobal;
  c1_v_out = c1_e_hoistedGlobal;
  c1_i_in = c1_f_hoistedGlobal;
  c1_w0in = c1_g_hoistedGlobal;
  c1_w1in = c1_h_hoistedGlobal;
  c1_P11in = c1_i_hoistedGlobal;
  c1_P12in = c1_j_hoistedGlobal;
  c1_P21in = c1_k_hoistedGlobal;
  c1_P22in = c1_l_hoistedGlobal;
  c1_Capin = c1_m_hoistedGlobal;
  c1_wi0in = c1_n_hoistedGlobal;
  c1_wi1in = c1_o_hoistedGlobal;
  c1_Pi11in = c1_p_hoistedGlobal;
  c1_Pi12in = c1_q_hoistedGlobal;
  c1_Pi21in = c1_r_hoistedGlobal;
  c1_Pi22in = c1_s_hoistedGlobal;
  c1_wu0in = c1_t_hoistedGlobal;
  c1_wu1in = c1_u_hoistedGlobal;
  c1_wu2in = c1_v_hoistedGlobal;
  c1_Pu11in = c1_w_hoistedGlobal;
  c1_Pu12in = c1_x_hoistedGlobal;
  c1_Pu13in = c1_y_hoistedGlobal;
  c1_Pu21in = c1_ab_hoistedGlobal;
  c1_Pu22in = c1_bb_hoistedGlobal;
  c1_Pu23in = c1_cb_hoistedGlobal;
  c1_Pu31in = c1_db_hoistedGlobal;
  c1_Pu32in = c1_eb_hoistedGlobal;
  c1_Pu33in = c1_fb_hoistedGlobal;
  c1_ESRin = c1_gb_hoistedGlobal;
  c1_t0in = c1_hb_hoistedGlobal;
  c1_cntin = c1_ib_hoistedGlobal;
  c1_cntin1 = c1_jb_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 122U, 122U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_sampling_time_base, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_splittime1, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_splittime2, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_offset, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_OFFSET_ON_START_abs, 4U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_ON_END_rel, 5U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_OFFSET_OFF_START_rel, 6U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_OFFSET_OFF_END_abs, 7U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_lambda, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_delta, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 10U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 11U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P, 12U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_wi, 13U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Pi, 14U, c1_g_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_uu, 15U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_wu, 16U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Pu, 17U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_VnoiseAmp, 18U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_InoiseAmp, 19U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_STEPS, 20U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_SP_Num, 21U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_SP_ON_min, 22U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_SP_ON_max, 23U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_SP_ON_list, 24U,
    c1_e_sf_marshallOut, c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_SP_OFF_max, 25U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_SP_OFF_min, 26U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_SP_OFF_list, 27U,
    c1_e_sf_marshallOut, c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_sampling_time, 28U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_dyn_importable(c1_local_t_data, (const int32_T *)
    &c1_local_t_sizes, NULL, 0, 29, (void *)c1_d_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_k, 30U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_ku, 31U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu2real, 32U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu1real, 33U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu0real, 34U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wi1real, 35U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wi0real, 36U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_temp_1, 37U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_temp_2, 38U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_temp_3, 39U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_c, 40U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_allowedRateChange, 41U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_rateChange, 42U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 43U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 44U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_startrej, 45U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_start, 46U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t, 47U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_duty, 48U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_v_out, 49U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_i_in, 50U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w0in, 51U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w1in, 52U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_P11in, 53U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_P12in, 54U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_P21in, 55U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_P22in, 56U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Capin, 57U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_wi0in, 58U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_wi1in, 59U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pi11in, 60U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pi12in, 61U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pi21in, 62U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pi22in, 63U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_wu0in, 64U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_wu1in, 65U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_wu2in, 66U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu11in, 67U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu12in, 68U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu13in, 69U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu21in, 70U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu22in, 71U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu23in, 72U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu31in, 73U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu32in, 74U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Pu33in, 75U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_ESRin, 76U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t0in, 77U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_cntin, 78U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_cntin1, 79U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 80U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_e, 81U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w0, 82U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w1, 83U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_P11, 84U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_P12, 85U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_P21, 86U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_P22, 87U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Capout, 88U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yi, 89U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ei, 90U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wi0, 91U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wi1, 92U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pi11, 93U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pi12, 94U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pi21, 95U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pi22, 96U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_yu, 97U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_eu, 98U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu0, 99U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu1, 100U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_wu2, 101U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu11, 102U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu12, 103U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu13, 104U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu21, 105U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu22, 106U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu23, 107U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu31, 108U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu32, 109U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Pu33, 110U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ESRout, 111U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Vnoise, 112U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Inoise, 113U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_t0, 114U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_k0, 115U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_k1, 116U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ku0, 117U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ku1, 118U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ku2, 119U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_cnt, 120U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_cnt1, 121U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_sampling_time_base = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_splittime1 = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_splittime2 = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_offset = c1_t - c1_duty;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_lambda = 0.85;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_delta = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_u[c1_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_u[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
  c1_u[1] = c1_t;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_w[c1_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
  c1_w[0] = c1_w0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_w[1] = c1_w1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  c1_w0 = c1_w0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  c1_w1 = c1_w1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_P[c1_i6] = c1_dv0[c1_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  c1_P[0] = c1_P11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  c1_P[2] = c1_P12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
  c1_P[1] = c1_P21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
  c1_P[3] = c1_P22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  c1_P11 = c1_P11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  c1_P12 = c1_P12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  c1_P21 = c1_P21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  c1_P22 = c1_P22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
  c1_yi = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
  c1_ei = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_wi[c1_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
  c1_wi[0] = c1_wi0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
  c1_wi[1] = c1_wi1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_wi0 = c1_wi0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_wi1 = c1_wi1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    c1_Pi[c1_i8] = c1_dv0[c1_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 75);
  c1_Pi[0] = c1_Pi11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 75);
  c1_Pi[2] = c1_Pi12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
  c1_Pi[1] = c1_Pi21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
  c1_Pi[3] = c1_Pi22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
  c1_Pi11 = c1_Pi11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
  c1_Pi12 = c1_Pi12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
  c1_Pi21 = c1_Pi21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
  c1_Pi22 = c1_Pi22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
  c1_yu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 87);
  c1_eu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 90);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_uu[c1_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 91);
  c1_uu[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
  c1_uu[1] = c1_t;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 93);
  c1_a = c1_t;
  c1_b = c1_t;
  c1_b_y = c1_a * c1_b;
  c1_uu[2] = c1_b_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 96);
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_wu[c1_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 97);
  c1_wu[0] = c1_wu0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
  c1_wu[1] = c1_wu1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 99);
  c1_wu[2] = c1_wu2in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 100);
  c1_wu0 = c1_wu0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 100);
  c1_wu1 = c1_wu1in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 100);
  c1_wu2 = c1_wu2in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 103);
  for (c1_i11 = 0; c1_i11 < 9; c1_i11++) {
    c1_Pu[c1_i11] = c1_dv1[c1_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 105);
  c1_Pu[0] = c1_Pu11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 105);
  c1_Pu[3] = c1_Pu12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 105);
  c1_Pu[6] = c1_Pu13in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 106);
  c1_Pu[1] = c1_Pu21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 106);
  c1_Pu[4] = c1_Pu22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 106);
  c1_Pu[7] = c1_Pu23in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 107);
  c1_Pu[2] = c1_Pu31in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 107);
  c1_Pu[5] = c1_Pu32in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 107);
  c1_Pu[8] = c1_Pu33in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 111);
  c1_Pu11 = c1_Pu11in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 111);
  c1_Pu12 = c1_Pu12in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 111);
  c1_Pu13 = c1_Pu13in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 112);
  c1_Pu21 = c1_Pu21in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 112);
  c1_Pu22 = c1_Pu22in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 112);
  c1_Pu23 = c1_Pu23in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 113);
  c1_Pu31 = c1_Pu31in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 113);
  c1_Pu32 = c1_Pu32in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 113);
  c1_Pu33 = c1_Pu33in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 119);
  c1_Capout = c1_Capin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 120);
  c1_ESRout = c1_ESRin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 121);
  c1_t0 = c1_t0in;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 123);
  c1_Vnoise = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 124);
  c1_Inoise = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
  c1_k0 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
  c1_k1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
  c1_ku0 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
  c1_ku1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 126);
  c1_ku2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 130U);
  c1_VnoiseAmp = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 131U);
  c1_InoiseAmp = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 132U);
  c1_cnt = c1_cntin;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 132U);
  c1_cnt1 = c1_cntin1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 140U);
  c1_STEPS = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 143U);
  c1_SP_Num = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 145U);
  c1_SP_ON_min = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 146U);
  c1_SP_ON_max = 21.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 147U);
  c1_realmax(chartInstance);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    c1_SP_ON_list[c1_i12] = 6.0 + 5.0 * (real_T)c1_i12;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 149U);
  c1_SP_OFF_max = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 150U);
  c1_SP_OFF_min = 80.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 151U);
  c1_realmax(chartInstance);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_SP_OFF_list[c1_i13] = 80.0 + 5.0 * (real_T)c1_i13;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 153U);
  c1_sampling_time = 4.9999999999999996E-6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 155U);
  if (CV_EML_IF(0, 1, 0, c1_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 158U);
    for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
      c1_b_t[c1_i14] = (c1_t == c1_SP_ON_list[c1_i14]);
    }

    if (CV_EML_IF(0, 1, 1, c1_any(chartInstance, c1_b_t))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 161U);
      if (CV_EML_IF(0, 1, 2, c1_t == 6.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 163U);
        c1_cnt = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 165U);
        c1_cnt = c1_cntin + 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 172U);
      for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
        c1_x[c1_i15] = (c1_SP_ON_list[c1_i15] == c1_t);
      }

      c1_idx = 0;
      for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
        c1_ii_sizes[c1_i16] = 1 + 3 * c1_i16;
      }

      c1_check_forloop_overflow_error(chartInstance);
      c1_ii = 1;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (c1_ii < 5)) {
        c1_b_ii = c1_ii;
        guard21 = FALSE;
        if (c1_x[c1_b_ii - 1]) {
          c1_b_a = c1_idx + 1;
          c1_idx = c1_b_a;
          c1_ii_data[c1_idx - 1] = c1_b_ii;
          if (c1_idx >= 4) {
            exitg2 = TRUE;
          } else {
            guard21 = TRUE;
          }
        } else {
          guard21 = TRUE;
        }

        if (guard21 == TRUE) {
          c1_ii++;
        }
      }

      c1_b0 = (1 > c1_idx);
      c1_b1 = c1_b0;
      c1_b2 = c1_b1;
      if (c1_b2) {
        c1_i17 = 0;
      } else {
        c1_i17 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 4, 0, 0);
      }

      c1_tmp_sizes = c1_i17;
      c1_loop_ub = c1_i17 - 1;
      for (c1_i18 = 0; c1_i18 <= c1_loop_ub; c1_i18++) {
        c1_tmp_data[c1_i18] = 1 + c1_i18;
      }

      c1_iv0[0] = 1;
      c1_iv0[1] = c1_tmp_sizes;
      c1_b_ii_sizes[0] = c1_iv0[0];
      c1_b_ii_sizes[1] = c1_iv0[1];
      c1_b_loop_ub = c1_iv0[1] - 1;
      for (c1_i19 = 0; c1_i19 <= c1_b_loop_ub; c1_i19++) {
        c1_c_loop_ub = c1_iv0[0] - 1;
        for (c1_i20 = 0; c1_i20 <= c1_c_loop_ub; c1_i20++) {
          c1_b_ii_data[c1_i20 + c1_b_ii_sizes[0] * c1_i19] =
            c1_ii_data[c1_tmp_data[c1_i20 + c1_iv0[0] * c1_i19] - 1];
        }
      }

      c1_ii_sizes[0] = 1;
      c1_ii_sizes[1] = c1_b_ii_sizes[1];
      c1_d_loop_ub = c1_b_ii_sizes[1] - 1;
      for (c1_i21 = 0; c1_i21 <= c1_d_loop_ub; c1_i21++) {
        c1_ii_data[c1_ii_sizes[0] * c1_i21] = c1_b_ii_data[c1_b_ii_sizes[0] *
          c1_i21];
      }

      c1_i_sizes[0] = 1;
      c1_i_sizes[1] = c1_ii_sizes[1];
      c1_i = c1_i_sizes[0];
      c1_b_i = c1_i_sizes[1];
      c1_e_loop_ub = c1_ii_sizes[0] * c1_ii_sizes[1] - 1;
      for (c1_i22 = 0; c1_i22 <= c1_e_loop_ub; c1_i22++) {
        c1_i_data[c1_i22] = (real_T)c1_ii_data[c1_i22];
      }

      c1_local_t_sizes[0] = 1;
      c1_local_t_sizes[1] = c1_i_sizes[1];
      c1_local_t = c1_local_t_sizes[0];
      c1_b_local_t = c1_local_t_sizes[1];
      c1_f_loop_ub = c1_i_sizes[0] * c1_i_sizes[1] - 1;
      for (c1_i23 = 0; c1_i23 <= c1_f_loop_ub; c1_i23++) {
        c1_local_t_data[c1_i23] = c1_i_data[c1_i23] - 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 173U);
      sf_debug_size_eq_check_1d(1, c1_local_t_sizes[1]);
      _SFD_EML_ARRAY_BOUNDS_CHECK("local_t", 1, 1, c1_local_t_sizes[1], 2, 0);
      c1_u[1] = c1_local_t_data[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 174U);
      for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
        c1_c_a[c1_i24] = c1_P[c1_i24];
      }

      for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
        c1_b_b[c1_i25] = c1_u[c1_i25];
      }

      for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
        c1_c_y[c1_i26] = 0.0;
        c1_i27 = 0;
        for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
          c1_c_y[c1_i26] += c1_c_a[c1_i27 + c1_i26] * c1_b_b[c1_i28];
          c1_i27 += 2;
        }
      }

      for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
        c1_d_a[c1_i29] = c1_u[c1_i29];
      }

      for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
        c1_c_a[c1_i30] = c1_P[c1_i30];
      }

      c1_i31 = 0;
      for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
        c1_d_y[c1_i32] = 0.0;
        for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
          c1_d_y[c1_i32] += c1_d_a[c1_i33] * c1_c_a[c1_i33 + c1_i31];
        }

        c1_i31 += 2;
      }

      for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
        c1_b_b[c1_i34] = c1_u[c1_i34];
      }

      c1_e_y = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_b_k = 1; c1_b_k < 3; c1_b_k++) {
        c1_c_k = c1_b_k - 1;
        c1_e_y += c1_d_y[c1_c_k] * c1_b_b[c1_c_k];
      }

      c1_A = c1_e_y;
      c1_b_x = c1_A;
      c1_c_x = c1_b_x;
      c1_f_y = c1_c_x / 0.85;
      c1_B = 1.0 + c1_f_y;
      c1_g_y = c1_B;
      c1_h_y = c1_g_y;
      for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
        c1_c_y[c1_i35] /= c1_h_y;
      }

      for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
        c1_k[c1_i36] = c1_c_y[c1_i36] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 175U);
      for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
        c1_d_a[c1_i37] = c1_w[c1_i37];
      }

      for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
        c1_b_b[c1_i38] = c1_u[c1_i38];
      }

      c1_y = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_d_k = 1; c1_d_k < 3; c1_d_k++) {
        c1_e_k = c1_d_k - 1;
        c1_y += c1_d_a[c1_e_k] * c1_b_b[c1_e_k];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 177U);
      c1_c_b = c1_rand(chartInstance);
      c1_i_y = 0.0 * c1_c_b;
      c1_Vnoise = c1_v_out + c1_i_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 178U);
      c1_d_b = c1_rand(chartInstance);
      c1_j_y = 0.0 * c1_d_b;
      c1_e = (c1_v_out + c1_j_y) - c1_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 180U);
      for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
        c1_b_b[c1_i39] = c1_k[c1_i39];
      }

      c1_e_b = c1_e;
      for (c1_i40 = 0; c1_i40 < 2; c1_i40++) {
        c1_b_b[c1_i40] *= c1_e_b;
      }

      for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
        c1_w[c1_i41] += c1_b_b[c1_i41];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 181U);
      c1_w0 = c1_w[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 181U);
      c1_w1 = c1_w[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 183U);
      for (c1_i42 = 0; c1_i42 < 2; c1_i42++) {
        c1_b_b[c1_i42] = c1_k[c1_i42];
      }

      for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
        c1_d_a[c1_i43] = c1_u[c1_i43];
      }

      for (c1_i44 = 0; c1_i44 < 2; c1_i44++) {
        c1_i45 = 0;
        for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
          c1_k_y[c1_i45 + c1_i44] = c1_b_b[c1_i44] * c1_d_a[c1_i46];
          c1_i45 += 2;
        }
      }

      for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
        c1_c_a[c1_i47] = c1_P[c1_i47];
      }

      for (c1_i48 = 0; c1_i48 < 2; c1_i48++) {
        c1_i49 = 0;
        for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
          c1_l_y[c1_i49 + c1_i48] = 0.0;
          c1_i51 = 0;
          for (c1_i52 = 0; c1_i52 < 2; c1_i52++) {
            c1_l_y[c1_i49 + c1_i48] += c1_k_y[c1_i51 + c1_i48] * c1_c_a[c1_i52 +
              c1_i49];
            c1_i51 += 2;
          }

          c1_i49 += 2;
        }
      }

      for (c1_i53 = 0; c1_i53 < 4; c1_i53++) {
        c1_l_y[c1_i53] = c1_P[c1_i53] - c1_l_y[c1_i53];
      }

      for (c1_i54 = 0; c1_i54 < 4; c1_i54++) {
        c1_P[c1_i54] = c1_l_y[c1_i54] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 184U);
      c1_P11 = c1_P[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 184U);
      c1_P12 = c1_P[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 185U);
      c1_P21 = c1_P[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 185U);
      c1_P22 = c1_P[3];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 189U);
    guard2 = FALSE;
    if (CV_EML_COND(0, 1, 0, c1_offset >= -5.0)) {
      if (CV_EML_COND(0, 1, 1, c1_offset <= -4.0)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 190U);
        c1_b_A = -c1_w0;
        c1_b_B = c1_w1;
        c1_d_x = c1_b_A;
        c1_m_y = c1_b_B;
        c1_e_x = c1_d_x;
        c1_n_y = c1_m_y;
        c1_o_y = c1_e_x / c1_n_y;
        c1_c_A = c1_o_y;
        c1_f_x = c1_c_A;
        c1_g_x = c1_f_x;
        c1_p_y = c1_g_x / 30.0;
        c1_e_a = c1_p_y;
        c1_Capout = c1_e_a * 4.9999999999999996E-6;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 196U);
    for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
      c1_c_t[c1_i55] = (c1_t == c1_SP_OFF_list[c1_i55]);
    }

    if (CV_EML_IF(0, 1, 4, c1_any(chartInstance, c1_c_t))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 199U);
      if (CV_EML_IF(0, 1, 5, c1_t == 80.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 201U);
        c1_cnt1 = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 203U);
        c1_cnt1 = c1_cntin1 + 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 207U);
      for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
        c1_x[c1_i56] = (c1_SP_OFF_list[c1_i56] == c1_t);
      }

      c1_b_idx = 0;
      for (c1_i57 = 0; c1_i57 < 2; c1_i57++) {
        c1_ii_sizes[c1_i57] = 1 + 3 * c1_i57;
      }

      c1_check_forloop_overflow_error(chartInstance);
      c1_c_ii = 1;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (c1_c_ii < 5)) {
        c1_d_ii = c1_c_ii;
        guard11 = FALSE;
        if (c1_x[c1_d_ii - 1]) {
          c1_f_a = c1_b_idx + 1;
          c1_b_idx = c1_f_a;
          c1_ii_data[c1_b_idx - 1] = c1_d_ii;
          if (c1_b_idx >= 4) {
            exitg1 = TRUE;
          } else {
            guard11 = TRUE;
          }
        } else {
          guard11 = TRUE;
        }

        if (guard11 == TRUE) {
          c1_c_ii++;
        }
      }

      c1_b3 = (1 > c1_b_idx);
      c1_b4 = c1_b3;
      c1_b5 = c1_b4;
      if (c1_b5) {
        c1_i58 = 0;
      } else {
        c1_i58 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_idx, 1, 4, 0, 0);
      }

      c1_b_tmp_sizes = c1_i58;
      c1_g_loop_ub = c1_i58 - 1;
      for (c1_i59 = 0; c1_i59 <= c1_g_loop_ub; c1_i59++) {
        c1_b_tmp_data[c1_i59] = 1 + c1_i59;
      }

      c1_iv1[0] = 1;
      c1_iv1[1] = c1_b_tmp_sizes;
      c1_c_ii_sizes[0] = c1_iv1[0];
      c1_c_ii_sizes[1] = c1_iv1[1];
      c1_h_loop_ub = c1_iv1[1] - 1;
      for (c1_i60 = 0; c1_i60 <= c1_h_loop_ub; c1_i60++) {
        c1_i_loop_ub = c1_iv1[0] - 1;
        for (c1_i61 = 0; c1_i61 <= c1_i_loop_ub; c1_i61++) {
          c1_c_ii_data[c1_i61 + c1_c_ii_sizes[0] * c1_i60] =
            c1_ii_data[c1_b_tmp_data[c1_i61 + c1_iv1[0] * c1_i60] - 1];
        }
      }

      c1_ii_sizes[0] = 1;
      c1_ii_sizes[1] = c1_c_ii_sizes[1];
      c1_j_loop_ub = c1_c_ii_sizes[1] - 1;
      for (c1_i62 = 0; c1_i62 <= c1_j_loop_ub; c1_i62++) {
        c1_ii_data[c1_ii_sizes[0] * c1_i62] = c1_c_ii_data[c1_c_ii_sizes[0] *
          c1_i62];
      }

      c1_i_sizes[0] = 1;
      c1_i_sizes[1] = c1_ii_sizes[1];
      c1_c_i = c1_i_sizes[0];
      c1_d_i = c1_i_sizes[1];
      c1_k_loop_ub = c1_ii_sizes[0] * c1_ii_sizes[1] - 1;
      for (c1_i63 = 0; c1_i63 <= c1_k_loop_ub; c1_i63++) {
        c1_i_data[c1_i63] = (real_T)c1_ii_data[c1_i63];
      }

      c1_local_t_sizes[0] = 1;
      c1_local_t_sizes[1] = c1_i_sizes[1];
      c1_c_local_t = c1_local_t_sizes[0];
      c1_d_local_t = c1_local_t_sizes[1];
      c1_l_loop_ub = c1_i_sizes[0] * c1_i_sizes[1] - 1;
      for (c1_i64 = 0; c1_i64 <= c1_l_loop_ub; c1_i64++) {
        c1_local_t_data[c1_i64] = c1_i_data[c1_i64] - 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 211U);
      sf_debug_size_eq_check_1d(1, c1_local_t_sizes[1]);
      _SFD_EML_ARRAY_BOUNDS_CHECK("local_t", 1, 1, c1_local_t_sizes[1], 2, 0);
      c1_u[1] = c1_local_t_data[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 212U);
      for (c1_i65 = 0; c1_i65 < 4; c1_i65++) {
        c1_c_a[c1_i65] = c1_Pi[c1_i65];
      }

      for (c1_i66 = 0; c1_i66 < 2; c1_i66++) {
        c1_b_b[c1_i66] = c1_u[c1_i66];
      }

      for (c1_i67 = 0; c1_i67 < 2; c1_i67++) {
        c1_c_y[c1_i67] = 0.0;
        c1_i68 = 0;
        for (c1_i69 = 0; c1_i69 < 2; c1_i69++) {
          c1_c_y[c1_i67] += c1_c_a[c1_i68 + c1_i67] * c1_b_b[c1_i69];
          c1_i68 += 2;
        }
      }

      for (c1_i70 = 0; c1_i70 < 2; c1_i70++) {
        c1_d_a[c1_i70] = c1_u[c1_i70];
      }

      for (c1_i71 = 0; c1_i71 < 4; c1_i71++) {
        c1_c_a[c1_i71] = c1_Pi[c1_i71];
      }

      c1_i72 = 0;
      for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
        c1_d_y[c1_i73] = 0.0;
        for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
          c1_d_y[c1_i73] += c1_d_a[c1_i74] * c1_c_a[c1_i74 + c1_i72];
        }

        c1_i72 += 2;
      }

      for (c1_i75 = 0; c1_i75 < 2; c1_i75++) {
        c1_b_b[c1_i75] = c1_u[c1_i75];
      }

      c1_q_y = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_f_k = 1; c1_f_k < 3; c1_f_k++) {
        c1_g_k = c1_f_k - 1;
        c1_q_y += c1_d_y[c1_g_k] * c1_b_b[c1_g_k];
      }

      c1_d_A = c1_q_y;
      c1_h_x = c1_d_A;
      c1_i_x = c1_h_x;
      c1_r_y = c1_i_x / 0.85;
      c1_c_B = 1.0 + c1_r_y;
      c1_s_y = c1_c_B;
      c1_t_y = c1_s_y;
      for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
        c1_c_y[c1_i76] /= c1_t_y;
      }

      for (c1_i77 = 0; c1_i77 < 2; c1_i77++) {
        c1_k[c1_i77] = c1_c_y[c1_i77] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 213U);
      c1_k0 = c1_k[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 213U);
      c1_k1 = c1_k[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 214U);
      for (c1_i78 = 0; c1_i78 < 2; c1_i78++) {
        c1_d_a[c1_i78] = c1_wi[c1_i78];
      }

      for (c1_i79 = 0; c1_i79 < 2; c1_i79++) {
        c1_b_b[c1_i79] = c1_u[c1_i79];
      }

      c1_yi = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_h_k = 1; c1_h_k < 3; c1_h_k++) {
        c1_i_k = c1_h_k - 1;
        c1_yi += c1_d_a[c1_i_k] * c1_b_b[c1_i_k];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 216U);
      c1_f_b = c1_rand(chartInstance);
      c1_u_y = 0.0 * c1_f_b;
      c1_Inoise = c1_i_in + c1_u_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 217U);
      c1_g_b = c1_rand(chartInstance);
      c1_v_y = 0.0 * c1_g_b;
      c1_ei = (c1_i_in + c1_v_y) - c1_yi;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 219U);
      for (c1_i80 = 0; c1_i80 < 2; c1_i80++) {
        c1_b_b[c1_i80] = c1_k[c1_i80];
      }

      c1_h_b = c1_ei;
      for (c1_i81 = 0; c1_i81 < 2; c1_i81++) {
        c1_b_b[c1_i81] *= c1_h_b;
      }

      for (c1_i82 = 0; c1_i82 < 2; c1_i82++) {
        c1_wi[c1_i82] += c1_b_b[c1_i82];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 220U);
      c1_wi0 = c1_wi[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 220U);
      c1_wi1 = c1_wi[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 222U);
      for (c1_i83 = 0; c1_i83 < 2; c1_i83++) {
        c1_b_b[c1_i83] = c1_k[c1_i83];
      }

      for (c1_i84 = 0; c1_i84 < 2; c1_i84++) {
        c1_d_a[c1_i84] = c1_u[c1_i84];
      }

      for (c1_i85 = 0; c1_i85 < 2; c1_i85++) {
        c1_i86 = 0;
        for (c1_i87 = 0; c1_i87 < 2; c1_i87++) {
          c1_k_y[c1_i86 + c1_i85] = c1_b_b[c1_i85] * c1_d_a[c1_i87];
          c1_i86 += 2;
        }
      }

      for (c1_i88 = 0; c1_i88 < 4; c1_i88++) {
        c1_c_a[c1_i88] = c1_Pi[c1_i88];
      }

      for (c1_i89 = 0; c1_i89 < 2; c1_i89++) {
        c1_i90 = 0;
        for (c1_i91 = 0; c1_i91 < 2; c1_i91++) {
          c1_l_y[c1_i90 + c1_i89] = 0.0;
          c1_i92 = 0;
          for (c1_i93 = 0; c1_i93 < 2; c1_i93++) {
            c1_l_y[c1_i90 + c1_i89] += c1_k_y[c1_i92 + c1_i89] * c1_c_a[c1_i93 +
              c1_i90];
            c1_i92 += 2;
          }

          c1_i90 += 2;
        }
      }

      for (c1_i94 = 0; c1_i94 < 4; c1_i94++) {
        c1_l_y[c1_i94] = c1_Pi[c1_i94] - c1_l_y[c1_i94];
      }

      for (c1_i95 = 0; c1_i95 < 4; c1_i95++) {
        c1_Pi[c1_i95] = c1_l_y[c1_i95] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 223U);
      c1_Pi11 = c1_Pi[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 223U);
      c1_Pi12 = c1_Pi[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 224U);
      c1_Pi21 = c1_Pi[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 224U);
      c1_Pi22 = c1_Pi[3];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 229U);
      sf_debug_size_eq_check_1d(1, c1_local_t_sizes[1]);
      _SFD_EML_ARRAY_BOUNDS_CHECK("local_t", 1, 1, c1_local_t_sizes[1], 2, 0);
      c1_uu[1] = c1_local_t_data[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 230U);
      c1_g_a = c1_uu[1];
      c1_i_b = c1_uu[1];
      c1_w_y = c1_g_a * c1_i_b;
      c1_uu[2] = c1_w_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 231U);
      for (c1_i96 = 0; c1_i96 < 9; c1_i96++) {
        c1_h_a[c1_i96] = c1_Pu[c1_i96];
      }

      for (c1_i97 = 0; c1_i97 < 3; c1_i97++) {
        c1_j_b[c1_i97] = c1_uu[c1_i97];
      }

      for (c1_i98 = 0; c1_i98 < 3; c1_i98++) {
        c1_x_y[c1_i98] = 0.0;
        c1_i99 = 0;
        for (c1_i100 = 0; c1_i100 < 3; c1_i100++) {
          c1_x_y[c1_i98] += c1_h_a[c1_i99 + c1_i98] * c1_j_b[c1_i100];
          c1_i99 += 3;
        }
      }

      for (c1_i101 = 0; c1_i101 < 3; c1_i101++) {
        c1_i_a[c1_i101] = c1_uu[c1_i101];
      }

      for (c1_i102 = 0; c1_i102 < 9; c1_i102++) {
        c1_h_a[c1_i102] = c1_Pu[c1_i102];
      }

      c1_i103 = 0;
      for (c1_i104 = 0; c1_i104 < 3; c1_i104++) {
        c1_y_y[c1_i104] = 0.0;
        for (c1_i105 = 0; c1_i105 < 3; c1_i105++) {
          c1_y_y[c1_i104] += c1_i_a[c1_i105] * c1_h_a[c1_i105 + c1_i103];
        }

        c1_i103 += 3;
      }

      for (c1_i106 = 0; c1_i106 < 3; c1_i106++) {
        c1_j_b[c1_i106] = c1_uu[c1_i106];
      }

      c1_ab_y = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_j_k = 1; c1_j_k < 4; c1_j_k++) {
        c1_k_k = c1_j_k - 1;
        c1_ab_y += c1_y_y[c1_k_k] * c1_j_b[c1_k_k];
      }

      c1_e_A = c1_ab_y;
      c1_j_x = c1_e_A;
      c1_k_x = c1_j_x;
      c1_bb_y = c1_k_x / 0.85;
      c1_d_B = 1.0 + c1_bb_y;
      c1_cb_y = c1_d_B;
      c1_db_y = c1_cb_y;
      for (c1_i107 = 0; c1_i107 < 3; c1_i107++) {
        c1_x_y[c1_i107] /= c1_db_y;
      }

      for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
        c1_ku[c1_i108] = c1_x_y[c1_i108] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 232U);
      c1_ku0 = c1_ku[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 232U);
      c1_ku1 = c1_ku[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 232U);
      c1_ku2 = c1_ku[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 233U);
      for (c1_i109 = 0; c1_i109 < 3; c1_i109++) {
        c1_i_a[c1_i109] = c1_wu[c1_i109];
      }

      for (c1_i110 = 0; c1_i110 < 3; c1_i110++) {
        c1_j_b[c1_i110] = c1_uu[c1_i110];
      }

      c1_yu = 0.0;
      c1_check_forloop_overflow_error(chartInstance);
      for (c1_l_k = 1; c1_l_k < 4; c1_l_k++) {
        c1_m_k = c1_l_k - 1;
        c1_yu += c1_i_a[c1_m_k] * c1_j_b[c1_m_k];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 235U);
      c1_k_b = c1_rand(chartInstance);
      c1_eb_y = 0.0 * c1_k_b;
      c1_Vnoise = c1_v_out + c1_eb_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 236U);
      c1_l_b = c1_rand(chartInstance);
      c1_fb_y = 0.0 * c1_l_b;
      c1_eu = (c1_v_out + c1_fb_y) - c1_yu;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 238U);
      for (c1_i111 = 0; c1_i111 < 3; c1_i111++) {
        c1_j_b[c1_i111] = c1_ku[c1_i111];
      }

      c1_m_b = c1_eu;
      for (c1_i112 = 0; c1_i112 < 3; c1_i112++) {
        c1_j_b[c1_i112] *= c1_m_b;
      }

      for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
        c1_wu[c1_i113] += c1_j_b[c1_i113];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 239U);
      c1_wu0 = c1_wu[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 239U);
      c1_wu1 = c1_wu[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 239U);
      c1_wu2 = c1_wu[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 241U);
      for (c1_i114 = 0; c1_i114 < 3; c1_i114++) {
        c1_j_b[c1_i114] = c1_ku[c1_i114];
      }

      for (c1_i115 = 0; c1_i115 < 3; c1_i115++) {
        c1_i_a[c1_i115] = c1_uu[c1_i115];
      }

      for (c1_i116 = 0; c1_i116 < 3; c1_i116++) {
        c1_i117 = 0;
        for (c1_i118 = 0; c1_i118 < 3; c1_i118++) {
          c1_gb_y[c1_i117 + c1_i116] = c1_j_b[c1_i116] * c1_i_a[c1_i118];
          c1_i117 += 3;
        }
      }

      for (c1_i119 = 0; c1_i119 < 9; c1_i119++) {
        c1_h_a[c1_i119] = c1_Pu[c1_i119];
      }

      for (c1_i120 = 0; c1_i120 < 3; c1_i120++) {
        c1_i121 = 0;
        for (c1_i122 = 0; c1_i122 < 3; c1_i122++) {
          c1_hb_y[c1_i121 + c1_i120] = 0.0;
          c1_i123 = 0;
          for (c1_i124 = 0; c1_i124 < 3; c1_i124++) {
            c1_hb_y[c1_i121 + c1_i120] += c1_gb_y[c1_i123 + c1_i120] *
              c1_h_a[c1_i124 + c1_i121];
            c1_i123 += 3;
          }

          c1_i121 += 3;
        }
      }

      for (c1_i125 = 0; c1_i125 < 9; c1_i125++) {
        c1_hb_y[c1_i125] = c1_Pu[c1_i125] - c1_hb_y[c1_i125];
      }

      for (c1_i126 = 0; c1_i126 < 9; c1_i126++) {
        c1_Pu[c1_i126] = c1_hb_y[c1_i126] / 0.85;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 242U);
      c1_Pu11 = c1_Pu[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 242U);
      c1_Pu12 = c1_Pu[3];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 242U);
      c1_Pu13 = c1_Pu[6];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 243U);
      c1_Pu21 = c1_Pu[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 243U);
      c1_Pu22 = c1_Pu[4];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 243U);
      c1_Pu23 = c1_Pu[7];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 244U);
      c1_Pu31 = c1_Pu[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 244U);
      c1_Pu32 = c1_Pu[5];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 244U);
      c1_Pu33 = c1_Pu[8];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 248U);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 2, c1_t >= 95.0)) {
      if (CV_EML_COND(0, 1, 3, c1_t <= 96.0)) {
        CV_EML_MCDC(0, 1, 1, TRUE);
        CV_EML_IF(0, 1, 6, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 249U);
        c1_f_A = c1_wu2;
        c1_l_x = c1_f_A;
        c1_m_x = c1_l_x;
        c1_wu2real = c1_m_x / 2.4999999999999994E-11;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 250U);
        c1_g_A = c1_wu1;
        c1_n_x = c1_g_A;
        c1_o_x = c1_n_x;
        c1_wu1real = c1_o_x / 4.9999999999999996E-6;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 251U);
        c1_wu0real = c1_wu0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 252U);
        c1_h_A = c1_wi1;
        c1_p_x = c1_h_A;
        c1_q_x = c1_p_x;
        c1_wi1real = c1_q_x / 4.9999999999999996E-6;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 253U);
        c1_wi0real = c1_wi0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 258);
        c1_n_b = c1_wu0real;
        c1_ib_y = 2.0 * c1_n_b;
        c1_j_a = c1_ib_y;
        c1_o_b = c1_wu2real;
        c1_temp_1 = c1_j_a * c1_o_b;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 259);
        c1_k_a = c1_wi1real;
        c1_temp_2 = c1_k_a * 30.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 260);
        c1_l_a = c1_wi1real;
        c1_jb_y = c1_l_a * 30.0;
        c1_temp_3 = c1_jb_y - c1_wu1real;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 261);
        c1_m_a = c1_temp_3;
        c1_p_b = c1_temp_2;
        c1_kb_y = c1_m_a * c1_p_b;
        c1_i_A = c1_temp_1 + c1_kb_y;
        c1_e_B = c1_temp_3;
        c1_r_x = c1_i_A;
        c1_lb_y = c1_e_B;
        c1_s_x = c1_r_x;
        c1_mb_y = c1_lb_y;
        c1_nb_y = c1_s_x / c1_mb_y;
        c1_c = c1_nb_y - c1_temp_3;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 262);
        c1_n_a = c1_c;
        c1_q_b = c1_Capin;
        c1_ob_y = c1_n_a * c1_q_b;
        c1_o_a = c1_wi0real - c1_ob_y;
        c1_pb_y = c1_o_a * 30.0;
        c1_p_a = c1_wi1real;
        c1_qb_y = c1_p_a * 30.0;
        c1_q_a = c1_c - c1_qb_y;
        c1_r_b = c1_Capin;
        c1_rb_y = c1_q_a * c1_r_b;
        c1_j_A = c1_pb_y;
        c1_f_B = c1_rb_y;
        c1_t_x = c1_j_A;
        c1_sb_y = c1_f_B;
        c1_u_x = c1_t_x;
        c1_tb_y = c1_sb_y;
        c1_ESRout = c1_u_x / c1_tb_y;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 6, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 281);
    if (CV_EML_IF(0, 1, 7, c1_startrej == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 282);
      c1_allowedRateChange = 50.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 283);
      if (CV_EML_IF(0, 1, 8, c1_Capin != 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 284);
        c1_k_A = c1_Capout - c1_Capin;
        c1_g_B = c1_Capin;
        c1_v_x = c1_k_A;
        c1_ub_y = c1_g_B;
        c1_w_x = c1_v_x;
        c1_vb_y = c1_ub_y;
        c1_wb_y = c1_w_x / c1_vb_y;
        c1_r_a = c1_abs(chartInstance, c1_wb_y);
        c1_rateChange = c1_r_a * 100.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 285);
        if (CV_EML_IF(0, 1, 9, c1_rateChange >= 50.0)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 287);
          c1_Capout = c1_Capin;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 290);
      if (CV_EML_IF(0, 1, 10, c1_ESRin != 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 291);
        c1_l_A = c1_ESRout - c1_ESRin;
        c1_h_B = c1_ESRin;
        c1_x_x = c1_l_A;
        c1_xb_y = c1_h_B;
        c1_y_x = c1_x_x;
        c1_yb_y = c1_xb_y;
        c1_ac_y = c1_y_x / c1_yb_y;
        c1_s_a = c1_abs(chartInstance, c1_ac_y);
        c1_rateChange = c1_s_a * 100.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 292);
        if (CV_EML_IF(0, 1, 11, c1_rateChange >= 50.0)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 294);
          c1_ESRout = c1_ESRin;
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -294);
  sf_debug_symbol_scope_pop();
  *c1_bc_y = c1_y;
  *c1_b_e = c1_e;
  *c1_b_w0 = c1_w0;
  *c1_b_w1 = c1_w1;
  *c1_b_P11 = c1_P11;
  *c1_b_P12 = c1_P12;
  *c1_b_P21 = c1_P21;
  *c1_b_P22 = c1_P22;
  *c1_b_Capout = c1_Capout;
  *c1_b_yi = c1_yi;
  *c1_b_ei = c1_ei;
  *c1_b_wi0 = c1_wi0;
  *c1_b_wi1 = c1_wi1;
  *c1_b_Pi11 = c1_Pi11;
  *c1_b_Pi12 = c1_Pi12;
  *c1_b_Pi21 = c1_Pi21;
  *c1_b_Pi22 = c1_Pi22;
  *c1_b_yu = c1_yu;
  *c1_b_eu = c1_eu;
  *c1_b_wu0 = c1_wu0;
  *c1_b_wu1 = c1_wu1;
  *c1_b_wu2 = c1_wu2;
  *c1_b_Pu11 = c1_Pu11;
  *c1_b_Pu12 = c1_Pu12;
  *c1_b_Pu13 = c1_Pu13;
  *c1_b_Pu21 = c1_Pu21;
  *c1_b_Pu22 = c1_Pu22;
  *c1_b_Pu23 = c1_Pu23;
  *c1_b_Pu31 = c1_Pu31;
  *c1_b_Pu32 = c1_Pu32;
  *c1_b_Pu33 = c1_Pu33;
  *c1_b_ESRout = c1_ESRout;
  *c1_b_Vnoise = c1_Vnoise;
  *c1_b_Inoise = c1_Inoise;
  *c1_b_t0 = c1_t0;
  *c1_b_k0 = c1_k0;
  *c1_b_k1 = c1_k1;
  *c1_b_ku0 = c1_ku0;
  *c1_b_ku1 = c1_ku1;
  *c1_b_ku2 = c1_ku2;
  *c1_b_cnt = c1_cnt;
  *c1_b_cnt1 = c1_cnt1;
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
  const mxArray *c1_cnt1, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_cnt1), &c1_thisId);
  sf_mex_destroy(&c1_cnt1);
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
  const mxArray *c1_cnt1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_cnt1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_cnt1), &c1_thisId);
  sf_mex_destroy(&c1_cnt1);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i127;
  real_T c1_b_inData[3];
  int32_T c1_i128;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i127 = 0; c1_i127 < 3; c1_i127++) {
    c1_b_inData[c1_i127] = (*(real_T (*)[3])c1_inData)[c1_i127];
  }

  for (c1_i128 = 0; c1_i128 < 3; c1_i128++) {
    c1_u[c1_i128] = c1_b_inData[c1_i128];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i129;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i129 = 0; c1_i129 < 3; c1_i129++) {
    c1_y[c1_i129] = c1_dv2[c1_i129];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ku;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i130;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_ku = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ku), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_ku);
  for (c1_i130 = 0; c1_i130 < 3; c1_i130++) {
    (*(real_T (*)[3])c1_outData)[c1_i130] = c1_y[c1_i130];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i131;
  real_T c1_b_inData[2];
  int32_T c1_i132;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i131 = 0; c1_i131 < 2; c1_i131++) {
    c1_b_inData[c1_i131] = (*(real_T (*)[2])c1_inData)[c1_i131];
  }

  for (c1_i132 = 0; c1_i132 < 2; c1_i132++) {
    c1_u[c1_i132] = c1_b_inData[c1_i132];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i133;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i133 = 0; c1_i133 < 2; c1_i133++) {
    c1_y[c1_i133] = c1_dv3[c1_i133];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_k;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i134;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_k = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_k), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_k);
  for (c1_i134 = 0; c1_i134 < 2; c1_i134++) {
    (*(real_T (*)[2])c1_outData)[c1_i134] = c1_y[c1_i134];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[4], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes[2];
  int32_T c1_loop_ub;
  int32_T c1_i135;
  real_T c1_b_inData_data[4];
  int32_T c1_u_sizes[2];
  int32_T c1_b_loop_ub;
  int32_T c1_i136;
  real_T c1_u_data[4];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes[0] = 1;
  c1_b_inData_sizes[1] = c1_inData_sizes[1];
  c1_loop_ub = c1_inData_sizes[1] - 1;
  for (c1_i135 = 0; c1_i135 <= c1_loop_ub; c1_i135++) {
    c1_b_inData_data[c1_b_inData_sizes[0] * c1_i135] =
      c1_inData_data[c1_inData_sizes[0] * c1_i135];
  }

  c1_u_sizes[0] = 1;
  c1_u_sizes[1] = c1_b_inData_sizes[1];
  c1_b_loop_ub = c1_b_inData_sizes[1] - 1;
  for (c1_i136 = 0; c1_i136 <= c1_b_loop_ub; c1_i136++) {
    c1_u_data[c1_u_sizes[0] * c1_i136] = c1_b_inData_data[c1_b_inData_sizes[0] *
      c1_i136];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_sizes[0], c1_u_sizes[1]), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data[4],
  int32_T c1_y_sizes[2])
{
  int32_T c1_i137;
  uint32_T c1_uv2[2];
  int32_T c1_i138;
  static boolean_T c1_bv0[2] = { FALSE, TRUE };

  boolean_T c1_bv1[2];
  int32_T c1_tmp_sizes[2];
  real_T c1_tmp_data[4];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i139;
  for (c1_i137 = 0; c1_i137 < 2; c1_i137++) {
    c1_uv2[c1_i137] = 1U + 3U * (uint32_T)c1_i137;
  }

  for (c1_i138 = 0; c1_i138 < 2; c1_i138++) {
    c1_bv1[c1_i138] = c1_bv0[c1_i138];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c1_bv1, c1_uv2, c1_tmp_sizes);
  c1_y_sizes[0] = 1;
  c1_y_sizes[1] = c1_tmp_sizes[1];
  c1_y = c1_y_sizes[0];
  c1_b_y = c1_y_sizes[1];
  c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i139 = 0; c1_i139 <= c1_loop_ub; c1_i139++) {
    c1_y_data[c1_i139] = c1_tmp_data[c1_i139];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[4],
  int32_T c1_outData_sizes[2])
{
  const mxArray *c1_local_t;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes[2];
  real_T c1_y_data[4];
  int32_T c1_loop_ub;
  int32_T c1_i140;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_local_t = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_local_t), &c1_thisId,
                        c1_y_data, c1_y_sizes);
  sf_mex_destroy(&c1_local_t);
  c1_outData_sizes[0] = 1;
  c1_outData_sizes[1] = c1_y_sizes[1];
  c1_loop_ub = c1_y_sizes[1] - 1;
  for (c1_i140 = 0; c1_i140 <= c1_loop_ub; c1_i140++) {
    c1_outData_data[c1_outData_sizes[0] * c1_i140] = c1_y_data[c1_y_sizes[0] *
      c1_i140];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i141;
  real_T c1_b_inData[4];
  int32_T c1_i142;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i141 = 0; c1_i141 < 4; c1_i141++) {
    c1_b_inData[c1_i141] = (*(real_T (*)[4])c1_inData)[c1_i141];
  }

  for (c1_i142 = 0; c1_i142 < 4; c1_i142++) {
    c1_u[c1_i142] = c1_b_inData[c1_i142];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv4[4];
  int32_T c1_i143;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i143 = 0; c1_i143 < 4; c1_i143++) {
    c1_y[c1_i143] = c1_dv4[c1_i143];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_SP_OFF_list;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i144;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_SP_OFF_list = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_SP_OFF_list), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_SP_OFF_list);
  for (c1_i144 = 0; c1_i144 < 4; c1_i144++) {
    (*(real_T (*)[4])c1_outData)[c1_i144] = c1_y[c1_i144];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i145;
  int32_T c1_i146;
  int32_T c1_i147;
  real_T c1_b_inData[9];
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i145 = 0;
  for (c1_i146 = 0; c1_i146 < 3; c1_i146++) {
    for (c1_i147 = 0; c1_i147 < 3; c1_i147++) {
      c1_b_inData[c1_i147 + c1_i145] = (*(real_T (*)[9])c1_inData)[c1_i147 +
        c1_i145];
    }

    c1_i145 += 3;
  }

  c1_i148 = 0;
  for (c1_i149 = 0; c1_i149 < 3; c1_i149++) {
    for (c1_i150 = 0; c1_i150 < 3; c1_i150++) {
      c1_u[c1_i150 + c1_i148] = c1_b_inData[c1_i150 + c1_i148];
    }

    c1_i148 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv5[9];
  int32_T c1_i151;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i151 = 0; c1_i151 < 9; c1_i151++) {
    c1_y[c1_i151] = c1_dv5[c1_i151];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Pu;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i152;
  int32_T c1_i153;
  int32_T c1_i154;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_Pu = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Pu), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Pu);
  c1_i152 = 0;
  for (c1_i153 = 0; c1_i153 < 3; c1_i153++) {
    for (c1_i154 = 0; c1_i154 < 3; c1_i154++) {
      (*(real_T (*)[9])c1_outData)[c1_i154 + c1_i152] = c1_y[c1_i154 + c1_i152];
    }

    c1_i152 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i155;
  int32_T c1_i156;
  int32_T c1_i157;
  real_T c1_b_inData[4];
  int32_T c1_i158;
  int32_T c1_i159;
  int32_T c1_i160;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i155 = 0;
  for (c1_i156 = 0; c1_i156 < 2; c1_i156++) {
    for (c1_i157 = 0; c1_i157 < 2; c1_i157++) {
      c1_b_inData[c1_i157 + c1_i155] = (*(real_T (*)[4])c1_inData)[c1_i157 +
        c1_i155];
    }

    c1_i155 += 2;
  }

  c1_i158 = 0;
  for (c1_i159 = 0; c1_i159 < 2; c1_i159++) {
    for (c1_i160 = 0; c1_i160 < 2; c1_i160++) {
      c1_u[c1_i160 + c1_i158] = c1_b_inData[c1_i160 + c1_i158];
    }

    c1_i158 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv6[4];
  int32_T c1_i161;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i161 = 0; c1_i161 < 4; c1_i161++) {
    c1_y[c1_i161] = c1_dv6[c1_i161];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Pi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i162;
  int32_T c1_i163;
  int32_T c1_i164;
  SFc1_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc1_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c1_Pi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Pi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Pi);
  c1_i162 = 0;
  for (c1_i163 = 0; c1_i163 < 2; c1_i163++) {
    for (c1_i164 = 0; c1_i164 < 2; c1_i164++) {
      (*(real_T (*)[4])c1_outData)[c1_i164 + c1_i162] = c1_y[c1_i164 + c1_i162];
    }

    c1_i162 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[110];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i165;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 110), FALSE);
  for (c1_i165 = 0; c1_i165 < 110; c1_i165++) {
    c1_r0 = &c1_info[c1_i165];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i165);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i165);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[110])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 1342789344U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 1319708366U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1286797244U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_div";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[2].fileTimeLo = 1313326210U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "eye";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c1_info[3].fileTimeLo = 1286797088U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[4].name = "eml_assert_valid_size_arg";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[4].fileTimeLo = 1286797094U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[5].name = "isinf";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[5].fileTimeLo = 1286797160U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[6].name = "mtimes";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].fileTimeLo = 1289494492U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[7].name = "eml_index_class";
  c1_info[7].dominantType = "";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[7].fileTimeLo = 1323145378U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[8].name = "intmax";
  c1_info[8].dominantType = "char";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[8].fileTimeLo = 1311233716U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[9].name = "eml_is_float_class";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[9].fileTimeLo = 1286797182U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[10].name = "min";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[10].fileTimeLo = 1311233718U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[11].name = "eml_min_or_max";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[11].fileTimeLo = 1334049890U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[12].name = "eml_scalar_eg";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[12].fileTimeLo = 1286797196U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[13].name = "eml_scalexp_alloc";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[13].fileTimeLo = 1330583234U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[14].name = "eml_index_class";
  c1_info[14].dominantType = "";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[14].fileTimeLo = 1323145378U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[15].name = "eml_scalar_eg";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[15].fileTimeLo = 1286797196U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323145378U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[17].name = "eml_int_forloop_overflow_check";
  c1_info[17].dominantType = "";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[17].fileTimeLo = 1332143472U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[18].name = "intmax";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[18].fileTimeLo = 1311233716U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "mtimes";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[19].fileTimeLo = 1289494492U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context = "";
  c1_info[20].name = "colon";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[20].fileTimeLo = 1311233718U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c1_info[21].name = "isfinite";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[21].fileTimeLo = 1286797158U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[22].name = "isinf";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[22].fileTimeLo = 1286797160U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[23].name = "isnan";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[23].fileTimeLo = 1286797160U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c1_info[24].name = "floor";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[24].fileTimeLo = 1286797142U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[25].name = "eml_scalar_floor";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[25].fileTimeLo = 1286797126U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c1_info[26].name = "abs";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[26].fileTimeLo = 1286797094U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[27].name = "eml_scalar_abs";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[27].fileTimeLo = 1286797112U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c1_info[28].name = "eps";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[28].fileTimeLo = 1326702796U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[29].name = "eml_mantissa_nbits";
  c1_info[29].dominantType = "char";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c1_info[29].fileTimeLo = 1307629642U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c1_info[30].name = "eml_float_model";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[30].fileTimeLo = 1326702796U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[31].name = "eml_realmin";
  c1_info[31].dominantType = "char";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[31].fileTimeLo = 1307629644U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[32].name = "eml_float_model";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[32].fileTimeLo = 1326702796U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[33].name = "eml_realmin_denormal";
  c1_info[33].dominantType = "char";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c1_info[33].fileTimeLo = 1326702798U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c1_info[34].name = "eml_float_model";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[34].fileTimeLo = 1326702796U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[35].name = "abs";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[35].fileTimeLo = 1286797094U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[36].name = "isfinite";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[36].fileTimeLo = 1286797158U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[37].name = "realmax";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[37].fileTimeLo = 1307629642U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[38].name = "eml_realmax";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[38].fileTimeLo = 1326702796U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[39].name = "eml_float_model";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[39].fileTimeLo = 1326702796U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[40].name = "mtimes";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[40].fileTimeLo = 1289494492U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c1_info[41].name = "mrdivide";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[41].fileTimeLo = 1342789344U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 1319708366U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c1_info[42].name = "floor";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[42].fileTimeLo = 1286797142U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c1_info[43].name = "eml_index_class";
  c1_info[43].dominantType = "";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[43].fileTimeLo = 1323145378U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  c1_info[44].name = "intmax";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[44].fileTimeLo = 1311233716U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context = "";
  c1_info[45].name = "any";
  c1_info[45].dominantType = "logical";
  c1_info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[45].fileTimeLo = 1286797234U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[46].name = "eml_all_or_any";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[46].fileTimeLo = 1286797094U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[47].name = "isequal";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[47].fileTimeLo = 1286797158U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[48].name = "eml_isequal_core";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[48].fileTimeLo = 1286797186U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[49].name = "eml_const_nonsingleton_dim";
  c1_info[49].dominantType = "logical";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[49].fileTimeLo = 1286797096U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[50].name = "isnan";
  c1_info[50].dominantType = "logical";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[50].fileTimeLo = 1286797160U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context = "";
  c1_info[51].name = "find";
  c1_info[51].dominantType = "logical";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c1_info[51].fileTimeLo = 1303124606U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[52].name = "eml_index_class";
  c1_info[52].dominantType = "";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[52].fileTimeLo = 1323145378U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[53].name = "eml_scalar_eg";
  c1_info[53].dominantType = "logical";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[53].fileTimeLo = 1286797196U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[54].name = "eml_int_forloop_overflow_check";
  c1_info[54].dominantType = "";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[54].fileTimeLo = 1332143472U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[55].name = "eml_index_plus";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[55].fileTimeLo = 1286797178U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[56].name = "eml_index_class";
  c1_info[56].dominantType = "";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[56].fileTimeLo = 1323145378U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[57].name = "eml_index_class";
  c1_info[57].dominantType = "";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[57].fileTimeLo = 1323145378U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[58].name = "eml_scalar_eg";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[58].fileTimeLo = 1286797196U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[59].name = "eml_xgemm";
  c1_info[59].dominantType = "char";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[59].fileTimeLo = 1299051572U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[60].name = "eml_blas_inline";
  c1_info[60].dominantType = "";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[60].fileTimeLo = 1299051568U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[61].name = "mtimes";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[61].fileTimeLo = 1289494492U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[62].name = "eml_index_class";
  c1_info[62].dominantType = "";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[62].fileTimeLo = 1323145378U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[63].name = "eml_scalar_eg";
  c1_info[63].dominantType = "double";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[63].fileTimeLo = 1286797196U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[110])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[64].name = "eml_refblas_xgemm";
  c1_info[64].dominantType = "char";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[64].fileTimeLo = 1299051574U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[65].name = "eml_xdotu";
  c1_info[65].dominantType = "double";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[65].fileTimeLo = 1299051572U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[66].name = "eml_blas_inline";
  c1_info[66].dominantType = "";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[66].fileTimeLo = 1299051568U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[67].name = "eml_xdot";
  c1_info[67].dominantType = "double";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[67].fileTimeLo = 1299051572U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[68].name = "eml_blas_inline";
  c1_info[68].dominantType = "";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[68].fileTimeLo = 1299051568U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[69].name = "eml_index_class";
  c1_info[69].dominantType = "";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[69].fileTimeLo = 1323145378U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[70].name = "eml_refblas_xdot";
  c1_info[70].dominantType = "double";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[70].fileTimeLo = 1299051572U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[71].name = "eml_refblas_xdotx";
  c1_info[71].dominantType = "char";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[71].fileTimeLo = 1299051574U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[72].name = "eml_scalar_eg";
  c1_info[72].dominantType = "double";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[72].fileTimeLo = 1286797196U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[73].name = "eml_index_class";
  c1_info[73].dominantType = "";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[73].fileTimeLo = 1323145378U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[74].name = "eml_index_minus";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[74].fileTimeLo = 1286797178U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[75].name = "eml_index_class";
  c1_info[75].dominantType = "";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[75].fileTimeLo = 1323145378U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[76].name = "eml_index_times";
  c1_info[76].dominantType = "coder.internal.indexInt";
  c1_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[76].fileTimeLo = 1286797180U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[77].name = "eml_index_class";
  c1_info[77].dominantType = "";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[77].fileTimeLo = 1323145378U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[78].name = "eml_index_plus";
  c1_info[78].dominantType = "coder.internal.indexInt";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[78].fileTimeLo = 1286797178U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[79].name = "eml_int_forloop_overflow_check";
  c1_info[79].dominantType = "";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[79].fileTimeLo = 1332143472U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context = "";
  c1_info[80].name = "rand";
  c1_info[80].dominantType = "";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c1_info[80].fileTimeLo = 1313326222U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c1_info[81].name = "eml_is_rand_extrinsic";
  c1_info[81].dominantType = "";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m";
  c1_info[81].fileTimeLo = 1334049890U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c1_info[82].name = "eml_rand";
  c1_info[82].dominantType = "char";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[82].fileTimeLo = 1313326220U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[83].name = "eml_rand_str2id";
  c1_info[83].dominantType = "char";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c1_info[83].fileTimeLo = 1313326222U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[84].name = "eml_rand_mcg16807_stateful";
  c1_info[84].dominantType = "char";
  c1_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[84].fileTimeLo = 1313326220U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[85].name = "eml_rand_mcg16807";
  c1_info[85].dominantType = "char";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c1_info[85].fileTimeLo = 1313326220U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c1_info[86].name = "eml_rand_mcg16807";
  c1_info[86].dominantType = "uint32";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c1_info[86].fileTimeLo = 1313326220U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandu";
  c1_info[87].name = "mtimes";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[87].fileTimeLo = 1289494492U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[88].name = "eml_rand_shr3cong_stateful";
  c1_info[88].dominantType = "char";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[88].fileTimeLo = 1313326222U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[89].name = "eml_rand_shr3cong";
  c1_info[89].dominantType = "char";
  c1_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[89].fileTimeLo = 1313326220U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 0U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c1_info[90].name = "eml_rand_shr3cong";
  c1_info[90].dominantType = "uint32";
  c1_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c1_info[90].fileTimeLo = 1313326220U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandu";
  c1_info[91].name = "mtimes";
  c1_info[91].dominantType = "double";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[91].fileTimeLo = 1289494492U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c1_info[92].name = "eml_rand_mt19937ar_stateful";
  c1_info[92].dominantType = "char";
  c1_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[92].fileTimeLo = 1313326220U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[93].name = "eml_rand_mt19937ar";
  c1_info[93].dominantType = "char";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c1_info[93].fileTimeLo = 1313326220U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c1_info[94].name = "eml_rand_mt19937ar";
  c1_info[94].dominantType = "uint32";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c1_info[94].fileTimeLo = 1313326220U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[95].name = "eps";
  c1_info[95].dominantType = "";
  c1_info[95].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[95].fileTimeLo = 1326702796U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[96].name = "eml_eps";
  c1_info[96].dominantType = "char";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[96].fileTimeLo = 1326702796U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[97].name = "eml_float_model";
  c1_info[97].dominantType = "char";
  c1_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[97].fileTimeLo = 1326702796U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[98].name = "isequal";
  c1_info[98].dominantType = "double";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[98].fileTimeLo = 1286797158U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c1_info[99].name = "isnan";
  c1_info[99].dominantType = "double";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[99].fileTimeLo = 1286797160U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[100].name = "mtimes";
  c1_info[100].dominantType = "double";
  c1_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[100].fileTimeLo = 1289494492U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[101].name = "eml_index_class";
  c1_info[101].dominantType = "";
  c1_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[101].fileTimeLo = 1323145378U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c1_info[102].name = "eml_index_plus";
  c1_info[102].dominantType = "double";
  c1_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[102].fileTimeLo = 1286797178U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c1_info[103].name = "eml_error";
  c1_info[103].dominantType = "char";
  c1_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[103].fileTimeLo = 1305296400U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context = "";
  c1_info[104].name = "mpower";
  c1_info[104].dominantType = "double";
  c1_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[104].fileTimeLo = 1286797242U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[105].name = "power";
  c1_info[105].dominantType = "double";
  c1_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[105].fileTimeLo = 1336500496U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[106].name = "eml_scalar_eg";
  c1_info[106].dominantType = "double";
  c1_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[106].fileTimeLo = 1286797196U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[107].name = "eml_scalexp_alloc";
  c1_info[107].dominantType = "double";
  c1_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[107].fileTimeLo = 1330583234U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[108].name = "floor";
  c1_info[108].dominantType = "double";
  c1_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[108].fileTimeLo = 1286797142U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context = "";
  c1_info[109].name = "abs";
  c1_info[109].dominantType = "double";
  c1_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[109].fileTimeLo = 1286797094U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
}

static void c1_check_forloop_overflow_error(SFc1_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static real_T c1_abs(SFc1_BuckBoost1InstanceStruct *chartInstance, real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  return muDoubleScalarAbs(c1_b_x);
}

static void c1_realmax(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

static boolean_T c1_any(SFc1_BuckBoost1InstanceStruct *chartInstance, boolean_T
  c1_x[4])
{
  boolean_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  boolean_T c1_b6;
  boolean_T exitg1;
  c1_y = FALSE;
  c1_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_k < 4)) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b6 = ((real_T)c1_x[(int32_T)c1_b_k - 1] == 0.0);
    if (!c1_b6) {
      c1_y = TRUE;
      exitg1 = TRUE;
    } else {
      c1_k++;
    }
  }

  return c1_y;
}

static real_T c1_rand(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
  uint32_T c1_uv3[625];
  int32_T c1_i166;
  int32_T c1_i167;
  uint32_T c1_d_state[625];
  real_T c1_d1;
  int32_T c1_i168;
  if (!chartInstance->c1_method_not_empty) {
    chartInstance->c1_method_not_empty = TRUE;
  }

  if (!chartInstance->c1_c_state_not_empty) {
    c1_eml_rand_mt19937ar(chartInstance, c1_uv3);
    for (c1_i166 = 0; c1_i166 < 625; c1_i166++) {
      chartInstance->c1_c_state[c1_i166] = c1_uv3[c1_i166];
    }

    chartInstance->c1_c_state_not_empty = TRUE;
  }

  for (c1_i167 = 0; c1_i167 < 625; c1_i167++) {
    c1_d_state[c1_i167] = chartInstance->c1_c_state[c1_i167];
  }

  c1_d1 = c1_c_eml_rand_mt19937ar(chartInstance, c1_d_state);
  for (c1_i168 = 0; c1_i168 < 625; c1_i168++) {
    chartInstance->c1_c_state[c1_i168] = c1_d_state[c1_i168];
  }

  return c1_d1;
}

static void c1_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_d_state[625])
{
  real_T c1_d2;
  int32_T c1_i169;
  c1_d2 = 5489.0;
  for (c1_i169 = 0; c1_i169 < 625; c1_i169++) {
    c1_d_state[c1_i169] = 0U;
  }

  c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d2);
}

static void c1_twister_state_vector(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625])
{
  int32_T c1_i170;
  for (c1_i170 = 0; c1_i170 < 625; c1_i170++) {
    c1_b_mt[c1_i170] = c1_mt[c1_i170];
  }

  c1_b_twister_state_vector(chartInstance, c1_b_mt, c1_seed);
}

static void c1_b_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_r)
{
  int32_T c1_i171;
  for (c1_i171 = 0; c1_i171 < 625; c1_i171++) {
    c1_e_state[c1_i171] = c1_d_state[c1_i171];
  }

  *c1_r = c1_c_eml_rand_mt19937ar(chartInstance, c1_e_state);
}

static void c1_eml_error(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
  int32_T c1_i172;
  static char_T c1_varargin_1[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l',
    'i', 'd', 'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c1_u[37];
  const mxArray *c1_y = NULL;
  for (c1_i172 = 0; c1_i172 < 37; c1_i172++) {
    c1_u[c1_i172] = c1_varargin_1[c1_i172];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 37), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
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

static int32_T c1_i_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i173;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i173, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i173;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_j_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_method),
    &c1_thisId);
  sf_mex_destroy(&c1_b_method);
  return c1_y;
}

static uint32_T c1_k_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u0;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_method_not_empty = FALSE;
  } else {
    chartInstance->c1_method_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u0;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_l_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId);
  sf_mex_destroy(&c1_d_state);
  return c1_y;
}

static uint32_T c1_m_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u1;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_state_not_empty = FALSE;
  } else {
    chartInstance->c1_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u1;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_n_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_o_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625])
{
  uint32_T c1_uv4[625];
  int32_T c1_i174;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_c_state_not_empty = FALSE;
  } else {
    chartInstance->c1_c_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 7, 0U, 1, 0U, 1, 625);
    for (c1_i174 = 0; c1_i174 < 625; c1_i174++) {
      c1_y[c1_i174] = c1_uv4[c1_i174];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_p_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_q_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2])
{
  uint32_T c1_uv5[2];
  int32_T c1_i175;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_state_not_empty = FALSE;
  } else {
    chartInstance->c1_b_state_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv5, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i175 = 0; c1_i175 < 2; c1_i175++) {
      c1_y[c1_i175] = c1_uv5[c1_i175];
    }
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_r_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_BuckBoost1, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_BuckBoost1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_BuckBoost1);
  return c1_y;
}

static uint8_T c1_s_emlrt_marshallIn(SFc1_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u2, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_twister_state_vector(SFc1_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed)
{
  uint32_T c1_r;
  int32_T c1_mti;
  real_T c1_b_mti;
  real_T c1_d3;
  uint32_T c1_u3;
  c1_r = 5489U;
  c1_mt[0] = 5489U;
  for (c1_mti = 0; c1_mti < 623; c1_mti++) {
    c1_b_mti = 2.0 + (real_T)c1_mti;
    c1_d3 = muDoubleScalarRound(c1_b_mti - 1.0);
    if (c1_d3 < 4.294967296E+9) {
      if (c1_d3 >= 0.0) {
        c1_u3 = (uint32_T)c1_d3;
      } else {
        c1_u3 = 0U;
      }
    } else if (c1_d3 >= 4.294967296E+9) {
      c1_u3 = MAX_uint32_T;
    } else {
      c1_u3 = 0U;
    }

    c1_r = (c1_r ^ c1_r >> 30U) * 1812433253U + c1_u3;
    c1_mt[(int32_T)c1_b_mti - 1] = c1_r;
  }

  c1_mt[624] = 624U;
}

static real_T c1_c_eml_rand_mt19937ar(SFc1_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c1_d_state[625])
{
  int32_T c1_i176;
  uint32_T c1_u[2];
  int32_T c1_j;
  real_T c1_b_j;
  uint32_T c1_mti;
  int32_T c1_kk;
  real_T c1_b_kk;
  uint32_T c1_y;
  uint32_T c1_b_y;
  uint32_T c1_c_y;
  int32_T c1_c_kk;
  uint32_T c1_d_y;
  uint32_T c1_e_y;
  uint32_T c1_f_y;
  uint32_T c1_g_y;
  real_T c1_a;
  real_T c1_h_y;
  real_T c1_b;
  real_T c1_b_r;
  boolean_T c1_b7;
  boolean_T c1_isvalid;
  int32_T c1_k;
  int32_T c1_b_a;
  real_T c1_d4;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  boolean_T exitg2;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg1 = 0;
    for (c1_i176 = 0; c1_i176 < 2; c1_i176++) {
      c1_u[c1_i176] = 0U;
    }

    for (c1_j = 0; c1_j < 2; c1_j++) {
      c1_b_j = 1.0 + (real_T)c1_j;
      c1_mti = c1_d_state[624] + 1U;
      if ((real_T)c1_mti >= 625.0) {
        for (c1_kk = 0; c1_kk < 227; c1_kk++) {
          c1_b_kk = 1.0 + (real_T)c1_kk;
          c1_y = (c1_d_state[(int32_T)c1_b_kk - 1] & 2147483648U) | (c1_d_state
            [(int32_T)(c1_b_kk + 1.0) - 1] & 2147483647U);
          c1_b_y = c1_y;
          c1_c_y = c1_b_y;
          if ((real_T)(c1_c_y & 1U) == 0.0) {
            c1_c_y >>= 1U;
          } else {
            c1_c_y = c1_c_y >> 1U ^ 2567483615U;
          }

          c1_d_state[(int32_T)c1_b_kk - 1] = c1_d_state[(int32_T)(c1_b_kk +
            397.0) - 1] ^ c1_c_y;
        }

        for (c1_c_kk = 0; c1_c_kk < 396; c1_c_kk++) {
          c1_b_kk = 228.0 + (real_T)c1_c_kk;
          c1_y = (c1_d_state[(int32_T)c1_b_kk - 1] & 2147483648U) | (c1_d_state
            [(int32_T)(c1_b_kk + 1.0) - 1] & 2147483647U);
          c1_d_y = c1_y;
          c1_e_y = c1_d_y;
          if ((real_T)(c1_e_y & 1U) == 0.0) {
            c1_e_y >>= 1U;
          } else {
            c1_e_y = c1_e_y >> 1U ^ 2567483615U;
          }

          c1_d_state[(int32_T)c1_b_kk - 1] = c1_d_state[(int32_T)((c1_b_kk + 1.0)
            - 228.0) - 1] ^ c1_e_y;
        }

        c1_y = (c1_d_state[623] & 2147483648U) | (c1_d_state[0] & 2147483647U);
        c1_f_y = c1_y;
        c1_g_y = c1_f_y;
        if ((real_T)(c1_g_y & 1U) == 0.0) {
          c1_g_y >>= 1U;
        } else {
          c1_g_y = c1_g_y >> 1U ^ 2567483615U;
        }

        c1_d_state[623] = c1_d_state[396] ^ c1_g_y;
        c1_mti = 1U;
      }

      c1_y = c1_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c1_mti, 1, 625, 1, 0) - 1];
      c1_d_state[624] = c1_mti;
      c1_y ^= c1_y >> 11U;
      c1_y ^= c1_y << 7U & 2636928640U;
      c1_y ^= c1_y << 15U & 4022730752U;
      c1_y ^= c1_y >> 18U;
      c1_u[(int32_T)c1_b_j - 1] = c1_y;
    }

    c1_u[0] >>= 5U;
    c1_u[1] >>= 6U;
    c1_a = (real_T)c1_u[0];
    c1_h_y = c1_a * 6.7108864E+7;
    c1_b = c1_h_y + (real_T)c1_u[1];
    c1_b_r = 1.1102230246251565E-16 * c1_b;
    if (c1_b_r == 0.0) {
      guard1 = FALSE;
      if ((real_T)c1_d_state[624] >= 1.0) {
        if ((real_T)c1_d_state[624] < 625.0) {
          c1_b7 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c1_b7 = FALSE;
      }

      c1_isvalid = c1_b7;
      if (c1_isvalid) {
        c1_isvalid = FALSE;
        c1_k = 0;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (c1_k + 1 < 625)) {
          if ((real_T)c1_d_state[c1_k] == 0.0) {
            c1_b_a = c1_k + 1;
            c1_k = c1_b_a;
          } else {
            c1_isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!c1_isvalid) {
        c1_eml_error(chartInstance);
        c1_d4 = 5489.0;
        c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d4);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_b_r;
}

static void init_dsm_address_info(SFc1_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1584114734U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3589778851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1490310527U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3561069369U);
}

mxArray *sf_c1_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sd5qo0ro2FUo2tA6cbgxwF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,35,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,34,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,34,"type",mxType);
    }

    mxSetField(mxData,34,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,42,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,34,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,34,"type",mxType);
    }

    mxSetField(mxData,34,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,35,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,35,"type",mxType);
    }

    mxSetField(mxData,35,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,36,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,36,"type",mxType);
    }

    mxSetField(mxData,36,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,37,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,37,"type",mxType);
    }

    mxSetField(mxData,37,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,38,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,38,"type",mxType);
    }

    mxSetField(mxData,38,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,39,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,39,"type",mxType);
    }

    mxSetField(mxData,39,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,40,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,40,"type",mxType);
    }

    mxSetField(mxData,40,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,41,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,41,"type",mxType);
    }

    mxSetField(mxData,41,"complexity",mxCreateDoubleScalar(0));
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
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[34],T\"Capout\",},{M[1],M[83],T\"ESRout\",},{M[1],M[94],T\"Inoise\",},{M[1],M[35],T\"P11\",},{M[1],M[31],T\"P12\",},{M[1],M[46],T\"P21\",},{M[1],M[47],T\"P22\",},{M[1],M[89],T\"Pi11\",},{M[1],M[90],T\"Pi12\",},{M[1],M[91],T\"Pi21\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[92],T\"Pi22\",},{M[1],M[74],T\"Pu11\",},{M[1],M[75],T\"Pu12\",},{M[1],M[76],T\"Pu13\",},{M[1],M[77],T\"Pu21\",},{M[1],M[78],T\"Pu22\",},{M[1],M[79],T\"Pu23\",},{M[1],M[80],T\"Pu31\",},{M[1],M[81],T\"Pu32\",},{M[1],M[82],T\"Pu33\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"Vnoise\",},{M[1],M[101],T\"cnt\",},{M[1],M[103],T\"cnt1\",},{M[1],M[29],T\"e\",},{M[1],M[66],T\"ei\",},{M[1],M[70],T\"eu\",},{M[1],M[95],T\"k0\",},{M[1],M[96],T\"k1\",},{M[1],M[97],T\"ku0\",},{M[1],M[98],T\"ku1\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[99],T\"ku2\",},{M[1],M[84],T\"t0\",},{M[1],M[44],T\"w0\",},{M[1],M[45],T\"w1\",},{M[1],M[67],T\"wi0\",},{M[1],M[68],T\"wi1\",},{M[1],M[71],T\"wu0\",},{M[1],M[72],T\"wu1\",},{M[1],M[73],T\"wu2\",},{M[1],M[28],T\"y\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[65],T\"yi\",},{M[1],M[69],T\"yu\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c1_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 47, 10);
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
           77,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"startrej");
          _SFD_SET_DATA_PROPS(1,1,1,0,"start");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t");
          _SFD_SET_DATA_PROPS(3,1,1,0,"duty");
          _SFD_SET_DATA_PROPS(4,1,1,0,"v_out");
          _SFD_SET_DATA_PROPS(5,1,1,0,"i_in");
          _SFD_SET_DATA_PROPS(6,1,1,0,"w0in");
          _SFD_SET_DATA_PROPS(7,1,1,0,"w1in");
          _SFD_SET_DATA_PROPS(8,1,1,0,"P11in");
          _SFD_SET_DATA_PROPS(9,1,1,0,"P12in");
          _SFD_SET_DATA_PROPS(10,1,1,0,"P21in");
          _SFD_SET_DATA_PROPS(11,1,1,0,"P22in");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(13,2,0,1,"y");
          _SFD_SET_DATA_PROPS(14,2,0,1,"e");
          _SFD_SET_DATA_PROPS(15,2,0,1,"w0");
          _SFD_SET_DATA_PROPS(16,2,0,1,"w1");
          _SFD_SET_DATA_PROPS(17,2,0,1,"P11");
          _SFD_SET_DATA_PROPS(18,2,0,1,"P12");
          _SFD_SET_DATA_PROPS(19,2,0,1,"P21");
          _SFD_SET_DATA_PROPS(20,2,0,1,"P22");
          _SFD_SET_DATA_PROPS(21,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(22,1,1,0,"wi0in");
          _SFD_SET_DATA_PROPS(23,1,1,0,"wi1in");
          _SFD_SET_DATA_PROPS(24,1,1,0,"Pi11in");
          _SFD_SET_DATA_PROPS(25,1,1,0,"Pi12in");
          _SFD_SET_DATA_PROPS(26,1,1,0,"Pi21in");
          _SFD_SET_DATA_PROPS(27,1,1,0,"Pi22in");
          _SFD_SET_DATA_PROPS(28,1,1,0,"wu0in");
          _SFD_SET_DATA_PROPS(29,1,1,0,"wu1in");
          _SFD_SET_DATA_PROPS(30,1,1,0,"wu2in");
          _SFD_SET_DATA_PROPS(31,1,1,0,"Pu11in");
          _SFD_SET_DATA_PROPS(32,1,1,0,"Pu12in");
          _SFD_SET_DATA_PROPS(33,1,1,0,"Pu13in");
          _SFD_SET_DATA_PROPS(34,1,1,0,"Pu21in");
          _SFD_SET_DATA_PROPS(35,1,1,0,"Pu22in");
          _SFD_SET_DATA_PROPS(36,1,1,0,"Pu23in");
          _SFD_SET_DATA_PROPS(37,1,1,0,"Pu31in");
          _SFD_SET_DATA_PROPS(38,1,1,0,"Pu32in");
          _SFD_SET_DATA_PROPS(39,1,1,0,"Pu33in");
          _SFD_SET_DATA_PROPS(40,1,1,0,"ESRin");
          _SFD_SET_DATA_PROPS(41,1,1,0,"t0in");
          _SFD_SET_DATA_PROPS(42,2,0,1,"yi");
          _SFD_SET_DATA_PROPS(43,2,0,1,"ei");
          _SFD_SET_DATA_PROPS(44,2,0,1,"wi0");
          _SFD_SET_DATA_PROPS(45,2,0,1,"wi1");
          _SFD_SET_DATA_PROPS(46,2,0,1,"Pi11");
          _SFD_SET_DATA_PROPS(47,2,0,1,"Pi12");
          _SFD_SET_DATA_PROPS(48,2,0,1,"Pi21");
          _SFD_SET_DATA_PROPS(49,2,0,1,"Pi22");
          _SFD_SET_DATA_PROPS(50,2,0,1,"yu");
          _SFD_SET_DATA_PROPS(51,2,0,1,"eu");
          _SFD_SET_DATA_PROPS(52,2,0,1,"wu0");
          _SFD_SET_DATA_PROPS(53,2,0,1,"wu1");
          _SFD_SET_DATA_PROPS(54,2,0,1,"wu2");
          _SFD_SET_DATA_PROPS(55,2,0,1,"Pu11");
          _SFD_SET_DATA_PROPS(56,2,0,1,"Pu12");
          _SFD_SET_DATA_PROPS(57,2,0,1,"Pu13");
          _SFD_SET_DATA_PROPS(58,2,0,1,"Pu21");
          _SFD_SET_DATA_PROPS(59,2,0,1,"Pu22");
          _SFD_SET_DATA_PROPS(60,2,0,1,"Pu23");
          _SFD_SET_DATA_PROPS(61,2,0,1,"Pu31");
          _SFD_SET_DATA_PROPS(62,2,0,1,"Pu32");
          _SFD_SET_DATA_PROPS(63,2,0,1,"Pu33");
          _SFD_SET_DATA_PROPS(64,2,0,1,"ESRout");
          _SFD_SET_DATA_PROPS(65,2,0,1,"Vnoise");
          _SFD_SET_DATA_PROPS(66,2,0,1,"Inoise");
          _SFD_SET_DATA_PROPS(67,2,0,1,"t0");
          _SFD_SET_DATA_PROPS(68,2,0,1,"k0");
          _SFD_SET_DATA_PROPS(69,2,0,1,"k1");
          _SFD_SET_DATA_PROPS(70,2,0,1,"ku0");
          _SFD_SET_DATA_PROPS(71,2,0,1,"ku1");
          _SFD_SET_DATA_PROPS(72,2,0,1,"ku2");
          _SFD_SET_DATA_PROPS(73,1,1,0,"cntin");
          _SFD_SET_DATA_PROPS(74,2,0,1,"cnt");
          _SFD_SET_DATA_PROPS(75,1,1,0,"cntin1");
          _SFD_SET_DATA_PROPS(76,2,0,1,"cnt1");
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
        _SFD_CV_INIT_EML(0,1,1,12,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,9765);
        _SFD_CV_INIT_EML_IF(0,1,0,4302,4314,-1,9764);
        _SFD_CV_INIT_EML_IF(0,1,1,4521,4543,-1,5637);
        _SFD_CV_INIT_EML_IF(0,1,2,4657,4676,4750,4795);
        _SFD_CV_INIT_EML_IF(0,1,3,5642,5706,-1,5761);
        _SFD_CV_INIT_EML_IF(0,1,4,6058,6081,-1,7993);
        _SFD_CV_INIT_EML_IF(0,1,5,6210,6229,6298,6345);
        _SFD_CV_INIT_EML_IF(0,1,6,7998,8054,-1,8821);
        _SFD_CV_INIT_EML_IF(0,1,7,9194,9209,-1,9731);
        _SFD_CV_INIT_EML_IF(0,1,8,9280,9295,-1,9497);
        _SFD_CV_INIT_EML_IF(0,1,9,9366,9402,-1,9485);
        _SFD_CV_INIT_EML_IF(0,1,10,9506,9521,-1,9723);
        _SFD_CV_INIT_EML_IF(0,1,11,9592,9628,-1,9711);

        {
          static int condStart[] = { 5645, 5676 };

          static int condEnd[] = { 5672, 5705 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,5645,5705,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 8001, 8028 };

          static int condEnd[] = { 8024, 8053 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,8001,8053,2,2,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_startrej;
          real_T *c1_start;
          real_T *c1_t;
          real_T *c1_duty;
          real_T *c1_v_out;
          real_T *c1_i_in;
          real_T *c1_w0in;
          real_T *c1_w1in;
          real_T *c1_P11in;
          real_T *c1_P12in;
          real_T *c1_P21in;
          real_T *c1_P22in;
          real_T *c1_Capin;
          real_T *c1_y;
          real_T *c1_e;
          real_T *c1_w0;
          real_T *c1_w1;
          real_T *c1_P11;
          real_T *c1_P12;
          real_T *c1_P21;
          real_T *c1_P22;
          real_T *c1_Capout;
          real_T *c1_wi0in;
          real_T *c1_wi1in;
          real_T *c1_Pi11in;
          real_T *c1_Pi12in;
          real_T *c1_Pi21in;
          real_T *c1_Pi22in;
          real_T *c1_wu0in;
          real_T *c1_wu1in;
          real_T *c1_wu2in;
          real_T *c1_Pu11in;
          real_T *c1_Pu12in;
          real_T *c1_Pu13in;
          real_T *c1_Pu21in;
          real_T *c1_Pu22in;
          real_T *c1_Pu23in;
          real_T *c1_Pu31in;
          real_T *c1_Pu32in;
          real_T *c1_Pu33in;
          real_T *c1_ESRin;
          real_T *c1_t0in;
          real_T *c1_yi;
          real_T *c1_ei;
          real_T *c1_wi0;
          real_T *c1_wi1;
          real_T *c1_Pi11;
          real_T *c1_Pi12;
          real_T *c1_Pi21;
          real_T *c1_Pi22;
          real_T *c1_yu;
          real_T *c1_eu;
          real_T *c1_wu0;
          real_T *c1_wu1;
          real_T *c1_wu2;
          real_T *c1_Pu11;
          real_T *c1_Pu12;
          real_T *c1_Pu13;
          real_T *c1_Pu21;
          real_T *c1_Pu22;
          real_T *c1_Pu23;
          real_T *c1_Pu31;
          real_T *c1_Pu32;
          real_T *c1_Pu33;
          real_T *c1_ESRout;
          real_T *c1_Vnoise;
          real_T *c1_Inoise;
          real_T *c1_t0;
          real_T *c1_k0;
          real_T *c1_k1;
          real_T *c1_ku0;
          real_T *c1_ku1;
          real_T *c1_ku2;
          real_T *c1_cntin;
          real_T *c1_cnt;
          real_T *c1_cntin1;
          real_T *c1_cnt1;
          c1_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 42);
          c1_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
          c1_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 41);
          c1_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
          c1_ku2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 40);
          c1_ku1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 39);
          c1_ku0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 38);
          c1_k1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 37);
          c1_k0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 36);
          c1_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 35);
          c1_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 34);
          c1_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 33);
          c1_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
          c1_Pu33 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
          c1_Pu32 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
          c1_Pu31 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
          c1_Pu23 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
          c1_Pu22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
          c1_Pu21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
          c1_Pu13 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
          c1_Pu12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
          c1_Pu11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
          c1_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
          c1_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
          c1_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
          c1_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
          c1_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
          c1_Pi22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
          c1_Pi21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
          c1_Pi12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c1_Pi11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c1_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c1_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c1_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c1_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c1_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
          c1_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
          c1_Pu33in = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
          c1_Pu32in = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
          c1_Pu31in = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
          c1_Pu23in = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
          c1_Pu22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
          c1_Pu21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
          c1_Pu13in = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
          c1_Pu12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
          c1_Pu11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
          c1_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
          c1_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
          c1_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
          c1_Pi22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
          c1_Pi21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
          c1_Pi12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
          c1_Pi11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c1_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c1_P22 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c1_P21 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_P12 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_P11 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_P22in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_P21in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_P12in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_P11in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_startrej = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_startrej);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_start);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_duty);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_v_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_i_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_w0in);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_w1in);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_P11in);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_P12in);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_P21in);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_P22in);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_Capin);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_e);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_w0);
          _SFD_SET_DATA_VALUE_PTR(16U, c1_w1);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_P11);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_P12);
          _SFD_SET_DATA_VALUE_PTR(19U, c1_P21);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_P22);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_Capout);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_wi0in);
          _SFD_SET_DATA_VALUE_PTR(23U, c1_wi1in);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_Pi11in);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_Pi12in);
          _SFD_SET_DATA_VALUE_PTR(26U, c1_Pi21in);
          _SFD_SET_DATA_VALUE_PTR(27U, c1_Pi22in);
          _SFD_SET_DATA_VALUE_PTR(28U, c1_wu0in);
          _SFD_SET_DATA_VALUE_PTR(29U, c1_wu1in);
          _SFD_SET_DATA_VALUE_PTR(30U, c1_wu2in);
          _SFD_SET_DATA_VALUE_PTR(31U, c1_Pu11in);
          _SFD_SET_DATA_VALUE_PTR(32U, c1_Pu12in);
          _SFD_SET_DATA_VALUE_PTR(33U, c1_Pu13in);
          _SFD_SET_DATA_VALUE_PTR(34U, c1_Pu21in);
          _SFD_SET_DATA_VALUE_PTR(35U, c1_Pu22in);
          _SFD_SET_DATA_VALUE_PTR(36U, c1_Pu23in);
          _SFD_SET_DATA_VALUE_PTR(37U, c1_Pu31in);
          _SFD_SET_DATA_VALUE_PTR(38U, c1_Pu32in);
          _SFD_SET_DATA_VALUE_PTR(39U, c1_Pu33in);
          _SFD_SET_DATA_VALUE_PTR(40U, c1_ESRin);
          _SFD_SET_DATA_VALUE_PTR(41U, c1_t0in);
          _SFD_SET_DATA_VALUE_PTR(42U, c1_yi);
          _SFD_SET_DATA_VALUE_PTR(43U, c1_ei);
          _SFD_SET_DATA_VALUE_PTR(44U, c1_wi0);
          _SFD_SET_DATA_VALUE_PTR(45U, c1_wi1);
          _SFD_SET_DATA_VALUE_PTR(46U, c1_Pi11);
          _SFD_SET_DATA_VALUE_PTR(47U, c1_Pi12);
          _SFD_SET_DATA_VALUE_PTR(48U, c1_Pi21);
          _SFD_SET_DATA_VALUE_PTR(49U, c1_Pi22);
          _SFD_SET_DATA_VALUE_PTR(50U, c1_yu);
          _SFD_SET_DATA_VALUE_PTR(51U, c1_eu);
          _SFD_SET_DATA_VALUE_PTR(52U, c1_wu0);
          _SFD_SET_DATA_VALUE_PTR(53U, c1_wu1);
          _SFD_SET_DATA_VALUE_PTR(54U, c1_wu2);
          _SFD_SET_DATA_VALUE_PTR(55U, c1_Pu11);
          _SFD_SET_DATA_VALUE_PTR(56U, c1_Pu12);
          _SFD_SET_DATA_VALUE_PTR(57U, c1_Pu13);
          _SFD_SET_DATA_VALUE_PTR(58U, c1_Pu21);
          _SFD_SET_DATA_VALUE_PTR(59U, c1_Pu22);
          _SFD_SET_DATA_VALUE_PTR(60U, c1_Pu23);
          _SFD_SET_DATA_VALUE_PTR(61U, c1_Pu31);
          _SFD_SET_DATA_VALUE_PTR(62U, c1_Pu32);
          _SFD_SET_DATA_VALUE_PTR(63U, c1_Pu33);
          _SFD_SET_DATA_VALUE_PTR(64U, c1_ESRout);
          _SFD_SET_DATA_VALUE_PTR(65U, c1_Vnoise);
          _SFD_SET_DATA_VALUE_PTR(66U, c1_Inoise);
          _SFD_SET_DATA_VALUE_PTR(67U, c1_t0);
          _SFD_SET_DATA_VALUE_PTR(68U, c1_k0);
          _SFD_SET_DATA_VALUE_PTR(69U, c1_k1);
          _SFD_SET_DATA_VALUE_PTR(70U, c1_ku0);
          _SFD_SET_DATA_VALUE_PTR(71U, c1_ku1);
          _SFD_SET_DATA_VALUE_PTR(72U, c1_ku2);
          _SFD_SET_DATA_VALUE_PTR(73U, c1_cntin);
          _SFD_SET_DATA_VALUE_PTR(74U, c1_cnt);
          _SFD_SET_DATA_VALUE_PTR(75U, c1_cntin1);
          _SFD_SET_DATA_VALUE_PTR(76U, c1_cnt1);
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
  return "zbA1b1L58ssEwfeACpcSgE";
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
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 23, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 24, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 25, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 26, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 27, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 28, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 29, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 30, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 31, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 32, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 33, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 34, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,35);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,42);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3136479192U));
  ssSetChecksum1(S,(850689215U));
  ssSetChecksum2(S,(3027188325U));
  ssSetChecksum3(S,(3439615947U));
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
