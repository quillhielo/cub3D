# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quill <quill@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 16:50:54 by quill             #+#    #+#              #
#    Updated: 2026/07/26 12:21:30 by quill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I inc -I inc/libft -I inc/get_next_line -I mlx
LFLAGS = -L inc/get_next_line -lget_next_line -L inc/libft -lft -L mlx -lmlx -lXext -lX11

SRCDIR = src
OBJDIR = objs

SRC = $(SRCDIR)/main.c \
		$(SRCDIR)/parsing/load_file.c \
    	$(SRCDIR)/parsing/load_file_utils.c \
   	 	$(SRCDIR)/utils/exit_utils.c \
   		$(SRCDIR)/exec/init_exec.c \
		
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFT_DIR = inc/libft
GNL_DIR = inc/get_next_line
MLX_DIR = mlx

LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_A   = $(GNL_DIR)/libget_next_line.a
MLX_A = $(MLX_DIR)/libmlx.a

all: $(OBJDIR) $(LIBFT_A) $(GNL_A) $(MLX_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(GNL_A):
	@make -C $(GNL_DIR)

$(MLX_A):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
