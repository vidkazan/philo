#include "philo.h"

void philo_close()
{

}

//void thinking(int philo_id)
//{
//	printf("%05llums | philo %03d | is thinking\n", current_timestamp(), philo_id);
//	usleep(100);
//}

//void sleeping(int philo_id)
//{
//	printf("%05llums | philo %03d | is sleeping\n", current_timestamp(), philo_id);
//	usleep(1000 * data->sleep_time);
//}


void eating(t_philo *philo)
{
	unsigned long long stamp;
	stamp = current_timestamp(philo->data);
	pthread_mutex_lock(&philo->data->fork[0]);
	printf("%05llums | philo %03d | has taken  left %d fork %p\n", stamp, philo->id, philo->left_fork, &philo->data->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->data->fork[0]);
	printf("%05llums | philo %03d | has taken right %d fork %p\n", stamp, philo->id, philo->right_fork, &philo->data->fork[philo->right_fork]);
	printf("%05llums | philo %03d | is eating after %llu\n", stamp, philo->id, stamp - philo->last_meal_time);
	philo->meal_count++;
	philo->last_meal_time = stamp;
	usleep(1000 * philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
}

void *philosopher(void *philo_void)
{
    t_philo *philo = (t_philo *)philo_void;
    while(current_timestamp(philo->data) < 2000)
	{
		eating(philo);
//		sleeping(philo->id);
//		thinking(philo->id);
	}
    return  NULL;
}

void philos_create(t_list *data)
{
	int i;
	i = 0;
	while(++i < data->philo_num + 1)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = left_fork(data->philos[i].id, data);
		data->philos[i].right_fork = right_fork(data->philos[i].id, data);
		data->philos[i].last_meal_time = 0;
		data->philos[i].is_died = 0;
		data->philos[i].meal_count = 0;
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, philosopher, &data->philos[i]);
		usleep(100);
	}

}

void philos_join(t_list *data)
{
	int i;

	i = 0;
	while(++i < data->philo_num + 1)
	{
		if(pthread_join(data->philos[i].thread, NULL) < 0 )
			philo_close();
	}
}

void simulation(t_list *data)
{
	forks_create(data);
	start_timestamp(data);
	philos_create(data);
	philos_join(data);
	forks_destroy(data);
}

void init(t_list *data)
{
	data->start_ms = 0;
    data->die_time = 900;
    data->eat_time = 200;
    data->sleep_time = 200;
    data->philo_num = 1;
    data->philos = (t_philo *) malloc(sizeof (t_philo) * data->philo_num);
	data->fork = (pthread_mutex_t *) malloc(sizeof (pthread_mutex_t) * data->philo_num);
	data->someone_is_dead = 0;
}

int main()
{
	t_list data;
    init(&data);
    simulation(&data);
    return 0;
}
