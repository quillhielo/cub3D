# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quill <quill@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 16:50:54 by quill             #+#    #+#              #
#    Updated: 2026/07/20 17:16:20 by quill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I inc -I inc/libft -I mlx
LFLAGS = -L inc/libft -lft -L mlx -lmlx -lXext -lX11

SRCDIR = src
OBJDIR = objs

SRC = $(SRCDIR)/main.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFT_DIR = inc/libft
MLX_DIR = mlx

LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

all: $(OBJDIR) $(LIBFT_A) $(MLX_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(MLX_A):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
