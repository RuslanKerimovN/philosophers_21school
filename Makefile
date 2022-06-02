# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 10:59:14 by botilia           #+#    #+#              #
#    Updated: 2022/04/21 11:39:59 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

MANDATORY = main.c	\
			utils.c	\
			init.c	\
			philosophers.c	\
			death_philo.c	\
			clear.c	\

FLAGS = -Wall -Wextra -Werror 

OBJ = $(patsubst %.c,%.o,$(MANDATORY))

HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	cc $(FLAGS) $(MANDATORY) -o $(NAME) 
clean	: 
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re 