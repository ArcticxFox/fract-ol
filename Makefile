# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 17:06:12 by ejones            #+#    #+#              #
#    Updated: 2026/03/09 15:17:41 by ejones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT_DIR ?= ./object_files
SRC_DIR = ./src
BONUS_DIR = ./bonus
INC_DIR = ./header
MLX_DIR = ./minilibx-linux

SRCC = main.c draw_mandelbrot.c manage_zoom.c event_handler.c draw_julia.c \
		parsing.c
OBJ_C = $(addprefix $(OBJECT_DIR)/, $(SRCC:.c=.o))

SRCC_BONUS = main_bonus.c draw_mandelbrot_bonus.c manage_zoom_bonus.c \
	event_handler_bonus.c draw_julia_bonus.c parsing_bonus.c move_axis_bonus.c \
	snowflake_koch.c init_fractals.c
OBJ_B = $(addprefix $(OBJECT_DIR)/, $(SRCC_BONUS:.c=.o))

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(MLX_DIR)
LDFLAGS += -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

UTILS = libft.a
NAME = fractol
BONUS = fractol_bonus

#==============================MANDATORY==============================#
all: $(NAME)

$(UTILS):
	@make -C libft

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(UTILS) $(OBJ_C)
	@echo "The Object files have been variled"
	@$(CC) $(OBJ_C) $(UTILS) $(LDFLAGS) -o $(NAME)

#================================BONUS================================#

$(OBJECT_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(UTILS) $(OBJ_B)
	@echo "The Object files have been variled"
	@$(CC) $(OBJ_B) $(UTILS) $(LDFLAGS) -o $(BONUS)

clean:
	@rm -rf $(OBJECT_DIR);
	@echo "Objects were removed Succesfully!!!!"

# Does clean and removes libft.a
fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make fclean -C libft
	@echo "The NAME was Succesfully Removed!!!!"

# Does fclean and then revariles everything
re: fclean $(NAME)


# Declaration of PHONY intructions
.PHONY: all clean fclean re bonus

-include $(OBJ_C:.o=.d)
