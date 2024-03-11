# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 10:59:42 by cblonde           #+#    #+#              #
#    Updated: 2024/03/11 14:02:13 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall -fsanitize=thread -g

INCLUDES = -Iinclude

SRCS = main.c srcs/parse_error.c srcs/parse_args.c srcs/utils/ft_strlen.c srcs/utils/ft_atol.c\
	   srcs/utils/ft_putendl_fd.c srcs/utils_data.c srcs/utils/ft_calloc.c srcs/utils/ft_usleep.c\
	   srcs/utils_philo.c srcs/routine.c srcs/watcher.c

NAME = philo

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
