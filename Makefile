CC=gcc

CFLAGS=-Wall -Wextra -std=c11 -Iinclude

SRC=src/list.c \
src/queue.c \
src/ready_queue.c \
src/task.c \
src/task_manager.c \
src/scheduler.c \
src/kernel.c

TARGET=PhoenixRTOS

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)