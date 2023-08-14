# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoine <antoine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:54:22 by icario            #+#    #+#              #
#    Updated: 2023/08/14 18:52:19 by antoine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Colors ####
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END		= \033[0m

### Names ###
NAME 		= cube3D
LIBNAME 	= libft.a
CC 			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
MLXFLAGS	= -L mlx -lm -lmlx -lXext -lX11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libft
MLX_DIR = mlx

ERROR_DIR		= error
CLEAN_DIR		= clean
INIT_DIR		= init
RAYCASTING_DIR	= raycasting
INPUTS_DIR		= inputs

ERROR		= exit_msg.c
CLEAN		= clean_mlx.c \
			clean_img.c \
			terminate.c
INIT		= init_structs.c \
			init_mlx.c \
			init_game.c \
			init.c
RAYCASTING	= raycaster.c \
			draw_pixels.c \
			floor_and_ceiling.c
INPUTS		= inputs.c \

SRC_ERROR		= $(addprefix $(ERROR_DIR)/, $(ERROR))
SRC_CLEAN		= $(addprefix $(CLEAN_DIR)/, $(CLEAN))
SRC_INIT		= $(addprefix $(INIT_DIR)/, $(INIT))
SRC_RAYCASTING	= $(addprefix $(RAYCASTING_DIR)/, $(RAYCASTING))
SRC_INPUTS		= $(addprefix $(INPUTS_DIR)/, $(INPUTS))

_SRC	= main.c \
		start.c \
		$(SRC_ERROR) \
		$(SRC_CLEAN) \
		$(SRC_INIT) \
		$(SRC_RAYCASTING) \
		$(SRC_INPUTS)

SRC		= $(addprefix $(SRC_DIR)/, $(_SRC))
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEADER	= $(addprefix $(INC_DIR)/, $(NAME).h)

#### Makefile work ####
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		@mkdir -p $(@D)		
		@$(CC) -c $(CFLAGS) -I$(LIB_DIR) -Imlx -I$(INC_DIR) $< -o $@
		
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@echo "Baking $(LIB_DIR)"
		@make -s -C $(LIB_DIR)
		@echo "$(GREEN)OK!$(END)"
		@echo "Baking $(NAME)..."
		@$(CC) -I$(INC_DIR) -I$(LIB_DIR) -o $@ $^ $(LIB_DIR)/$(LIBNAME) $(MLXFLAGS) -Imlx $(CFLAGS)
		@echo "$(GREEN)OK!$(END)"
		@echo "$(BLUE)$(NAME) READY !$(END)"
		
clean:
		@echo "Removing objects..."
		@make clean -s -C $(LIB_DIR)
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)Done!$(END)"
		
fclean: clean
		@echo "Cleaning everything..."
		@make fclean -s -C $(LIB_DIR)
		@rm -f $(NAME)
		@echo "$(GREEN)Done!$(END)"
		@echo "$(BLUE)Everything is clean!$(END)"
		
re: fclean all

.PHONY: all clean fclean re
