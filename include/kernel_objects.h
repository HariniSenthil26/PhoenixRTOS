#ifndef KERNEL_OBJECTS_H
#define KERNEL_OBJECTS_H

#include "task.h"

void KernelObjects_Init(void);

bool KernelObjects_MoveToReady(TCB *task);

bool KernelObjects_MoveToBlocked(TCB *task);

bool KernelObjects_Delete(TCB *task);

#endif