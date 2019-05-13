/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "philo.h"
#include "extern.h"

void display_help(void)
{
	printf("USAGE\n"
		"\t./philo -p nbr_p -e nbr_e\n\n"
		"DESCRIPTION\n"
		"\t-p nbr_p number of philosophers\n"
		"\t-e nbr_e maximum number times a philosopher"
		" eats before exiting the program\n");
}

int is_num(char *str)
{
	int i = 0;

	while (str[i] != 0) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void init_struc(arg_t *arg)
{
	arg->help = 0;
	arg->nbr_p = 0;
	arg->nbr_e = 0;
}

bool check_arg(char **av, arg_t *arg)
{
	int i = 1;

	while (av[i] != NULL) {
		if (!strcmp(av[i], "--help"))
			arg->help = 1;
		else if (!strcmp(av[i], "-p") && av[i + 1] &&
			is_num(av[i + 1]))
			arg->nbr_p = atoi(av[i + 1]);
		(!strcmp(av[i], "-e") && av[i + 1] && is_num(av[i + 1])) ?
			(arg->nbr_e = atoi(av[i + 1])) : 0;
		i++;
	}
	if (arg->help || !arg->nbr_p || arg->nbr_p == 1 || !arg->nbr_e) {
		display_help();
		return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	arg_t arg;

	RCFStartup(ac, av);
	init_struc(&arg);
	if (!check_arg(av, &arg) || ac > 5)
		return (84);
	if (!philo_fnt(&arg))
		return (84);
	RCFCleanup();
	return (0);
}
