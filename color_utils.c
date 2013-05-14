#include <stdint.h>

#include "utils.h"
#include "colors.h"
#include "color_utils.h"

void reset_leds(color *leds, uint8_t length)
{
    int i;
    for (i = 0; i < length; ++i) {
	  apply_random_color(&leds[i]);
    }
}

void apply_random_color(color *c_ptr)
{
    reseed();
    c_ptr->r = (uint8_t) limited_rand(UINT8_MAX);
    c_ptr->g = (uint8_t) limited_rand(UINT8_MAX);
    c_ptr->b = (uint8_t) limited_rand(UINT8_MAX);
}
