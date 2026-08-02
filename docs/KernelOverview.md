# PhoenixRTOS Kernel Overview

## Kernel Responsibilities

The PhoenixRTOS kernel is responsible for:

- Task creation
- Task scheduling
- Context switching
- Time management
- Synchronization
- Inter-task communication
- Memory management

---

## Core Modules

- Generic Linked List
- Task Control Block (TCB)
- Ready Queue
- Scheduler
- Tick Manager
- Queue Manager
- Semaphore Manager
- Mutex Manager
- Timer Manager

---

## Design Philosophy

- Modular architecture
- Deterministic execution
- No hidden dynamic memory allocation
- Portable across microcontrollers
- Clean and testable C code