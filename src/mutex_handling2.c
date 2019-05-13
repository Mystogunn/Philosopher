/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** mutex_handling2
*/

#include "philo.h"

int think_lock(data_t *data)
{
	if (data->philo[data->index].chopstick == true) {
		pthread_mutex_lock(
			&data->philo
			[check_over(data->index - 1,
					data->philo->nbr_p)].mutex);
		lphilo_take_chopstick(
			&data->philo
			[check_over(data->index - 1,
					data->philo->nbr_p)].mutex);
	} else {
		pthread_mutex_lock(&data->philo
		[check_over(data->index,
				data->philo->nbr_p)].mutex);
		lphilo_take_chopstick(&data->philo
		[check_over(data->index,
				data->philo->nbr_p)].mutex);
		data->philo[data->index].chopstick = true;
	}
	return (true);
}

bool check_around(data_t *data)
{
	if (data->philo[check_over(data->index - 1, data->philo->nbr_p)]
		.chopstick == true)
		return (true);
	return (false);
}