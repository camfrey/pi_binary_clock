#include "framebuffer.h"

/* contains the necessary prototypes for the dispay handler block 
/  Daniel DeSantis
/  Cameron Frey
/  Tyler Petruccelli
/  Binary Clock CISC210 -- Spring 2019
/
*/


void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *fb); //Used to write time data to the screen

void display_colons(pi_framebuffer_t *fb); //Automatically draw the colons

void display_hours(int hours,  pi_framebuffer_t *fb); //Internal to the disp func

void display_minutes(int minutes, pi_framebuffer_t *fb);

void display_seconds(int seconds, pi_framebuffer_t *fb);

