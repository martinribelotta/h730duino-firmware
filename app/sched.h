#ifndef SCHED
#define SCHED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint_least32_t timestamp_t;
typedef uint_least32_t timedelta_t;

typedef struct {
    void* ctx;
    void (*func)(void* ctx);
} sched_func_t;

typedef struct sched_entry_s sched_entry_t;

struct sched_entry_s {
    timestamp_t exec_time;
    timestamp_t reload;
    sched_func_t functor;
};

typedef struct {
    sched_entry_t* pool;
    size_t pool_count;
} sched_t;

#define SCHED_FUNCTOR(ctx, func) ((sched_func_t) { ctx, func })

static inline sched_func_t sched_mkfunc2(void* ctx, void (*func)(void*))
{
    return ((sched_func_t) { ctx, func });
}

static inline sched_func_t sched_mkfunc(void (*func)(void*)) { return sched_mkfunc2(NULL, func); }

extern void sched_init(sched_t* self, sched_entry_t* pool, size_t count);
extern sched_entry_t* sched_scheduleDefer(sched_t* self, sched_func_t e);
extern sched_entry_t* sched_scheduleEvery(sched_t* self, timedelta_t t, sched_func_t e);
extern sched_entry_t* sched_scheduleAt(sched_t* self, timestamp_t t, sched_func_t e);
extern sched_entry_t* sched_scheduleBefore(sched_t* self, timedelta_t t, sched_func_t e);
extern void sched_scheduleEntry(sched_t* self, sched_entry_t* p, timestamp_t t, timedelta_t r, sched_func_t e);
extern void sched_scheduleEntryDefer(sched_t* self, sched_entry_t* p, sched_func_t e);
extern void sched_scheduleEntryEvery(sched_t* self, sched_entry_t* p, timedelta_t t, sched_func_t e);
extern void sched_scheduleEntryAt(sched_t* self, sched_entry_t* p, timestamp_t t, sched_func_t e);
extern void sched_scheduleEntryBefore(sched_t* self, sched_entry_t* p, timedelta_t t, sched_func_t e);
extern void sched_pool(sched_t* self);

extern timestamp_t __sched_priv_get_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* SCHED */
