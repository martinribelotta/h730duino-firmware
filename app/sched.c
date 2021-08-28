#include "sched.h"

#include <string.h>
#include <printf.h>

extern void sched_init(sched_t* self, sched_entry_t* pool, size_t count)
{
    self->pool = pool;
    self->pool_count = count;
    memset(pool, 0, sizeof(sched_entry_t) * count);
}

static sched_entry_t *find_free(sched_t *self)
{
    for (size_t i = 0; i < self->pool_count; i++) {
        sched_entry_t *e = self->pool + i;
        if (e->functor.func == NULL) {
            return e;
        }
    }
    return NULL;
}

static void entry_free(sched_entry_t *e) {
    e->functor.func = NULL;
}

extern void sched_scheduleDefer(sched_t* self, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    if (p) {
        p->functor = e;
        p->exec_time = __sched_priv_get_tick();
        p->reload = 0;
    }
}

extern void sched_scheduleEvery(sched_t* self, timedelta_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    if (p) {
        p->functor = e;
        p->exec_time = __sched_priv_get_tick() + t;
        p->reload = t;
    }
}

extern void sched_scheduleAt(sched_t* self, timestamp_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    if (p) {
        p->functor = e;
        p->exec_time = t;
        p->reload = 0;
    }
}

extern void sched_scheduleBefore(sched_t* self, timedelta_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    if (p) {
        p->functor = e;
        p->exec_time = __sched_priv_get_tick() + t;
        p->reload = 0;
    }
}

extern void sched_pool(sched_t* self)
{
    timestamp_t curr = __sched_priv_get_tick();
    for (size_t i = 0; i < self->pool_count; i++) {
        sched_entry_t *e = self->pool + i;
        if (e->functor.func != NULL) {
            if (curr >= e->exec_time) {
                e->functor.func(e->functor.ctx);
                if (e->reload != 0) {
                    e->exec_time += e->reload;
                } else {
                    entry_free(e);
                }
            }
        }
    }
}
