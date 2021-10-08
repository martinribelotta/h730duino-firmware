#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))
#define FOREACH(i, a) for ( typeof(*a) *i = a; i < (a + ARRAY_SIZE(a)); i++)

#ifdef __cplusplus
template<typename T, size_t N>
size_t arraySize(const T (&) [N]) {
    return N;
}

#endif


#ifdef __cplusplus
extern "C" {
#endif

static inline bool isEq(const char* a, const char* b)
{
    return 0 == strcmp(a, b);
}

extern void hexdump(const uint8_t *buf, size_t offset, size_t count);
extern void chexdump(const uint8_t* buf, size_t offset, size_t n, int columns);

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H__ */
