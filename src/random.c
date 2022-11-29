#include "random.h"

#include <stdlib.h>

unsigned int randomInRange(unsigned int min, unsigned int max) {
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;
    do
        r = rand();
    while (r >= limit);
    return min + (r / buckets);
}