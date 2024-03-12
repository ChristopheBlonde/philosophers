# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 13:01:47 by cblonde           #+#    #+#              #
#    Updated: 2024/03/12 13:06:59 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

INCLUDE = -Linclude

NAME = philo_bonus

SRCS = main.c

OBJS = $(SRCS:.o=.c)

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
