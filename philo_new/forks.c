#include "philo.h"

int right_fork(int philo_id, t_list *data)
{
	return (philo_id % data->philo_num);
}

int left_fork(int philo_id, t_list *data)
{
	return (philo_id - 1);
}

void	forks_create(t_list *data)
{
	int i;

	i = -1;
	while(++i < data->philo_num)
		pthread_mutex_init(&data->fork[i], NULL);
}
