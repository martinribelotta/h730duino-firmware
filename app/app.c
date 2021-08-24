#include "SEGGER_RTT.h"
#include "tusb.h"
#include "printf.h"
#include "microrl.h"
#include "exec.h"

static microrl_t rl;

static void cdc_task(void)
{
  while (tud_cdc_available() > 0) {
    char c = tud_cdc_read_char();
    microrl_insert_char(&rl, c);
  }
}

static void cdc_print(const char *s)
{
  tud_cdc_write_str(s);
  tud_cdc_write_flush();
}

void setup()
{
  SEGGER_RTT_WriteString(0, "Hello World!\n");
  tusb_init();
  microrl_init(&rl, cdc_print);
  rl.execute = exec_commands;

}

void loop()
{
    tud_task();
    cdc_task();
}

void _putchar(char character)
{
  tud_cdc_write_char(character);
  if (character == '\n')
    tud_cdc_write_flush();
}
