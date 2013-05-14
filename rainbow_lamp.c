/* @TODO define this properly! */
#define F_CPU 1.0L

#ifdef DEBUG
#include <stdio.h>
#include "debug_utils.h"
#endif

#include <stdlib.h>
#include <stdint.h>

#include "utils.h"
#include "colors.h"
#include "color_utils.h"

#define LED_NUMBER 3
#define FADE_MAX_CYCLES 360

color led[LED_NUMBER];
color current_color;
color white = { UINT8_MAX, UINT8_MAX, UINT8_MAX };
unsigned int current_cycle = 0;
enum MODES { WHITE, FULL, RAINBOW };
enum MODES mode = RAINBOW;

void loop(void);
void save_current_color(color c);

int main(void)
{
    /* initialize leds */
    randomize_colors_array(led, LED_NUMBER);
   
	/* save initial */
	current_color.r = led[0].r;
	current_color.g = led[0].g;
	current_color.b = led[0].b;

#ifdef DEBUG
	printf("starting colors\n");
	dump_colors(led, LED_NUMBER);
#endif

	while (1) {
	  loop();
	  if (current_cycle == FADE_MAX_CYCLES) {
		current_cycle = 0;
	  }
	  current_cycle++;
	}

    return 0;
}

/* change this to interrupt handler */
void loop() {
  color c;
  switch (mode) {
  case WHITE:
	if (!compare_colors(white, current_color)) {
		apply_color_to_colors_array(white, led, LED_NUMBER);
		save_current_color(white);
	}
	break;
  case RAINBOW:
	c = HSVtoRGB(current_cycle, 1, 0.5);
	apply_color_to_colors_array(c, led, LED_NUMBER);
	break;
  default:
  case FULL:
	randomize_colors_array(led, LED_NUMBER);
	break;
  }
#ifdef DEBUG
	printf("starting colors\n");
	dump_colors(led, LED_NUMBER);
#endif
}

void save_current_color(color c) {
  current_color.r = c.r;
  current_color.g = c.g;
  current_color.b = c.b;
}
