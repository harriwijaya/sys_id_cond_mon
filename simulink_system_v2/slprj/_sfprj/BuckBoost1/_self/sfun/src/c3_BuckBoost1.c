/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c3_BuckBoost1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[51] = { "sampling_time", "offset",
  "OFFSET_ON_START_abs", "OFFSET_ON_END_rel", "OFFSET_OFF_START_rel",
  "OFFSET_OFF_END_abs", "beta", "u", "w", "wi", "uu", "wu", "noiseAmp", "rms",
  "rmsu", "a", "b", "c", "nargin", "nargout", "start", "t", "duty", "v_out",
  "i_in", "w0in", "w1in", "Capin", "wi0in", "wi1in", "wu0in", "wu1in", "wu2in",
  "ESRin", "t0in", "y", "e", "w0", "w1", "Capout", "yi", "ei", "wi0", "wi1",
  "yu", "eu", "wu0", "wu1", "wu2", "ESRout", "t0" };

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
  const mxArray *c3_t0, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[54]);
static real_T c3_mpower(SFc3_BuckBoost1InstanceStruct *chartInstance, real_T
  c3_a);
static void c3_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_check_forloop_overflow_error(SFc3_BuckBoost1InstanceStruct
  *chartInstance);
static real_T c3_rand(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_d_state[625]);
static void c3_twister_state_vector(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625]);
static void c3_b_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T *c3_r);
static void c3_eml_error(SFc3_BuckBoost1InstanceStruct *chartInstance);
static void c3_b_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_f_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier);
static uint32_T c3_g_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint32_T c3_h_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier);
static uint32_T c3_i_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_d_state, const char_T *c3_identifier, uint32_T c3_y[625]);
static void c3_k_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, uint32_T c3_y[625]);
static void c3_l_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_d_state, const char_T *c3_identifier, uint32_T c3_y[2]);
static void c3_m_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, uint32_T c3_y[2]);
static uint8_T c3_n_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_BuckBoost1, const char_T
  *c3_identifier);
static uint8_T c3_o_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_twister_state_vector(SFc3_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed);
static real_T c3_c_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c3_d_state[625]);
static void init_dsm_address_info(SFc3_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_method_not_empty = FALSE;
  chartInstance->c3_state_not_empty = FALSE;
  chartInstance->c3_b_state_not_empty = FALSE;
  chartInstance->c3_c_state_not_empty = FALSE;
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
  real_T c3_j_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_k_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_l_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  real_T c3_m_hoistedGlobal;
  real_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  real_T c3_n_hoistedGlobal;
  real_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  real_T c3_o_hoistedGlobal;
  real_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  real_T c3_p_hoistedGlobal;
  real_T c3_p_u;
  const mxArray *c3_q_y = NULL;
  uint32_T c3_q_hoistedGlobal;
  uint32_T c3_q_u;
  const mxArray *c3_r_y = NULL;
  uint32_T c3_r_hoistedGlobal;
  uint32_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  int32_T c3_i0;
  uint32_T c3_s_u[625];
  const mxArray *c3_t_y = NULL;
  int32_T c3_i1;
  uint32_T c3_t_u[2];
  const mxArray *c3_u_y = NULL;
  uint8_T c3_s_hoistedGlobal;
  uint8_T c3_u_u;
  const mxArray *c3_v_y = NULL;
  real_T *c3_Capout;
  real_T *c3_ESRout;
  real_T *c3_e;
  real_T *c3_ei;
  real_T *c3_eu;
  real_T *c3_t0;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_wi0;
  real_T *c3_wi1;
  real_T *c3_wu0;
  real_T *c3_wu1;
  real_T *c3_wu2;
  real_T *c3_w_y;
  real_T *c3_yi;
  real_T *c3_yu;
  c3_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_w_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(21), FALSE);
  c3_hoistedGlobal = *c3_Capout;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_ESRout;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_e;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_ei;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_eu;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_t0;
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
  c3_i_hoistedGlobal = *c3_wi0;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *c3_wi1;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = *c3_wu0;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = *c3_wu1;
  c3_l_u = c3_l_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = *c3_wu2;
  c3_m_u = c3_m_hoistedGlobal;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_n_hoistedGlobal = *c3_w_y;
  c3_n_u = c3_n_hoistedGlobal;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_o_hoistedGlobal = *c3_yi;
  c3_o_u = c3_o_hoistedGlobal;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_p_hoistedGlobal = *c3_yu;
  c3_p_u = c3_p_hoistedGlobal;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_q_hoistedGlobal = chartInstance->c3_method;
  c3_q_u = c3_q_hoistedGlobal;
  c3_r_y = NULL;
  if (!chartInstance->c3_method_not_empty) {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_hoistedGlobal = chartInstance->c3_state;
  c3_r_u = c3_r_hoistedGlobal;
  c3_s_y = NULL;
  if (!chartInstance->c3_state_not_empty) {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 17, c3_s_y);
  for (c3_i0 = 0; c3_i0 < 625; c3_i0++) {
    c3_s_u[c3_i0] = chartInstance->c3_c_state[c3_i0];
  }

  c3_t_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", c3_s_u, 7, 0U, 1U, 0U, 1, 625),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 18, c3_t_y);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_t_u[c3_i1] = chartInstance->c3_b_state[c3_i1];
  }

  c3_u_y = NULL;
  if (!chartInstance->c3_b_state_not_empty) {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", c3_t_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_s_hoistedGlobal = chartInstance->c3_is_active_c3_BuckBoost1;
  c3_u_u = c3_s_hoistedGlobal;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_u_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_BuckBoost1(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  uint32_T c3_uv0[625];
  int32_T c3_i2;
  uint32_T c3_uv1[2];
  int32_T c3_i3;
  real_T *c3_Capout;
  real_T *c3_ESRout;
  real_T *c3_e;
  real_T *c3_ei;
  real_T *c3_eu;
  real_T *c3_t0;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_wi0;
  real_T *c3_wi1;
  real_T *c3_wu0;
  real_T *c3_wu1;
  real_T *c3_wu2;
  real_T *c3_y;
  real_T *c3_yi;
  real_T *c3_yu;
  c3_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_Capout = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "Capout");
  *c3_ESRout = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    1)), "ESRout");
  *c3_e = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "e");
  *c3_ei = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "ei");
  *c3_eu = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
    "eu");
  *c3_t0 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
    "t0");
  *c3_w0 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
    "w0");
  *c3_w1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
    "w1");
  *c3_wi0 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)),
    "wi0");
  *c3_wi1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 9)),
    "wi1");
  *c3_wu0 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    10)), "wu0");
  *c3_wu1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    11)), "wu1");
  *c3_wu2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    12)), "wu2");
  *c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
    "y");
  *c3_yi = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
    "yi");
  *c3_yu = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 15)),
    "yu");
  chartInstance->c3_method = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 16)), "method");
  chartInstance->c3_state = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 17)), "state");
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 18)),
                        "state", c3_uv0);
  for (c3_i2 = 0; c3_i2 < 625; c3_i2++) {
    chartInstance->c3_c_state[c3_i2] = c3_uv0[c3_i2];
  }

  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 19)),
                        "state", c3_uv1);
  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    chartInstance->c3_b_state[c3_i3] = c3_uv1[c3_i3];
  }

  chartInstance->c3_is_active_c3_BuckBoost1 = c3_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 20)),
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
  real_T *c3_start;
  real_T *c3_t;
  real_T *c3_duty;
  real_T *c3_v_out;
  real_T *c3_i_in;
  real_T *c3_w0in;
  real_T *c3_w1in;
  real_T *c3_Capin;
  real_T *c3_y;
  real_T *c3_e;
  real_T *c3_w0;
  real_T *c3_w1;
  real_T *c3_Capout;
  real_T *c3_wi0in;
  real_T *c3_wi1in;
  real_T *c3_wu0in;
  real_T *c3_wu1in;
  real_T *c3_wu2in;
  real_T *c3_ESRin;
  real_T *c3_t0in;
  real_T *c3_yi;
  real_T *c3_ei;
  real_T *c3_wi0;
  real_T *c3_wi1;
  real_T *c3_yu;
  real_T *c3_eu;
  real_T *c3_wu0;
  real_T *c3_wu1;
  real_T *c3_wu2;
  real_T *c3_ESRout;
  real_T *c3_t0;
  c3_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c3_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c3_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_start, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_t, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_duty, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_v_out, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_i_in, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_w0in, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_w1in, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_Capin, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_y, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_e, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_w0, 10U);
  _SFD_DATA_RANGE_CHECK(*c3_w1, 11U);
  _SFD_DATA_RANGE_CHECK(*c3_Capout, 12U);
  _SFD_DATA_RANGE_CHECK(*c3_wi0in, 13U);
  _SFD_DATA_RANGE_CHECK(*c3_wi1in, 14U);
  _SFD_DATA_RANGE_CHECK(*c3_wu0in, 15U);
  _SFD_DATA_RANGE_CHECK(*c3_wu1in, 16U);
  _SFD_DATA_RANGE_CHECK(*c3_wu2in, 17U);
  _SFD_DATA_RANGE_CHECK(*c3_ESRin, 18U);
  _SFD_DATA_RANGE_CHECK(*c3_t0in, 19U);
  _SFD_DATA_RANGE_CHECK(*c3_yi, 20U);
  _SFD_DATA_RANGE_CHECK(*c3_ei, 21U);
  _SFD_DATA_RANGE_CHECK(*c3_wi0, 22U);
  _SFD_DATA_RANGE_CHECK(*c3_wi1, 23U);
  _SFD_DATA_RANGE_CHECK(*c3_yu, 24U);
  _SFD_DATA_RANGE_CHECK(*c3_eu, 25U);
  _SFD_DATA_RANGE_CHECK(*c3_wu0, 26U);
  _SFD_DATA_RANGE_CHECK(*c3_wu1, 27U);
  _SFD_DATA_RANGE_CHECK(*c3_wu2, 28U);
  _SFD_DATA_RANGE_CHECK(*c3_ESRout, 29U);
  _SFD_DATA_RANGE_CHECK(*c3_t0, 30U);
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
  real_T c3_m_hoistedGlobal;
  real_T c3_n_hoistedGlobal;
  real_T c3_o_hoistedGlobal;
  real_T c3_start;
  real_T c3_t;
  real_T c3_duty;
  real_T c3_v_out;
  real_T c3_i_in;
  real_T c3_w0in;
  real_T c3_w1in;
  real_T c3_Capin;
  real_T c3_wi0in;
  real_T c3_wi1in;
  real_T c3_wu0in;
  real_T c3_wu1in;
  real_T c3_wu2in;
  real_T c3_ESRin;
  real_T c3_t0in;
  uint32_T c3_debug_family_var_map[51];
  real_T c3_sampling_time;
  real_T c3_offset;
  real_T c3_OFFSET_ON_START_abs;
  real_T c3_OFFSET_ON_END_rel;
  real_T c3_OFFSET_OFF_START_rel;
  real_T c3_OFFSET_OFF_END_abs;
  real_T c3_beta;
  real_T c3_u[2];
  real_T c3_w[2];
  real_T c3_wi[2];
  real_T c3_uu[3];
  real_T c3_wu[3];
  real_T c3_noiseAmp;
  real_T c3_rms;
  real_T c3_rmsu;
  real_T c3_a;
  real_T c3_b;
  real_T c3_c;
  real_T c3_nargin = 15.0;
  real_T c3_nargout = 16.0;
  real_T c3_y;
  real_T c3_e;
  real_T c3_w0;
  real_T c3_w1;
  real_T c3_Capout;
  real_T c3_yi;
  real_T c3_ei;
  real_T c3_wi0;
  real_T c3_wi1;
  real_T c3_yu;
  real_T c3_eu;
  real_T c3_wu0;
  real_T c3_wu1;
  real_T c3_wu2;
  real_T c3_ESRout;
  real_T c3_t0;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_y;
  int32_T c3_i8;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  int32_T c3_i9;
  real_T c3_c_a[2];
  int32_T c3_i10;
  real_T c3_c_b[2];
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_d_b;
  real_T c3_c_y;
  real_T c3_e_b;
  real_T c3_d_y;
  real_T c3_d_a;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_B;
  real_T c3_e_y;
  real_T c3_f_y;
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_c_x;
  real_T c3_g_y;
  real_T c3_d_x;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_c_A;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_j_y;
  real_T c3_e_a;
  real_T c3_f_a;
  real_T c3_k_y;
  real_T c3_d_A;
  real_T c3_g_x;
  real_T c3_h_x;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_c_k;
  int32_T c3_d_k;
  real_T c3_f_b;
  real_T c3_l_y;
  real_T c3_g_b;
  real_T c3_m_y;
  real_T c3_g_a;
  int32_T c3_i17;
  int32_T c3_i18;
  real_T c3_c_B;
  real_T c3_n_y;
  real_T c3_o_y;
  int32_T c3_i19;
  int32_T c3_i20;
  real_T c3_h_a;
  real_T c3_p_y;
  real_T c3_i_a;
  real_T c3_h_b;
  real_T c3_q_y;
  real_T c3_e_A;
  real_T c3_i_x;
  real_T c3_j_x;
  int32_T c3_i21;
  real_T c3_j_a[3];
  int32_T c3_i22;
  real_T c3_i_b[3];
  int32_T c3_e_k;
  int32_T c3_f_k;
  real_T c3_j_b;
  real_T c3_r_y;
  real_T c3_k_b;
  real_T c3_s_y;
  real_T c3_k_a;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_d_B;
  real_T c3_t_y;
  real_T c3_u_y;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_l_b;
  real_T c3_v_y;
  real_T c3_l_a;
  real_T c3_w_y;
  real_T c3_f_A;
  real_T c3_e_B;
  real_T c3_k_x;
  real_T c3_x_y;
  real_T c3_l_x;
  real_T c3_y_y;
  real_T c3_m_b;
  real_T c3_ab_y;
  real_T c3_g_A;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_bb_y;
  real_T c3_h_A;
  real_T c3_f_B;
  real_T c3_o_x;
  real_T c3_cb_y;
  real_T c3_p_x;
  real_T c3_db_y;
  real_T c3_eb_y;
  real_T c3_i_A;
  real_T c3_g_B;
  real_T c3_q_x;
  real_T c3_fb_y;
  real_T c3_r_x;
  real_T c3_gb_y;
  real_T c3_m_a;
  real_T c3_n_b;
  real_T c3_hb_y;
  real_T c3_j_A;
  real_T c3_h_B;
  real_T c3_s_x;
  real_T c3_ib_y;
  real_T c3_t_x;
  real_T c3_jb_y;
  real_T c3_kb_y;
  real_T c3_o_b;
  real_T c3_lb_y;
  real_T c3_k_A;
  real_T c3_i_B;
  real_T c3_u_x;
  real_T c3_mb_y;
  real_T c3_v_x;
  real_T c3_nb_y;
  real_T c3_ob_y;
  real_T c3_l_A;
  real_T c3_j_B;
  real_T c3_w_x;
  real_T c3_pb_y;
  real_T c3_x_x;
  real_T c3_qb_y;
  real_T c3_rb_y;
  real_T c3_m_A;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_sb_y;
  real_T c3_n_A;
  real_T c3_k_B;
  real_T c3_bb_x;
  real_T c3_tb_y;
  real_T c3_cb_x;
  real_T c3_ub_y;
  real_T *c3_b_start;
  real_T *c3_b_t;
  real_T *c3_b_duty;
  real_T *c3_b_v_out;
  real_T *c3_b_i_in;
  real_T *c3_b_w0in;
  real_T *c3_b_w1in;
  real_T *c3_b_Capin;
  real_T *c3_b_wi0in;
  real_T *c3_b_wi1in;
  real_T *c3_b_wu0in;
  real_T *c3_b_wu1in;
  real_T *c3_b_wu2in;
  real_T *c3_b_ESRin;
  real_T *c3_b_t0in;
  real_T *c3_vb_y;
  real_T *c3_b_e;
  real_T *c3_b_w0;
  real_T *c3_b_w1;
  real_T *c3_b_Capout;
  real_T *c3_b_yi;
  real_T *c3_b_ei;
  real_T *c3_b_wi0;
  real_T *c3_b_wi1;
  real_T *c3_b_yu;
  real_T *c3_b_eu;
  real_T *c3_b_wu0;
  real_T *c3_b_wu1;
  real_T *c3_b_wu2;
  real_T *c3_b_ESRout;
  real_T *c3_b_t0;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  c3_b_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_b_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_b_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_b_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_b_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_b_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_b_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_b_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_b_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_b_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_b_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_b_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c3_b_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c3_b_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_b_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_b_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_b_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_vb_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_start;
  c3_b_hoistedGlobal = *c3_b_t;
  c3_c_hoistedGlobal = *c3_b_duty;
  c3_d_hoistedGlobal = *c3_b_v_out;
  c3_e_hoistedGlobal = *c3_b_i_in;
  c3_f_hoistedGlobal = *c3_b_w0in;
  c3_g_hoistedGlobal = *c3_b_w1in;
  c3_h_hoistedGlobal = *c3_b_Capin;
  c3_i_hoistedGlobal = *c3_b_wi0in;
  c3_j_hoistedGlobal = *c3_b_wi1in;
  c3_k_hoistedGlobal = *c3_b_wu0in;
  c3_l_hoistedGlobal = *c3_b_wu1in;
  c3_m_hoistedGlobal = *c3_b_wu2in;
  c3_n_hoistedGlobal = *c3_b_ESRin;
  c3_o_hoistedGlobal = *c3_b_t0in;
  c3_start = c3_hoistedGlobal;
  c3_t = c3_b_hoistedGlobal;
  c3_duty = c3_c_hoistedGlobal;
  c3_v_out = c3_d_hoistedGlobal;
  c3_i_in = c3_e_hoistedGlobal;
  c3_w0in = c3_f_hoistedGlobal;
  c3_w1in = c3_g_hoistedGlobal;
  c3_Capin = c3_h_hoistedGlobal;
  c3_wi0in = c3_i_hoistedGlobal;
  c3_wi1in = c3_j_hoistedGlobal;
  c3_wu0in = c3_k_hoistedGlobal;
  c3_wu1in = c3_l_hoistedGlobal;
  c3_wu2in = c3_m_hoistedGlobal;
  c3_ESRin = c3_n_hoistedGlobal;
  c3_t0in = c3_o_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 51U, 51U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_sampling_time, 0U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_offset, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_ON_START_abs, 2U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_ON_END_rel, 3U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_OFF_START_rel, 4U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_OFFSET_OFF_END_abs, 5U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_beta, 6U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_u, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_w, 8U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_wi, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_uu, 10U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_wu, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_noiseAmp, 12U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_rms, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_rmsu, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_a, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_c, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 18U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 19U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_start, 20U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_t, 21U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_duty, 22U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_v_out, 23U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_i_in, 24U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_w0in, 25U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_w1in, 26U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Capin, 27U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_wi0in, 28U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_wi1in, 29U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_wu0in, 30U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_wu1in, 31U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_wu2in, 32U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_ESRin, 33U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_t0in, 34U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_y, 35U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_e, 36U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w0, 37U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w1, 38U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Capout, 39U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_yi, 40U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ei, 41U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_wi0, 42U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_wi1, 43U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_yu, 44U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_eu, 45U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_wu0, 46U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_wu1, 47U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_wu2, 48U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ESRout, 49U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_t0, 50U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_sampling_time = 1.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_offset = c3_t - c3_duty;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_OFFSET_ON_START_abs = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_OFFSET_ON_END_rel = -5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_OFFSET_OFF_START_rel = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_OFFSET_OFF_END_abs = 95.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_beta = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_e = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    c3_u[c3_i4] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_u[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_u[1] = c3_t;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_w[c3_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  c3_w[0] = c3_w0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  c3_w[1] = c3_w1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  c3_w0 = c3_w0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  c3_w1 = c3_w1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
  c3_yi = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  c3_ei = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_wi[c3_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
  c3_wi[0] = c3_wi0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
  c3_wi[1] = c3_wi1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
  c3_wi0 = c3_wi0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
  c3_wi1 = c3_wi1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
  c3_yu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 68);
  c3_eu = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 71);
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_uu[c3_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
  c3_uu[0] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
  c3_uu[1] = c3_t;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 74);
  c3_b_a = c3_t;
  c3_b_b = c3_t;
  c3_b_y = c3_b_a * c3_b_b;
  c3_uu[2] = c3_b_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 77);
  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    c3_wu[c3_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
  c3_wu[0] = c3_wu0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 79);
  c3_wu[1] = c3_wu1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 80);
  c3_wu[2] = c3_wu2in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
  c3_wu0 = c3_wu0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
  c3_wu1 = c3_wu1in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
  c3_wu2 = c3_wu2in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 90);
  c3_Capout = c3_Capin;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 91);
  c3_ESRout = c3_ESRin;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 92);
  c3_t0 = c3_t0in;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
  c3_noiseAmp = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 98);
  if (CV_EML_IF(0, 1, 0, c3_start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 100);
    guard5 = FALSE;
    if (CV_EML_COND(0, 1, 0, c3_t > c3_OFFSET_ON_START_abs)) {
      if (CV_EML_COND(0, 1, 1, c3_offset < c3_OFFSET_ON_END_rel)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 103);
        if (CV_EML_IF(0, 1, 2, c3_t <= c3_OFFSET_ON_START_abs + 2.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 104);
          c3_t0 = c3_t;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 108);
        c3_u[1] = c3_t - c3_t0;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
        c3_A = c3_mpower(chartInstance, c3_u[0]) + c3_mpower(chartInstance,
          c3_u[1]);
        c3_x = c3_A;
        c3_b_x = c3_x;
        c3_rms = c3_b_x / 2.0;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 110);
        for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
          c3_c_a[c3_i9] = c3_w[c3_i9];
        }

        for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
          c3_c_b[c3_i10] = c3_u[c3_i10];
        }

        c3_eml_scalar_eg(chartInstance);
        c3_eml_scalar_eg(chartInstance);
        c3_y = 0.0;
        c3_check_forloop_overflow_error(chartInstance);
        for (c3_k = 1; c3_k < 3; c3_k++) {
          c3_b_k = c3_k;
          c3_y += c3_c_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 2, 1, 0) - 1] *
            c3_c_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c3_b_k), 1, 2, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
        c3_d_b = c3_rand(chartInstance);
        c3_c_y = 0.0 * c3_d_b;
        c3_e = (c3_v_out + c3_c_y) - c3_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 114);
        c3_e_b = c3_e;
        c3_d_y = 0.5 * c3_e_b;
        c3_d_a = c3_d_y;
        for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
          c3_c_b[c3_i11] = c3_u[c3_i11];
        }

        for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
          c3_c_b[c3_i12] *= c3_d_a;
        }

        c3_B = c3_rms;
        c3_e_y = c3_B;
        c3_f_y = c3_e_y;
        for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
          c3_c_b[c3_i13] /= c3_f_y;
        }

        for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
          c3_w[c3_i14] += c3_c_b[c3_i14];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
        c3_w0 = c3_w[0];
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
        c3_w1 = c3_w[1];
      } else {
        guard5 = TRUE;
      }
    } else {
      guard5 = TRUE;
    }

    if (guard5 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 120);
    guard4 = FALSE;
    if (CV_EML_COND(0, 1, 2, c3_offset >= c3_OFFSET_ON_END_rel)) {
      if (CV_EML_COND(0, 1, 3, c3_offset <= c3_OFFSET_ON_END_rel + 1.0)) {
        CV_EML_MCDC(0, 1, 1, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 121);
        c3_b_A = -c3_w0;
        c3_b_B = c3_w1;
        c3_c_x = c3_b_A;
        c3_g_y = c3_b_B;
        c3_d_x = c3_c_x;
        c3_h_y = c3_g_y;
        c3_i_y = c3_d_x / c3_h_y;
        c3_c_A = c3_i_y;
        c3_e_x = c3_c_A;
        c3_f_x = c3_e_x;
        c3_j_y = c3_f_x / 30.0;
        c3_e_a = c3_j_y;
        c3_Capout = c3_e_a * 1.0E-5;
      } else {
        guard4 = TRUE;
      }
    } else {
      guard4 = TRUE;
    }

    if (guard4 == TRUE) {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 126);
    guard2 = FALSE;
    if (CV_EML_COND(0, 1, 4, c3_offset > c3_OFFSET_OFF_START_rel)) {
      if (CV_EML_COND(0, 1, 5, c3_t < c3_OFFSET_OFF_END_abs)) {
        CV_EML_MCDC(0, 1, 2, TRUE);
        CV_EML_IF(0, 1, 4, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 128U);
        guard3 = FALSE;
        if (CV_EML_COND(0, 1, 6, c3_offset > c3_OFFSET_OFF_START_rel)) {
          if (CV_EML_COND(0, 1, 7, c3_offset <= c3_OFFSET_OFF_START_rel + 2.0))
          {
            CV_EML_MCDC(0, 1, 3, TRUE);
            CV_EML_IF(0, 1, 5, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 129U);
            c3_t0 = c3_t;
          } else {
            guard3 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }

        if (guard3 == TRUE) {
          CV_EML_MCDC(0, 1, 3, FALSE);
          CV_EML_IF(0, 1, 5, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 132U);
          c3_f_a = c3_t - c3_t0;
          c3_k_y = c3_f_a * 1.0E-5;
          c3_u[1] = c3_k_y;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 133U);
          c3_d_A = c3_mpower(chartInstance, c3_u[0]) + c3_mpower(chartInstance,
            c3_u[1]);
          c3_g_x = c3_d_A;
          c3_h_x = c3_g_x;
          c3_rms = c3_h_x / 2.0;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 134U);
          for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
            c3_c_a[c3_i15] = c3_wi[c3_i15];
          }

          for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
            c3_c_b[c3_i16] = c3_u[c3_i16];
          }

          c3_eml_scalar_eg(chartInstance);
          c3_eml_scalar_eg(chartInstance);
          c3_yi = 0.0;
          c3_check_forloop_overflow_error(chartInstance);
          for (c3_c_k = 1; c3_c_k < 3; c3_c_k++) {
            c3_d_k = c3_c_k;
            c3_yi += c3_c_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c3_d_k), 1, 2, 1, 0) - 1] *
              c3_c_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c3_d_k), 1, 2, 1, 0) - 1];
          }

          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 136U);
          c3_f_b = c3_rand(chartInstance);
          c3_l_y = 0.0 * c3_f_b;
          c3_ei = (c3_i_in + c3_l_y) - c3_yi;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
          c3_g_b = c3_ei;
          c3_m_y = 0.5 * c3_g_b;
          c3_g_a = c3_m_y;
          for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
            c3_c_b[c3_i17] = c3_u[c3_i17];
          }

          for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
            c3_c_b[c3_i18] *= c3_g_a;
          }

          c3_c_B = c3_rms;
          c3_n_y = c3_c_B;
          c3_o_y = c3_n_y;
          for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
            c3_c_b[c3_i19] /= c3_o_y;
          }

          for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
            c3_wi[c3_i20] += c3_c_b[c3_i20];
          }

          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
          c3_wi0 = c3_wi[0];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
          c3_wi1 = c3_wi[1];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
          c3_h_a = c3_t - c3_t0;
          c3_p_y = c3_h_a * 1.0E-5;
          c3_uu[1] = c3_p_y;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 145U);
          c3_i_a = c3_uu[1];
          c3_h_b = c3_uu[1];
          c3_q_y = c3_i_a * c3_h_b;
          c3_uu[2] = c3_q_y;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 146U);
          c3_e_A = (c3_mpower(chartInstance, c3_uu[0]) + c3_mpower(chartInstance,
                     c3_uu[1])) + c3_mpower(chartInstance, c3_uu[2]);
          c3_i_x = c3_e_A;
          c3_j_x = c3_i_x;
          c3_rmsu = c3_j_x / 3.0;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 147U);
          for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
            c3_j_a[c3_i21] = c3_wu[c3_i21];
          }

          for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
            c3_i_b[c3_i22] = c3_uu[c3_i22];
          }

          c3_b_eml_scalar_eg(chartInstance);
          c3_b_eml_scalar_eg(chartInstance);
          c3_yu = 0.0;
          c3_check_forloop_overflow_error(chartInstance);
          for (c3_e_k = 1; c3_e_k < 4; c3_e_k++) {
            c3_f_k = c3_e_k;
            c3_yu += c3_j_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c3_f_k), 1, 3, 1, 0) - 1] *
              c3_i_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c3_f_k), 1, 3, 1, 0) - 1];
          }

          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 149U);
          c3_j_b = c3_rand(chartInstance);
          c3_r_y = 0.0 * c3_j_b;
          c3_eu = (c3_v_out + c3_r_y) - c3_yu;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 151U);
          c3_k_b = c3_eu;
          c3_s_y = 0.5 * c3_k_b;
          c3_k_a = c3_s_y;
          for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
            c3_i_b[c3_i23] = c3_uu[c3_i23];
          }

          for (c3_i24 = 0; c3_i24 < 3; c3_i24++) {
            c3_i_b[c3_i24] *= c3_k_a;
          }

          c3_d_B = c3_rmsu;
          c3_t_y = c3_d_B;
          c3_u_y = c3_t_y;
          for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
            c3_i_b[c3_i25] /= c3_u_y;
          }

          for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
            c3_wu[c3_i26] += c3_i_b[c3_i26];
          }

          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 152U);
          c3_wu0 = c3_wu[0];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 152U);
          c3_wu1 = c3_wu[1];
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 152U);
          c3_wu2 = c3_wu[2];
        }
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 1, 2, FALSE);
      CV_EML_IF(0, 1, 4, FALSE);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 157U);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 8, c3_t >= c3_OFFSET_OFF_END_abs)) {
      if (CV_EML_COND(0, 1, 9, c3_t <= c3_OFFSET_OFF_END_abs + 1.0)) {
        CV_EML_MCDC(0, 1, 4, TRUE);
        CV_EML_IF(0, 1, 6, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 158U);
        c3_l_b = c3_wu2;
        c3_v_y = 2.0 * c3_l_b;
        c3_l_a = c3_wi1;
        c3_w_y = c3_l_a * 30.0;
        c3_f_A = c3_v_y;
        c3_e_B = c3_w_y - c3_wu1;
        c3_k_x = c3_f_A;
        c3_x_y = c3_e_B;
        c3_l_x = c3_k_x;
        c3_y_y = c3_x_y;
        c3_a = c3_l_x / c3_y_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 159U);
        c3_m_b = c3_wu2;
        c3_ab_y = 2.0 * c3_m_b;
        c3_g_A = c3_wu1;
        c3_m_x = c3_g_A;
        c3_n_x = c3_m_x;
        c3_bb_y = c3_n_x / 30.0;
        c3_h_A = c3_bb_y;
        c3_f_B = c3_wi1;
        c3_o_x = c3_h_A;
        c3_cb_y = c3_f_B;
        c3_p_x = c3_o_x;
        c3_db_y = c3_cb_y;
        c3_eb_y = c3_p_x / c3_db_y;
        c3_i_A = c3_ab_y;
        c3_g_B = 1.0 - c3_eb_y;
        c3_q_x = c3_i_A;
        c3_fb_y = c3_g_B;
        c3_r_x = c3_q_x;
        c3_gb_y = c3_fb_y;
        c3_b = c3_r_x / c3_gb_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 160U);
        c3_m_a = c3_wu0;
        c3_n_b = c3_a;
        c3_hb_y = c3_m_a * c3_n_b;
        c3_j_A = c3_b;
        c3_h_B = c3_a;
        c3_s_x = c3_j_A;
        c3_ib_y = c3_h_B;
        c3_t_x = c3_s_x;
        c3_jb_y = c3_ib_y;
        c3_kb_y = c3_t_x / c3_jb_y;
        c3_o_b = c3_wu2;
        c3_lb_y = 2.0 * c3_o_b;
        c3_k_A = c3_lb_y;
        c3_i_B = c3_a;
        c3_u_x = c3_k_A;
        c3_mb_y = c3_i_B;
        c3_v_x = c3_u_x;
        c3_nb_y = c3_mb_y;
        c3_ob_y = c3_v_x / c3_nb_y;
        c3_c = (c3_hb_y + c3_kb_y) - c3_ob_y;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 161U);
        c3_l_A = c3_wi0;
        c3_j_B = c3_Capin;
        c3_w_x = c3_l_A;
        c3_pb_y = c3_j_B;
        c3_x_x = c3_w_x;
        c3_qb_y = c3_pb_y;
        c3_rb_y = c3_x_x / c3_qb_y;
        c3_m_A = c3_c;
        c3_y_x = c3_m_A;
        c3_ab_x = c3_y_x;
        c3_sb_y = c3_ab_x / 30.0;
        c3_n_A = c3_rb_y - c3_c;
        c3_k_B = c3_sb_y - c3_wi1;
        c3_bb_x = c3_n_A;
        c3_tb_y = c3_k_B;
        c3_cb_x = c3_bb_x;
        c3_ub_y = c3_tb_y;
        c3_ESRout = c3_cb_x / c3_ub_y;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 4, FALSE);
      CV_EML_IF(0, 1, 6, FALSE);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -161);
  sf_debug_symbol_scope_pop();
  *c3_vb_y = c3_y;
  *c3_b_e = c3_e;
  *c3_b_w0 = c3_w0;
  *c3_b_w1 = c3_w1;
  *c3_b_Capout = c3_Capout;
  *c3_b_yi = c3_yi;
  *c3_b_ei = c3_ei;
  *c3_b_wi0 = c3_wi0;
  *c3_b_wi1 = c3_wi1;
  *c3_b_yu = c3_yu;
  *c3_b_eu = c3_eu;
  *c3_b_wu0 = c3_wu0;
  *c3_b_wu1 = c3_wu1;
  *c3_b_wu2 = c3_wu2;
  *c3_b_ESRout = c3_ESRout;
  *c3_b_t0 = c3_t0;
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
  const mxArray *c3_t0, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_t0), &c3_thisId);
  sf_mex_destroy(&c3_t0);
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
  const mxArray *c3_t0;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_t0 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_t0), &c3_thisId);
  sf_mex_destroy(&c3_t0);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i27;
  real_T c3_b_inData[3];
  int32_T c3_i28;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i27 = 0; c3_i27 < 3; c3_i27++) {
    c3_b_inData[c3_i27] = (*(real_T (*)[3])c3_inData)[c3_i27];
  }

  for (c3_i28 = 0; c3_i28 < 3; c3_i28++) {
    c3_u[c3_i28] = c3_b_inData[c3_i28];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv0[3];
  int32_T c3_i29;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i29 = 0; c3_i29 < 3; c3_i29++) {
    c3_y[c3_i29] = c3_dv0[c3_i29];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_wu;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i30;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_wu = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_wu), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_wu);
  for (c3_i30 = 0; c3_i30 < 3; c3_i30++) {
    (*(real_T (*)[3])c3_outData)[c3_i30] = c3_y[c3_i30];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i31;
  real_T c3_b_inData[2];
  int32_T c3_i32;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
    c3_b_inData[c3_i31] = (*(real_T (*)[2])c3_inData)[c3_i31];
  }

  for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
    c3_u[c3_i32] = c3_b_inData[c3_i32];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i33;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
    c3_y[c3_i33] = c3_dv1[c3_i33];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_wi;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i34;
  SFc3_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc3_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c3_wi = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_wi), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_wi);
  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    (*(real_T (*)[2])c3_outData)[c3_i34] = c3_y[c3_i34];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[54];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i35;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 54), FALSE);
  for (c3_i35 = 0; c3_i35 < 54; c3_i35++) {
    c3_r0 = &c3_info[c3_i35];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i35);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[54])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289494492U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mpower";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[1].fileTimeLo = 1286797242U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[2].name = "power";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[2].fileTimeLo = 1336500496U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[3].name = "eml_scalar_eg";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[3].fileTimeLo = 1286797196U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[4].name = "eml_scalexp_alloc";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[4].fileTimeLo = 1330583234U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[5].name = "floor";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[5].fileTimeLo = 1286797142U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[6].name = "eml_scalar_floor";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[6].fileTimeLo = 1286797126U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "";
  c3_info[7].name = "mrdivide";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[7].fileTimeLo = 1342789344U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 1319708366U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[8].name = "rdivide";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[8].fileTimeLo = 1286797244U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[9].name = "eml_div";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[9].fileTimeLo = 1313326210U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].name = "eml_index_class";
  c3_info[10].dominantType = "";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[10].fileTimeLo = 1323145378U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].name = "eml_scalar_eg";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[11].fileTimeLo = 1286797196U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[12].name = "eml_xdotu";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[12].fileTimeLo = 1299051572U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[13].name = "eml_blas_inline";
  c3_info[13].dominantType = "";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[13].fileTimeLo = 1299051568U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[14].name = "eml_xdot";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[14].fileTimeLo = 1299051572U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[15].name = "eml_blas_inline";
  c3_info[15].dominantType = "";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[15].fileTimeLo = 1299051568U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[16].name = "eml_index_class";
  c3_info[16].dominantType = "";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[16].fileTimeLo = 1323145378U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[17].name = "eml_refblas_xdot";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[17].fileTimeLo = 1299051572U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[18].name = "eml_refblas_xdotx";
  c3_info[18].dominantType = "char";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[18].fileTimeLo = 1299051574U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[19].name = "eml_scalar_eg";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[19].fileTimeLo = 1286797196U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[20].name = "eml_index_class";
  c3_info[20].dominantType = "";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[20].fileTimeLo = 1323145378U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[21].name = "eml_index_minus";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[21].fileTimeLo = 1286797178U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[22].name = "eml_index_class";
  c3_info[22].dominantType = "";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[22].fileTimeLo = 1323145378U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[23].name = "eml_index_times";
  c3_info[23].dominantType = "coder.internal.indexInt";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[23].fileTimeLo = 1286797180U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[24].name = "eml_index_class";
  c3_info[24].dominantType = "";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[24].fileTimeLo = 1323145378U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[25].name = "eml_index_plus";
  c3_info[25].dominantType = "coder.internal.indexInt";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[25].fileTimeLo = 1286797178U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[26].name = "eml_index_class";
  c3_info[26].dominantType = "";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[26].fileTimeLo = 1323145378U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[27].name = "eml_int_forloop_overflow_check";
  c3_info[27].dominantType = "";
  c3_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[27].fileTimeLo = 1332143472U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[28].name = "intmax";
  c3_info[28].dominantType = "char";
  c3_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[28].fileTimeLo = 1311233716U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context = "";
  c3_info[29].name = "rand";
  c3_info[29].dominantType = "";
  c3_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c3_info[29].fileTimeLo = 1313326222U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c3_info[30].name = "eml_is_rand_extrinsic";
  c3_info[30].dominantType = "";
  c3_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m";
  c3_info[30].fileTimeLo = 1334049890U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c3_info[31].name = "eml_rand";
  c3_info[31].dominantType = "char";
  c3_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c3_info[31].fileTimeLo = 1313326220U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c3_info[32].name = "eml_rand_str2id";
  c3_info[32].dominantType = "char";
  c3_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c3_info[32].fileTimeLo = 1313326222U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c3_info[33].name = "eml_rand_mcg16807_stateful";
  c3_info[33].dominantType = "char";
  c3_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c3_info[33].fileTimeLo = 1313326220U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c3_info[34].name = "eml_rand_mcg16807";
  c3_info[34].dominantType = "char";
  c3_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c3_info[34].fileTimeLo = 1313326220U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c3_info[35].name = "eml_rand_mcg16807";
  c3_info[35].dominantType = "uint32";
  c3_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c3_info[35].fileTimeLo = 1313326220U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandu";
  c3_info[36].name = "mtimes";
  c3_info[36].dominantType = "double";
  c3_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[36].fileTimeLo = 1289494492U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c3_info[37].name = "eml_rand_shr3cong_stateful";
  c3_info[37].dominantType = "char";
  c3_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c3_info[37].fileTimeLo = 1313326222U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c3_info[38].name = "eml_rand_shr3cong";
  c3_info[38].dominantType = "char";
  c3_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c3_info[38].fileTimeLo = 1313326220U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c3_info[39].name = "eml_rand_shr3cong";
  c3_info[39].dominantType = "uint32";
  c3_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c3_info[39].fileTimeLo = 1313326220U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandu";
  c3_info[40].name = "mtimes";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[40].fileTimeLo = 1289494492U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c3_info[41].name = "eml_rand_mt19937ar_stateful";
  c3_info[41].dominantType = "char";
  c3_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c3_info[41].fileTimeLo = 1313326220U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
  c3_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c3_info[42].name = "eml_rand_mt19937ar";
  c3_info[42].dominantType = "char";
  c3_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c3_info[42].fileTimeLo = 1313326220U;
  c3_info[42].fileTimeHi = 0U;
  c3_info[42].mFileTimeLo = 0U;
  c3_info[42].mFileTimeHi = 0U;
  c3_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c3_info[43].name = "eml_rand_mt19937ar";
  c3_info[43].dominantType = "uint32";
  c3_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c3_info[43].fileTimeLo = 1313326220U;
  c3_info[43].fileTimeHi = 0U;
  c3_info[43].mFileTimeLo = 0U;
  c3_info[43].mFileTimeHi = 0U;
  c3_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c3_info[44].name = "eps";
  c3_info[44].dominantType = "";
  c3_info[44].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[44].fileTimeLo = 1326702796U;
  c3_info[44].fileTimeHi = 0U;
  c3_info[44].mFileTimeLo = 0U;
  c3_info[44].mFileTimeHi = 0U;
  c3_info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[45].name = "eml_eps";
  c3_info[45].dominantType = "char";
  c3_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[45].fileTimeLo = 1326702796U;
  c3_info[45].fileTimeHi = 0U;
  c3_info[45].mFileTimeLo = 0U;
  c3_info[45].mFileTimeHi = 0U;
  c3_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[46].name = "eml_float_model";
  c3_info[46].dominantType = "char";
  c3_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[46].fileTimeLo = 1326702796U;
  c3_info[46].fileTimeHi = 0U;
  c3_info[46].mFileTimeLo = 0U;
  c3_info[46].mFileTimeHi = 0U;
  c3_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c3_info[47].name = "isequal";
  c3_info[47].dominantType = "double";
  c3_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[47].fileTimeLo = 1286797158U;
  c3_info[47].fileTimeHi = 0U;
  c3_info[47].mFileTimeLo = 0U;
  c3_info[47].mFileTimeHi = 0U;
  c3_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[48].name = "eml_isequal_core";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c3_info[48].fileTimeLo = 1286797186U;
  c3_info[48].fileTimeHi = 0U;
  c3_info[48].mFileTimeLo = 0U;
  c3_info[48].mFileTimeHi = 0U;
  c3_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c3_info[49].name = "isnan";
  c3_info[49].dominantType = "double";
  c3_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[49].fileTimeLo = 1286797160U;
  c3_info[49].fileTimeHi = 0U;
  c3_info[49].mFileTimeLo = 0U;
  c3_info[49].mFileTimeHi = 0U;
  c3_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c3_info[50].name = "mtimes";
  c3_info[50].dominantType = "double";
  c3_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[50].fileTimeLo = 1289494492U;
  c3_info[50].fileTimeHi = 0U;
  c3_info[50].mFileTimeLo = 0U;
  c3_info[50].mFileTimeHi = 0U;
  c3_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c3_info[51].name = "eml_index_class";
  c3_info[51].dominantType = "";
  c3_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[51].fileTimeLo = 1323145378U;
  c3_info[51].fileTimeHi = 0U;
  c3_info[51].mFileTimeLo = 0U;
  c3_info[51].mFileTimeHi = 0U;
  c3_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c3_info[52].name = "eml_index_plus";
  c3_info[52].dominantType = "double";
  c3_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[52].fileTimeLo = 1286797178U;
  c3_info[52].fileTimeHi = 0U;
  c3_info[52].mFileTimeLo = 0U;
  c3_info[52].mFileTimeHi = 0U;
  c3_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c3_info[53].name = "eml_error";
  c3_info[53].dominantType = "char";
  c3_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[53].fileTimeLo = 1305296400U;
  c3_info[53].fileTimeHi = 0U;
  c3_info[53].mFileTimeLo = 0U;
  c3_info[53].mFileTimeHi = 0U;
}

static real_T c3_mpower(SFc3_BuckBoost1InstanceStruct *chartInstance, real_T
  c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_ak = c3_c_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

static void c3_check_forloop_overflow_error(SFc3_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static real_T c3_rand(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
  real_T c3_r;
  uint32_T c3_hoistedGlobal;
  uint32_T c3_d_state;
  uint32_T c3_e_state;
  uint32_T c3_s;
  uint32_T c3_u0;
  uint32_T c3_hi;
  uint32_T c3_lo;
  uint32_T c3_test1;
  uint32_T c3_test2;
  uint32_T c3_f_state;
  real_T c3_a;
  real_T c3_b_r;
  real_T c3_d1;
  int32_T c3_i36;
  uint32_T c3_icng;
  uint32_T c3_jsr;
  uint32_T c3_u1;
  uint32_T c3_u2;
  uint32_T c3_ui;
  uint32_T c3_b_ui;
  real_T c3_b_a;
  real_T c3_c_r;
  real_T c3_d2;
  uint32_T c3_uv2[625];
  int32_T c3_i37;
  int32_T c3_i38;
  uint32_T c3_g_state[625];
  real_T c3_d3;
  int32_T c3_i39;
  if (!chartInstance->c3_method_not_empty) {
    chartInstance->c3_method = 7U;
    chartInstance->c3_method_not_empty = TRUE;
  }

  if (chartInstance->c3_method == 4U) {
    if (!chartInstance->c3_state_not_empty) {
      chartInstance->c3_state = 1144108930U;
      chartInstance->c3_state_not_empty = TRUE;
    }

    c3_hoistedGlobal = chartInstance->c3_state;
    c3_d_state = c3_hoistedGlobal;
    c3_e_state = c3_d_state;
    c3_s = c3_e_state;
    c3_u0 = 127773U;
    if (c3_u0 == 0) {
      c3_hi = MAX_uint32_T;
    } else {
      c3_hi = c3_s / c3_u0;
    }

    c3_lo = c3_s - c3_hi * 127773U;
    c3_test1 = 16807U * c3_lo;
    c3_test2 = 2836U * c3_hi;
    if (c3_test1 < c3_test2) {
      c3_f_state = (c3_test1 - c3_test2) + 2147483647U;
    } else {
      c3_f_state = c3_test1 - c3_test2;
    }

    c3_a = (real_T)c3_f_state;
    c3_b_r = c3_a * 4.6566128752457969E-10;
    c3_e_state = c3_f_state;
    c3_d1 = c3_b_r;
    chartInstance->c3_state = c3_e_state;
    c3_r = c3_d1;
  } else if (chartInstance->c3_method == 5U) {
    if (!chartInstance->c3_b_state_not_empty) {
      for (c3_i36 = 0; c3_i36 < 2; c3_i36++) {
        chartInstance->c3_b_state[c3_i36] = 362436069U + 158852560U * (uint32_T)
          c3_i36;
      }

      chartInstance->c3_b_state_not_empty = TRUE;
    }

    c3_icng = chartInstance->c3_b_state[0];
    c3_jsr = chartInstance->c3_b_state[1];
    c3_u1 = c3_jsr;
    c3_u2 = c3_icng;
    c3_u2 = 69069U * c3_u2 + 1234567U;
    c3_u1 ^= c3_u1 << 13U;
    c3_u1 ^= c3_u1 >> 17U;
    c3_u1 ^= c3_u1 << 5U;
    c3_ui = c3_u2 + c3_u1;
    chartInstance->c3_b_state[0] = c3_u2;
    chartInstance->c3_b_state[1] = c3_u1;
    c3_b_ui = c3_ui;
    c3_b_a = (real_T)c3_b_ui;
    c3_c_r = c3_b_a * 2.328306436538696E-10;
    c3_d2 = c3_c_r;
    c3_r = c3_d2;
  } else {
    if (!chartInstance->c3_c_state_not_empty) {
      c3_eml_rand_mt19937ar(chartInstance, c3_uv2);
      for (c3_i37 = 0; c3_i37 < 625; c3_i37++) {
        chartInstance->c3_c_state[c3_i37] = c3_uv2[c3_i37];
      }

      chartInstance->c3_c_state_not_empty = TRUE;
    }

    for (c3_i38 = 0; c3_i38 < 625; c3_i38++) {
      c3_g_state[c3_i38] = chartInstance->c3_c_state[c3_i38];
    }

    c3_d3 = c3_c_eml_rand_mt19937ar(chartInstance, c3_g_state);
    for (c3_i39 = 0; c3_i39 < 625; c3_i39++) {
      chartInstance->c3_c_state[c3_i39] = c3_g_state[c3_i39];
    }

    c3_r = c3_d3;
  }

  return c3_r;
}

static void c3_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_d_state[625])
{
  real_T c3_d4;
  int32_T c3_i40;
  c3_d4 = 5489.0;
  for (c3_i40 = 0; c3_i40 < 625; c3_i40++) {
    c3_d_state[c3_i40] = 0U;
  }

  c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d4);
}

static void c3_twister_state_vector(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625])
{
  int32_T c3_i41;
  for (c3_i41 = 0; c3_i41 < 625; c3_i41++) {
    c3_b_mt[c3_i41] = c3_mt[c3_i41];
  }

  c3_b_twister_state_vector(chartInstance, c3_b_mt, c3_seed);
}

static void c3_b_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct *chartInstance,
  uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T *c3_r)
{
  int32_T c3_i42;
  for (c3_i42 = 0; c3_i42 < 625; c3_i42++) {
    c3_e_state[c3_i42] = c3_d_state[c3_i42];
  }

  *c3_r = c3_c_eml_rand_mt19937ar(chartInstance, c3_e_state);
}

static void c3_eml_error(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
  int32_T c3_i43;
  static char_T c3_varargin_1[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l',
    'i', 'd', 'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c3_u[37];
  const mxArray *c3_y = NULL;
  for (c3_i43 = 0; c3_i43 < 37; c3_i43++) {
    c3_u[c3_i43] = c3_varargin_1[c3_i43];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 37), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static void c3_b_eml_scalar_eg(SFc3_BuckBoost1InstanceStruct *chartInstance)
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
  int32_T c3_i44;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i44, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i44;
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

static uint32_T c3_f_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_method),
    &c3_thisId);
  sf_mex_destroy(&c3_b_method);
  return c3_y;
}

static uint32_T c3_g_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u3;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_method_not_empty = FALSE;
  } else {
    chartInstance->c3_method_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u3;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint32_T c3_h_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId);
  sf_mex_destroy(&c3_d_state);
  return c3_y;
}

static uint32_T c3_i_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u4;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_state_not_empty = FALSE;
  } else {
    chartInstance->c3_state_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u4, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u4;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_j_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_d_state, const char_T *c3_identifier, uint32_T c3_y[625])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_k_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, uint32_T c3_y[625])
{
  uint32_T c3_uv3[625];
  int32_T c3_i45;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_c_state_not_empty = FALSE;
  } else {
    chartInstance->c3_c_state_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c3_i45 = 0; c3_i45 < 625; c3_i45++) {
      c3_y[c3_i45] = c3_uv3[c3_i45];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_l_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_d_state, const char_T *c3_identifier, uint32_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_m_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, uint32_T c3_y[2])
{
  uint32_T c3_uv4[2];
  int32_T c3_i46;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_b_state_not_empty = FALSE;
  } else {
    chartInstance->c3_b_state_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
      c3_y[c3_i46] = c3_uv4[c3_i46];
    }
  }

  sf_mex_destroy(&c3_u);
}

static uint8_T c3_n_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_BuckBoost1, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_BuckBoost1), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_BuckBoost1);
  return c3_y;
}

static uint8_T c3_o_emlrt_marshallIn(SFc3_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u5, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_twister_state_vector(SFc3_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed)
{
  real_T c3_d5;
  uint32_T c3_u6;
  uint32_T c3_r;
  int32_T c3_mti;
  real_T c3_b_mti;
  real_T c3_d6;
  uint32_T c3_u7;
  c3_d5 = c3_seed;
  if (c3_d5 < 4.294967296E+9) {
    if (c3_d5 >= 0.0) {
      c3_u6 = (uint32_T)c3_d5;
    } else {
      c3_u6 = 0U;
    }
  } else if (c3_d5 >= 4.294967296E+9) {
    c3_u6 = MAX_uint32_T;
  } else {
    c3_u6 = 0U;
  }

  c3_r = c3_u6;
  c3_mt[0] = c3_r;
  for (c3_mti = 0; c3_mti < 623; c3_mti++) {
    c3_b_mti = 2.0 + (real_T)c3_mti;
    c3_d6 = muDoubleScalarRound(c3_b_mti - 1.0);
    if (c3_d6 < 4.294967296E+9) {
      if (c3_d6 >= 0.0) {
        c3_u7 = (uint32_T)c3_d6;
      } else {
        c3_u7 = 0U;
      }
    } else if (c3_d6 >= 4.294967296E+9) {
      c3_u7 = MAX_uint32_T;
    } else {
      c3_u7 = 0U;
    }

    c3_r = (c3_r ^ c3_r >> 30U) * 1812433253U + c3_u7;
    c3_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c3_b_mti), 1, 625, 1, 0) - 1] = c3_r;
  }

  c3_mt[624] = 624U;
}

static real_T c3_c_eml_rand_mt19937ar(SFc3_BuckBoost1InstanceStruct
  *chartInstance, uint32_T c3_d_state[625])
{
  int32_T c3_i47;
  uint32_T c3_u[2];
  int32_T c3_j;
  real_T c3_b_j;
  uint32_T c3_mti;
  int32_T c3_kk;
  real_T c3_b_kk;
  uint32_T c3_y;
  uint32_T c3_b_y;
  uint32_T c3_c_y;
  int32_T c3_c_kk;
  uint32_T c3_d_y;
  uint32_T c3_e_y;
  uint32_T c3_f_y;
  uint32_T c3_g_y;
  real_T c3_a;
  real_T c3_h_y;
  real_T c3_b;
  real_T c3_b_r;
  boolean_T c3_b0;
  boolean_T c3_isvalid;
  int32_T c3_k;
  int32_T c3_b_a;
  real_T c3_d7;
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
    for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
      c3_u[c3_i47] = 0U;
    }

    for (c3_j = 0; c3_j < 2; c3_j++) {
      c3_b_j = 1.0 + (real_T)c3_j;
      c3_mti = c3_d_state[624] + 1U;
      if ((real_T)c3_mti >= 625.0) {
        for (c3_kk = 0; c3_kk < 227; c3_kk++) {
          c3_b_kk = 1.0 + (real_T)c3_kk;
          c3_y = (c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c3_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c3_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c3_b_y = c3_y;
          c3_c_y = c3_b_y;
          if ((real_T)(c3_c_y & 1U) == 0.0) {
            c3_c_y >>= 1U;
          } else {
            c3_c_y = c3_c_y >> 1U ^ 2567483615U;
          }

          c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c3_b_kk), 1, 625, 1, 0) - 1] =
            c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c3_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c3_c_y;
        }

        for (c3_c_kk = 0; c3_c_kk < 396; c3_c_kk++) {
          c3_b_kk = 228.0 + (real_T)c3_c_kk;
          c3_y = (c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c3_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c3_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c3_d_y = c3_y;
          c3_e_y = c3_d_y;
          if ((real_T)(c3_e_y & 1U) == 0.0) {
            c3_e_y >>= 1U;
          } else {
            c3_e_y = c3_e_y >> 1U ^ 2567483615U;
          }

          c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c3_b_kk), 1, 625, 1, 0) - 1] =
            c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c3_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c3_e_y;
        }

        c3_y = (c3_d_state[623] & 2147483648U) | (c3_d_state[0] & 2147483647U);
        c3_f_y = c3_y;
        c3_g_y = c3_f_y;
        if ((real_T)(c3_g_y & 1U) == 0.0) {
          c3_g_y >>= 1U;
        } else {
          c3_g_y = c3_g_y >> 1U ^ 2567483615U;
        }

        c3_d_state[623] = c3_d_state[396] ^ c3_g_y;
        c3_mti = 1U;
      }

      c3_y = c3_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c3_mti), 1, 625, 1, 0)
        - 1];
      c3_d_state[624] = c3_mti;
      c3_y ^= c3_y >> 11U;
      c3_y ^= c3_y << 7U & 2636928640U;
      c3_y ^= c3_y << 15U & 4022730752U;
      c3_y ^= c3_y >> 18U;
      c3_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c3_b_j), 1, 2, 1, 0) - 1] = c3_y;
    }

    c3_u[0] >>= 5U;
    c3_u[1] >>= 6U;
    c3_a = (real_T)c3_u[0];
    c3_h_y = c3_a * 6.7108864E+7;
    c3_b = c3_h_y + (real_T)c3_u[1];
    c3_b_r = 1.1102230246251565E-16 * c3_b;
    if (c3_b_r == 0.0) {
      guard1 = FALSE;
      if ((real_T)c3_d_state[624] >= 1.0) {
        if ((real_T)c3_d_state[624] < 625.0) {
          c3_b0 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c3_b0 = FALSE;
      }

      c3_isvalid = c3_b0;
      if (c3_isvalid) {
        c3_isvalid = FALSE;
        c3_k = 1;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (c3_k < 625)) {
          if ((real_T)c3_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c3_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c3_b_a = c3_k + 1;
            c3_k = c3_b_a;
          } else {
            c3_isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!c3_isvalid) {
        c3_eml_error(chartInstance);
        c3_d7 = 5489.0;
        c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_b_r;
}

static void init_dsm_address_info(SFc3_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1244854622U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1025986582U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1739435948U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2025558792U);
}

mxArray *sf_c3_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SdgSJhuqT3po9EclgJjyvH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[34],T\"Capout\",},{M[1],M[83],T\"ESRout\",},{M[1],M[29],T\"e\",},{M[1],M[66],T\"ei\",},{M[1],M[70],T\"eu\",},{M[1],M[84],T\"t0\",},{M[1],M[44],T\"w0\",},{M[1],M[45],T\"w1\",},{M[1],M[67],T\"wi0\",},{M[1],M[68],T\"wi1\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[71],T\"wu0\",},{M[1],M[72],T\"wu1\",},{M[1],M[73],T\"wu2\",},{M[1],M[28],T\"y\",},{M[1],M[65],T\"yi\",},{M[1],M[69],T\"yu\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m\"}}}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 21, 10);
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
           31,
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
          _SFD_SET_DATA_PROPS(7,1,1,0,"Capin");
          _SFD_SET_DATA_PROPS(8,2,0,1,"y");
          _SFD_SET_DATA_PROPS(9,2,0,1,"e");
          _SFD_SET_DATA_PROPS(10,2,0,1,"w0");
          _SFD_SET_DATA_PROPS(11,2,0,1,"w1");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Capout");
          _SFD_SET_DATA_PROPS(13,1,1,0,"wi0in");
          _SFD_SET_DATA_PROPS(14,1,1,0,"wi1in");
          _SFD_SET_DATA_PROPS(15,1,1,0,"wu0in");
          _SFD_SET_DATA_PROPS(16,1,1,0,"wu1in");
          _SFD_SET_DATA_PROPS(17,1,1,0,"wu2in");
          _SFD_SET_DATA_PROPS(18,1,1,0,"ESRin");
          _SFD_SET_DATA_PROPS(19,1,1,0,"t0in");
          _SFD_SET_DATA_PROPS(20,2,0,1,"yi");
          _SFD_SET_DATA_PROPS(21,2,0,1,"ei");
          _SFD_SET_DATA_PROPS(22,2,0,1,"wi0");
          _SFD_SET_DATA_PROPS(23,2,0,1,"wi1");
          _SFD_SET_DATA_PROPS(24,2,0,1,"yu");
          _SFD_SET_DATA_PROPS(25,2,0,1,"eu");
          _SFD_SET_DATA_PROPS(26,2,0,1,"wu0");
          _SFD_SET_DATA_PROPS(27,2,0,1,"wu1");
          _SFD_SET_DATA_PROPS(28,2,0,1,"wu2");
          _SFD_SET_DATA_PROPS(29,2,0,1,"ESRout");
          _SFD_SET_DATA_PROPS(30,2,0,1,"t0");
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
        _SFD_CV_INIT_EML(0,1,1,7,0,0,0,0,0,10,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4316);
        _SFD_CV_INIT_EML_IF(0,1,0,2001,2013,-1,4315);
        _SFD_CV_INIT_EML_IF(0,1,1,2094,2151,-1,2701);
        _SFD_CV_INIT_EML_IF(0,1,2,2258,2288,-1,2334);
        _SFD_CV_INIT_EML_IF(0,1,3,2706,2770,-1,2844);
        _SFD_CV_INIT_EML_IF(0,1,4,3006,3065,-1,4007);
        _SFD_CV_INIT_EML_IF(0,1,5,3109,3178,3207,3999);
        _SFD_CV_INIT_EML_IF(0,1,6,4012,4068,-1,4234);

        {
          static int condStart[] = { 2097, 2124 };

          static int condEnd[] = { 2120, 2150 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,2097,2150,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2709, 2740 };

          static int condEnd[] = { 2736, 2769 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,2709,2769,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3009, 3042 };

          static int condEnd[] = { 3038, 3064 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,3009,3064,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3112, 3145 };

          static int condEnd[] = { 3141, 3177 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,3112,3177,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4015, 4042 };

          static int condEnd[] = { 4038, 4067 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,4015,4067,2,8,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_start;
          real_T *c3_t;
          real_T *c3_duty;
          real_T *c3_v_out;
          real_T *c3_i_in;
          real_T *c3_w0in;
          real_T *c3_w1in;
          real_T *c3_Capin;
          real_T *c3_y;
          real_T *c3_e;
          real_T *c3_w0;
          real_T *c3_w1;
          real_T *c3_Capout;
          real_T *c3_wi0in;
          real_T *c3_wi1in;
          real_T *c3_wu0in;
          real_T *c3_wu1in;
          real_T *c3_wu2in;
          real_T *c3_ESRin;
          real_T *c3_t0in;
          real_T *c3_yi;
          real_T *c3_ei;
          real_T *c3_wi0;
          real_T *c3_wi1;
          real_T *c3_yu;
          real_T *c3_eu;
          real_T *c3_wu0;
          real_T *c3_wu1;
          real_T *c3_wu2;
          real_T *c3_ESRout;
          real_T *c3_t0;
          c3_t0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
          c3_ESRout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c3_wu2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c3_wu1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c3_wu0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c3_eu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c3_yu = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c3_wi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c3_wi0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c3_ei = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c3_yi = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_t0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c3_ESRin = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c3_wu2in = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c3_wu1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c3_wu0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c3_wi1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c3_wi0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c3_Capout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_w1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_w0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Capin = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_w1in = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_w0in = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_i_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_v_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_start);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_t);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_duty);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_v_out);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_i_in);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_w0in);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_w1in);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_Capin);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_e);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_w0);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_w1);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_Capout);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_wi0in);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_wi1in);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_wu0in);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_wu1in);
          _SFD_SET_DATA_VALUE_PTR(17U, c3_wu2in);
          _SFD_SET_DATA_VALUE_PTR(18U, c3_ESRin);
          _SFD_SET_DATA_VALUE_PTR(19U, c3_t0in);
          _SFD_SET_DATA_VALUE_PTR(20U, c3_yi);
          _SFD_SET_DATA_VALUE_PTR(21U, c3_ei);
          _SFD_SET_DATA_VALUE_PTR(22U, c3_wi0);
          _SFD_SET_DATA_VALUE_PTR(23U, c3_wi1);
          _SFD_SET_DATA_VALUE_PTR(24U, c3_yu);
          _SFD_SET_DATA_VALUE_PTR(25U, c3_eu);
          _SFD_SET_DATA_VALUE_PTR(26U, c3_wu0);
          _SFD_SET_DATA_VALUE_PTR(27U, c3_wu1);
          _SFD_SET_DATA_VALUE_PTR(28U, c3_wu2);
          _SFD_SET_DATA_VALUE_PTR(29U, c3_ESRout);
          _SFD_SET_DATA_VALUE_PTR(30U, c3_t0);
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
  return "6t6V4j54Q1fl3sPgx3FSX";
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
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,15);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,16);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4037263709U));
  ssSetChecksum1(S,(929935314U));
  ssSetChecksum2(S,(88319435U));
  ssSetChecksum3(S,(1694000844U));
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
