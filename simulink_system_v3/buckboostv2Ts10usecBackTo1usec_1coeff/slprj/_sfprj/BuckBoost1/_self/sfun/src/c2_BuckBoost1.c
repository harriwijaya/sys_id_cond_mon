/* Include files */

#include "blascompat32.h"
#include "BuckBoost1_sfun.h"
#include "c2_BuckBoost1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BuckBoost1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[27] = { "Err1", "Tsimulation",
  "Fix10us", "nargin", "nargout", "SS_Start", "Carrier", "Duty", "Vc", "IL",
  "Vo_Onk1", "Slope_Vo_Onk1", "IL_Onk1", "Slope_IL_Onk1", "Vo_Offk1",
  "Slope_Vo_Offk1", "IL_Offk1", "Slope_IL_Offk1", "Vo_On", "Slope_Vo_On",
  "IL_On", "Slope_IL_On", "Vo_Off", "Slope_Vo_Off", "IL_Off", "Slope_IL_Off",
  "Read" };

/* Function Declarations */
static void initialize_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance);
static void initialize_params_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance);
static void enable_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance);
static void disable_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *
  chartInstance);
static void set_sim_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance);
static void sf_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance);
static void c2_chartstep_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance);
static void initSimStructsc2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c2_Read, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_BuckBoost1, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_BuckBoost1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_BuckBoost1 = 0U;
}

static void initialize_params_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void enable_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  uint8_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T *c2_IL_Off;
  real_T *c2_IL_On;
  real_T *c2_Read;
  real_T *c2_Slope_IL_Off;
  real_T *c2_Slope_IL_On;
  real_T *c2_Slope_Vo_Off;
  real_T *c2_Slope_Vo_On;
  real_T *c2_Vo_Off;
  real_T *c2_Vo_On;
  c2_Read = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_Slope_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_Slope_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_Slope_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Slope_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(10), FALSE);
  c2_hoistedGlobal = *c2_IL_Off;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_IL_On;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_Read;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_Slope_IL_Off;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_Slope_IL_On;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_Slope_Vo_Off;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_Slope_Vo_On;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *c2_Vo_Off;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *c2_Vo_On;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = chartInstance->c2_is_active_c2_BuckBoost1;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_IL_Off;
  real_T *c2_IL_On;
  real_T *c2_Read;
  real_T *c2_Slope_IL_Off;
  real_T *c2_Slope_IL_On;
  real_T *c2_Slope_Vo_Off;
  real_T *c2_Slope_Vo_On;
  real_T *c2_Vo_Off;
  real_T *c2_Vo_On;
  c2_Read = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_Slope_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_Slope_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_Slope_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Slope_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_IL_Off = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "IL_Off");
  *c2_IL_On = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "IL_On");
  *c2_Read = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "Read");
  *c2_Slope_IL_Off = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "Slope_IL_Off");
  *c2_Slope_IL_On = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "Slope_IL_On");
  *c2_Slope_Vo_Off = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "Slope_Vo_Off");
  *c2_Slope_Vo_On = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 6)), "Slope_Vo_On");
  *c2_Vo_Off = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    7)), "Vo_Off");
  *c2_Vo_On = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    8)), "Vo_On");
  chartInstance->c2_is_active_c2_BuckBoost1 = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 9)),
     "is_active_c2_BuckBoost1");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_BuckBoost1(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance)
{
}

static void sf_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct *chartInstance)
{
  real_T *c2_SS_Start;
  real_T *c2_Carrier;
  real_T *c2_Duty;
  real_T *c2_Vc;
  real_T *c2_IL;
  real_T *c2_Vo_Onk1;
  real_T *c2_Slope_Vo_Onk1;
  real_T *c2_IL_Onk1;
  real_T *c2_Slope_IL_Onk1;
  real_T *c2_Vo_Offk1;
  real_T *c2_Slope_Vo_Offk1;
  real_T *c2_IL_Offk1;
  real_T *c2_Vo_On;
  real_T *c2_Slope_Vo_On;
  real_T *c2_IL_On;
  real_T *c2_Slope_IL_On;
  real_T *c2_Vo_Off;
  real_T *c2_Slope_Vo_Off;
  real_T *c2_IL_Off;
  real_T *c2_Slope_IL_Off;
  real_T *c2_Read;
  real_T *c2_Slope_IL_Offk1;
  c2_Slope_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c2_Read = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_Slope_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_Slope_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_Slope_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Slope_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_Slope_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c2_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_Slope_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_Slope_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_IL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_Vc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_Duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Carrier = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_SS_Start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_SS_Start, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_Carrier, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_Duty, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_Vc, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_IL, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_Vo_Onk1, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_Vo_Onk1, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_IL_Onk1, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_IL_Onk1, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_Vo_Offk1, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_Vo_Offk1, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_IL_Offk1, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_Vo_On, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_Vo_On, 13U);
  _SFD_DATA_RANGE_CHECK(*c2_IL_On, 14U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_IL_On, 15U);
  _SFD_DATA_RANGE_CHECK(*c2_Vo_Off, 16U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_Vo_Off, 17U);
  _SFD_DATA_RANGE_CHECK(*c2_IL_Off, 18U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_IL_Off, 19U);
  _SFD_DATA_RANGE_CHECK(*c2_Read, 20U);
  _SFD_DATA_RANGE_CHECK(*c2_Slope_IL_Offk1, 21U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_BuckBoost1(chartInstance);
  sf_debug_check_for_state_inconsistency(_BuckBoost1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_hoistedGlobal;
  real_T c2_j_hoistedGlobal;
  real_T c2_k_hoistedGlobal;
  real_T c2_l_hoistedGlobal;
  real_T c2_m_hoistedGlobal;
  real_T c2_SS_Start;
  real_T c2_Carrier;
  real_T c2_Duty;
  real_T c2_Vc;
  real_T c2_IL;
  real_T c2_Vo_Onk1;
  real_T c2_Slope_Vo_Onk1;
  real_T c2_IL_Onk1;
  real_T c2_Slope_IL_Onk1;
  real_T c2_Vo_Offk1;
  real_T c2_Slope_Vo_Offk1;
  real_T c2_IL_Offk1;
  real_T c2_Slope_IL_Offk1;
  uint32_T c2_debug_family_var_map[27];
  real_T c2_Err1;
  real_T c2_Tsimulation;
  real_T c2_Fix10us;
  real_T c2_nargin = 13.0;
  real_T c2_nargout = 9.0;
  real_T c2_Vo_On;
  real_T c2_Slope_Vo_On;
  real_T c2_IL_On;
  real_T c2_Slope_IL_On;
  real_T c2_Vo_Off;
  real_T c2_Slope_Vo_Off;
  real_T c2_IL_Off;
  real_T c2_Slope_IL_Off;
  real_T c2_Read;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_c_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_d_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T *c2_b_Read;
  real_T *c2_b_Slope_IL_Off;
  real_T *c2_b_IL_Off;
  real_T *c2_b_Slope_Vo_Off;
  real_T *c2_b_Vo_Off;
  real_T *c2_b_Slope_IL_On;
  real_T *c2_b_IL_On;
  real_T *c2_b_Slope_Vo_On;
  real_T *c2_b_Vo_On;
  real_T *c2_b_Slope_IL_Offk1;
  real_T *c2_b_IL_Offk1;
  real_T *c2_b_Slope_Vo_Offk1;
  real_T *c2_b_Vo_Offk1;
  real_T *c2_b_Slope_IL_Onk1;
  real_T *c2_b_IL_Onk1;
  real_T *c2_b_Slope_Vo_Onk1;
  real_T *c2_b_Vo_Onk1;
  real_T *c2_b_IL;
  real_T *c2_b_Vc;
  real_T *c2_b_Duty;
  real_T *c2_b_Carrier;
  real_T *c2_b_SS_Start;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c2_b_Slope_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c2_b_Read = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_b_Slope_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_b_Slope_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_Slope_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_Slope_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_b_Slope_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c2_b_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_b_Slope_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_b_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_Slope_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_IL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_Vc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_Duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Carrier = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_SS_Start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_SS_Start;
  c2_b_hoistedGlobal = *c2_b_Carrier;
  c2_c_hoistedGlobal = *c2_b_Duty;
  c2_d_hoistedGlobal = *c2_b_Vc;
  c2_e_hoistedGlobal = *c2_b_IL;
  c2_f_hoistedGlobal = *c2_b_Vo_Onk1;
  c2_g_hoistedGlobal = *c2_b_Slope_Vo_Onk1;
  c2_h_hoistedGlobal = *c2_b_IL_Onk1;
  c2_i_hoistedGlobal = *c2_b_Slope_IL_Onk1;
  c2_j_hoistedGlobal = *c2_b_Vo_Offk1;
  c2_k_hoistedGlobal = *c2_b_Slope_Vo_Offk1;
  c2_l_hoistedGlobal = *c2_b_IL_Offk1;
  c2_m_hoistedGlobal = *c2_b_Slope_IL_Offk1;
  c2_SS_Start = c2_hoistedGlobal;
  c2_Carrier = c2_b_hoistedGlobal;
  c2_Duty = c2_c_hoistedGlobal;
  c2_Vc = c2_d_hoistedGlobal;
  c2_IL = c2_e_hoistedGlobal;
  c2_Vo_Onk1 = c2_f_hoistedGlobal;
  c2_Slope_Vo_Onk1 = c2_g_hoistedGlobal;
  c2_IL_Onk1 = c2_h_hoistedGlobal;
  c2_Slope_IL_Onk1 = c2_i_hoistedGlobal;
  c2_Vo_Offk1 = c2_j_hoistedGlobal;
  c2_Slope_Vo_Offk1 = c2_k_hoistedGlobal;
  c2_IL_Offk1 = c2_l_hoistedGlobal;
  c2_Slope_IL_Offk1 = c2_m_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 27U, 27U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_Err1, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Tsimulation, 1U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_Fix10us, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_SS_Start, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Carrier, 6U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Duty, 7U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Vc, 8U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_IL, 9U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Vo_Onk1, 10U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Slope_Vo_Onk1, 11U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_IL_Onk1, 12U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Slope_IL_Onk1, 13U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Vo_Offk1, 14U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Slope_Vo_Offk1, 15U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_IL_Offk1, 16U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Slope_IL_Offk1, 17U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_Vo_On, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Slope_Vo_On, 19U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_IL_On, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Slope_IL_On, 21U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Vo_Off, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Slope_Vo_Off, 23U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_IL_Off, 24U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Slope_IL_Off, 25U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Read, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_Err1 = c2_Carrier - c2_Duty;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_Tsimulation = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_Fix10us = 1.0E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c2_SS_Start == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c2_Err1 >= -12.0)) {
      if (CV_EML_COND(0, 1, 1, c2_Err1 < -11.0)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
        c2_Vo_On = c2_Vc;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
        c2_IL_On = c2_IL;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
        c2_Read = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
        c2_Slope_Vo_On = c2_Slope_Vo_Onk1;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
        c2_Slope_IL_On = c2_Slope_IL_Onk1;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
        c2_Slope_Vo_Off = c2_Slope_Vo_Offk1;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
        c2_Slope_IL_Off = c2_Slope_IL_Offk1;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
        c2_Vo_Off = c2_Vo_Offk1;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
        c2_IL_Off = c2_IL_Offk1;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
      guard2 = FALSE;
      if (CV_EML_COND(0, 1, 2, c2_Err1 >= -2.0)) {
        if (CV_EML_COND(0, 1, 3, c2_Err1 < -1.0)) {
          CV_EML_MCDC(0, 1, 1, TRUE);
          CV_EML_IF(0, 1, 2, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
          c2_A = c2_Vc - c2_Vo_Onk1;
          c2_x = c2_A;
          c2_b_x = c2_x;
          c2_Slope_Vo_On = c2_b_x / 1.0E-5;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
          c2_b_A = c2_IL - c2_IL_Onk1;
          c2_c_x = c2_b_A;
          c2_d_x = c2_c_x;
          c2_Slope_IL_On = c2_d_x / 1.0E-5;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
          c2_Vo_On = c2_Vo_Onk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
          c2_IL_On = c2_IL_Onk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
          c2_Slope_Vo_Off = c2_Slope_Vo_Offk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
          c2_Slope_IL_Off = c2_Slope_IL_Offk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
          c2_Read = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
          c2_Vo_Off = c2_Vo_Offk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
          c2_IL_Off = c2_IL_Offk1;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 2, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
        if (CV_EML_IF(0, 1, 3, c2_Carrier == 89.0)) {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
          c2_Vo_Off = c2_Vc;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
          c2_IL_Off = c2_IL;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
          c2_Slope_Vo_Off = c2_Slope_Vo_Offk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
          c2_Slope_IL_Off = c2_Slope_IL_Offk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
          c2_Slope_Vo_On = c2_Slope_Vo_Onk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
          c2_Slope_IL_On = c2_Slope_IL_Onk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
          c2_Read = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
          c2_Vo_On = c2_Vo_Onk1;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
          c2_IL_On = c2_IL_Onk1;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
          if (CV_EML_IF(0, 1, 4, c2_Carrier == 99.0)) {
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
            c2_c_A = c2_Vc - c2_Vo_Offk1;
            c2_e_x = c2_c_A;
            c2_f_x = c2_e_x;
            c2_Slope_Vo_Off = c2_f_x / 1.0E-5;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
            c2_d_A = c2_IL - c2_IL_Offk1;
            c2_g_x = c2_d_A;
            c2_h_x = c2_g_x;
            c2_Slope_IL_Off = c2_h_x / 1.0E-5;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
            c2_Vo_Off = c2_Vo_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
            c2_IL_Off = c2_IL_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
            c2_Read = 1.0;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
            c2_Slope_Vo_On = c2_Slope_Vo_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
            c2_Slope_IL_On = c2_Slope_IL_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
            c2_Vo_On = c2_Vo_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
            c2_IL_On = c2_IL_Onk1;
          } else {
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
            c2_Vo_On = c2_Vo_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
            c2_Slope_Vo_On = c2_Slope_Vo_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
            c2_IL_On = c2_IL_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
            c2_Slope_IL_On = c2_Slope_IL_Onk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
            c2_Vo_Off = c2_Vo_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
            c2_Slope_Vo_Off = c2_Slope_Vo_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
            c2_IL_Off = c2_IL_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
            c2_Slope_IL_Off = c2_Slope_IL_Offk1;
            _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
            c2_Read = 0.0;
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_Vo_On = 49.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_Slope_Vo_On = 0.5;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_IL_On = 4.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    c2_Slope_IL_On = 0.2;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_Vo_Off = 50.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_Slope_Vo_Off = 0.5;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_IL_Off = 3.8;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_Slope_IL_Off = 0.2;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_Read = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -37);
  sf_debug_symbol_scope_pop();
  *c2_b_Vo_On = c2_Vo_On;
  *c2_b_Slope_Vo_On = c2_Slope_Vo_On;
  *c2_b_IL_On = c2_IL_On;
  *c2_b_Slope_IL_On = c2_Slope_IL_On;
  *c2_b_Vo_Off = c2_Vo_Off;
  *c2_b_Slope_Vo_Off = c2_Slope_Vo_Off;
  *c2_b_IL_Off = c2_IL_Off;
  *c2_b_Slope_IL_Off = c2_Slope_IL_Off;
  *c2_b_Read = c2_Read;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_BuckBoost1(SFc2_BuckBoost1InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc2_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c2_Read, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Read), &c2_thisId);
  sf_mex_destroy(&c2_Read);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Read;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc2_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c2_Read = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Read), &c2_thisId);
  sf_mex_destroy(&c2_Read);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_BuckBoost1_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[3];
  c2_ResolvedFunctionInfo (*c2_b_info)[3];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[3])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 1342789344U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 1319708366U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1286797244U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 1313326210U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc2_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc2_BuckBoost1InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_BuckBoost1, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_BuckBoost1), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_BuckBoost1);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_BuckBoost1InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_BuckBoost1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_BuckBoost1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2485807878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2850156479U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(106810938U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3160165002U);
}

mxArray *sf_c2_BuckBoost1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TQvEwnkgbGzl8OYp6cChaB");
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

static const mxArray *sf_get_sim_state_info_c2_BuckBoost1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[46],T\"IL_Off\",},{M[1],M[44],T\"IL_On\",},{M[1],M[34],T\"Read\",},{M[1],M[47],T\"Slope_IL_Off\",},{M[1],M[45],T\"Slope_IL_On\",},{M[1],M[31],T\"Slope_Vo_Off\",},{M[1],M[29],T\"Slope_Vo_On\",},{M[1],M[35],T\"Vo_Off\",},{M[1],M[28],T\"Vo_On\",},{M[8],M[0],T\"is_active_c2_BuckBoost1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_BuckBoost1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_BuckBoost1InstanceStruct *chartInstance;
    chartInstance = (SFc2_BuckBoost1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_BuckBoost1MachineNumber_,
           2,
           1,
           1,
           22,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"SS_Start");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Carrier");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Duty");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Vc");
          _SFD_SET_DATA_PROPS(4,1,1,0,"IL");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Vo_Onk1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Slope_Vo_Onk1");
          _SFD_SET_DATA_PROPS(7,1,1,0,"IL_Onk1");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Slope_IL_Onk1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Vo_Offk1");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Slope_Vo_Offk1");
          _SFD_SET_DATA_PROPS(11,1,1,0,"IL_Offk1");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Vo_On");
          _SFD_SET_DATA_PROPS(13,2,0,1,"Slope_Vo_On");
          _SFD_SET_DATA_PROPS(14,2,0,1,"IL_On");
          _SFD_SET_DATA_PROPS(15,2,0,1,"Slope_IL_On");
          _SFD_SET_DATA_PROPS(16,2,0,1,"Vo_Off");
          _SFD_SET_DATA_PROPS(17,2,0,1,"Slope_Vo_Off");
          _SFD_SET_DATA_PROPS(18,2,0,1,"IL_Off");
          _SFD_SET_DATA_PROPS(19,2,0,1,"Slope_IL_Off");
          _SFD_SET_DATA_PROPS(20,2,0,1,"Read");
          _SFD_SET_DATA_PROPS(21,1,1,0,"Slope_IL_Offk1");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2154);
        _SFD_CV_INIT_EML_IF(0,1,0,402,417,2007,2149);
        _SFD_CV_INIT_EML_IF(0,1,1,422,447,726,2006);
        _SFD_CV_INIT_EML_IF(0,1,2,726,755,1099,2006);
        _SFD_CV_INIT_EML_IF(0,1,3,1099,1118,1388,2006);
        _SFD_CV_INIT_EML_IF(0,1,4,1388,1407,1766,2006);

        {
          static int condStart[] = { 425, 438 };

          static int condEnd[] = { 434, 446 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,424,447,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 734, 746 };

          static int condEnd[] = { 742, 753 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,733,754,2,2,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_SS_Start;
          real_T *c2_Carrier;
          real_T *c2_Duty;
          real_T *c2_Vc;
          real_T *c2_IL;
          real_T *c2_Vo_Onk1;
          real_T *c2_Slope_Vo_Onk1;
          real_T *c2_IL_Onk1;
          real_T *c2_Slope_IL_Onk1;
          real_T *c2_Vo_Offk1;
          real_T *c2_Slope_Vo_Offk1;
          real_T *c2_IL_Offk1;
          real_T *c2_Vo_On;
          real_T *c2_Slope_Vo_On;
          real_T *c2_IL_On;
          real_T *c2_Slope_IL_On;
          real_T *c2_Vo_Off;
          real_T *c2_Slope_Vo_Off;
          real_T *c2_IL_Off;
          real_T *c2_Slope_IL_Off;
          real_T *c2_Read;
          real_T *c2_Slope_IL_Offk1;
          c2_Slope_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S,
            12);
          c2_Read = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c2_Slope_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c2_IL_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c2_Slope_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c2_Vo_Off = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_Slope_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_IL_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_Slope_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_Vo_On = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_IL_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c2_Slope_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S,
            10);
          c2_Vo_Offk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c2_Slope_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c2_IL_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c2_Slope_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_Vo_Onk1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_IL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_Vc = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_Duty = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Carrier = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_SS_Start = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_SS_Start);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Carrier);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Duty);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_Vc);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_IL);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Vo_Onk1);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_Slope_Vo_Onk1);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_IL_Onk1);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_Slope_IL_Onk1);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_Vo_Offk1);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_Slope_Vo_Offk1);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_IL_Offk1);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_Vo_On);
          _SFD_SET_DATA_VALUE_PTR(13U, c2_Slope_Vo_On);
          _SFD_SET_DATA_VALUE_PTR(14U, c2_IL_On);
          _SFD_SET_DATA_VALUE_PTR(15U, c2_Slope_IL_On);
          _SFD_SET_DATA_VALUE_PTR(16U, c2_Vo_Off);
          _SFD_SET_DATA_VALUE_PTR(17U, c2_Slope_Vo_Off);
          _SFD_SET_DATA_VALUE_PTR(18U, c2_IL_Off);
          _SFD_SET_DATA_VALUE_PTR(19U, c2_Slope_IL_Off);
          _SFD_SET_DATA_VALUE_PTR(20U, c2_Read);
          _SFD_SET_DATA_VALUE_PTR(21U, c2_Slope_IL_Offk1);
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
  return "zQTrIjtkNyjcj3Wz1bMsq";
}

static void sf_opaque_initialize_c2_BuckBoost1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*)
    chartInstanceVar);
  initialize_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_BuckBoost1(void *chartInstanceVar)
{
  enable_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_BuckBoost1(void *chartInstanceVar)
{
  disable_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_BuckBoost1(void *chartInstanceVar)
{
  sf_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_BuckBoost1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_BuckBoost1
    ((SFc2_BuckBoost1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_BuckBoost1();/* state var info */
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

extern void sf_internal_set_sim_state_c2_BuckBoost1(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_BuckBoost1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_BuckBoost1(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_BuckBoost1(S);
}

static void sf_opaque_set_sim_state_c2_BuckBoost1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_BuckBoost1(S, st);
}

static void sf_opaque_terminate_c2_BuckBoost1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_BuckBoost1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_BuckBoost1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_BuckBoost1((SFc2_BuckBoost1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BuckBoost1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
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
        infoStruct,2,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1726509124U));
  ssSetChecksum1(S,(2169830569U));
  ssSetChecksum2(S,(3879209749U));
  ssSetChecksum3(S,(30011311U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_BuckBoost1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_BuckBoost1(SimStruct *S)
{
  SFc2_BuckBoost1InstanceStruct *chartInstance;
  chartInstance = (SFc2_BuckBoost1InstanceStruct *)malloc(sizeof
    (SFc2_BuckBoost1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_BuckBoost1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_BuckBoost1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_BuckBoost1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_BuckBoost1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_BuckBoost1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_BuckBoost1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_BuckBoost1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_BuckBoost1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_BuckBoost1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_BuckBoost1;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_BuckBoost1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_BuckBoost1;
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

void c2_BuckBoost1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_BuckBoost1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_BuckBoost1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_BuckBoost1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_BuckBoost1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
