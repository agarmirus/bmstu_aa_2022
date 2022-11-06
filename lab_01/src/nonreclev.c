#include "nonreclev.h"

int non_rec_lev(size_t *const res, const char *s1, const char *s2)
{
    size_t n = strlen(s1) + 1;
    size_t m = strlen(s2) + 1;

    if (n == 1)
        return m - 1;

    if (m == 1)
        return n - 1;

    mtrx_t mtrx = mtrxalloc(n, m);

    if (!mtrx.rptrs)
        return MEMORY_ALLOCATION_ERROR;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
                mtrx.rptrs[i][j] = 0;
            else if (i == 0)
                mtrx.rptrs[i][j] = j;
            else if (j == 0)
                mtrx.rptrs[i][j] = i;
            else
                mtrx.rptrs[i][j] = min_size_t(3,
                    mtrx.rptrs[i][j - 1] + 1,
                    mtrx.rptrs[i - 1][j] + 1,
                    mtrx.rptrs[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])
                );
        }
    }

    *res = mtrx.rptrs[n - 1][m - 1];

    mtrxfree(&mtrx);

    return EXIT_SUCCESS;
}
