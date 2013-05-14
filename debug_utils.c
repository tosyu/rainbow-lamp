#include <stdio.h>
#include <stdint.h>
#include "colors.h"
#include "debug_utils.h"

void dump_color(color c) {
  printf("R:%d G:%d B:%d\n", c.r, c.g, c.b);
}

void dump_colors(color *colors, uint8_t length) {
  int i;
  for (i = 0; i < length; ++i) {
	printf("#%d ", (i+1));
	dump_color(colors[i]);
  }
}
