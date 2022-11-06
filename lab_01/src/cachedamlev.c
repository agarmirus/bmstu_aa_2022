#include "cachedamlev.h"

static void fill_mtrx_with_inf(mtrx_t *const mtrx)
{
    for (size_t i = 0; i < mtrx->n; ++i)
        for (size_t j = 0; j < mtrx->m; ++j)
            mtrx->rptrs[i][j] = LONG_MAX;
}

int cache_dam_lev(
    size_t *const res,
    mtrx_t *cache,
    const char *s1,
    const char *s2,
    const size_t li1,
    const size_t li2
)
{
    bool first_call = false;
    
    if (!cache->rptrs)
    {
        *cache = mtrxalloc(strlen(s1) + 1, strlen(s2) + 1);

        if (!cache->rptrs)
            return MEMORY_ALLOCATION_ERROR;

        fill_mtrx_with_inf(cache);

        first_call = true;
    }

    if (li1 == 0)
    {
        cache->rptrs[0][li2] = li2;
        return li2;
    }
    
    if (li2 == 0)
    {
        cache->rptrs[li1][0] = li1;
        return li1;
    }

    size_t r1 = 0, r2 = 0, r3 = 0;

    cache_dam_lev(&r1, cache, s1, s2, li1 - 1, li2);
    cache_dam_lev(&r2, cache, s1, s2, li1, li2 - 1);
    cache_dam_lev(&r3, cache, s1, s2, li1 - 1, li2 - 1);
    
    ++r1;
    ++r2;
    r3 += s1[li1 - 1] != s2[li2 - 1];

    if (li1 > 1 && li2 > 1)
    {
        size_t r4 = 0;

        cache_dam_lev(&r4, cache, s1, s2, li1 - 2, li2 - 2);
        ++r4;

        *res = min_size_t(4, r1, r2, r3, r4);
    }
    else
        *res = min_size_t(3, r1, r2, r3);
    
    if (cache->rptrs[li1][li2] == LONG_MAX)
        cache->rptrs[li1][li2] = *res;
    
    if (first_call)
        mtrxfree(cache);
    
    return EXIT_SUCCESS;
}
