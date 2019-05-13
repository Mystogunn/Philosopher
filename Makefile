##
## EPITECH PROJECT, 2018
## PSU_philosopher_2017
## File description:
## makefile
##

CC      = gcc

RM      = rm -rf

NAME    = philo

SRCS    = src/main.c			\
		  src/philo.c			\
		  src/mutex_handling.c	\
		  src/mutex_handling2.c

OBJS    = $(SRCS:.c=.o)

CFLAGS  =  -W -Wall -Wextra -I include

LDFLAGS = -L./ -lriceferee -lpthread

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
