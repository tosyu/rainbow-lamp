/* @TODO define this properly! */
#define F_CPU 1.0L

#ifdef __unix
#include <stdio.h>
#endif
#include <stdlib.h>

#define LED_NUMBER 3
#define uint8_t unsigned char
#define limited_rand(a) (rand() / (RAND_MAX / 1.0) * (a))

typedef struct {
    uint8_t r;
    uint8_t b;
    uint8_t g;
} color;

color led[LED_NUMBER];
uint8_t rseed = 0;
uint8_t max_rand = sizeof(uint8_t) * 255;

void apply_random_color(color *c);
void reset_leds(color *leds, uint8_t length);
void reseed(void);

int main()
{
    int i;

    /* initialize leds */
    reset_leds(led, LED_NUMBER);

#ifdef __unix
    for (i = 0; i < LED_NUMBER; ++i) {
	  printf("#%d R:%d G:%d B:%d\n", (i + 1), led[i].r, led[i].g, led[i].b);
    }
#endif

    return 0;
}

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
    c_ptr->r = (uint8_t) limited_rand(max_rand);
    c_ptr->g = (uint8_t) limited_rand(max_rand);
    c_ptr->b = (uint8_t) limited_rand(max_rand);
}

void reseed() {
  if (rseed == 255) {
	rseed = 0;
  } else {
	++rseed;
  }
  srand(rseed);
}
