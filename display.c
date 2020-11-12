#include "framebuffer.h"
#include <stdio.h>
#include <stdlib.h>


void display_colons(pi_framebuffer_t *fb){
	uint16_t white=getColor(153,0,153);
        	fb->bitmap->pixel[1][1]=white;
        	fb->bitmap->pixel[1][2]=white;
        	fb->bitmap->pixel[2][1]=white;
        	fb->bitmap->pixel[2][2]=white;
        	fb->bitmap->pixel[4][1]=white;
        	fb->bitmap->pixel[4][2]=white;
        	fb->bitmap->pixel[5][1]=white;
        	fb->bitmap->pixel[5][2]=white;
        	fb->bitmap->pixel[1][4]=white;
        	fb->bitmap->pixel[1][5]=white;
        	fb->bitmap->pixel[2][4]=white;
        	fb->bitmap->pixel[2][5]=white;
        	fb->bitmap->pixel[4][4]=white;
        	fb->bitmap->pixel[4][5]=white;
        	fb->bitmap->pixel[5][4]=white;
        	fb->bitmap->pixel[5][5]=white;
}

void display_hours(int hours, pi_framebuffer_t *fb){

	int B;
	uint16_t blue=getColor(0,0,255);
	for (int c = 7; c >= 0; c--){
		B = hours >> c;
		if(B & 1){
        		fb->bitmap->pixel[6][c]=blue;
		}	
	}
}


void display_minutes(int minutes, pi_framebuffer_t *fb){
	int B;
	uint16_t green=getColor(0,255,0);
	for (int c = 7; c >= 0; c--){
		B = minutes >> c;
		if(B & 1){
        		fb->bitmap->pixel[3][c]=green;
		}	
	}
}


void display_seconds(int seconds, pi_framebuffer_t *fb){
	int B;
	uint16_t red=getColor(255,0,0);
	for (int c = 7; c >= 0; c--){
		B = seconds >> c;
		if(B & 1){
        		fb->bitmap->pixel[0][c]=red;
		}	
	}
}

void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *fb){
	display_colons(fb);
	display_hours(hours,fb);
	display_minutes(minutes,fb);
	display_seconds(seconds,fb);
}
