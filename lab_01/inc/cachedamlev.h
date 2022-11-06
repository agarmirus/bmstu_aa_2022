#ifndef CACHEDAMLEV_H
#define CACHEDAMLEV_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#include "mtrx.h"
#include "mytools.h"
#include "myerrors.h"

int cache_dam_lev(
    size_t *const res,
    mtrx_t *cache,
    const char *s1,
    const char *s2,
    const size_t li1,
    const size_t li2
);

#endif
