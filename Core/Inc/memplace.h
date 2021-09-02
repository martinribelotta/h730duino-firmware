#ifndef __MEMPLACE_H__
#define __MEMPLACE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define PLACE_IN(name) __attribute__((section(name)))

#define PLACE_IN_ITCM PLACE_IN(".itcmtext")
#define PLACE_IN_DTCM PLACE_IN(".dtcmdata")
#define PLACE_IN_DTCM_BSS PLACE_IN(".dtcmbss")
#define PLACE_IN_QSPI PLACE_IN(".qspiftext")
#define PLACE_IN_QSPI_RODATA PLACE_IN(".qspifrodata")
#define PLACE_IN_IFLASH PLACE_IN(".text")
#define PLACE_IN_IFLASH_RODATA PLACE_IN(".rodata")


#ifdef __cplusplus
}
#endif

#endif // __MEMPLACE_H__
