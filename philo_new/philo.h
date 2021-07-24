#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_list t_list;

typedef struct		s_philo
{
    int				id;
    pthread_t		thread;
    pthread_mutex_t mutex;
    int				left_fork;
    int				right_fork;
    unsigned long long 			last_meal_time;
    short 			is_died;
    int 			meal_count;
    t_list  		*data;
}					t_philo;

typedef struct  	s_list
{
    int 			philo_num;
    int 			eat_time;
    int 			sleep_time;
    int 			die_time;
    unsigned long long	start_ms;
    struct timeval	timeval;
    struct timezone	timezone;
    t_philo 		*philos;
    pthread_mutex_t	*fork;
    short 			someone_is_dead;
}               	t_list;


void start_timestamp();
unsigned long long current_timestamp();

int 	right_fork(int n, t_list *data);
int 	left_fork(int n, t_list *data);
void	forks_create(t_list *data);
void	forks_destroy(t_list *data);

void 	philo_close();