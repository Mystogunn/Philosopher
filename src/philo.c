/*
** EPITECH PROJECT, 2018
** philo.c
** File description:
** philo
*/

#include "philo.h"

bool philo_fnt(arg_t *arg)
{
	philo_t *philo = malloc(sizeof(philo_t) * arg->nbr_p);

	for (int i = 0; i < arg->nbr_p; i++) {
		if (pthread_mutex_init(&philo[i].mutex, NULL) != 0) {
			return (false);
		}
		philo[i].chopstick = false;
		philo[i].state = REST;
		philo[i].eat_max = arg->nbr_e;
		philo[i].nbr_p = arg->nbr_p;
	}
	if (!create_thread(philo))
		return (false);
	return (true);
}

bool create_thread(philo_t *philo)
{
	pthread_t thread[philo->nbr_p];
	data_t *data = NULL;

	for (int i = 0; i < philo->nbr_p; i++) {
		data = malloc(sizeof(data_t));
		data->index = i;
		data->philo = philo;
		if (pthread_create(&thread[i], NULL, thread_fnt, data))
			return (false);
		usleep(1000);
	}
	for (int i2 = 0; i2 < philo->nbr_p; i2++) {
		if (pthread_join(thread[i2], NULL))
			return (false);
	}
	return (true);
}

void *thread_fnt(void *arg)
{
	data_t *data = (data_t *)arg;

	while (data->philo[data->index].eat_max > 0) {
		if (data->philo[data->index].state == REST)
			rest(data);
		else if (data->philo[data->index].state == THINK)
			think(data);
		else
			eat(data);
	}
	pthread_exit(NULL);
}
