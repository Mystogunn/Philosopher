/*
** EPITECH PROJECT, 2021
** PSU_philosopher_2017
** File description:
** Created by Yoann Sarkissian,
*/

#ifndef PSU_PHILOSOPHER_2017_PHILO_H
#define PSU_PHILOSOPHER_2017_PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "extern.h"

typedef enum state
{
	REST,
	THINK,
	EAT,
} t_state;

typedef struct arg {
	int help;
	int nbr_p;
	int nbr_e;
} arg_t;

typedef struct philo {
	pthread_mutex_t mutex;
	bool chopstick;
	t_state state;
	int eat_max;
	int nbr_p;
} philo_t;

typedef struct data {
	int index;
	philo_t *philo;
} data_t;

bool philo_fnt(arg_t *arg);
bool create_thread(philo_t *philo);
void *thread_fnt(void *arg);
bool check_mutex(pthread_mutex_t *mutex);
int check_over(int index, int nbr_p);
void rest(data_t *data);
void think(data_t *data);
void eat(data_t *data);
bool check_around(data_t *data);
int think_lock(data_t *data);

#endif //PSU_PHILOSOPHER_2017_PHILO_H
