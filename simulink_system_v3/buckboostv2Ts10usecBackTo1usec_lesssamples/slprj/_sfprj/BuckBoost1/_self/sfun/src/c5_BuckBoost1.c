/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c5_BuckBoost1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[165] = { "sampling_time", "splittime1",
  "splittime2", "offset", "OFFSET_ON_START_abs", "OFFSET_ON_END_rel",
  "OFFSET_OFF_START_rel", "OFFSET_OFF_END_abs", "lambda", "delta", "lambdai",
  "alpha", "beta", "gamma", "K", "u0", "u1", "A_0_iOFF", "A_1_iOFF", "G_0_iOFF",
  "G_1_iOFF", "ktilde_0_iOFF", "ktilde_1_iOFF", "alphai_iOFF", "betai_iOFF",
  "gamma_iOFF", "gammai_iOFF", "uu0", "uu1", "uu2", "A_0_vOFF", "A_1_vOFF",
  "G_0_vOFF", "G_1_vOFF", "ktilde_0_vOFF", "ktilde_1_vOFF", "alphai_vOFF",
  "betai_vOFF", "gamma_vOFF", "gammai_vOFF", "noiseAmp", "STEPS", "SAMPLEPOINT",
  "BOUNDPOINTS", "d", "X_0", "X_1", "A_0", "A_1", "G_0", "G_1", "ktilde_0",
  "ktilde_1", "alphai", "betai", "gammai", "Wk_0", "Wk_1", "input_0", "input_1",
  "eta_0", "eta_1", "rfi_0", "rfi_1", "ktildeLi_0", "ktildeLi_1", "gammaLii",
  "gammaLi", "psif_0", "psif_1", "rbif_0", "rbif_1", "rbis_0", "rbis_1",
  "psis_0", "psis_1", "psierr_0", "psierr_1", "psi1_0", "psi1_1", "psi2_0",
  "psi2_1", "psi5_0", "psi5_1", "rbierr_0", "rbierr_1", "temp_0", "temp_1",
  "f_0", "f_1", "gammais", "gammas", "gammaif", "gammaierr", "b1_0", "b1_1",
  "b2_0", "b2_1", "gammaiinv", "gammaerr", "epsilon", "err", "nargin", "nargout",
  "start", "t", "duty", "v_out", "i_in", "w0in", "w1in", "X_0_vON_in",
  "X_1_vON_in", "A_0_vON_in", "A_1_vON_in", "G_0_vON_in", "G_1_vON_in",
  "ktilde_0_vON_in", "ktilde_1_vON_in", "alphai_vON_in", "betai_vON_in",
  "gamma_vON_in", "gammai_vON_in", "wi0in", "wi1in", "wu0in", "wu1in", "wu2in",
  "Capin", "ESRin", "t0in", "cntin", "cntin1", "y", "e", "w0", "w1", "X_0_vON",
  "X_1_vON", "A_0_vON", "A_1_vON", "G_0_vON", "G_1_vON", "ktilde_0_vON",
  "ktilde_1_vON", "alphai_vON", "betai_vON", "gamma_vON", "gammai_vON", "yi",
  "ei", "wi0", "wi1", "yu", "eu", "wu0", "wu1", "wu2", "Capout", "ESRout",
  "Vnoise", "Inoise", "t0", "cnt", "cnt1" };

/* Function Declarations */
static void initialize_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void disable_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void sf_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void c5_chartstep_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance);
static void initSimStructsc5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_cnt1, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[40]);
static real_T c5_mod(SFc5_BuckBoost1InstanceStruct *chartInstance, real_T c5_x,
                     real_T c5_y);
static void c5_eml_scalar_eg(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void c5_eml_eps(SFc5_BuckBoost1InstanceStruct *chartInstance);
static real_T c5_rand(SFc5_BuckBoost1InstanceStruct *chartInstance);
static void c5_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_d_state[625]);
static void c5_twister_state_vector(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_mt[625], real_T c5_seed, uint32_T c5_b_mt[625]);
static void c5_b_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_d_state[625], uint32_T c5_e_state[625], real_T *c5_r);
static void c5_eml_error(SFc5_BuckBoost1InstanceStruct *chartInstance);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint32_T c5_d_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_b_method, const char_T *c5_identifier);
static uint32_T c5_e_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static uint32_T c5_f_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier);
static uint32_T c5_g_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_h_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_d_state, const char_T *c5_identifier, uint32_T c5_y[625]);
static void c5_i_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint32_T c5_y[625]);
static void c5_j_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_d_state, const char_T *c5_identifier, uint32_T c5_y[2]);
static void c5_k_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint32_T c5_y[2]);
static uint8_T c5_l_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_BuckBoost1, const char_T
  *c5_identifier);
static uint8_T c5_m_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_twister_state_vector(SFc5_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c5_mt[625], real_T c5_seed);
static real_T c5_c_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c5_d_state[625]);
static void init_dsm_address_info(SFc5_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_method_not_empty = FALSE;
  chartInstance->c5_state_not_empty = FALSE;
  chartInstance->c5_b_state_not_empty = FALSE;
  chartInstance->c5_c_state_not_empty = FALSE;
  chartInstance->c5_is_active_c5_BuckBoost1 = 0U;
}

static void initialize_params_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_e_hoistedGlobal;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_f_hoistedGlobal;
  real_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_g_hoistedGlobal;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_h_hoistedGlobal;
  real_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  real_T c5_i_hoistedGlobal;
  real_T c5_i_u;
  const mxArray *c5_j_y = NULL;
  real_T c5_j_hoistedGlobal;
  real_T c5_j_u;
  const mxArray *c5_k_y = NULL;
  real_T c5_k_hoistedGlobal;
  real_T c5_k_u;
  const mxArray *c5_l_y = NULL;
  real_T c5_l_hoistedGlobal;
  real_T c5_l_u;
  const mxArray *c5_m_y = NULL;
  real_T c5_m_hoistedGlobal;
  real_T c5_m_u;
  const mxArray *c5_n_y = NULL;
  real_T c5_n_hoistedGlobal;
  real_T c5_n_u;
  const mxArray *c5_o_y = NULL;
  real_T c5_o_hoistedGlobal;
  real_T c5_o_u;
  const mxArray *c5_p_y = NULL;
  real_T c5_p_hoistedGlobal;
  real_T c5_p_u;
  const mxArray *c5_q_y = NULL;
  real_T c5_q_hoistedGlobal;
  real_T c5_q_u;
  const mxArray *c5_r_y = NULL;
  real_T c5_r_hoistedGlobal;
  real_T c5_r_u;
  const mxArray *c5_s_y = NULL;
  real_T c5_s_hoistedGlobal;
  real_T c5_s_u;
  const mxArray *c5_t_y = NULL;
  real_T c5_t_hoistedGlobal;
  real_T c5_t_u;
  const mxArray *c5_u_y = NULL;
  real_T c5_u_hoistedGlobal;
  real_T c5_u_u;
  const mxArray *c5_v_y = NULL;
  real_T c5_v_hoistedGlobal;
  real_T c5_v_u;
  const mxArray *c5_w_y = NULL;
  real_T c5_w_hoistedGlobal;
  real_T c5_w_u;
  const mxArray *c5_x_y = NULL;
  real_T c5_x_hoistedGlobal;
  real_T c5_x_u;
  const mxArray *c5_y_y = NULL;
  real_T c5_y_hoistedGlobal;
  real_T c5_y_u;
  const mxArray *c5_ab_y = NULL;
  real_T c5_ab_hoistedGlobal;
  real_T c5_ab_u;
  const mxArray *c5_bb_y = NULL;
  real_T c5_bb_hoistedGlobal;
  real_T c5_bb_u;
  const mxArray *c5_cb_y = NULL;
  real_T c5_cb_hoistedGlobal;
  real_T c5_cb_u;
  const mxArray *c5_db_y = NULL;
  real_T c5_db_hoistedGlobal;
  real_T c5_db_u;
  const mxArray *c5_eb_y = NULL;
  real_T c5_eb_hoistedGlobal;
  real_T c5_eb_u;
  const mxArray *c5_fb_y = NULL;
  real_T c5_fb_hoistedGlobal;
  real_T c5_fb_u;
  const mxArray *c5_gb_y = NULL;
  real_T c5_gb_hoistedGlobal;
  real_T c5_gb_u;
  const mxArray *c5_hb_y = NULL;
  uint32_T c5_hb_hoistedGlobal;
  uint32_T c5_hb_u;
  const mxArray *c5_ib_y = NULL;
  uint32_T c5_ib_hoistedGlobal;
  uint32_T c5_ib_u;
  const mxArray *c5_jb_y = NULL;
  int32_T c5_i0;
  uint32_T c5_jb_u[625];
  const mxArray *c5_kb_y = NULL;
  int32_T c5_i1;
  uint32_T c5_kb_u[2];
  const mxArray *c5_lb_y = NULL;
  uint8_T c5_jb_hoistedGlobal;
  uint8_T c5_lb_u;
  const mxArray *c5_mb_y = NULL;
  real_T *c5_A_0_vON;
  real_T *c5_A_1_vON;
  real_T *c5_Capout;
  real_T *c5_ESRout;
  real_T *c5_G_0_vON;
  real_T *c5_G_1_vON;
  real_T *c5_Inoise;
  real_T *c5_Vnoise;
  real_T *c5_X_0_vON;
  real_T *c5_X_1_vON;
  real_T *c5_alphai_vON;
  real_T *c5_betai_vON;
  real_T *c5_cnt;
  real_T *c5_cnt1;
  real_T *c5_e;
  real_T *c5_ei;
  real_T *c5_eu;
  real_T *c5_gamma_vON;
  real_T *c5_gammai_vON;
  real_T *c5_ktilde_0_vON;
  real_T *c5_ktilde_1_vON;
  real_T *c5_t0;
  real_T *c5_w0;
  real_T *c5_w1;
  real_T *c5_wi0;
  real_T *c5_wi1;
  real_T *c5_wu0;
  real_T *c5_wu1;
  real_T *c5_wu2;
  real_T *c5_nb_y;
  real_T *c5_yi;
  real_T *c5_yu;
  c5_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c5_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c5_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c5_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c5_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c5_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c5_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c5_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c5_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c5_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c5_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c5_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c5_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c5_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c5_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c5_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c5_gammai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c5_gamma_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c5_betai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c5_alphai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c5_ktilde_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c5_ktilde_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c5_G_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c5_G_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c5_A_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c5_A_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_X_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_X_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_nb_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(37), FALSE);
  c5_hoistedGlobal = *c5_A_0_vON;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_A_1_vON;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_Capout;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_ESRout;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = *c5_G_0_vON;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_f_hoistedGlobal = *c5_G_1_vON;
  c5_f_u = c5_f_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 5, c5_g_y);
  c5_g_hoistedGlobal = *c5_Inoise;
  c5_g_u = c5_g_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 6, c5_h_y);
  c5_h_hoistedGlobal = *c5_Vnoise;
  c5_h_u = c5_h_hoistedGlobal;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 7, c5_i_y);
  c5_i_hoistedGlobal = *c5_X_0_vON;
  c5_i_u = c5_i_hoistedGlobal;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 8, c5_j_y);
  c5_j_hoistedGlobal = *c5_X_1_vON;
  c5_j_u = c5_j_hoistedGlobal;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 9, c5_k_y);
  c5_k_hoistedGlobal = *c5_alphai_vON;
  c5_k_u = c5_k_hoistedGlobal;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 10, c5_l_y);
  c5_l_hoistedGlobal = *c5_betai_vON;
  c5_l_u = c5_l_hoistedGlobal;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 11, c5_m_y);
  c5_m_hoistedGlobal = *c5_cnt;
  c5_m_u = c5_m_hoistedGlobal;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 12, c5_n_y);
  c5_n_hoistedGlobal = *c5_cnt1;
  c5_n_u = c5_n_hoistedGlobal;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 13, c5_o_y);
  c5_o_hoistedGlobal = *c5_e;
  c5_o_u = c5_o_hoistedGlobal;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 14, c5_p_y);
  c5_p_hoistedGlobal = *c5_ei;
  c5_p_u = c5_p_hoistedGlobal;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 15, c5_q_y);
  c5_q_hoistedGlobal = *c5_eu;
  c5_q_u = c5_q_hoistedGlobal;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 16, c5_r_y);
  c5_r_hoistedGlobal = *c5_gamma_vON;
  c5_r_u = c5_r_hoistedGlobal;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 17, c5_s_y);
  c5_s_hoistedGlobal = *c5_gammai_vON;
  c5_s_u = c5_s_hoistedGlobal;
  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", &c5_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 18, c5_t_y);
  c5_t_hoistedGlobal = *c5_ktilde_0_vON;
  c5_t_u = c5_t_hoistedGlobal;
  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 19, c5_u_y);
  c5_u_hoistedGlobal = *c5_ktilde_1_vON;
  c5_u_u = c5_u_hoistedGlobal;
  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", &c5_u_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 20, c5_v_y);
  c5_v_hoistedGlobal = *c5_t0;
  c5_v_u = c5_v_hoistedGlobal;
  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_v_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 21, c5_w_y);
  c5_w_hoistedGlobal = *c5_w0;
  c5_w_u = c5_w_hoistedGlobal;
  c5_x_y = NULL;
  sf_mex_assign(&c5_x_y, sf_mex_create("y", &c5_w_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 22, c5_x_y);
  c5_x_hoistedGlobal = *c5_w1;
  c5_x_u = c5_x_hoistedGlobal;
  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", &c5_x_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 23, c5_y_y);
  c5_y_hoistedGlobal = *c5_wi0;
  c5_y_u = c5_y_hoistedGlobal;
  c5_ab_y = NULL;
  sf_mex_assign(&c5_ab_y, sf_mex_create("y", &c5_y_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 24, c5_ab_y);
  c5_ab_hoistedGlobal = *c5_wi1;
  c5_ab_u = c5_ab_hoistedGlobal;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_ab_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 25, c5_bb_y);
  c5_bb_hoistedGlobal = *c5_wu0;
  c5_bb_u = c5_bb_hoistedGlobal;
  c5_cb_y = NULL;
  sf_mex_assign(&c5_cb_y, sf_mex_create("y", &c5_bb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 26, c5_cb_y);
  c5_cb_hoistedGlobal = *c5_wu1;
  c5_cb_u = c5_cb_hoistedGlobal;
  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_create("y", &c5_cb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 27, c5_db_y);
  c5_db_hoistedGlobal = *c5_wu2;
  c5_db_u = c5_db_hoistedGlobal;
  c5_eb_y = NULL;
  sf_mex_assign(&c5_eb_y, sf_mex_create("y", &c5_db_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 28, c5_eb_y);
  c5_eb_hoistedGlobal = *c5_nb_y;
  c5_eb_u = c5_eb_hoistedGlobal;
  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", &c5_eb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 29, c5_fb_y);
  c5_fb_hoistedGlobal = *c5_yi;
  c5_fb_u = c5_fb_hoistedGlobal;
  c5_gb_y = NULL;
  sf_mex_assign(&c5_gb_y, sf_mex_create("y", &c5_fb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 30, c5_gb_y);
  c5_gb_hoistedGlobal = *c5_yu;
  c5_gb_u = c5_gb_hoistedGlobal;
  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", &c5_gb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 31, c5_hb_y);
  c5_hb_hoistedGlobal = chartInstance->c5_method;
  c5_hb_u = c5_hb_hoistedGlobal;
  c5_ib_y = NULL;
  if (!chartInstance->c5_method_not_empty) {
    sf_mex_assign(&c5_ib_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c5_ib_y, sf_mex_create("y", &c5_hb_u, 7, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c5_y, 32, c5_ib_y);
  c5_ib_hoistedGlobal = chartInstance->c5_state;
  c5_ib_u = c5_ib_hoistedGlobal;
  c5_jb_y = NULL;
  if (!chartInstance->c5_state_not_empty) {
    sf_mex_assign(&c5_jb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c5_jb_y, sf_mex_create("y", &c5_ib_u, 7, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c5_y, 33, c5_jb_y);
  for (c5_i0 = 0; c5_i0 < 625; c5_i0++) {
    c5_jb_u[c5_i0] = chartInstance->c5_c_state[c5_i0];
  }

  c5_kb_y = NULL;
  if (!chartInstance->c5_c_state_not_empty) {
    sf_mex_assign(&c5_kb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c5_kb_y, sf_mex_create("y", c5_jb_u, 7, 0U, 1U, 0U, 1, 625),
                  FALSE);
  }

  sf_mex_setcell(c5_y, 34, c5_kb_y);
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_kb_u[c5_i1] = chartInstance->c5_b_state[c5_i1];
  }

  c5_lb_y = NULL;
  if (!chartInstance->c5_b_state_not_empty) {
    sf_mex_assign(&c5_lb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c5_lb_y, sf_mex_create("y", c5_kb_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c5_y, 35, c5_lb_y);
  c5_jb_hoistedGlobal = chartInstance->c5_is_active_c5_BuckBoost1;
  c5_lb_u = c5_jb_hoistedGlobal;
  c5_mb_y = NULL;
  sf_mex_assign(&c5_mb_y, sf_mex_create("y", &c5_lb_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 36, c5_mb_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  uint32_T c5_uv0[625];
  int32_T c5_i2;
  uint32_T c5_uv1[2];
  int32_T c5_i3;
  real_T *c5_A_0_vON;
  real_T *c5_A_1_vON;
  real_T *c5_Capout;
  real_T *c5_ESRout;
  real_T *c5_G_0_vON;
  real_T *c5_G_1_vON;
  real_T *c5_Inoise;
  real_T *c5_Vnoise;
  real_T *c5_X_0_vON;
  real_T *c5_X_1_vON;
  real_T *c5_alphai_vON;
  real_T *c5_betai_vON;
  real_T *c5_cnt;
  real_T *c5_cnt1;
  real_T *c5_e;
  real_T *c5_ei;
  real_T *c5_eu;
  real_T *c5_gamma_vON;
  real_T *c5_gammai_vON;
  real_T *c5_ktilde_0_vON;
  real_T *c5_ktilde_1_vON;
  real_T *c5_t0;
  real_T *c5_w0;
  real_T *c5_w1;
  real_T *c5_wi0;
  real_T *c5_wi1;
  real_T *c5_wu0;
  real_T *c5_wu1;
  real_T *c5_wu2;
  real_T *c5_y;
  real_T *c5_yi;
  real_T *c5_yu;
  c5_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c5_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c5_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c5_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c5_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c5_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c5_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c5_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c5_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c5_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c5_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c5_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c5_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c5_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c5_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c5_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c5_gammai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c5_gamma_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c5_betai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c5_alphai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c5_ktilde_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c5_ktilde_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c5_G_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c5_G_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c5_A_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c5_A_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_X_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_X_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_A_0_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "A_0_vON");
  *c5_A_1_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 1)), "A_1_vON");
  *c5_Capout = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    2)), "Capout");
  *c5_ESRout = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    3)), "ESRout");
  *c5_G_0_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 4)), "G_0_vON");
  *c5_G_1_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 5)), "G_1_vON");
  *c5_Inoise = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    6)), "Inoise");
  *c5_Vnoise = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    7)), "Vnoise");
  *c5_X_0_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 8)), "X_0_vON");
  *c5_X_1_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 9)), "X_1_vON");
  *c5_alphai_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 10)), "alphai_vON");
  *c5_betai_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 11)), "betai_vON");
  *c5_cnt = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    12)), "cnt");
  *c5_cnt1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    13)), "cnt1");
  *c5_e = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 14)),
    "e");
  *c5_ei = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 15)),
    "ei");
  *c5_eu = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 16)),
    "eu");
  *c5_gamma_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 17)), "gamma_vON");
  *c5_gammai_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 18)), "gammai_vON");
  *c5_ktilde_0_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 19)), "ktilde_0_vON");
  *c5_ktilde_1_vON = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 20)), "ktilde_1_vON");
  *c5_t0 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 21)),
    "t0");
  *c5_w0 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 22)),
    "w0");
  *c5_w1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 23)),
    "w1");
  *c5_wi0 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    24)), "wi0");
  *c5_wi1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    25)), "wi1");
  *c5_wu0 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    26)), "wu0");
  *c5_wu1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    27)), "wu1");
  *c5_wu2 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    28)), "wu2");
  *c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 29)),
    "y");
  *c5_yi = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 30)),
    "yi");
  *c5_yu = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 31)),
    "yu");
  chartInstance->c5_method = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 32)), "method");
  chartInstance->c5_state = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 33)), "state");
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 34)),
                        "state", c5_uv0);
  for (c5_i2 = 0; c5_i2 < 625; c5_i2++) {
    chartInstance->c5_c_state[c5_i2] = c5_uv0[c5_i2];
  }

  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 35)),
                        "state", c5_uv1);
  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    chartInstance->c5_b_state[c5_i3] = c5_uv1[c5_i3];
  }

  chartInstance->c5_is_active_c5_BuckBoost1 = c5_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 36)),
     "is_active_c5_BuckBoost1");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_BuckBoost1(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
  real_T *c5_start;
  real_T *c5_t;
  real_T *c5_duty;
  real_T *c5_v_out;
  real_T *c5_i_in;
  real_T *c5_w0in;
  real_T *c5_w1in;
  real_T *c5_X_0_vON_in;
  real_T *c5_X_1_vON_in;
  real_T *c5_A_0_vON_in;
  real_T *c5_A_1_vON_in;
  real_T *c5_G_0_vON_in;
  real_T *c5_G_1_vON_in;
  real_T *c5_ktilde_0_vON_in;
  real_T *c5_ktilde_1_vON_in;
  real_T *c5_alphai_vON_in;
  real_T *c5_betai_vON_in;
  real_T *c5_gamma_vON_in;
  real_T *c5_gammai_vON_in;
  real_T *c5_wi0in;
  real_T *c5_wi1in;
  real_T *c5_wu0in;
  real_T *c5_wu1in;
  real_T *c5_wu2in;
  real_T *c5_Capin;
  real_T *c5_y;
  real_T *c5_e;
  real_T *c5_w0;
  real_T *c5_w1;
  real_T *c5_X_0_vON;
  real_T *c5_X_1_vON;
  real_T *c5_A_0_vON;
  real_T *c5_A_1_vON;
  real_T *c5_G_0_vON;
  real_T *c5_G_1_vON;
  real_T *c5_ktilde_0_vON;
  real_T *c5_ktilde_1_vON;
  real_T *c5_alphai_vON;
  real_T *c5_betai_vON;
  real_T *c5_gamma_vON;
  real_T *c5_gammai_vON;
  real_T *c5_yi;
  real_T *c5_ei;
  real_T *c5_wi0;
  real_T *c5_wi1;
  real_T *c5_yu;
  real_T *c5_eu;
  real_T *c5_wu0;
  real_T *c5_wu1;
  real_T *c5_wu2;
  real_T *c5_Capout;
  real_T *c5_ESRin;
  real_T *c5_t0in;
  real_T *c5_ESRout;
  real_T *c5_Vnoise;
  real_T *c5_Inoise;
  real_T *c5_t0;
  real_T *c5_cntin;
  real_T *c5_cnt;
  real_T *c5_cntin1;
  real_T *c5_cnt1;
  c5_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c5_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c5_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c5_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c5_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c5_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c5_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c5_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c5_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c5_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c5_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c5_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c5_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c5_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c5_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c5_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c5_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c5_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c5_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c5_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c5_gammai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c5_gamma_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c5_betai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c5_alphai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c5_ktilde_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c5_ktilde_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c5_G_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c5_G_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c5_A_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c5_A_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_X_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_X_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c5_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c5_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c5_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c5_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c5_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c5_gammai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c5_gamma_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c5_betai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c5_alphai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c5_ktilde_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c5_ktilde_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c5_G_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c5_G_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c5_A_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c5_A_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c5_X_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c5_X_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c5_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c5_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_start, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_t, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_duty, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_v_out, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_i_in, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_w0in, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_w1in, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_X_0_vON_in, 7U);
  _SFD_DATA_RANGE_CHECK(*c5_X_1_vON_in, 8U);
  _SFD_DATA_RANGE_CHECK(*c5_A_0_vON_in, 9U);
  _SFD_DATA_RANGE_CHECK(*c5_A_1_vON_in, 10U);
  _SFD_DATA_RANGE_CHECK(*c5_G_0_vON_in, 11U);
  _SFD_DATA_RANGE_CHECK(*c5_G_1_vON_in, 12U);
  _SFD_DATA_RANGE_CHECK(*c5_ktilde_0_vON_in, 13U);
  _SFD_DATA_RANGE_CHECK(*c5_ktilde_1_vON_in, 14U);
  _SFD_DATA_RANGE_CHECK(*c5_alphai_vON_in, 15U);
  _SFD_DATA_RANGE_CHECK(*c5_betai_vON_in, 16U);
  _SFD_DATA_RANGE_CHECK(*c5_gamma_vON_in, 17U);
  _SFD_DATA_RANGE_CHECK(*c5_gammai_vON_in, 18U);
  _SFD_DATA_RANGE_CHECK(*c5_wi0in, 19U);
  _SFD_DATA_RANGE_CHECK(*c5_wi1in, 20U);
  _SFD_DATA_RANGE_CHECK(*c5_wu0in, 21U);
  _SFD_DATA_RANGE_CHECK(*c5_wu1in, 22U);
  _SFD_DATA_RANGE_CHECK(*c5_wu2in, 23U);
  _SFD_DATA_RANGE_CHECK(*c5_Capin, 24U);
  _SFD_DATA_RANGE_CHECK(*c5_y, 25U);
  _SFD_DATA_RANGE_CHECK(*c5_e, 26U);
  _SFD_DATA_RANGE_CHECK(*c5_w0, 27U);
  _SFD_DATA_RANGE_CHECK(*c5_w1, 28U);
  _SFD_DATA_RANGE_CHECK(*c5_X_0_vON, 29U);
  _SFD_DATA_RANGE_CHECK(*c5_X_1_vON, 30U);
  _SFD_DATA_RANGE_CHECK(*c5_A_0_vON, 31U);
  _SFD_DATA_RANGE_CHECK(*c5_A_1_vON, 32U);
  _SFD_DATA_RANGE_CHECK(*c5_G_0_vON, 33U);
  _SFD_DATA_RANGE_CHECK(*c5_G_1_vON, 34U);
  _SFD_DATA_RANGE_CHECK(*c5_ktilde_0_vON, 35U);
  _SFD_DATA_RANGE_CHECK(*c5_ktilde_1_vON, 36U);
  _SFD_DATA_RANGE_CHECK(*c5_alphai_vON, 37U);
  _SFD_DATA_RANGE_CHECK(*c5_betai_vON, 38U);
  _SFD_DATA_RANGE_CHECK(*c5_gamma_vON, 39U);
  _SFD_DATA_RANGE_CHECK(*c5_gammai_vON, 40U);
  _SFD_DATA_RANGE_CHECK(*c5_yi, 41U);
  _SFD_DATA_RANGE_CHECK(*c5_ei, 42U);
  _SFD_DATA_RANGE_CHECK(*c5_wi0, 43U);
  _SFD_DATA_RANGE_CHECK(*c5_wi1, 44U);
  _SFD_DATA_RANGE_CHECK(*c5_yu, 45U);
  _SFD_DATA_RANGE_CHECK(*c5_eu, 46U);
  _SFD_DATA_RANGE_CHECK(*c5_wu0, 47U);
  _SFD_DATA_RANGE_CHECK(*c5_wu1, 48U);
  _SFD_DATA_RANGE_CHECK(*c5_wu2, 49U);
  _SFD_DATA_RANGE_CHECK(*c5_Capout, 50U);
  _SFD_DATA_RANGE_CHECK(*c5_ESRin, 51U);
  _SFD_DATA_RANGE_CHECK(*c5_t0in, 52U);
  _SFD_DATA_RANGE_CHECK(*c5_ESRout, 53U);
  _SFD_DATA_RANGE_CHECK(*c5_Vnoise, 54U);
  _SFD_DATA_RANGE_CHECK(*c5_Inoise, 55U);
  _SFD_DATA_RANGE_CHECK(*c5_t0, 56U);
  _SFD_DATA_RANGE_CHECK(*c5_cntin, 57U);
  _SFD_DATA_RANGE_CHECK(*c5_cnt, 58U);
  _SFD_DATA_RANGE_CHECK(*c5_cntin1, 59U);
  _SFD_DATA_RANGE_CHECK(*c5_cnt1, 60U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_BuckBoost1(chartInstance);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_f_hoistedGlobal;
  real_T c5_g_hoistedGlobal;
  real_T c5_h_hoistedGlobal;
  real_T c5_i_hoistedGlobal;
  real_T c5_j_hoistedGlobal;
  real_T c5_k_hoistedGlobal;
  real_T c5_l_hoistedGlobal;
  real_T c5_m_hoistedGlobal;
  real_T c5_n_hoistedGlobal;
  real_T c5_o_hoistedGlobal;
  real_T c5_p_hoistedGlobal;
  real_T c5_q_hoistedGlobal;
  real_T c5_r_hoistedGlobal;
  real_T c5_s_hoistedGlobal;
  real_T c5_t_hoistedGlobal;
  real_T c5_u_hoistedGlobal;
  real_T c5_v_hoistedGlobal;
  real_T c5_w_hoistedGlobal;
  real_T c5_x_hoistedGlobal;
  real_T c5_y_hoistedGlobal;
  real_T c5_ab_hoistedGlobal;
  real_T c5_bb_hoistedGlobal;
  real_T c5_cb_hoistedGlobal;
  real_T c5_db_hoistedGlobal;
  real_T c5_start;
  real_T c5_t;
  real_T c5_duty;
  real_T c5_v_out;
  real_T c5_i_in;
  real_T c5_w0in;
  real_T c5_w1in;
  real_T c5_X_0_vON_in;
  real_T c5_X_1_vON_in;
  real_T c5_A_0_vON_in;
  real_T c5_A_1_vON_in;
  real_T c5_G_0_vON_in;
  real_T c5_G_1_vON_in;
  real_T c5_ktilde_0_vON_in;
  real_T c5_ktilde_1_vON_in;
  real_T c5_alphai_vON_in;
  real_T c5_betai_vON_in;
  real_T c5_gamma_vON_in;
  real_T c5_gammai_vON_in;
  real_T c5_wi0in;
  real_T c5_wi1in;
  real_T c5_wu0in;
  real_T c5_wu1in;
  real_T c5_wu2in;
  real_T c5_Capin;
  real_T c5_ESRin;
  real_T c5_t0in;
  real_T c5_cntin;
  real_T c5_cntin1;
  uint32_T c5_debug_family_var_map[165];
  real_T c5_sampling_time;
  real_T c5_splittime1;
  real_T c5_splittime2;
  real_T c5_offset;
  real_T c5_OFFSET_ON_START_abs;
  real_T c5_OFFSET_ON_END_rel;
  real_T c5_OFFSET_OFF_START_rel;
  real_T c5_OFFSET_OFF_END_abs;
  real_T c5_lambda;
  real_T c5_delta;
  real_T c5_lambdai;
  real_T c5_alpha;
  real_T c5_beta;
  real_T c5_gamma;
  real_T c5_K[6];
  real_T c5_u0;
  real_T c5_u1;
  real_T c5_A_0_iOFF;
  real_T c5_A_1_iOFF;
  real_T c5_G_0_iOFF;
  real_T c5_G_1_iOFF;
  real_T c5_ktilde_0_iOFF;
  real_T c5_ktilde_1_iOFF;
  real_T c5_alphai_iOFF;
  real_T c5_betai_iOFF;
  real_T c5_gamma_iOFF;
  real_T c5_gammai_iOFF;
  real_T c5_uu0;
  real_T c5_uu1;
  real_T c5_uu2;
  real_T c5_A_0_vOFF;
  real_T c5_A_1_vOFF;
  real_T c5_G_0_vOFF;
  real_T c5_G_1_vOFF;
  real_T c5_ktilde_0_vOFF;
  real_T c5_ktilde_1_vOFF;
  real_T c5_alphai_vOFF;
  real_T c5_betai_vOFF;
  real_T c5_gamma_vOFF;
  real_T c5_gammai_vOFF;
  real_T c5_noiseAmp;
  real_T c5_STEPS;
  real_T c5_SAMPLEPOINT;
  real_T c5_BOUNDPOINTS;
  real_T c5_d;
  real_T c5_X_0;
  real_T c5_X_1;
  real_T c5_A_0;
  real_T c5_A_1;
  real_T c5_G_0;
  real_T c5_G_1;
  real_T c5_ktilde_0;
  real_T c5_ktilde_1;
  real_T c5_alphai;
  real_T c5_betai;
  real_T c5_gammai;
  real_T c5_Wk_0;
  real_T c5_Wk_1;
  real_T c5_input_0;
  real_T c5_input_1;
  real_T c5_eta_0;
  real_T c5_eta_1;
  real_T c5_rfi_0;
  real_T c5_rfi_1;
  real_T c5_ktildeLi_0;
  real_T c5_ktildeLi_1;
  real_T c5_gammaLii;
  real_T c5_gammaLi;
  real_T c5_psif_0;
  real_T c5_psif_1;
  real_T c5_rbif_0;
  real_T c5_rbif_1;
  real_T c5_rbis_0;
  real_T c5_rbis_1;
  real_T c5_psis_0;
  real_T c5_psis_1;
  real_T c5_psierr_0;
  real_T c5_psierr_1;
  real_T c5_psi1_0;
  real_T c5_psi1_1;
  real_T c5_psi2_0;
  real_T c5_psi2_1;
  real_T c5_psi5_0;
  real_T c5_psi5_1;
  real_T c5_rbierr_0;
  real_T c5_rbierr_1;
  real_T c5_temp_0;
  real_T c5_temp_1;
  real_T c5_f_0;
  real_T c5_f_1;
  real_T c5_gammais;
  real_T c5_gammas;
  real_T c5_gammaif;
  real_T c5_gammaierr;
  real_T c5_b1_0;
  real_T c5_b1_1;
  real_T c5_b2_0;
  real_T c5_b2_1;
  real_T c5_gammaiinv;
  real_T c5_gammaerr;
  real_T c5_epsilon;
  real_T c5_err;
  real_T c5_nargin = 29.0;
  real_T c5_nargout = 32.0;
  real_T c5_y;
  real_T c5_e;
  real_T c5_w0;
  real_T c5_w1;
  real_T c5_X_0_vON;
  real_T c5_X_1_vON;
  real_T c5_A_0_vON;
  real_T c5_A_1_vON;
  real_T c5_G_0_vON;
  real_T c5_G_1_vON;
  real_T c5_ktilde_0_vON;
  real_T c5_ktilde_1_vON;
  real_T c5_alphai_vON;
  real_T c5_betai_vON;
  real_T c5_gamma_vON;
  real_T c5_gammai_vON;
  real_T c5_yi;
  real_T c5_ei;
  real_T c5_wi0;
  real_T c5_wi1;
  real_T c5_yu;
  real_T c5_eu;
  real_T c5_wu0;
  real_T c5_wu1;
  real_T c5_wu2;
  real_T c5_Capout;
  real_T c5_ESRout;
  real_T c5_Vnoise;
  real_T c5_Inoise;
  real_T c5_t0;
  real_T c5_cnt;
  real_T c5_cnt1;
  int32_T c5_i4;
  static real_T c5_dv0[6] = { 1.5, 2.5, 0.0, 0.0, 1.0, 1.0 };

  real_T c5_b;
  real_T c5_b_y;
  real_T c5_a;
  real_T c5_b_b;
  real_T c5_c_y;
  real_T c5_b_a;
  real_T c5_c_b;
  real_T c5_d_y;
  real_T c5_d_b;
  real_T c5_e_y;
  real_T c5_c_a;
  real_T c5_e_b;
  real_T c5_f_b;
  real_T c5_f_y;
  real_T c5_d_a;
  real_T c5_g_b;
  real_T c5_e_a;
  real_T c5_h_b;
  real_T c5_g_y;
  real_T c5_f_a;
  real_T c5_i_b;
  real_T c5_h_y;
  real_T c5_B;
  real_T c5_i_y;
  real_T c5_j_y;
  real_T c5_g_a;
  real_T c5_h_a;
  real_T c5_j_b;
  real_T c5_k_b;
  real_T c5_k_y;
  real_T c5_i_a;
  real_T c5_l_b;
  real_T c5_m_b;
  real_T c5_l_y;
  real_T c5_j_a;
  real_T c5_n_b;
  real_T c5_k_a;
  real_T c5_o_b;
  real_T c5_m_y;
  real_T c5_l_a;
  real_T c5_p_b;
  real_T c5_n_y;
  real_T c5_q_b;
  real_T c5_o_y;
  real_T c5_m_a;
  real_T c5_r_b;
  real_T c5_p_y;
  real_T c5_n_a;
  real_T c5_s_b;
  real_T c5_q_y;
  real_T c5_t_b;
  real_T c5_r_y;
  real_T c5_u_b;
  real_T c5_s_y;
  real_T c5_v_b;
  real_T c5_t_y;
  real_T c5_w_b;
  real_T c5_u_y;
  real_T c5_x_b;
  real_T c5_v_y;
  real_T c5_y_b;
  real_T c5_w_y;
  real_T c5_ab_b;
  real_T c5_x_y;
  real_T c5_o_a;
  real_T c5_bb_b;
  real_T c5_p_a;
  real_T c5_cb_b;
  real_T c5_q_a;
  real_T c5_db_b;
  real_T c5_y_y;
  real_T c5_r_a;
  real_T c5_eb_b;
  real_T c5_ab_y;
  real_T c5_s_a;
  real_T c5_fb_b;
  real_T c5_bb_y;
  real_T c5_t_a;
  real_T c5_gb_b;
  real_T c5_cb_y;
  real_T c5_u_a;
  real_T c5_hb_b;
  real_T c5_db_y;
  real_T c5_v_a;
  real_T c5_ib_b;
  real_T c5_eb_y;
  real_T c5_b_B;
  real_T c5_fb_y;
  real_T c5_gb_y;
  real_T c5_w_a;
  real_T c5_hb_y;
  real_T c5_x_a;
  real_T c5_jb_b;
  real_T c5_ib_y;
  real_T c5_kb_b;
  real_T c5_jb_y;
  real_T c5_lb_b;
  real_T c5_kb_y;
  real_T c5_y_a;
  real_T c5_mb_b;
  real_T c5_lb_y;
  real_T c5_ab_a;
  real_T c5_nb_b;
  real_T c5_mb_y;
  real_T c5_bb_a;
  real_T c5_ob_b;
  real_T c5_nb_y;
  real_T c5_cb_a;
  real_T c5_pb_b;
  real_T c5_ob_y;
  real_T c5_db_a;
  real_T c5_qb_b;
  real_T c5_eb_a;
  real_T c5_rb_b;
  real_T c5_fb_a;
  real_T c5_sb_b;
  real_T c5_gb_a;
  real_T c5_tb_b;
  real_T c5_hb_a;
  real_T c5_ub_b;
  real_T c5_pb_y;
  real_T c5_ib_a;
  real_T c5_vb_b;
  real_T c5_qb_y;
  real_T c5_jb_a;
  real_T c5_wb_b;
  real_T c5_rb_y;
  real_T c5_kb_a;
  real_T c5_xb_b;
  real_T c5_sb_y;
  real_T c5_yb_b;
  real_T c5_tb_y;
  real_T c5_lb_a;
  real_T c5_ac_b;
  real_T c5_ub_y;
  real_T c5_mb_a;
  real_T c5_bc_b;
  real_T c5_vb_y;
  real_T c5_nb_a;
  real_T c5_cc_b;
  real_T c5_wb_y;
  real_T c5_ob_a;
  real_T c5_dc_b;
  real_T c5_xb_y;
  real_T c5_c_B;
  real_T c5_yb_y;
  real_T c5_ac_y;
  real_T c5_ec_b;
  real_T c5_bc_y;
  real_T c5_pb_a;
  real_T c5_fc_b;
  real_T c5_gc_b;
  real_T c5_cc_y;
  real_T c5_qb_a;
  real_T c5_dc_y;
  real_T c5_rb_a;
  real_T c5_hc_b;
  real_T c5_ec_y;
  real_T c5_sb_a;
  real_T c5_ic_b;
  real_T c5_tb_a;
  real_T c5_jc_b;
  real_T c5_fc_y;
  real_T c5_ub_a;
  real_T c5_kc_b;
  real_T c5_gc_y;
  real_T c5_A;
  real_T c5_d_B;
  real_T c5_x;
  real_T c5_hc_y;
  real_T c5_b_x;
  real_T c5_ic_y;
  real_T c5_jc_y;
  real_T c5_b_A;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_kc_y;
  real_T c5_vb_a;
  real_T *c5_b_cnt1;
  real_T *c5_b_cnt;
  real_T *c5_b_t0;
  real_T *c5_b_Inoise;
  real_T *c5_b_Vnoise;
  real_T *c5_b_ESRout;
  real_T *c5_b_Capout;
  real_T *c5_b_wu2;
  real_T *c5_b_wu1;
  real_T *c5_b_wu0;
  real_T *c5_b_eu;
  real_T *c5_b_yu;
  real_T *c5_b_wi1;
  real_T *c5_b_wi0;
  real_T *c5_b_ei;
  real_T *c5_b_yi;
  real_T *c5_b_gammai_vON;
  real_T *c5_b_gamma_vON;
  real_T *c5_b_betai_vON;
  real_T *c5_b_alphai_vON;
  real_T *c5_b_ktilde_1_vON;
  real_T *c5_b_ktilde_0_vON;
  real_T *c5_b_G_1_vON;
  real_T *c5_b_G_0_vON;
  real_T *c5_b_A_1_vON;
  real_T *c5_b_A_0_vON;
  real_T *c5_b_X_1_vON;
  real_T *c5_b_X_0_vON;
  real_T *c5_b_w1;
  real_T *c5_b_w0;
  real_T *c5_b_e;
  real_T *c5_lc_y;
  real_T *c5_b_cntin1;
  real_T *c5_b_cntin;
  real_T *c5_b_t0in;
  real_T *c5_b_ESRin;
  real_T *c5_b_Capin;
  real_T *c5_b_wu2in;
  real_T *c5_b_wu1in;
  real_T *c5_b_wu0in;
  real_T *c5_b_wi1in;
  real_T *c5_b_wi0in;
  real_T *c5_b_gammai_vON_in;
  real_T *c5_b_gamma_vON_in;
  real_T *c5_b_betai_vON_in;
  real_T *c5_b_alphai_vON_in;
  real_T *c5_b_ktilde_1_vON_in;
  real_T *c5_b_ktilde_0_vON_in;
  real_T *c5_b_G_1_vON_in;
  real_T *c5_b_G_0_vON_in;
  real_T *c5_b_A_1_vON_in;
  real_T *c5_b_A_0_vON_in;
  real_T *c5_b_X_1_vON_in;
  real_T *c5_b_X_0_vON_in;
  real_T *c5_b_w1in;
  real_T *c5_b_w0in;
  real_T *c5_b_i_in;
  real_T *c5_b_v_out;
  real_T *c5_b_duty;
  real_T *c5_b_t;
  real_T *c5_b_start;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  c5_b_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
  c5_b_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c5_b_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
  c5_b_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c5_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
  c5_b_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
  c5_b_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
  c5_b_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
  c5_b_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c5_b_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c5_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
  c5_b_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
  c5_b_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
  c5_b_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
  c5_b_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
  c5_b_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
  c5_b_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c5_b_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c5_b_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c5_b_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c5_b_gammai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c5_b_gamma_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c5_b_betai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c5_b_alphai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c5_b_ktilde_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c5_b_ktilde_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c5_b_G_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c5_b_G_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c5_b_A_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c5_b_A_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_b_X_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_b_X_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_lc_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c5_b_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c5_b_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c5_b_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c5_b_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c5_b_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c5_b_gammai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c5_b_gamma_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c5_b_betai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c5_b_alphai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c5_b_ktilde_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c5_b_ktilde_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c5_b_G_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c5_b_G_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c5_b_A_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c5_b_A_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c5_b_X_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c5_b_X_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c5_b_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_b_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c5_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_start;
  c5_b_hoistedGlobal = *c5_b_t;
  c5_c_hoistedGlobal = *c5_b_duty;
  c5_d_hoistedGlobal = *c5_b_v_out;
  c5_e_hoistedGlobal = *c5_b_i_in;
  c5_f_hoistedGlobal = *c5_b_w0in;
  c5_g_hoistedGlobal = *c5_b_w1in;
  c5_h_hoistedGlobal = *c5_b_X_0_vON_in;
  c5_i_hoistedGlobal = *c5_b_X_1_vON_in;
  c5_j_hoistedGlobal = *c5_b_A_0_vON_in;
  c5_k_hoistedGlobal = *c5_b_A_1_vON_in;
  c5_l_hoistedGlobal = *c5_b_G_0_vON_in;
  c5_m_hoistedGlobal = *c5_b_G_1_vON_in;
  c5_n_hoistedGlobal = *c5_b_ktilde_0_vON_in;
  c5_o_hoistedGlobal = *c5_b_ktilde_1_vON_in;
  c5_p_hoistedGlobal = *c5_b_alphai_vON_in;
  c5_q_hoistedGlobal = *c5_b_betai_vON_in;
  c5_r_hoistedGlobal = *c5_b_gamma_vON_in;
  c5_s_hoistedGlobal = *c5_b_gammai_vON_in;
  c5_t_hoistedGlobal = *c5_b_wi0in;
  c5_u_hoistedGlobal = *c5_b_wi1in;
  c5_v_hoistedGlobal = *c5_b_wu0in;
  c5_w_hoistedGlobal = *c5_b_wu1in;
  c5_x_hoistedGlobal = *c5_b_wu2in;
  c5_y_hoistedGlobal = *c5_b_Capin;
  c5_ab_hoistedGlobal = *c5_b_ESRin;
  c5_bb_hoistedGlobal = *c5_b_t0in;
  c5_cb_hoistedGlobal = *c5_b_cntin;
  c5_db_hoistedGlobal = *c5_b_cntin1;
  c5_start = c5_hoistedGlobal;
  c5_t = c5_b_hoistedGlobal;
  c5_duty = c5_c_hoistedGlobal;
  c5_v_out = c5_d_hoistedGlobal;
  c5_i_in = c5_e_hoistedGlobal;
  c5_w0in = c5_f_hoistedGlobal;
  c5_w1in = c5_g_hoistedGlobal;
  c5_X_0_vON_in = c5_h_hoistedGlobal;
  c5_X_1_vON_in = c5_i_hoistedGlobal;
  c5_A_0_vON_in = c5_j_hoistedGlobal;
  c5_A_1_vON_in = c5_k_hoistedGlobal;
  c5_G_0_vON_in = c5_l_hoistedGlobal;
  c5_G_1_vON_in = c5_m_hoistedGlobal;
  c5_ktilde_0_vON_in = c5_n_hoistedGlobal;
  c5_ktilde_1_vON_in = c5_o_hoistedGlobal;
  c5_alphai_vON_in = c5_p_hoistedGlobal;
  c5_betai_vON_in = c5_q_hoistedGlobal;
  c5_gamma_vON_in = c5_r_hoistedGlobal;
  c5_gammai_vON_in = c5_s_hoistedGlobal;
  c5_wi0in = c5_t_hoistedGlobal;
  c5_wi1in = c5_u_hoistedGlobal;
  c5_wu0in = c5_v_hoistedGlobal;
  c5_wu1in = c5_w_hoistedGlobal;
  c5_wu2in = c5_x_hoistedGlobal;
  c5_Capin = c5_y_hoistedGlobal;
  c5_ESRin = c5_ab_hoistedGlobal;
  c5_t0in = c5_bb_hoistedGlobal;
  c5_cntin = c5_cb_hoistedGlobal;
  c5_cntin1 = c5_db_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 165U, 165U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_sampling_time, 0U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_splittime1, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_splittime2, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_offset, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_OFFSET_ON_START_abs, 4U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_OFFSET_ON_END_rel, 5U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_OFFSET_OFF_START_rel, 6U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_OFFSET_OFF_END_abs, 7U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_lambda, 8U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_delta, 9U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_lambdai, 10U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_alpha, 11U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_beta, 12U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_gamma, 13U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_K, 14U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_u0, 15U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_u1, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_0_iOFF, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_1_iOFF, 18U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_0_iOFF, 19U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_1_iOFF, 20U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_0_iOFF, 21U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_1_iOFF, 22U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_alphai_iOFF, 23U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_betai_iOFF, 24U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gamma_iOFF, 25U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammai_iOFF, 26U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_uu0, 27U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_uu1, 28U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_uu2, 29U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_0_vOFF, 30U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_1_vOFF, 31U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_0_vOFF, 32U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_1_vOFF, 33U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_0_vOFF, 34U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_1_vOFF, 35U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_alphai_vOFF, 36U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_betai_vOFF, 37U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gamma_vOFF, 38U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammai_vOFF, 39U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_noiseAmp, 40U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_STEPS, 41U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_SAMPLEPOINT, 42U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_BOUNDPOINTS, 43U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_d, 44U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_0, 45U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_1, 46U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_0, 47U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_1, 48U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_0, 49U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_1, 50U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_0, 51U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_1, 52U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_alphai, 53U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_betai, 54U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammai, 55U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Wk_0, 56U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Wk_1, 57U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_input_0, 58U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_input_1, 59U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_eta_0, 60U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_eta_1, 61U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rfi_0, 62U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rfi_1, 63U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktildeLi_0, 64U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktildeLi_1, 65U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaLii, 66U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaLi, 67U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psif_0, 68U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psif_1, 69U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbif_0, 70U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbif_1, 71U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbis_0, 72U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbis_1, 73U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psis_0, 74U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psis_1, 75U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psierr_0, 76U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psierr_1, 77U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi1_0, 78U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi1_1, 79U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi2_0, 80U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi2_1, 81U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi5_0, 82U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi5_1, 83U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbierr_0, 84U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_rbierr_1, 85U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_temp_0, 86U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_temp_1, 87U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_f_0, 88U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_f_1, 89U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammais, 90U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammas, 91U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaif, 92U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaierr, 93U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b1_0, 94U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b1_1, 95U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b2_0, 96U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b2_1, 97U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaiinv, 98U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammaerr, 99U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_epsilon, 100U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_err, 101U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 102U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 103U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_start, 104U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_t, 105U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_duty, 106U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_v_out, 107U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_i_in, 108U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_w0in, 109U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_w1in, 110U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_X_0_vON_in, 111U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_X_1_vON_in, 112U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_A_0_vON_in, 113U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_A_1_vON_in, 114U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_G_0_vON_in, 115U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_G_1_vON_in, 116U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ktilde_0_vON_in, 117U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ktilde_1_vON_in, 118U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_alphai_vON_in, 119U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_betai_vON_in, 120U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_gamma_vON_in, 121U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_gammai_vON_in, 122U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_wi0in, 123U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_wi1in, 124U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_wu0in, 125U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_wu1in, 126U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_wu2in, 127U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Capin, 128U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ESRin, 129U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_t0in, 130U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_cntin, 131U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_cntin1, 132U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_y, 133U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_e, 134U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_w0, 135U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_w1, 136U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_0_vON, 137U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_1_vON, 138U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_0_vON, 139U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A_1_vON, 140U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_0_vON, 141U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_G_1_vON, 142U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_0_vON, 143U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ktilde_1_vON, 144U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_alphai_vON, 145U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_betai_vON, 146U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gamma_vON, 147U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_gammai_vON, 148U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_yi, 149U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ei, 150U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_wi0, 151U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_wi1, 152U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_yu, 153U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_eu, 154U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_wu0, 155U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_wu1, 156U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_wu2, 157U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Capout, 158U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ESRout, 159U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Vnoise, 160U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Inoise, 161U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t0, 162U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_cnt, 163U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_cnt1, 164U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_sampling_time = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_splittime1 = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_splittime2 = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_offset = c5_t - c5_duty;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
  c5_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
  c5_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
  c5_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
  c5_lambda = 0.85;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 38);
  c5_delta = 1.0E-8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 40);
  c5_lambdai = 1.1764705882352942;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 41);
  c5_alpha = 8.5E-9;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 42);
  c5_beta = 1.0E-8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
  c5_gamma = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 44);
  for (c5_i4 = 0; c5_i4 < 6; c5_i4++) {
    c5_K[c5_i4] = c5_dv0[c5_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 49);
  c5_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 50);
  c5_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 53);
  c5_u0 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 54);
  c5_u1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
  c5_w0 = c5_w0in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
  c5_w1 = c5_w1in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 60);
  c5_X_0_vON = c5_X_0_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 61);
  c5_X_1_vON = c5_X_1_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 62);
  c5_A_0_vON = c5_A_0_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 63);
  c5_A_1_vON = c5_A_1_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 64);
  c5_G_0_vON = c5_G_0_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 65);
  c5_G_1_vON = c5_G_1_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 66);
  c5_ktilde_0_vON = c5_ktilde_0_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 67);
  c5_ktilde_1_vON = c5_ktilde_1_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 68);
  c5_alphai_vON = c5_alphai_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 69);
  c5_betai_vON = c5_betai_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 70);
  c5_gamma_vON = c5_gamma_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 71);
  c5_gammai_vON = c5_gammai_vON_in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 76);
  c5_yi = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 77);
  c5_ei = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_wi0 = c5_wi0in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_wi1 = c5_wi1in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_A_0_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_A_1_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_G_0_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_G_1_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_ktilde_0_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_ktilde_1_iOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_alphai_iOFF = 1.1764705882352941E+8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 93);
  c5_betai_iOFF = 1.0E+8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 94);
  c5_gamma_iOFF = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_gammai_iOFF = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_yu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_eu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 104);
  c5_uu0 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_uu1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_uu2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_wu0 = c5_wu0in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_wu1 = c5_wu1in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_wu2 = c5_wu2in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 112);
  c5_A_0_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 113);
  c5_A_1_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_G_0_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 115);
  c5_G_1_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 116);
  c5_ktilde_0_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_ktilde_1_vOFF = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 118);
  c5_alphai_vOFF = 1.1764705882352941E+8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 119);
  c5_betai_vOFF = 1.0E+8;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 120);
  c5_gamma_vOFF = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 121);
  c5_gammai_vOFF = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, MAX_int8_T);
  c5_Capout = c5_Capin;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 128U);
  c5_ESRout = c5_ESRin;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 129U);
  c5_t0 = c5_t0in;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 131U);
  c5_Vnoise = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 132U);
  c5_Inoise = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 136U);
  c5_noiseAmp = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 137U);
  c5_cnt = c5_cntin;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 137U);
  c5_cnt1 = c5_cntin1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 138U);
  c5_STEPS = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 139U);
  c5_SAMPLEPOINT = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 140U);
  c5_BOUNDPOINTS = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 143U);
  if (CV_EML_IF(0, 1, 0, c5_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 145U);
    guard2 = FALSE;
    guard3 = FALSE;
    guard4 = FALSE;
    if (CV_EML_COND(0, 1, 0, c5_t > c5_OFFSET_ON_START_abs)) {
      if (CV_EML_COND(0, 1, 1, c5_offset < c5_OFFSET_ON_END_rel)) {
        if (CV_EML_COND(0, 1, 2, c5_t < c5_OFFSET_ON_START_abs + c5_BOUNDPOINTS))
        {
          if (CV_EML_COND(0, 1, 3, c5_mod(chartInstance, c5_t, 1.0) == 0.0)) {
            CV_EML_MCDC(0, 1, 0, TRUE);
            CV_EML_IF(0, 1, 1, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 147U);
            guard5 = FALSE;
            if (CV_EML_COND(0, 1, 4, c5_t > c5_OFFSET_ON_START_abs)) {
              if (CV_EML_COND(0, 1, 5, c5_t <= c5_OFFSET_ON_START_abs + 1.0)) {
                CV_EML_MCDC(0, 1, 1, TRUE);
                CV_EML_IF(0, 1, 2, TRUE);
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 148U);
                c5_t0 = c5_t;
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 149U);
                c5_cnt = 0.0;
              } else {
                guard5 = TRUE;
              }
            } else {
              guard5 = TRUE;
            }

            if (guard5 == TRUE) {
              CV_EML_MCDC(0, 1, 1, FALSE);
              CV_EML_IF(0, 1, 2, FALSE);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 151U);
              c5_cnt = c5_cntin + 1.0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 155U);
              c5_u0 = 1.0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 156U);
              c5_u1 = c5_t - c5_t0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 158U);
              c5_b = c5_rand(chartInstance);
              c5_b_y = 0.0 * c5_b;
              c5_d = c5_v_out + c5_b_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 161U);
              c5_X_0 = c5_X_0_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 162U);
              c5_X_1 = c5_X_1_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 163U);
              c5_A_0 = c5_A_0_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 164U);
              c5_A_1 = c5_A_1_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 165U);
              c5_G_0 = c5_G_0_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 166U);
              c5_G_1 = c5_G_1_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 167U);
              c5_ktilde_0 = c5_ktilde_0_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 168U);
              c5_ktilde_1 = c5_ktilde_1_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 169U);
              c5_alphai = c5_alphai_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 170U);
              c5_betai = c5_betai_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 171U);
              c5_gamma = c5_gamma_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 172U);
              c5_gammai = c5_gammai_vON;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 173U);
              c5_Wk_0 = c5_w0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 174U);
              c5_Wk_1 = c5_w1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 176U);
              c5_input_0 = 1.0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 177U);
              c5_input_1 = c5_u1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 180U);
              c5_a = c5_A_0;
              c5_b_b = c5_X_0;
              c5_c_y = c5_a * c5_b_b;
              c5_eta_0 = c5_input_0 - c5_c_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 181U);
              c5_b_a = c5_A_1;
              c5_c_b = c5_X_1;
              c5_d_y = c5_b_a * c5_c_b;
              c5_eta_1 = c5_input_1 - c5_d_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 182U);
              c5_d_b = c5_alphai;
              c5_e_y = 1.1764705882352942 * c5_d_b;
              c5_c_a = c5_e_y;
              c5_e_b = c5_eta_0;
              c5_rfi_0 = c5_c_a * c5_e_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 183U);
              c5_f_b = c5_alphai;
              c5_f_y = 1.1764705882352942 * c5_f_b;
              c5_d_a = c5_f_y;
              c5_g_b = c5_eta_1;
              c5_rfi_1 = c5_d_a * c5_g_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 184U);
              c5_ktildeLi_0 = c5_rfi_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 185U);
              c5_ktildeLi_1 = c5_rfi_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 186U);
              c5_e_a = c5_rfi_0;
              c5_h_b = c5_eta_0;
              c5_g_y = c5_e_a * c5_h_b;
              c5_f_a = c5_rfi_1;
              c5_i_b = c5_eta_1;
              c5_h_y = c5_f_a * c5_i_b;
              c5_gammaLii = c5_gammai + (c5_g_y + c5_h_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 187U);
              c5_B = c5_gammaLii;
              c5_i_y = c5_B;
              c5_j_y = c5_i_y;
              c5_gammaLi = 1.0 / c5_j_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 188U);
              c5_X_0 = 1.0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 189U);
              c5_X_1 = c5_input_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 190U);
              c5_g_a = -c5_G_0;
              c5_psif_0 = c5_g_a;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 191U);
              c5_h_a = -c5_G_1;
              c5_j_b = c5_X_1;
              c5_psif_1 = c5_h_a * c5_j_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 192U);
              c5_k_b = c5_betai;
              c5_k_y = 1.1764705882352942 * c5_k_b;
              c5_i_a = c5_k_y;
              c5_l_b = c5_psif_0;
              c5_rbif_0 = c5_i_a * c5_l_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 193U);
              c5_m_b = c5_betai;
              c5_l_y = 1.1764705882352942 * c5_m_b;
              c5_j_a = c5_l_y;
              c5_n_b = c5_psif_1;
              c5_rbif_1 = c5_j_a * c5_n_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 194U);
              c5_k_a = c5_A_0;
              c5_o_b = c5_rfi_0;
              c5_m_y = c5_k_a * c5_o_b;
              c5_rbis_0 = c5_ktilde_0 - c5_m_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 195U);
              c5_l_a = c5_A_1;
              c5_p_b = c5_rfi_1;
              c5_n_y = c5_l_a * c5_p_b;
              c5_rbis_1 = c5_ktilde_1 - c5_n_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 196U);
              c5_q_b = c5_rbis_0;
              c5_o_y = 0.85 * c5_q_b;
              c5_m_a = c5_o_y;
              c5_psis_0 = c5_m_a * 1.0E-8;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 197U);
              c5_r_b = c5_rbis_1;
              c5_p_y = 0.85 * c5_r_b;
              c5_n_a = c5_p_y;
              c5_psis_1 = c5_n_a * 1.0E-8;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 198U);
              c5_psierr_0 = c5_psif_0 - c5_psis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 199U);
              c5_psierr_1 = c5_psif_1 - c5_psis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 200U);
              c5_s_b = c5_psierr_0;
              c5_q_y = 1.5 * c5_s_b;
              c5_psi1_0 = c5_q_y + c5_psis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 201U);
              c5_t_b = c5_psierr_1;
              c5_r_y = 1.5 * c5_t_b;
              c5_psi1_1 = c5_r_y + c5_psis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 202U);
              c5_u_b = c5_psierr_0;
              c5_s_y = 2.5 * c5_u_b;
              c5_psi2_0 = c5_s_y + c5_psis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 203U);
              c5_v_b = c5_psierr_1;
              c5_t_y = 2.5 * c5_v_b;
              c5_psi2_1 = c5_t_y + c5_psis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 204U);
              c5_w_b = c5_psierr_0;
              c5_u_y = c5_w_b;
              c5_psi5_0 = c5_u_y + c5_psis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 205U);
              c5_x_b = c5_psierr_1;
              c5_v_y = c5_x_b;
              c5_psi5_1 = c5_v_y + c5_psis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 206U);
              c5_rbierr_0 = c5_rbif_0 - c5_rbis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 207U);
              c5_rbierr_1 = c5_rbif_1 - c5_rbis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 208U);
              c5_y_b = c5_rbierr_0;
              c5_w_y = 0.0 * c5_y_b;
              c5_temp_0 = c5_w_y + c5_rbis_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 209U);
              c5_ab_b = c5_rbierr_1;
              c5_x_y = 0.0 * c5_ab_b;
              c5_temp_1 = c5_x_y + c5_rbis_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 210U);
              c5_o_a = c5_eta_0;
              c5_bb_b = c5_gamma;
              c5_f_0 = c5_o_a * c5_bb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 211U);
              c5_p_a = c5_eta_1;
              c5_cb_b = c5_gamma;
              c5_f_1 = c5_p_a * c5_cb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 212U);
              c5_q_a = c5_ktilde_0;
              c5_db_b = c5_f_0;
              c5_y_y = c5_q_a * c5_db_b;
              c5_A_0 += c5_y_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 213U);
              c5_r_a = c5_ktilde_1;
              c5_eb_b = c5_f_1;
              c5_ab_y = c5_r_a * c5_eb_b;
              c5_A_1 += c5_ab_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 214U);
              c5_s_a = c5_temp_0;
              c5_fb_b = c5_G_0;
              c5_bb_y = c5_s_a * c5_fb_b;
              c5_ktilde_0 = c5_ktildeLi_0 + c5_bb_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 215U);
              c5_t_a = c5_temp_1;
              c5_gb_b = c5_G_1;
              c5_cb_y = c5_t_a * c5_gb_b;
              c5_ktilde_1 = c5_ktildeLi_1 + c5_cb_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 216U);
              c5_u_a = c5_psi5_0;
              c5_hb_b = c5_temp_0;
              c5_db_y = c5_u_a * c5_hb_b;
              c5_v_a = c5_psi5_1;
              c5_ib_b = c5_temp_1;
              c5_eb_y = c5_v_a * c5_ib_b;
              c5_gammais = c5_gammaLii - (c5_db_y + c5_eb_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 217U);
              c5_b_B = c5_gammais;
              c5_fb_y = c5_b_B;
              c5_gb_y = c5_fb_y;
              c5_gammas = 1.0 / c5_gb_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 218U);
              c5_w_a = c5_ktilde_0;
              c5_hb_y = c5_w_a;
              c5_x_a = c5_ktilde_1;
              c5_jb_b = c5_X_1;
              c5_ib_y = c5_x_a * c5_jb_b;
              c5_gammaif = 1.0 + (c5_hb_y + c5_ib_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 219U);
              c5_gammaierr = c5_gammaif - c5_gammais;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 220U);
              c5_kb_b = c5_gammaierr;
              c5_jb_y = 0.0 * c5_kb_b;
              c5_gammai = c5_jb_y + c5_gammais;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 221U);
              c5_lb_b = c5_alphai;
              c5_kb_y = 1.1764705882352942 * c5_lb_b;
              c5_y_a = c5_rfi_0;
              c5_mb_b = c5_rfi_0;
              c5_lb_y = c5_y_a * c5_mb_b;
              c5_ab_a = c5_lb_y;
              c5_nb_b = c5_gammaLi;
              c5_mb_y = c5_ab_a * c5_nb_b;
              c5_bb_a = c5_rfi_1;
              c5_ob_b = c5_rfi_1;
              c5_nb_y = c5_bb_a * c5_ob_b;
              c5_cb_a = c5_nb_y;
              c5_pb_b = c5_gammaLi;
              c5_ob_y = c5_cb_a * c5_pb_b;
              c5_alphai = c5_kb_y - (c5_mb_y + c5_ob_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 222U);
              c5_db_a = c5_psi1_0;
              c5_qb_b = c5_gammas;
              c5_b1_0 = c5_db_a * c5_qb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 223U);
              c5_eb_a = c5_psi1_1;
              c5_rb_b = c5_gammas;
              c5_b1_1 = c5_eb_a * c5_rb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 224U);
              c5_fb_a = c5_psi2_0;
              c5_sb_b = c5_gammas;
              c5_b2_0 = c5_fb_a * c5_sb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 225U);
              c5_gb_a = c5_psi2_1;
              c5_tb_b = c5_gammas;
              c5_b2_1 = c5_gb_a * c5_tb_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 226U);
              c5_hb_a = c5_ktilde_0;
              c5_ub_b = c5_b1_0;
              c5_pb_y = c5_hb_a * c5_ub_b;
              c5_G_0 += c5_pb_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 227U);
              c5_ib_a = c5_ktilde_1;
              c5_vb_b = c5_b1_1;
              c5_qb_y = c5_ib_a * c5_vb_b;
              c5_G_1 += c5_qb_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 228U);
              c5_jb_a = c5_psi2_0;
              c5_wb_b = c5_b2_0;
              c5_rb_y = c5_jb_a * c5_wb_b;
              c5_kb_a = c5_psi2_1;
              c5_xb_b = c5_b2_1;
              c5_sb_y = c5_kb_a * c5_xb_b;
              c5_beta = 8.5E-9 + (c5_rb_y + c5_sb_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 229U);
              c5_yb_b = c5_betai;
              c5_tb_y = 1.1764705882352942 * c5_yb_b;
              c5_lb_a = c5_temp_0;
              c5_ac_b = c5_temp_0;
              c5_ub_y = c5_lb_a * c5_ac_b;
              c5_mb_a = c5_ub_y;
              c5_bc_b = c5_gammaLi;
              c5_vb_y = c5_mb_a * c5_bc_b;
              c5_nb_a = c5_temp_1;
              c5_cc_b = c5_temp_1;
              c5_wb_y = c5_nb_a * c5_cc_b;
              c5_ob_a = c5_wb_y;
              c5_dc_b = c5_gammaLi;
              c5_xb_y = c5_ob_a * c5_dc_b;
              c5_betai = c5_tb_y - (c5_vb_y + c5_xb_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 230U);
              c5_c_B = c5_gammai;
              c5_yb_y = c5_c_B;
              c5_ac_y = c5_yb_y;
              c5_gammaiinv = 1.0 / c5_ac_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 231U);
              c5_ec_b = c5_beta;
              c5_bc_y = 0.85 * c5_ec_b;
              c5_pb_a = c5_bc_y;
              c5_fc_b = c5_alphai;
              c5_gamma = c5_pb_a * c5_fc_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 232U);
              c5_gammaerr = c5_gamma - c5_gammaiinv;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 233U);
              c5_gc_b = c5_gammaerr;
              c5_cc_y = c5_gc_b;
              c5_gamma = c5_cc_y + c5_gammaiinv;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 235U);
              c5_qb_a = c5_Wk_0;
              c5_dc_y = c5_qb_a;
              c5_rb_a = c5_Wk_1;
              c5_hc_b = c5_X_1;
              c5_ec_y = c5_rb_a * c5_hc_b;
              c5_epsilon = c5_d - (c5_dc_y + c5_ec_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 236U);
              c5_sb_a = c5_epsilon;
              c5_ic_b = c5_gamma;
              c5_err = c5_sb_a * c5_ic_b;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 237U);
              c5_tb_a = c5_ktilde_0;
              c5_jc_b = c5_err;
              c5_fc_y = c5_tb_a * c5_jc_b;
              c5_Wk_0 += c5_fc_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 238U);
              c5_ub_a = c5_ktilde_1;
              c5_kc_b = c5_err;
              c5_gc_y = c5_ub_a * c5_kc_b;
              c5_Wk_1 += c5_gc_y;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 242U);
              c5_X_0_vON = c5_X_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 243U);
              c5_X_1_vON = c5_X_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 244U);
              c5_A_0_vON = c5_A_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 245U);
              c5_A_1_vON = c5_A_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 246U);
              c5_G_0_vON = c5_G_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 247U);
              c5_G_1_vON = c5_G_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 248U);
              c5_ktilde_0_vON = c5_ktilde_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 249U);
              c5_ktilde_1_vON = c5_ktilde_1;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 250U);
              c5_alphai_vON = c5_alphai;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 251U);
              c5_betai_vON = c5_betai;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 252U);
              c5_gamma_vON = c5_gamma;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 253U);
              c5_gammai_vON = c5_gammai;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 254U);
              c5_w0 = c5_Wk_0;
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, MAX_uint8_T);
              c5_w1 = c5_Wk_1;
            }
          } else {
            guard2 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 260);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 6, c5_offset >= c5_OFFSET_ON_END_rel)) {
      if (CV_EML_COND(0, 1, 7, c5_offset <= c5_OFFSET_ON_END_rel + 1.0)) {
        CV_EML_MCDC(0, 1, 2, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 261);
        c5_A = -c5_w0;
        c5_d_B = c5_w1;
        c5_x = c5_A;
        c5_hc_y = c5_d_B;
        c5_b_x = c5_x;
        c5_ic_y = c5_hc_y;
        c5_jc_y = c5_b_x / c5_ic_y;
        c5_b_A = c5_jc_y;
        c5_c_x = c5_b_A;
        c5_d_x = c5_c_x;
        c5_kc_y = c5_d_x / 30.0;
        c5_vb_a = c5_kc_y;
        c5_Capout = c5_vb_a * 1.0E-6;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 2, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -261);
  sf_debug_symbol_scope_pop();
  *c5_lc_y = c5_y;
  *c5_b_e = c5_e;
  *c5_b_w0 = c5_w0;
  *c5_b_w1 = c5_w1;
  *c5_b_X_0_vON = c5_X_0_vON;
  *c5_b_X_1_vON = c5_X_1_vON;
  *c5_b_A_0_vON = c5_A_0_vON;
  *c5_b_A_1_vON = c5_A_1_vON;
  *c5_b_G_0_vON = c5_G_0_vON;
  *c5_b_G_1_vON = c5_G_1_vON;
  *c5_b_ktilde_0_vON = c5_ktilde_0_vON;
  *c5_b_ktilde_1_vON = c5_ktilde_1_vON;
  *c5_b_alphai_vON = c5_alphai_vON;
  *c5_b_betai_vON = c5_betai_vON;
  *c5_b_gamma_vON = c5_gamma_vON;
  *c5_b_gammai_vON = c5_gammai_vON;
  *c5_b_yi = c5_yi;
  *c5_b_ei = c5_ei;
  *c5_b_wi0 = c5_wi0;
  *c5_b_wi1 = c5_wi1;
  *c5_b_yu = c5_yu;
  *c5_b_eu = c5_eu;
  *c5_b_wu0 = c5_wu0;
  *c5_b_wu1 = c5_wu1;
  *c5_b_wu2 = c5_wu2;
  *c5_b_Capout = c5_Capout;
  *c5_b_ESRout = c5_ESRout;
  *c5_b_Vnoise = c5_Vnoise;
  *c5_b_Inoise = c5_Inoise;
  *c5_b_t0 = c5_t0;
  *c5_b_cnt = c5_cnt;
  *c5_b_cnt1 = c5_cnt1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_BuckBoost1(SFc5_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_cnt1, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_cnt1), &c5_thisId);
  sf_mex_destroy(&c5_cnt1);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_cnt1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c5_cnt1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_cnt1), &c5_thisId);
  sf_mex_destroy(&c5_cnt1);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i5;
  real_T c5_b_inData[6];
  int32_T c5_i6;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i5 = 0; c5_i5 < 6; c5_i5++) {
    c5_b_inData[c5_i5] = (*(real_T (*)[6])c5_inData)[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 6; c5_i6++) {
    c5_u[c5_i6] = c5_b_inData[c5_i6];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[40];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i7;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 40), FALSE);
  for (c5_i7 = 0; c5_i7 < 40; c5_i7++) {
    c5_r0 = &c5_info[c5_i7];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i7);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i7);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[40])
{
  c5_info[0].context = "";
  c5_info[0].name = "mrdivide";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[0].fileTimeLo = 1342789344U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 1319708366U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[1].name = "rdivide";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[1].fileTimeLo = 1286797244U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[2].name = "eml_div";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[2].fileTimeLo = 1313326210U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "";
  c5_info[3].name = "mtimes";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].fileTimeLo = 1289494492U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "";
  c5_info[4].name = "mod";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[4].fileTimeLo = 1326702796U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[5].name = "eml_scalar_eg";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[5].fileTimeLo = 1286797196U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[6].name = "eml_scalexp_alloc";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[6].fileTimeLo = 1330583234U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[7].name = "eml_scalar_eg";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[7].fileTimeLo = 1286797196U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[8].name = "eml_scalar_floor";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[8].fileTimeLo = 1286797126U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[9].name = "eml_scalar_round";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c5_info[9].fileTimeLo = 1307629638U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[10].name = "eml_scalar_abs";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[10].fileTimeLo = 1286797112U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[11].name = "eps";
  c5_info[11].dominantType = "char";
  c5_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[11].fileTimeLo = 1326702796U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[12].name = "eml_is_float_class";
  c5_info[12].dominantType = "char";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[12].fileTimeLo = 1286797182U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[13].name = "eml_eps";
  c5_info[13].dominantType = "char";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[13].fileTimeLo = 1326702796U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[14].name = "eml_float_model";
  c5_info[14].dominantType = "char";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c5_info[14].fileTimeLo = 1326702796U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c5_info[15].name = "mtimes";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[15].fileTimeLo = 1289494492U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context = "";
  c5_info[16].name = "rand";
  c5_info[16].dominantType = "";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c5_info[16].fileTimeLo = 1313326222U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c5_info[17].name = "eml_is_rand_extrinsic";
  c5_info[17].dominantType = "";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m";
  c5_info[17].fileTimeLo = 1334049890U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c5_info[18].name = "eml_rand";
  c5_info[18].dominantType = "char";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c5_info[18].fileTimeLo = 1313326220U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c5_info[19].name = "eml_rand_str2id";
  c5_info[19].dominantType = "char";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c5_info[19].fileTimeLo = 1313326222U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c5_info[20].name = "eml_rand_mcg16807_stateful";
  c5_info[20].dominantType = "char";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c5_info[20].fileTimeLo = 1313326220U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c5_info[21].name = "eml_rand_mcg16807";
  c5_info[21].dominantType = "char";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c5_info[21].fileTimeLo = 1313326220U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c5_info[22].name = "eml_rand_mcg16807";
  c5_info[22].dominantType = "uint32";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c5_info[22].fileTimeLo = 1313326220U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandu";
  c5_info[23].name = "mtimes";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[23].fileTimeLo = 1289494492U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c5_info[24].name = "eml_rand_shr3cong_stateful";
  c5_info[24].dominantType = "char";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c5_info[24].fileTimeLo = 1313326222U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c5_info[25].name = "eml_rand_shr3cong";
  c5_info[25].dominantType = "char";
  c5_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c5_info[25].fileTimeLo = 1313326220U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 0U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c5_info[26].name = "eml_rand_shr3cong";
  c5_info[26].dominantType = "uint32";
  c5_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c5_info[26].fileTimeLo = 1313326220U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandu";
  c5_info[27].name = "mtimes";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[27].fileTimeLo = 1289494492U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 0U;
  c5_info[27].mFileTimeHi = 0U;
  c5_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c5_info[28].name = "eml_rand_mt19937ar_stateful";
  c5_info[28].dominantType = "char";
  c5_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c5_info[28].fileTimeLo = 1313326220U;
  c5_info[28].fileTimeHi = 0U;
  c5_info[28].mFileTimeLo = 0U;
  c5_info[28].mFileTimeHi = 0U;
  c5_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c5_info[29].name = "eml_rand_mt19937ar";
  c5_info[29].dominantType = "char";
  c5_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c5_info[29].fileTimeLo = 1313326220U;
  c5_info[29].fileTimeHi = 0U;
  c5_info[29].mFileTimeLo = 0U;
  c5_info[29].mFileTimeHi = 0U;
  c5_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c5_info[30].name = "eml_rand_mt19937ar";
  c5_info[30].dominantType = "uint32";
  c5_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c5_info[30].fileTimeLo = 1313326220U;
  c5_info[30].fileTimeHi = 0U;
  c5_info[30].mFileTimeLo = 0U;
  c5_info[30].mFileTimeHi = 0U;
  c5_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c5_info[31].name = "eps";
  c5_info[31].dominantType = "";
  c5_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[31].fileTimeLo = 1326702796U;
  c5_info[31].fileTimeHi = 0U;
  c5_info[31].mFileTimeLo = 0U;
  c5_info[31].mFileTimeHi = 0U;
  c5_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c5_info[32].name = "isequal";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c5_info[32].fileTimeLo = 1286797158U;
  c5_info[32].fileTimeHi = 0U;
  c5_info[32].mFileTimeLo = 0U;
  c5_info[32].mFileTimeHi = 0U;
  c5_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c5_info[33].name = "eml_isequal_core";
  c5_info[33].dominantType = "double";
  c5_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c5_info[33].fileTimeLo = 1286797186U;
  c5_info[33].fileTimeHi = 0U;
  c5_info[33].mFileTimeLo = 0U;
  c5_info[33].mFileTimeHi = 0U;
  c5_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c5_info[34].name = "isnan";
  c5_info[34].dominantType = "double";
  c5_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[34].fileTimeLo = 1286797160U;
  c5_info[34].fileTimeHi = 0U;
  c5_info[34].mFileTimeLo = 0U;
  c5_info[34].mFileTimeHi = 0U;
  c5_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c5_info[35].name = "mtimes";
  c5_info[35].dominantType = "double";
  c5_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[35].fileTimeLo = 1289494492U;
  c5_info[35].fileTimeHi = 0U;
  c5_info[35].mFileTimeLo = 0U;
  c5_info[35].mFileTimeHi = 0U;
  c5_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c5_info[36].name = "eml_index_class";
  c5_info[36].dominantType = "";
  c5_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[36].fileTimeLo = 1323145378U;
  c5_info[36].fileTimeHi = 0U;
  c5_info[36].mFileTimeLo = 0U;
  c5_info[36].mFileTimeHi = 0U;
  c5_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c5_info[37].name = "eml_index_plus";
  c5_info[37].dominantType = "double";
  c5_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[37].fileTimeLo = 1286797178U;
  c5_info[37].fileTimeHi = 0U;
  c5_info[37].mFileTimeLo = 0U;
  c5_info[37].mFileTimeHi = 0U;
  c5_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[38].name = "eml_index_class";
  c5_info[38].dominantType = "";
  c5_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[38].fileTimeLo = 1323145378U;
  c5_info[38].fileTimeHi = 0U;
  c5_info[38].mFileTimeLo = 0U;
  c5_info[38].mFileTimeHi = 0U;
  c5_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c5_info[39].name = "eml_error";
  c5_info[39].dominantType = "char";
  c5_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[39].fileTimeLo = 1305296400U;
  c5_info[39].fileTimeHi = 0U;
  c5_info[39].mFileTimeLo = 0U;
  c5_info[39].mFileTimeHi = 0U;
}

static real_T c5_mod(SFc5_BuckBoost1InstanceStruct *chartInstance, real_T c5_x,
                     real_T c5_y)
{
  real_T c5_r;
  real_T c5_xk;
  real_T c5_yk;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_c_y;
  real_T c5_j_x;
  real_T c5_d_y;
  real_T c5_b;
  real_T c5_e_y;
  real_T c5_k_x;
  real_T c5_l_x;
  c5_eml_scalar_eg(chartInstance);
  c5_xk = c5_x;
  c5_yk = c5_y;
  c5_b_x = c5_xk;
  c5_b_y = c5_yk;
  c5_eml_scalar_eg(chartInstance);
  if (c5_b_y == 0.0) {
    c5_r = c5_b_x;
  } else {
    c5_c_x = c5_b_y;
    c5_d_x = c5_c_x;
    c5_d_x = muDoubleScalarFloor(c5_d_x);
    if (c5_b_y == c5_d_x) {
      c5_e_x = c5_b_x / c5_b_y;
      c5_f_x = c5_e_x;
      c5_f_x = muDoubleScalarFloor(c5_f_x);
      c5_r = c5_b_x - c5_f_x * c5_b_y;
    } else {
      c5_r = c5_b_x / c5_b_y;
      c5_eml_eps(chartInstance);
      c5_g_x = c5_r;
      c5_h_x = c5_g_x;
      c5_h_x = muDoubleScalarRound(c5_h_x);
      c5_i_x = c5_r - c5_h_x;
      c5_c_y = muDoubleScalarAbs(c5_i_x);
      c5_j_x = c5_r;
      c5_d_y = muDoubleScalarAbs(c5_j_x);
      c5_b = c5_d_y;
      c5_e_y = 2.2204460492503131E-16 * c5_b;
      if (c5_c_y <= c5_e_y) {
        c5_r = 0.0;
      } else {
        c5_k_x = c5_r;
        c5_l_x = c5_k_x;
        c5_l_x = muDoubleScalarFloor(c5_l_x);
        c5_r = (c5_r - c5_l_x) * c5_b_y;
      }
    }
  }

  return c5_r;
}

static void c5_eml_scalar_eg(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c5_eml_eps(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
}

static real_T c5_rand(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
  real_T c5_r;
  uint32_T c5_hoistedGlobal;
  uint32_T c5_d_state;
  uint32_T c5_e_state;
  uint32_T c5_s;
  uint32_T c5_u0;
  uint32_T c5_hi;
  uint32_T c5_lo;
  uint32_T c5_test1;
  uint32_T c5_test2;
  uint32_T c5_f_state;
  real_T c5_a;
  real_T c5_b_r;
  real_T c5_d1;
  int32_T c5_i8;
  uint32_T c5_icng;
  uint32_T c5_jsr;
  uint32_T c5_u1;
  uint32_T c5_u2;
  uint32_T c5_ui;
  uint32_T c5_b_ui;
  real_T c5_b_a;
  real_T c5_c_r;
  real_T c5_d2;
  uint32_T c5_uv2[625];
  int32_T c5_i9;
  int32_T c5_i10;
  uint32_T c5_g_state[625];
  real_T c5_d3;
  int32_T c5_i11;
  if (!chartInstance->c5_method_not_empty) {
    chartInstance->c5_method = 7U;
    chartInstance->c5_method_not_empty = TRUE;
  }

  if (chartInstance->c5_method == 4U) {
    if (!chartInstance->c5_state_not_empty) {
      chartInstance->c5_state = 1144108930U;
      chartInstance->c5_state_not_empty = TRUE;
    }

    c5_hoistedGlobal = chartInstance->c5_state;
    c5_d_state = c5_hoistedGlobal;
    c5_e_state = c5_d_state;
    c5_s = c5_e_state;
    c5_u0 = 127773U;
    if (c5_u0 == 0) {
      c5_hi = MAX_uint32_T;
    } else {
      c5_hi = c5_s / c5_u0;
    }

    c5_lo = c5_s - c5_hi * 127773U;
    c5_test1 = 16807U * c5_lo;
    c5_test2 = 2836U * c5_hi;
    if (c5_test1 < c5_test2) {
      c5_f_state = (c5_test1 - c5_test2) + 2147483647U;
    } else {
      c5_f_state = c5_test1 - c5_test2;
    }

    c5_a = (real_T)c5_f_state;
    c5_b_r = c5_a * 4.6566128752457969E-10;
    c5_e_state = c5_f_state;
    c5_d1 = c5_b_r;
    chartInstance->c5_state = c5_e_state;
    c5_r = c5_d1;
  } else if (chartInstance->c5_method == 5U) {
    if (!chartInstance->c5_b_state_not_empty) {
      for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
        chartInstance->c5_b_state[c5_i8] = 362436069U + 158852560U * (uint32_T)
          c5_i8;
      }

      chartInstance->c5_b_state_not_empty = TRUE;
    }

    c5_icng = chartInstance->c5_b_state[0];
    c5_jsr = chartInstance->c5_b_state[1];
    c5_u1 = c5_jsr;
    c5_u2 = c5_icng;
    c5_u2 = 69069U * c5_u2 + 1234567U;
    c5_u1 ^= c5_u1 << 13U;
    c5_u1 ^= c5_u1 >> 17U;
    c5_u1 ^= c5_u1 << 5U;
    c5_ui = c5_u2 + c5_u1;
    chartInstance->c5_b_state[0] = c5_u2;
    chartInstance->c5_b_state[1] = c5_u1;
    c5_b_ui = c5_ui;
    c5_b_a = (real_T)c5_b_ui;
    c5_c_r = c5_b_a * 2.328306436538696E-10;
    c5_d2 = c5_c_r;
    c5_r = c5_d2;
  } else {
    if (!chartInstance->c5_c_state_not_empty) {
      c5_eml_rand_mt19937ar(chartInstance, c5_uv2);
      for (c5_i9 = 0; c5_i9 < 625; c5_i9++) {
        chartInstance->c5_c_state[c5_i9] = c5_uv2[c5_i9];
      }

      chartInstance->c5_c_state_not_empty = TRUE;
    }

    for (c5_i10 = 0; c5_i10 < 625; c5_i10++) {
      c5_g_state[c5_i10] = chartInstance->c5_c_state[c5_i10];
    }

    c5_d3 = c5_c_eml_rand_mt19937ar(chartInstance, c5_g_state);
    for (c5_i11 = 0; c5_i11 < 625; c5_i11++) {
      chartInstance->c5_c_state[c5_i11] = c5_g_state[c5_i11];
    }

    c5_r = c5_d3;
  }

  return c5_r;
}

static void c5_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_d_state[625])
{
  real_T c5_d4;
  int32_T c5_i12;
  c5_d4 = 5489.0;
  for (c5_i12 = 0; c5_i12 < 625; c5_i12++) {
    c5_d_state[c5_i12] = 0U;
  }

  c5_b_twister_state_vector(chartInstance, c5_d_state, c5_d4);
}

static void c5_twister_state_vector(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_mt[625], real_T c5_seed, uint32_T c5_b_mt[625])
{
  int32_T c5_i13;
  for (c5_i13 = 0; c5_i13 < 625; c5_i13++) {
    c5_b_mt[c5_i13] = c5_mt[c5_i13];
  }

  c5_b_twister_state_vector(chartInstance, c5_b_mt, c5_seed);
}

static void c5_b_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c5_d_state[625], uint32_T c5_e_state[625], real_T *c5_r)
{
  int32_T c5_i14;
  for (c5_i14 = 0; c5_i14 < 625; c5_i14++) {
    c5_e_state[c5_i14] = c5_d_state[c5_i14];
  }

  *c5_r = c5_c_eml_rand_mt19937ar(chartInstance, c5_e_state);
}

static void c5_eml_error(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
  int32_T c5_i15;
  static char_T c5_varargin_1[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l',
    'i', 'd', 'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c5_u[37];
  const mxArray *c5_y = NULL;
  for (c5_i15 = 0; c5_i15 < 37; c5_i15++) {
    c5_u[c5_i15] = c5_varargin_1[c5_i15];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 37), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c5_y));
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i16;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i16, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i16;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint32_T c5_d_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_b_method, const char_T *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_method),
    &c5_thisId);
  sf_mex_destroy(&c5_b_method);
  return c5_y;
}

static uint32_T c5_e_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u3;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_method_not_empty = FALSE;
  } else {
    chartInstance->c5_method_not_empty = TRUE;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u3, 1, 7, 0U, 0, 0U, 0);
    c5_y = c5_u3;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static uint32_T c5_f_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId);
  sf_mex_destroy(&c5_d_state);
  return c5_y;
}

static uint32_T c5_g_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u4;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_state_not_empty = FALSE;
  } else {
    chartInstance->c5_state_not_empty = TRUE;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u4, 1, 7, 0U, 0, 0U, 0);
    c5_y = c5_u4;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_h_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_d_state, const char_T *c5_identifier, uint32_T c5_y[625])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_d_state);
}

static void c5_i_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint32_T c5_y[625])
{
  uint32_T c5_uv3[625];
  int32_T c5_i17;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_c_state_not_empty = FALSE;
  } else {
    chartInstance->c5_c_state_not_empty = TRUE;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c5_i17 = 0; c5_i17 < 625; c5_i17++) {
      c5_y[c5_i17] = c5_uv3[c5_i17];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_j_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_d_state, const char_T *c5_identifier, uint32_T c5_y[2])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_d_state);
}

static void c5_k_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint32_T c5_y[2])
{
  uint32_T c5_uv4[2];
  int32_T c5_i18;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_b_state_not_empty = FALSE;
  } else {
    chartInstance->c5_b_state_not_empty = TRUE;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
      c5_y[c5_i18] = c5_uv4[c5_i18];
    }
  }

  sf_mex_destroy(&c5_u);
}

static uint8_T c5_l_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_BuckBoost1, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_BuckBoost1), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_BuckBoost1);
  return c5_y;
}

static uint8_T c5_m_emlrt_marshallIn(SFc5_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u5;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u5, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u5;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_twister_state_vector(SFc5_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c5_mt[625], real_T c5_seed)
{
  real_T c5_d5;
  uint32_T c5_u6;
  uint32_T c5_r;
  int32_T c5_mti;
  real_T c5_b_mti;
  real_T c5_d6;
  uint32_T c5_u7;
  c5_d5 = c5_seed;
  if (c5_d5 < 4.294967296E+9) {
    if (c5_d5 >= 0.0) {
      c5_u6 = (uint32_T)c5_d5;
    } else {
      c5_u6 = 0U;
    }
  } else if (c5_d5 >= 4.294967296E+9) {
    c5_u6 = MAX_uint32_T;
  } else {
    c5_u6 = 0U;
  }

  c5_r = c5_u6;
  c5_mt[0] = c5_r;
  for (c5_mti = 0; c5_mti < 623; c5_mti++) {
    c5_b_mti = 2.0 + (real_T)c5_mti;
    c5_d6 = muDoubleScalarRound(c5_b_mti - 1.0);
    if (c5_d6 < 4.294967296E+9) {
      if (c5_d6 >= 0.0) {
        c5_u7 = (uint32_T)c5_d6;
      } else {
        c5_u7 = 0U;
      }
    } else if (c5_d6 >= 4.294967296E+9) {
      c5_u7 = MAX_uint32_T;
    } else {
      c5_u7 = 0U;
    }

    c5_r = (c5_r ^ c5_r >> 30U) * 1812433253U + c5_u7;
    c5_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c5_b_mti), 1, 625, 1, 0) - 1] = c5_r;
  }

  c5_mt[624] = 624U;
}

static real_T c5_c_eml_rand_mt19937ar(SFc5_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c5_d_state[625])
{
  int32_T c5_i19;
  uint32_T c5_u[2];
  int32_T c5_j;
  real_T c5_b_j;
  uint32_T c5_mti;
  int32_T c5_kk;
  real_T c5_b_kk;
  uint32_T c5_y;
  uint32_T c5_b_y;
  uint32_T c5_c_y;
  int32_T c5_c_kk;
  uint32_T c5_d_y;
  uint32_T c5_e_y;
  uint32_T c5_f_y;
  uint32_T c5_g_y;
  real_T c5_a;
  real_T c5_h_y;
  real_T c5_b;
  real_T c5_b_r;
  boolean_T c5_b0;
  boolean_T c5_isvalid;
  int32_T c5_k;
  int32_T c5_b_a;
  real_T c5_d7;
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
  c5_eml_eps(chartInstance);
  do {
    exitg1 = 0;
    for (c5_i19 = 0; c5_i19 < 2; c5_i19++) {
      c5_u[c5_i19] = 0U;
    }

    for (c5_j = 0; c5_j < 2; c5_j++) {
      c5_b_j = 1.0 + (real_T)c5_j;
      c5_mti = c5_d_state[624] + 1U;
      if ((real_T)c5_mti >= 625.0) {
        for (c5_kk = 0; c5_kk < 227; c5_kk++) {
          c5_b_kk = 1.0 + (real_T)c5_kk;
          c5_y = (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c5_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c5_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c5_b_y = c5_y;
          c5_c_y = c5_b_y;
          if ((real_T)(c5_c_y & 1U) == 0.0) {
            c5_c_y >>= 1U;
          } else {
            c5_c_y = c5_c_y >> 1U ^ 2567483615U;
          }

          c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c5_b_kk), 1, 625, 1, 0) - 1] =
            c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c5_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c5_c_y;
        }

        for (c5_c_kk = 0; c5_c_kk < 396; c5_c_kk++) {
          c5_b_kk = 228.0 + (real_T)c5_c_kk;
          c5_y = (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c5_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c5_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c5_d_y = c5_y;
          c5_e_y = c5_d_y;
          if ((real_T)(c5_e_y & 1U) == 0.0) {
            c5_e_y >>= 1U;
          } else {
            c5_e_y = c5_e_y >> 1U ^ 2567483615U;
          }

          c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c5_b_kk), 1, 625, 1, 0) - 1] =
            c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c5_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c5_e_y;
        }

        c5_y = (c5_d_state[623] & 2147483648U) | (c5_d_state[0] & 2147483647U);
        c5_f_y = c5_y;
        c5_g_y = c5_f_y;
        if ((real_T)(c5_g_y & 1U) == 0.0) {
          c5_g_y >>= 1U;
        } else {
          c5_g_y = c5_g_y >> 1U ^ 2567483615U;
        }

        c5_d_state[623] = c5_d_state[396] ^ c5_g_y;
        c5_mti = 1U;
      }

      c5_y = c5_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c5_mti), 1, 625, 1, 0)
        - 1];
      c5_d_state[624] = c5_mti;
      c5_y ^= c5_y >> 11U;
      c5_y ^= c5_y << 7U & 2636928640U;
      c5_y ^= c5_y << 15U & 4022730752U;
      c5_y ^= c5_y >> 18U;
      c5_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c5_b_j), 1, 2, 1, 0) - 1] = c5_y;
    }

    c5_u[0] >>= 5U;
    c5_u[1] >>= 6U;
    c5_a = (real_T)c5_u[0];
    c5_h_y = c5_a * 6.7108864E+7;
    c5_b = c5_h_y + (real_T)c5_u[1];
    c5_b_r = 1.1102230246251565E-16 * c5_b;
    if (c5_b_r == 0.0) {
      guard1 = FALSE;
      if ((real_T)c5_d_state[624] >= 1.0) {
        if ((real_T)c5_d_state[624] < 625.0) {
          c5_b0 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c5_b0 = FALSE;
      }

      c5_isvalid = c5_b0;
      if (c5_isvalid) {
        c5_isvalid = FALSE;
        c5_k = 1;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (c5_k < 625)) {
          if ((real_T)c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c5_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c5_b_a = c5_k + 1;
            c5_k = c5_b_a;
          } else {
            c5_isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!c5_isvalid) {
        c5_eml_error(chartInstance);
        c5_d7 = 5489.0;
        c5_b_twister_state_vector(chartInstance, c5_d_state, c5_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c5_b_r;
}

static void init_dsm_address_info(SFc5_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(382998203U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4245475819U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2284977648U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(636746435U);
}

mxArray *sf_c5_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tgR4uajkiElw5HHE8XX1O");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,29,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,32,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[46],T\"A_0_vON\",},{M[1],M[47],T\"A_1_vON\",},{M[1],M[34],T\"Capout\",},{M[1],M[83],T\"ESRout\",},{M[1],M[89],T\"G_0_vON\",},{M[1],M[90],T\"G_1_vON\",},{M[1],M[94],T\"Inoise\",},{M[1],M[93],T\"Vnoise\",},{M[1],M[35],T\"X_0_vON\",},{M[1],M[31],T\"X_1_vON\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[74],T\"alphai_vON\",},{M[1],M[75],T\"betai_vON\",},{M[1],M[101],T\"cnt\",},{M[1],M[103],T\"cnt1\",},{M[1],M[29],T\"e\",},{M[1],M[66],T\"ei\",},{M[1],M[70],T\"eu\",},{M[1],M[76],T\"gamma_vON\",},{M[1],M[77],T\"gammai_vON\",},{M[1],M[91],T\"ktilde_0_vON\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[92],T\"ktilde_1_vON\",},{M[1],M[84],T\"t0\",},{M[1],M[44],T\"w0\",},{M[1],M[45],T\"w1\",},{M[1],M[67],T\"wi0\",},{M[1],M[68],T\"wi1\",},{M[1],M[71],T\"wu0\",},{M[1],M[72],T\"wu1\",},{M[1],M[73],T\"wu2\",},{M[1],M[28],T\"y\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[65],T\"yi\",},{M[1],M[69],T\"yu\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c5_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 37, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc5_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           5,
           1,
           1,
           61,
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
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_out");
          _SFD_SET_DATA_PROPS(4,1,1,0,"i_in");
          _SFD_SET_DATA_PROPS(5,1,1,0,"w0in");
          _SFD_SET_DATA_PROPS(6,1,1,0,"w1in");
          _SFD_SET_DATA_PROPS(7,1,1,0,"X_0_vON_in");
          _SFD_SET_DATA_PROPS(8,1,1,0,"X_1_vON_in");
          _SFD_SET_DATA_PROPS(9,1,1,0,"A_0_vON_in");
          _SFD_SET_DATA_PROPS(10,1,1,0,"A_1_vON_in");
          _SFD_SET_DATA_PROPS(11,1,1,0,"G_0_vON_in");
          _SFD_SET_DATA_PROPS(12,1,1,0,"G_1_vON_in");
          _SFD_SET_DATA_PROPS(13,1,1,0,"ktilde_0_vON_in");
          _SFD_SET_DATA_PROPS(14,1,1,0,"ktilde_1_vON_in");
          _SFD_SET_DATA_PROPS(15,1,1,0,"alphai_vON_in");
          _SFD_SET_DATA_PROPS(16,1,1,0,"betai_vON_in");
          _SFD_SET_DATA_PROPS(17,1,1,0,"gamma_vON_in");
          _SFD_SET_DATA_PROPS(18,1,1,0,"gammai_vON_in");
          _SFD_SET_DATA_PROPS(19,1,1,0,"wi0in");
          _SFD_SET_DATA_PROPS(20,1,1,0,"wi1in");
          _SFD_SET_DATA_PROPS(21,1,1,0,"wu0in");
          _SFD_SET_DATA_PROPS(22,1,1,0,"wu1in");
          _SFD_SET_DATA_PROPS(23,1,1,0,"wu2in");
          _SFD_SET_DATA_PROPS(24,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(25,2,0,1,"y");
          _SFD_SET_DATA_PROPS(26,2,0,1,"e");
          _SFD_SET_DATA_PROPS(27,2,0,1,"w0");
          _SFD_SET_DATA_PROPS(28,2,0,1,"w1");
          _SFD_SET_DATA_PROPS(29,2,0,1,"X_0_vON");
          _SFD_SET_DATA_PROPS(30,2,0,1,"X_1_vON");
          _SFD_SET_DATA_PROPS(31,2,0,1,"A_0_vON");
          _SFD_SET_DATA_PROPS(32,2,0,1,"A_1_vON");
          _SFD_SET_DATA_PROPS(33,2,0,1,"G_0_vON");
          _SFD_SET_DATA_PROPS(34,2,0,1,"G_1_vON");
          _SFD_SET_DATA_PROPS(35,2,0,1,"ktilde_0_vON");
          _SFD_SET_DATA_PROPS(36,2,0,1,"ktilde_1_vON");
          _SFD_SET_DATA_PROPS(37,2,0,1,"alphai_vON");
          _SFD_SET_DATA_PROPS(38,2,0,1,"betai_vON");
          _SFD_SET_DATA_PROPS(39,2,0,1,"gamma_vON");
          _SFD_SET_DATA_PROPS(40,2,0,1,"gammai_vON");
          _SFD_SET_DATA_PROPS(41,2,0,1,"yi");
          _SFD_SET_DATA_PROPS(42,2,0,1,"ei");
          _SFD_SET_DATA_PROPS(43,2,0,1,"wi0");
          _SFD_SET_DATA_PROPS(44,2,0,1,"wi1");
          _SFD_SET_DATA_PROPS(45,2,0,1,"yu");
          _SFD_SET_DATA_PROPS(46,2,0,1,"eu");
          _SFD_SET_DATA_PROPS(47,2,0,1,"wu0");
          _SFD_SET_DATA_PROPS(48,2,0,1,"wu1");
          _SFD_SET_DATA_PROPS(49,2,0,1,"wu2");
          _SFD_SET_DATA_PROPS(50,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(51,1,1,0,"ESRin");
          _SFD_SET_DATA_PROPS(52,1,1,0,"t0in");
          _SFD_SET_DATA_PROPS(53,2,0,1,"ESRout");
          _SFD_SET_DATA_PROPS(54,2,0,1,"Vnoise");
          _SFD_SET_DATA_PROPS(55,2,0,1,"Inoise");
          _SFD_SET_DATA_PROPS(56,2,0,1,"t0");
          _SFD_SET_DATA_PROPS(57,1,1,0,"cntin");
          _SFD_SET_DATA_PROPS(58,2,0,1,"cnt");
          _SFD_SET_DATA_PROPS(59,1,1,0,"cntin1");
          _SFD_SET_DATA_PROPS(60,2,0,1,"cnt1");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,8,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,10941);
        _SFD_CV_INIT_EML_IF(0,1,0,3841,3853,-1,10940);
        _SFD_CV_INIT_EML_IF(0,1,1,3934,4047,-1,7257);
        _SFD_CV_INIT_EML_IF(0,1,2,4088,4144,4210,7239);
        _SFD_CV_INIT_EML_IF(0,1,3,7262,7326,-1,7381);

        {
          static int condStart[] = { 3937, 3964, 3994, 4031 };

          static int condEnd[] = { 3960, 3990, 4027, 4046 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,3937,4046,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4091, 4118 };

          static int condEnd[] = { 4114, 4143 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,4091,4143,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 7265, 7296 };

          static int condEnd[] = { 7292, 7325 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,7265,7325,2,6,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_start;
          real_T *c5_t;
          real_T *c5_duty;
          real_T *c5_v_out;
          real_T *c5_i_in;
          real_T *c5_w0in;
          real_T *c5_w1in;
          real_T *c5_X_0_vON_in;
          real_T *c5_X_1_vON_in;
          real_T *c5_A_0_vON_in;
          real_T *c5_A_1_vON_in;
          real_T *c5_G_0_vON_in;
          real_T *c5_G_1_vON_in;
          real_T *c5_ktilde_0_vON_in;
          real_T *c5_ktilde_1_vON_in;
          real_T *c5_alphai_vON_in;
          real_T *c5_betai_vON_in;
          real_T *c5_gamma_vON_in;
          real_T *c5_gammai_vON_in;
          real_T *c5_wi0in;
          real_T *c5_wi1in;
          real_T *c5_wu0in;
          real_T *c5_wu1in;
          real_T *c5_wu2in;
          real_T *c5_Capin;
          real_T *c5_y;
          real_T *c5_e;
          real_T *c5_w0;
          real_T *c5_w1;
          real_T *c5_X_0_vON;
          real_T *c5_X_1_vON;
          real_T *c5_A_0_vON;
          real_T *c5_A_1_vON;
          real_T *c5_G_0_vON;
          real_T *c5_G_1_vON;
          real_T *c5_ktilde_0_vON;
          real_T *c5_ktilde_1_vON;
          real_T *c5_alphai_vON;
          real_T *c5_betai_vON;
          real_T *c5_gamma_vON;
          real_T *c5_gammai_vON;
          real_T *c5_yi;
          real_T *c5_ei;
          real_T *c5_wi0;
          real_T *c5_wi1;
          real_T *c5_yu;
          real_T *c5_eu;
          real_T *c5_wu0;
          real_T *c5_wu1;
          real_T *c5_wu2;
          real_T *c5_Capout;
          real_T *c5_ESRin;
          real_T *c5_t0in;
          real_T *c5_ESRout;
          real_T *c5_Vnoise;
          real_T *c5_Inoise;
          real_T *c5_t0;
          real_T *c5_cntin;
          real_T *c5_cnt;
          real_T *c5_cntin1;
          real_T *c5_cnt1;
          c5_cnt1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 32);
          c5_cntin1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
          c5_cnt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 31);
          c5_cntin = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
          c5_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 30);
          c5_Inoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 29);
          c5_Vnoise = (real_T *)ssGetOutputPortSignal(chartInstance->S, 28);
          c5_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 27);
          c5_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
          c5_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
          c5_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 26);
          c5_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 25);
          c5_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 24);
          c5_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 23);
          c5_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 22);
          c5_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 21);
          c5_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
          c5_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
          c5_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
          c5_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
          c5_gammai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
          c5_gamma_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c5_betai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c5_alphai_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c5_ktilde_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c5_ktilde_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c5_G_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c5_G_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c5_A_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c5_A_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c5_X_1_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c5_X_0_vON = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c5_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c5_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
          c5_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
          c5_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
          c5_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
          c5_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
          c5_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
          c5_gammai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
          c5_gamma_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
          c5_betai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
          c5_alphai_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c5_ktilde_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S,
            14);
          c5_ktilde_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S,
            13);
          c5_G_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c5_G_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c5_A_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c5_A_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c5_X_1_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c5_X_0_vON_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c5_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c5_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c5_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_start);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_t);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_duty);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_v_out);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_i_in);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_w0in);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_w1in);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_X_0_vON_in);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_X_1_vON_in);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_A_0_vON_in);
          _SFD_SET_DATA_VALUE_PTR(10U, c5_A_1_vON_in);
          _SFD_SET_DATA_VALUE_PTR(11U, c5_G_0_vON_in);
          _SFD_SET_DATA_VALUE_PTR(12U, c5_G_1_vON_in);
          _SFD_SET_DATA_VALUE_PTR(13U, c5_ktilde_0_vON_in);
          _SFD_SET_DATA_VALUE_PTR(14U, c5_ktilde_1_vON_in);
          _SFD_SET_DATA_VALUE_PTR(15U, c5_alphai_vON_in);
          _SFD_SET_DATA_VALUE_PTR(16U, c5_betai_vON_in);
          _SFD_SET_DATA_VALUE_PTR(17U, c5_gamma_vON_in);
          _SFD_SET_DATA_VALUE_PTR(18U, c5_gammai_vON_in);
          _SFD_SET_DATA_VALUE_PTR(19U, c5_wi0in);
          _SFD_SET_DATA_VALUE_PTR(20U, c5_wi1in);
          _SFD_SET_DATA_VALUE_PTR(21U, c5_wu0in);
          _SFD_SET_DATA_VALUE_PTR(22U, c5_wu1in);
          _SFD_SET_DATA_VALUE_PTR(23U, c5_wu2in);
          _SFD_SET_DATA_VALUE_PTR(24U, c5_Capin);
          _SFD_SET_DATA_VALUE_PTR(25U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(26U, c5_e);
          _SFD_SET_DATA_VALUE_PTR(27U, c5_w0);
          _SFD_SET_DATA_VALUE_PTR(28U, c5_w1);
          _SFD_SET_DATA_VALUE_PTR(29U, c5_X_0_vON);
          _SFD_SET_DATA_VALUE_PTR(30U, c5_X_1_vON);
          _SFD_SET_DATA_VALUE_PTR(31U, c5_A_0_vON);
          _SFD_SET_DATA_VALUE_PTR(32U, c5_A_1_vON);
          _SFD_SET_DATA_VALUE_PTR(33U, c5_G_0_vON);
          _SFD_SET_DATA_VALUE_PTR(34U, c5_G_1_vON);
          _SFD_SET_DATA_VALUE_PTR(35U, c5_ktilde_0_vON);
          _SFD_SET_DATA_VALUE_PTR(36U, c5_ktilde_1_vON);
          _SFD_SET_DATA_VALUE_PTR(37U, c5_alphai_vON);
          _SFD_SET_DATA_VALUE_PTR(38U, c5_betai_vON);
          _SFD_SET_DATA_VALUE_PTR(39U, c5_gamma_vON);
          _SFD_SET_DATA_VALUE_PTR(40U, c5_gammai_vON);
          _SFD_SET_DATA_VALUE_PTR(41U, c5_yi);
          _SFD_SET_DATA_VALUE_PTR(42U, c5_ei);
          _SFD_SET_DATA_VALUE_PTR(43U, c5_wi0);
          _SFD_SET_DATA_VALUE_PTR(44U, c5_wi1);
          _SFD_SET_DATA_VALUE_PTR(45U, c5_yu);
          _SFD_SET_DATA_VALUE_PTR(46U, c5_eu);
          _SFD_SET_DATA_VALUE_PTR(47U, c5_wu0);
          _SFD_SET_DATA_VALUE_PTR(48U, c5_wu1);
          _SFD_SET_DATA_VALUE_PTR(49U, c5_wu2);
          _SFD_SET_DATA_VALUE_PTR(50U, c5_Capout);
          _SFD_SET_DATA_VALUE_PTR(51U, c5_ESRin);
          _SFD_SET_DATA_VALUE_PTR(52U, c5_t0in);
          _SFD_SET_DATA_VALUE_PTR(53U, c5_ESRout);
          _SFD_SET_DATA_VALUE_PTR(54U, c5_Vnoise);
          _SFD_SET_DATA_VALUE_PTR(55U, c5_Inoise);
          _SFD_SET_DATA_VALUE_PTR(56U, c5_t0);
          _SFD_SET_DATA_VALUE_PTR(57U, c5_cntin);
          _SFD_SET_DATA_VALUE_PTR(58U, c5_cnt);
          _SFD_SET_DATA_VALUE_PTR(59U, c5_cntin1);
          _SFD_SET_DATA_VALUE_PTR(60U, c5_cnt1);
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
  return "xvKbjnWQutDBkIHkPgsdrC";
}

static void sf_opaque_initialize_c5_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_BuckBoost1(void *chartInstanceVar)
{
  enable_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_BuckBoost1(void *chartInstanceVar)
{
  disable_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_BuckBoost1(void *chartInstanceVar)
{
  sf_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_BuckBoost1
    ((SFc5_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c5_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c5_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c5_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_BuckBoost1((SFc5_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,29);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,32);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1417927250U));
  ssSetChecksum1(S,(2682537295U));
  ssSetChecksum2(S,(2128289123U));
  ssSetChecksum3(S,(2758627058U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_BuckBoost1(SimStruct *S)
{
  SFc5_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc5_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc5_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_BuckBoost1;
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

void c5_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
