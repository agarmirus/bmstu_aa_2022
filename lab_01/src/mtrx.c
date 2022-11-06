#include "mtrx.h"

mtrx_t mtrxalloc(const size_t n, const size_t m)
{
    mtrx_t mtrx;

    mtrx.rptrs = calloc(n, sizeof(size_t *));

    if (!mtrx.rptrs)
        return mtrx;
 
    mtrx.n = n;
    mtrx.m = m;

    for (size_t i = 0; i < n; ++i)
    {
        mtrx.rptrs[i] = calloc(m, sizeof(size_t));

        if (!mtrx.rptrs[i])
        {
            mtrxfree(&mtrx);
            mtrx.rptrs = NULL;
            
            return mtrx;
        }
    }

    return mtrx;
}

void mtrxfree(mtrx_t *const mtrx)
{
    for (size_t i = 0; i < mtrx->n; ++i)
        free(mtrx->rptrs[i]);
    
    free(mtrx->rptrs);
}

void print_mtrx(mtrx_t *const mtrx)
{
    for (size_t i = 0; i < mtrx->n; ++i)
    {
        for (size_t j = 0; j < mtrx->m; ++j)
            printf("%zu\t", mtrx->rptrs[i][j]);
        
        printf("\n");
    }
}
