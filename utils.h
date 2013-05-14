#ifndef _UTILS_H_
#define _UTILS_H_ 1

#include <stdlib.h>

#define limited_rand(a) (rand() / (RAND_MAX / 1.0) * (a))
void reseed(void);

#endif
