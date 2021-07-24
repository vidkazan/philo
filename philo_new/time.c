#include "philo.h"

void start_timestamp(t_list *data)
{
	gettimeofday(&data->timeval, &data->timezone);
	data->start_ms = data->timeval.tv_sec * 1000 + data->timeval.tv_usec / 1000;
}

unsigned long long current_timestamp(t_list *data)
{
	unsigned long long current_ms;
	gettimeofday(&data->timeval, &data->timezone);
	current_ms = data->timeval.tv_sec * 1000 + data->timeval.tv_usec / 1000;
	return (current_ms - data->start_ms);
}