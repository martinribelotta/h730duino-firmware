#ifndef __EXEC_H__
#define __EXEC_H__

#define COMMAND_ENTRY(name, func, descr) \
exec_command_entry_t __entry_##name __attribute__((used, section(".command_table"))) = { #name, descr, func }

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *command;
    const char *description;
    int (*func)(int argc, const char * const * argv);
} exec_command_entry_t;

int exec_commands(int argc, const char * const * argv);

#ifdef __cplusplus
}
#endif

#endif /* __EXEC_H__ */
