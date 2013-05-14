#include <stdlib.h>
#include <stdint.h>
#include "utils.h"

static uint8_t rseed = 0;

void reseed() {
  if (rseed >= UINT8_MAX) {
	rseed = 0;
  } else {
	++rseed;
  }
  srand(rseed);
}
