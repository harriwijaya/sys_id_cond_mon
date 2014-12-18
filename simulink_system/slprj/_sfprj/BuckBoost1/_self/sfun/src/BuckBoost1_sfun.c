/* Include files */

#include "BuckBoost1_sfun.h"
#include "c1_BuckBoost1.h"
#include "c2_BuckBoost1.h"
#include "c3_BuckBoost1.h"
#include "c4_BuckBoost1.h"
#include "c22_BuckBoost1.h"
#include "c25_BuckBoost1.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _BuckBoost1MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void BuckBoost1_initializer(void)
{
}

void BuckBoost1_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_BuckBoost1_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_BuckBoost1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_BuckBoost1_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4201368028U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(796893571U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3959415149U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1311566464U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2192382774U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2823209888U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(186431537U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2842622667U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c1_BuckBoost1_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c2_BuckBoost1_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c3_BuckBoost1_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c4_BuckBoost1_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c22_BuckBoost1_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_BuckBoost1_get_check_sum(mxArray *plhs[]);
          sf_c25_BuckBoost1_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2768847521U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2170491861U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(393509167U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1849675996U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BuckBoost1_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "GOLhlPUDzFNSZgWpHYSxwH") == 0) {
          extern mxArray *sf_c1_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c1_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "fghPsDLFPZQNGxlB0WLuqF") == 0) {
          extern mxArray *sf_c2_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c2_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "mibQNaLMKVlm7sAOk7PDm") == 0) {
          extern mxArray *sf_c3_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c3_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "znM1L0blrRbgHURBVUkmu") == 0) {
          extern mxArray *sf_c4_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c4_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "stiQ8C6cVQk9LSuJaF9fTB") == 0) {
          extern mxArray *sf_c22_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c22_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "Mt0bvEqmJnH8RLn5h6ZvaE") == 0) {
          extern mxArray *sf_c25_BuckBoost1_get_autoinheritance_info(void);
          plhs[0] = sf_c25_BuckBoost1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BuckBoost1_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray *sf_c25_BuckBoost1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_BuckBoost1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void BuckBoost1_debug_initialize(void)
{
  _BuckBoost1MachineNumber_ = sf_debug_initialize_machine("BuckBoost1","sfun",0,
    6,0,0,0);
  sf_debug_set_machine_event_thresholds(_BuckBoost1MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_BuckBoost1MachineNumber_,0);
}

void BuckBoost1_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_BuckBoost1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("BuckBoost1",
      "BuckBoost1");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_BuckBoost1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
