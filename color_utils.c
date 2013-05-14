#include <stdint.h>
#include <math.h>

#include "utils.h"
#include "colors.h"
#include "color_utils.h"

void randomize_colors_array(color *colors, uint8_t length)
{
    int i;
    for (i = 0; i < length; ++i) {
	  randomize_color(&colors[i]);
    }
}

void randomize_color(color *c_ptr)
{
    reseed();
	apply_color_rgb(c_ptr, (uint8_t) limited_rand(UINT8_MAX), (uint8_t) limited_rand(UINT8_MAX), (uint8_t) limited_rand(UINT8_MAX));
}

void apply_color_to_colors_array(color c, color *colors, uint8_t length) {
  int i;
  for (i = 0; i < length; ++i) {
	apply_color(c, &colors[i]);
  }
}

void apply_color(color c, color *c_ptr) {
  apply_color_rgb(c_ptr, c.r, c.g, c.b);
}

void apply_color_rgb(color *c_ptr, uint8_t r, uint8_t g, uint8_t b) {
  c_ptr->r = r;
  c_ptr->g = g;
  c_ptr->b = b;
}

uint8_t compare_colors(color a, color b) {
  return (a.r == b.r && a.g == b.g && a.b == b.b);
}

uint8_t compare_color_with_colors_array(color a, color *colors, uint8_t length) {
  int i;
  for (i = 0; i < length; ++i) {
	if (!compare_colors(a, colors[i])) {
	  return 0;
	}
  }

  return 1;
}

color HSVtoRGB(float h, float s, float v) {
  color c;
  int i;
  float f, p, q, t;

  if (s == 0) {
	c.r = c.g = c.b = (uint8_t) (v * UINT8_MAX);
	return c;
  }

  h /= 60;
  i = floor(h);
  f = h - i;
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  
  switch (i) {
  case 0:
	c.r = (uint8_t) (v * UINT8_MAX);
	c.g = (uint8_t) (t * UINT8_MAX);
	c.b = (uint8_t) (p * UINT8_MAX);
	break;
  case 1:
	c.r = (uint8_t) (q * UINT8_MAX);
	c.g = (uint8_t) (v * UINT8_MAX);
	c.b = (uint8_t) (p * UINT8_MAX);
	break;
  case 2:
	c.r = (uint8_t) (p * UINT8_MAX);
	c.g = (uint8_t) (v * UINT8_MAX);
	c.b = (uint8_t) (t * UINT8_MAX);
	break;
  case 3:
	c.r = (uint8_t) (p * UINT8_MAX);
	c.g = (uint8_t) (q * UINT8_MAX);
	c.b = (uint8_t) (v * UINT8_MAX);
	break;
  case 4:
	c.r = (uint8_t) (t * UINT8_MAX);
	c.g = (uint8_t) (p * UINT8_MAX);
	c.b = (uint8_t) (v * UINT8_MAX);
	break;
  default:
	c.r = (uint8_t) (v * UINT8_MAX);
	c.g = (uint8_t) (p * UINT8_MAX);
	c.b = (uint8_t) (q * UINT8_MAX);
	break;
  }

  return c;
}

