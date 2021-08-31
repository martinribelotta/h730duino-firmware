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
    memset(e, 0, sizeof(sched_entry_t));
}

extern sched_entry_t* sched_scheduleDefer(sched_t* self, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    sched_scheduleEntryDefer(self, p, e);
    return p;
}

extern sched_entry_t* sched_scheduleEvery(sched_t* self, timedelta_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    sched_scheduleEntryEvery(self, p, t, e);
    return p;
}

extern sched_entry_t* sched_scheduleAt(sched_t* self, timestamp_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    sched_scheduleEntryAt(self, p, t, e);
    return p;
}

extern sched_entry_t* sched_scheduleBefore(sched_t* self, timedelta_t t, sched_func_t e)
{
    sched_entry_t* p = find_free(self);
    sched_scheduleEntryBefore(self, p, t, e);
    return p;
}

void sched_scheduleEntry(sched_t* self, sched_entry_t* p, timestamp_t t, timedelta_t r, sched_func_t e)
{
    (void) self;
    if (p) {
        p->functor = e;
        p->exec_time = t;
        p->reload = r;
    }
}

void sched_scheduleEntryDefer(sched_t* self, sched_entry_t* p, sched_func_t e)
{
    sched_scheduleEntryAt(self, p, __sched_priv_get_tick(), e);
}

void sched_scheduleEntryEvery(sched_t* self, sched_entry_t* p, timedelta_t t, sched_func_t e)
{
    sched_scheduleEntry(self, p, __sched_priv_get_tick() + t, t, e);
}

void sched_scheduleEntryAt(sched_t* self, sched_entry_t* p, timestamp_t t, sched_func_t e)
{
    sched_scheduleEntry(self, p, t, 0, e);
}

void sched_scheduleEntryBefore(sched_t* self, sched_entry_t* p, timedelta_t t, sched_func_t e)
{
    sched_scheduleEntryAt(self, p, __sched_priv_get_tick() + t, e);
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
