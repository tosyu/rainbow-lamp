#ifndef _COLOR_UTILS_H
#define _COLOR_UTILS_H 1

#include <stdint.h>
#include "colors.h"
#include "color_utils.h"

void reset_leds(color *leds, uint8_t length);
void apply_random_color(color *c_ptr);


#endif
