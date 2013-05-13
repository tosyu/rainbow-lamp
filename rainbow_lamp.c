#define F_CPU 1.0L

#include <stdio.h>
#include <stdlib.h>

#define LED_NUMBER 3
#define uint8_t unsigned char

typedef struct {
  uint8_t r;
  uint8_t b;
  uint8_t g;
} color;

color led[LED_NUMBER];

void apply_random_color(color *c);

int main() {
  int i, seed;
  color c;

  /* seed the random number generator */
  srand(0);

  /* initialize leds */
  for (i = 0; i < LED_NUMBER; ++i) {
	apply_random_color(&led[i]);
  }

  for (i = 0; i < LED_NUMBER; ++i) {
	printf("#%d R:%d G:%d B:%d\n", (i+1), led[i].r, led[i].g, led[i].b);
  }

  return 0;
}

void apply_random_color(color *c_ptr) {
  uint8_t max_rand = sizeof(uint8_t);
  c_ptr->r = (uint8_t) (rand() / (RAND_MAX / 1.0) * max_rand);
  c_ptr->g = (uint8_t) (rand() / (RAND_MAX / 1.0) * max_rand);
  c_ptr->b = (uint8_t) (rand() / (RAND_MAX / 1.0) * max_rand);
}
