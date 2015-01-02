#include <stdio.h>   /* required for file operations */

//#define DATA_NUM	10
#define DATA_NUM	100
#define DATA_SIZE	100
#define DATA_LENGTH	(DATA_NUM*DATA_SIZE)
#define NUMCHARLINE	80

#define FILENAME_I	"Iin100_100.txt"
#define FILENAME_V	"Vin100_100.txt"

//FILE *fr;            /* declare the file pointer */
//FILE *fw;

FILE *vr, *ir; //read
//FILE *cw, *esrw; //write
FILE *res;

void findDuty(FILE *fp, int *dutyret)
{
	int i, j;
	float tempEdge;
	float p1, p2, ptemp;   
	char sLine[80];      
   
	for(i=0; i<DATA_NUM; i++) {
		// first data
		if (fgets(sLine, 80, fp) != NULL) {
			sscanf (sLine, "%g", &p2);
		}
		else {
			printf("abort 1");
			break;
		}
	
		for(j=1; j<DATA_SIZE; j++) {
			if ( (fgets(sLine, 80, fp) != NULL) ) {
				// assume no Duty=0, ...
				// so we can use that to check whether we have found Duty for each DATA_NUM, ...
				// once found, skip the routine but don't jump the data, you know why...
				// "fgets" still need to go thought all data.
				if( !dutyret[i] ) {
					sscanf (sLine, "%g", &ptemp); //scan as float
					
					p1 = p2; //store as prev.
					p2 = ptemp;
					
					if( (p2-p1) < 0 ) { // once detect negative edge
						//printf("p2[next]=%.8g\n",p2);
						dutyret[i] = j;
						//printf("duty[%d]=%d\n",i,j);
						//break; //next i
					}
				}
			}
			else {
				printf("\n\nNULL reading file...!\n\ni=%d, j=%d\n\n", i, j);
				break;
			}
		}
   }
}


main()

{
   int datacount, t, offset, t0;
   float datain;
   float dataout;
   //char line[DATALENGTH];
   float vdata[DATA_LENGTH];
   float idata[DATA_LENGTH];
   
   char sVLine[NUMCHARLINE];
   char sILine[NUMCHARLINE];
   
   /* --- signal --- */
   float v_out, i_in;
   // duty cycle info for provided data
   int duty[10];// = {59, 57, 53, 50, 49, 51, 55, 59, 61, 61};
   int epoch, iter;
   
   #define OFFSET_ON_START_abs	5
   #define OFFSET_ON_END_rel	-5
   #define OFFSET_OFF_START_rel	5
   #define OFFSET_OFF_END_abs	95
   /*sampling_time = 1e-5;*/
   #define SAMPLING_TIME		0.00001f
   
   /* --- LMS --- */
   #define BETA	0.5
   
   #define MODEL_ORDER_VON	1   
   float wv_on[MODEL_ORDER_VON+1];
   float yv_on, ev_on;
   
   #define MODEL_ORDER_VOFF	2
   float wv_off[MODEL_ORDER_VOFF+1];
   float yv_off, ev_off;
   
   #define MODEL_ORDER_IOFF	1
   float wi_off[MODEL_ORDER_IOFF+1];
   float yi_off, ei_off;
   
   float rms, rmsu;
   float u[MODEL_ORDER_VON+1];
   float uu[MODEL_ORDER_VOFF+1];
   
   /* --- --- */

   ir = fopen (FILENAME_I, "rt");  /* open the file for reading */
   /* elapsed.dta is the name of the file */
   /* "rt" means open the file for reading text */
   //fw = fopen("floatdataout.txt", "wt");
   
   datacount = 0;
   t = 0;
   
   findDuty(ir, duty);
   // int i;
   // for(i=0; i<DATA_NUM; i++) {
		// printf("duty[%d]=%d\n", i, duty[i]);
		// //duty[i] = 0; //part of test reopen file
   // }
   fclose(ir);
   
   // test that we able to reopen the file
   // printf("\nthis\n");   
   // ir = fopen ("Iin1000.txt", "rt");
   // //findDuty(ir, duty);
   // for(i=0; i<DATA_NUM; i++) {
		// printf("duty[%d]=%d\n", i, duty[i]);
		// duty[i] = 0;
   // }
   // fclose(ir);


   vr = fopen (FILENAME_V, "rt");
   ir = fopen (FILENAME_I, "rt");
   
   res = fopen("result_C_ESR.txt", "wt");
   // while(fgets(line, DATALENGTH, fr) != NULL)
   
	for ( epoch=0; epoch<DATA_NUM; epoch++) {
		for ( iter=0; iter<DATA_SIZE; iter++) {
			if ( (fgets(sVLine, NUMCHARLINE, vr) != NULL) && (fgets(sILine, NUMCHARLINE, ir) != NULL) ) {
				t = iter;
				sscanf (sVLine, "%g", &v_out);
				sscanf (sILine, "%g", &i_in);
				
				offset = t - duty[epoch];
		
				// State: ON
				if( t > OFFSET_ON_START_abs && offset < OFFSET_ON_END_rel ) {
					if (t <= OFFSET_ON_START_abs+2) {
						t0 = t;
					}
				
					// --- start LMS for uON(t) ---
					u[0] = 1;
					u[1] = t - t0;
					rms = (u[0]*u[0] + u[1]*u[1])/2;
					
					yv_on = wv_on[0]*u[0] + wv_on[1]*u[1];
					//printf("v_out=%g\n", v_out);
					ev_on = v_out - yv_on;
					
					wv_on[0] = wv_on[0] + BETA*ev_on*u[0]/rms;
					wv_on[1] = wv_on[1] + BETA*ev_on*u[1]/rms;
					// --- end ---
			 
				}
				
				// State: OFF
				if(offset > OFFSET_OFF_START_rel && t < OFFSET_OFF_END_abs) {
					if(offset > OFFSET_OFF_START_rel && offset <= OFFSET_OFF_START_rel+2) {
						t0 = t;
					}
					
					// --- start LMS for iOFF(t)
					u[0] = 1;
					u[1] = t - t0;
					rms = (u[0]*u[0] + u[1]*u[1])/2;
					
					yi_off = wi_off[0]*u[0] + wi_off[1]*u[1];
					ei_off = i_in - yi_off;
					
					wi_off[0] = wi_off[0] + BETA*ei_off*u[0]/rms;
					wi_off[1] = wi_off[1] + BETA*ei_off*u[1]/rms;
					// --- end ---
					
					// --- start LMS for vOFF(t)
					uu[0] = 1;
					uu[1] = t - t0;
					uu[2] = uu[1]*uu[1];
					rmsu = (uu[0]*uu[0] + uu[1]*uu[1] + uu[2]*uu[2])/2;
					
					yv_off = wv_off[0]*uu[0] + wv_off[1]*uu[1] + wv_off[2]*uu[2];
					ev_off = v_out - yv_off;
					
					wv_off[0] = wv_off[0] + BETA*ev_off*uu[0]/rmsu;
					wv_off[1] = wv_off[1] + BETA*ev_off*uu[1]/rmsu;
					wv_off[2] = wv_off[2] + BETA*ev_off*uu[2]/rmsu;
					// --- end ---
					
				}
				
			}
		}
		//printf("w0 = %g, w1 = %g\n", wv_on[0], wv_on[1]);
		float Cap;
		Cap = -wv_on[0]/wv_on[1]/30*SAMPLING_TIME;
		printf("Cap = %g\n", Cap );
		
		float wv_off_r[MODEL_ORDER_VOFF+1];
		float wi_off_r[MODEL_ORDER_IOFF+1];
		wv_off_r[0] = wv_off[0];
		wv_off_r[1] = wv_off[1]/SAMPLING_TIME;
		wv_off_r[2] = wv_off[2]/(SAMPLING_TIME*SAMPLING_TIME);
		wi_off_r[0] = wi_off[0];
		wi_off_r[1] = wi_off[1]/SAMPLING_TIME;
		float a, b, c;
		a = 2*wv_off_r[2]/(wi_off_r[1]*30-wv_off_r[1]);
		b = 2*wv_off_r[2]/(1-wv_off_r[1]/30/wi_off_r[1]);
		c = wv_off_r[0]*a + b/a - 2*wv_off_r[2]/a;
		float ESR;
		ESR = (wi_off_r[0]/Cap - c) / (c/30 - wi_off_r[1]);
		printf("ESR = %g\n", ESR);
		
		fprintf(res, "%.8g\t%.8g\n", Cap, ESR);
	}
	
	fclose(ir);  /* close the file prior to exiting the routine */
	fclose(vr);
	fclose(res);
	
} /*of main*/
