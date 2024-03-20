# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 13:01:47 by cblonde           #+#    #+#              #
#    Updated: 2024/03/20 13:17:43 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra 

INCLUDES = -Iinclude

NAME = philo_bonus

SRCS = main.c srcs/utils/ft_atol.c srcs/utils/ft_calloc.c srcs/utils/ft_putendl_fd.c\
	   srcs/utils/ft_strlen.c srcs/utils/ft_usleep.c srcs/parse_args.c srcs/parse_error.c\
	   srcs/utils_data.c srcs/utils_philo.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : NAME all clean fclean re
