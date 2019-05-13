/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** mutex_handling
*/

#include "philo.h"

bool check_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_trylock(mutex) == 0) {
		lphilo_take_chopstick(mutex);
		return (true);
	}
	else
		return (false);
}

int check_over(int index, int nbr_p)
{
	if (index == -1)
		return (nbr_p - 1);
	else if (index == nbr_p)
		return (0);
	else
		return (index);
}

void rest(data_t *data)
{
	int sum = 0;

	if (check_around(data) == true)
		return;
	data->philo[data->index].chopstick =
		check_mutex(&data->philo[data->index].mutex);
	if (data->philo[data->index].chopstick == true)
		sum = 1;
	else {
		sum = data->philo[data->index].chopstick + check_mutex(
			&data->philo[check_over(data->index - 1,
				data->philo->nbr_p)].mutex);
	}
	if (sum == 1) {
		lphilo_think();
		data->philo[data->index].state = THINK;
	}
	else if (sum == 2) {
		lphilo_eat();
		data->philo[data->index].state = EAT;
	}
}

void think(data_t *data)
{
	usleep(500);
	if (think_lock(data) == false)
		return;
	data->philo[data->index].state = EAT;
	lphilo_eat();
}

void eat(data_t *data)
{
	data->philo[data->index].eat_max--;
	data->philo[data->index].state = REST;
	data->philo[data->index].chopstick = false;
	pthread_mutex_unlock(&data->philo[data->index].mutex);
	lphilo_release_chopstick(&data->philo[data->index].mutex);
	pthread_mutex_unlock(&data->philo
	[check_over(data->index - 1,
			data->philo->nbr_p)].mutex);
	lphilo_release_chopstick(&data->philo
	[check_over(data->index - 1,
			data->philo->nbr_p)].mutex);
	lphilo_sleep();
	usleep(1000);
}
