# Generic Doubly Linked List Design

## Purpose

The linked list module provides a reusable data structure for managing kernel objects.

The scheduler, queues, timers, and synchronization primitives will all use this module.

---

## Design Goals

- Generic
- Lightweight
- Deterministic
- No dynamic memory allocation
- Constant-time insertion/removal

---

## Node Structure

```c
typedef struct ListNode
{
    void *data;

    struct ListNode *next;

    struct ListNode *prev;

} ListNode;
```

---

## List Structure

```c
typedef struct
{
    ListNode *head;

    ListNode *tail;

    uint32_t size;

} List;
```

---

## Supported Operations

- Initialize
- Insert Front
- Insert Back
- Remove Node
- Clear List
- Get Size
- Is Empty

---

## Memory Ownership

The linked list **does not allocate memory**.

The caller is responsible for creating and managing ListNode objects.

This avoids heap fragmentation and keeps the kernel deterministic.