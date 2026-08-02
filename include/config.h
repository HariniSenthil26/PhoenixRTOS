#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define MAX_TASKS             (10U)
#define DEFAULT_STACK_SIZE    (256U)
#define TASK_NAME_LENGTH      (32U)
#define IDLE_TASK_PRIORITY    (255U)
#define KERNEL_TICK_RATE_HZ   (1000U)

#endif