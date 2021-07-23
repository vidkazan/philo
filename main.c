#include "philo.h"

void *eating()
{
    return (NULL);
}

void philo_close(t_list *data)
{
    exit(0);
}

void *start_sim(void *in)
{
    t_philo *philo = (t_philo *)in;
    //pthread_mutex_lock(&mut);
    printf("philo %d is here:)\n", philo->id);
    //pthread_mutex_unlock(&mut);
    return  NULL;
}

void init(t_list *data)
{
    int i;

    data->die_time = 900;
    data->eat_time = 200;
    data->sleep_time = 200;
    data->philo_num = 5;
    data->philos = (t_philo *) malloc(sizeof (t_philo) * data->philo_num);
    pthread_mutex_init(&mut,NULL);
    i = -1;
    while(++i < data->philo_num)
    {
        data->philos[i].id = i;
        if(pthread_create(&data->philos[i].thread, NULL, start_sim, &data->philos[i]) < 0)
        {
            printf("here");
            philo_close(data);
        }
    }
    i = -1;
    while(++i < data->philo_num)
    {
        data->philos[i].id = i;
        if(pthread_join(data->philos[i].thread, NULL) < 0 )
        {
            printf("here2");
            philo_close(data);
        }
    }
    pthread_mutex_destroy(&mut);
    philo_close(data);
}

int main()
{
    t_list *data;
    data = (t_list *)malloc(sizeof(t_list));
    init(data);
    return 0;
}
