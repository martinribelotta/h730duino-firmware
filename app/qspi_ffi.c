#include "qspi_ffi.h"

#include <stm32h7xx.h>
#include <stm32h7xx_hal.h>
#include <stm32h7xx_hal_conf.h>
#include <stm32h7xx_hal_ospi.h>

#include <printf.h>

#include "exec.h"
#include "utils.h"

#include <memory.h>

#define QSPI_TIMEOUT 100

#define IS25_RESETEN 0x66
#define IS25_RESET 0x99
#define IS25_ENTERQPI 0x35
#define IS25_EXITQPI 0xF5
#define IS25_FASTREAD 0x0B

#define IS25_DUMMY_CYCLES 8

extern OSPI_HandleTypeDef hospi1;
extern OSPI_HandleTypeDef hospi2;

#define pQSPI (&hospi2)

static const char* st2str(HAL_StatusTypeDef st)
{
    switch (st) {
    case HAL_OK:
        return "Ok";
    case HAL_ERROR:
        return "Error";
    case HAL_BUSY:
        return "Busy";
    case HAL_TIMEOUT:
        return "Timeout";
    default:
        return "Unknown state";
    }
}

#define CHECK(st)                                                            \
    do {                                                                     \
        if (st != HAL_OK) {                                                  \
            printf("qpsi [%s]. on %s:%d\n", st2str(st), __FILE__, __LINE__); \
            return false;                                                    \
        }                                                                    \
    } while (0)

#define CHECK_SZ(st)                                                         \
    do {                                                                     \
        if (st != HAL_OK) {                                                  \
            printf("qpsi [%s]. on %s:%d\n", st2str(st), __FILE__, __LINE__); \
            return -1;                                                       \
        }                                                                    \
    } while (0)

bool qspi_exit_qpi(void)
{
    OSPI_RegularCmdTypeDef cmd;
    cmd.OperationType = HAL_OSPI_OPTYPE_COMMON_CFG;
    cmd.FlashId = HAL_OSPI_FLASH_ID_2;
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_4_LINES;
    cmd.InstructionSize = HAL_OSPI_INSTRUCTION_8_BITS;
    cmd.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;
    cmd.AddressDtrMode = HAL_OSPI_ADDRESS_DTR_DISABLE;
    cmd.AddressSize = 0;
    cmd.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
    cmd.DataMode = HAL_OSPI_DATA_NONE;
    cmd.DummyCycles = 0;
    cmd.DQSMode = HAL_OSPI_DQS_DISABLE;
    cmd.SIOOMode = HAL_OSPI_SIOO_INST_EVERY_CMD;

    cmd.Instruction = IS25_EXITQPI;
    CHECK(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    return true;
}

bool qspi_init(void)
{
    // qspi_exit_qpi();

    OSPI_RegularCmdTypeDef cmd;
    cmd.OperationType = HAL_OSPI_OPTYPE_COMMON_CFG;
    cmd.FlashId = HAL_OSPI_FLASH_ID_2;
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.InstructionSize = HAL_OSPI_INSTRUCTION_8_BITS;
    cmd.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;
    cmd.AddressDtrMode = HAL_OSPI_ADDRESS_DTR_DISABLE;
    cmd.AddressSize = 0;
    cmd.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
    cmd.DataMode = HAL_OSPI_DATA_NONE;
    cmd.DummyCycles = 0;
    cmd.DQSMode = HAL_OSPI_DQS_DISABLE;
    cmd.SIOOMode = HAL_OSPI_SIOO_INST_EVERY_CMD;

    cmd.Instruction = IS25_RESETEN;
    CHECK(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    cmd.Instruction = IS25_RESET;
    CHECK(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    // cmd.Instruction = IS25_ENTERQPI;
    // CHECK(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    return true;
}

uint16_t qspi_rdid(void)
{
    uint16_t buf = 0xFFFF;
    OSPI_RegularCmdTypeDef cmd;
    cmd.OperationType = HAL_OSPI_OPTYPE_COMMON_CFG;
    cmd.FlashId = HAL_OSPI_FLASH_ID_2;

    cmd.Instruction = 0xAB;
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.InstructionSize = HAL_OSPI_INSTRUCTION_8_BITS;
    cmd.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;

    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;

    cmd.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;

    cmd.NbData = 2;
    cmd.DataMode = HAL_OSPI_DATA_1_LINE;
    cmd.DataDtrMode = HAL_OSPI_DATA_DTR_DISABLE;

    cmd.DummyCycles = 3;
    cmd.DQSMode = HAL_OSPI_DQS_DISABLE;
    cmd.SIOOMode = HAL_OSPI_SIOO_INST_EVERY_CMD;

    CHECK_SZ(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    CHECK_SZ(HAL_OSPI_Receive(pQSPI, (uint8_t*)&buf, QSPI_TIMEOUT * 4));
    return buf;
}

size_t qspi_read(uint8_t* buf, uint32_t addr, size_t count)
{
    OSPI_RegularCmdTypeDef cmd;
    cmd.OperationType = HAL_OSPI_OPTYPE_COMMON_CFG;
    cmd.FlashId = HAL_OSPI_FLASH_ID_2;

    cmd.Instruction = 0x03;
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.InstructionSize = HAL_OSPI_INSTRUCTION_8_BITS;
    cmd.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;

    cmd.Address = addr;
    cmd.AddressMode = HAL_OSPI_ADDRESS_1_LINE;
    cmd.AddressDtrMode = HAL_OSPI_ADDRESS_DTR_DISABLE;
    cmd.AddressSize = HAL_OSPI_ADDRESS_24_BITS;

    cmd.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;

    cmd.NbData = count;
    cmd.DataMode = HAL_OSPI_DATA_1_LINE;
    cmd.DataDtrMode = HAL_OSPI_DATA_DTR_DISABLE;

    cmd.DummyCycles = 0;
    cmd.DQSMode = HAL_OSPI_DQS_DISABLE;
    cmd.SIOOMode = HAL_OSPI_SIOO_INST_EVERY_CMD;

    CHECK_SZ(HAL_OSPI_Command(pQSPI, &cmd, QSPI_TIMEOUT));
    CHECK_SZ(HAL_OSPI_Receive(pQSPI, buf, QSPI_TIMEOUT * 4));
    return count;
}

static int qspi_cmd(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    if (qspi_init()) {
        printf("QSPI Inited\n");
    }
    uint16_t id = qspi_rdid();
    printf("RDID %04X\n", id);
    static uint8_t buf[32];
    memset(buf, 1, sizeof(buf));
    qspi_read(buf, 0, sizeof(buf));
    hexdump(buf, 0, sizeof(buf));
    return 0;
}

static COMMAND_ENTRY(qspi, qspi_cmd, "QSPI commands");
