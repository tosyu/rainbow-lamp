#include <stdlib.h>
#include <stdint.h>
#include "utils.h"

static uint8_t rseed = 0;

void reseed() {
  if (rseed == 255) {
	rseed = 0;
  } else {
	++rseed;
  }
  srand(rseed);
}
