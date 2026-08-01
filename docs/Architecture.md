# PhoenixRTOS Architecture

## High-Level Architecture

```text
+----------------------------+
|      User Application      |
+----------------------------+
              |
              v
+----------------------------+
|         Kernel API         |
+----------------------------+
              |
              v
+----------------------------+
|         Scheduler          |
+----------------------------+
              |
              v
+----------------------------+
|      Task Management       |
+----------------------------+
      |                |
      |                |
      v                v
+------------+   +-------------+
|   Queues   |   |   Timers    |
+------------+   +-------------+
      |
      v
+----------------------------+
|      Memory Manager        |
+----------------------------+
              |
              v
+----------------------------+
| Hardware Abstraction Layer |
+----------------------------+
              |
              v
+----------------------------+
|            CPU             |
+----------------------------+
```

---

## Kernel Components

### Scheduler

Responsible for selecting the next task to execute.

### Task Manager

Creates, deletes and manages tasks.

### Queue Manager

Provides inter-task communication.

### Semaphore Manager

Provides synchronization between tasks.

### Mutex Manager

Protects shared resources.

### Timer Manager

Manages software timers.

### Memory Manager

Allocates task stacks and kernel memory.

---

## Design Goals

- Modular
- Portable
- Deterministic
- Lightweight
- Unit Testable
- Well Documented