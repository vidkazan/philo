#include "philo.h"

int right_fork(int n, t_list *data)
{
	return (n % data->philo_num);
}

int left_fork(int n, t_list *data)
{
	return (n - 1);
}

void	forks_create(t_list *data)
{
	int i;

	i = -1;
	while(++i < data->philo_num)
		pthread_mutex_init(&data->fork[i], NULL);
}

void	forks_destroy(t_list *data)
{
//	int i;
//
//	i = -1;
//	while(++i < data->philo_num)
//		pthread_mutex_destroy(&data->fork[i]);
//	pthread_mutex_destroy(&data->fork[0]);
}
