#ifndef MYTOOLS_H
#define MYTOOLS_H

#include <stdarg.h>
#include <stddef.h>

#define DEF_MIN(type) type min_##type(size_t count, ...)

#define MIN(type) type min_##type(size_t count, ...)\
{ \
    va_list args; \
    va_start(args, count); \
    type m = va_arg(args, type); \
    for (size_t i = 0; i < count - 1; ++i) \
    { \
        type a = va_arg(args, type); \
        if (a < m) \
            m = a; \
    } \
    va_end(args); \
    return m; \
}

DEF_MIN(size_t);

#endif
