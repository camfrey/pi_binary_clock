#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "framebuffer.h"

#define SEC 2
#define MIN 1
#define HRS 0


int *slice_time(char time_in[]);


int main(void){
	pi_framebuffer_t *dev = getFBDevice();
	int *out_array=malloc(sizeof(int)*3);
	char time_in[11];
	
	while(1){
		scanf("%s", time_in);
		if ( strlen(time_in) >= 8 ){ 
			clearBitmap(dev->bitmap,0);
			out_array = slice_time(time_in);
			display_time(out_array[HRS], out_array[MIN], out_array[SEC], dev);
		}	
		else {break;}
	}
	clearBitmap(dev->bitmap,0);
	return 0;
}

int *slice_time(char time_in[]){
	char time_delimiter[2] = ":";
	int *slices=(int *)malloc(sizeof(int)*3);
	char *token = strtok(time_in, time_delimiter);
	int slice_num = 0;
		while(token != NULL){
			
			slices[slice_num] =  atoi(token);
			token = strtok(NULL, time_delimiter);
			slice_num++;
		}
	return slices;

}
