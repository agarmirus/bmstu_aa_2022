#include "recdamlev.h"

size_t rec_dam_lev(
    const char *s1,
    const char *s2,
    const size_t li1,
    const size_t li2
)
{
    if (li1 == 0)
        return li2;
    
    if (li2 == 0)
        return li1;

    if (li1 > 1 && li2 > 1)
        return min_size_t(4,
            rec_dam_lev(s1, s2, li1 - 1, li2) + 1,
            rec_dam_lev(s1, s2, li1, li2 - 1) + 1,
            rec_dam_lev(s1, s2, li1 - 1, li2 - 1) + (s1[li1 - 1] != s2[li2 - 1]),
            rec_dam_lev(s1, s2, li1 - 2, li2 - 2) + 1
        );

    return min_size_t(3,
        rec_dam_lev(s1, s2, li1 - 1, li2) + 1,
        rec_dam_lev(s1, s2, li1, li2 - 1) + 1,
        rec_dam_lev(s1, s2, li1 - 1, li2 - 1) + (s1[li1 - 1] != s2[li2 - 1])
    );
}
