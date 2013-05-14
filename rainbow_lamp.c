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

color led[LED_NUMBER];

int main(void)
{
    /* initialize leds */
    reset_leds(led, LED_NUMBER);

#ifdef DEBUG
	printf("starting colors\n");
	dump_colors(led, LED_NUMBER);
#endif

    return 0;
}

