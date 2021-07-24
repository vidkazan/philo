cmake_minimum_required(VERSION 3.19)
project(philo_new C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_new main.c forks.c time.c)