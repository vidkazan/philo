#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mut;

typedef struct s_philo
{
    int id;
    pthread_t thread;
}   t_philo;

typedef struct  s_list
{
    int philo_num;
    int eat_time;
    int sleep_time;
    int die_time;
    struct timeval start_timeval;
    struct timezone timezone;
    t_philo *philos;
}               t_list;
