cmake_minimum_required(VERSION 3.16)

project(PhoenixRTOS C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(PhoenixRTOS
    src/kernel.c
    src/list.c
    src/queue.c
    src/ready_queue.c
    src/task.c
    src/task_manager.c
    src/scheduler.c
)