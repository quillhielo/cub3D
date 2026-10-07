# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+         #
#                                                 #   Created: 2025/05/29 10:11:14 by acarbajo          #+#    #+#              #
#    Updated: 2025/08/12 14:18:21 by acarbajo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE -I . -I ../libft

SRCS = get_next_line.c  # Agrega get_next_line_utils.c si lo tienes
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re