#ifndef _COLOR_UTILS_H
#define _COLOR_UTILS_H 1

#include <stdint.h>
#include "colors.h"
#include "color_utils.h"

void randomize_colors_array(color *colors, uint8_t length);
void randomize_color(color *c_ptr);
void apply_color_to_colors_array(color c, color *colors, uint8_t length);
void apply_color(color c, color *c_ptr);
void apply_color_rgb(color *c_ptr, uint8_t r, uint8_t g, uint8_t b);
uint8_t compare_colors(color a, color b);
uint8_t compare_color_with_colors_array(color a, color *colors, uint8_t length);
color HSVtoRGB(float h, float s, float v);

#endif
