# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 10:06:19 by insoares          #+#    #+#              #
#    Updated: 2024/05/05 17:30:48 by insoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	ft_printf.c ft_printf_utils.c ft_printf_utils2.c
HEAD = ft_printf.h
OBJS =  $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(SRCS) $(OBJS)
	ar rcs $(NAME) $(SRCS) $(OBJS)
	
clean:
	$(RM) -f $(OBJS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
