# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icario <icario@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:54:22 by icario            #+#    #+#              #
#    Updated: 2023/08/27 15:53:49 by icario           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Colors ####
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END		= \033[0m

### Names ###
NAME 		= cube3D
NAME_BONUS	= cube3D_bonus
LIBNAME 	= libft.a
CC 			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
MLXFLAGS	= -L mlx -lm -lmlx -lXext -lX11


SRC_DIR = src
BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
INC_DIR = inc
INC_DIR_BONUS = inc_bonus
LIB_DIR = libft
MLX_DIR = mlx

ERROR_DIR		= error
CLEAN_DIR		= clean
INIT_DIR		= init
RAYCASTING_DIR	= raycasting
INPUTS_DIR		= inputs
PARSING_DIR		= parsing

ERROR		= exit_msg.c
CLEAN		= clean_mlx.c \
			clean_img.c \
			clean_parsing.c \
			terminate.c
INIT		= init_structs.c \
			init_structs2.c \
			init_mlx.c \
			init_game.c \
			init_texs.c \
			init.c
RAYCASTING	= raycaster.c \
			draw_pixels.c \
			floor_and_ceiling.c
INPUTS		= inputs.c \
			movements.c \
			rotate.c
PARSING	= free_double_tab.c \
			get_map.c \
			parsing.c \
			split_file_map.c \
			check_map.c \
			check_map_info.c \
			check_digit_info.c \
			check_texture.c \
			check_args.c \
			fill.c \
			check_file_texture.c \

SRC_ERROR		= $(addprefix $(ERROR_DIR)/, $(ERROR))
SRC_CLEAN		= $(addprefix $(CLEAN_DIR)/, $(CLEAN))
SRC_INIT		= $(addprefix $(INIT_DIR)/, $(INIT))
SRC_RAYCASTING	= $(addprefix $(RAYCASTING_DIR)/, $(RAYCASTING))
SRC_INPUTS		= $(addprefix $(INPUTS_DIR)/, $(INPUTS))
SRC_PARSING	= $(addprefix $(PARSING_DIR)/, $(PARSING))

_SRC	= main.c \
    $(SRC_PARSING) \
		start.c \
		$(SRC_ERROR) \
		$(SRC_CLEAN) \
		$(SRC_INIT) \
		$(SRC_RAYCASTING) \
		$(SRC_INPUTS)

SRC		= $(addprefix $(SRC_DIR)/, $(_SRC))
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEADER	= $(addprefix $(INC_DIR)/, $(NAME).h)

#### Bonus ####
_SRC_BONUS = $(_SRC:.c=_bonus.c) \
			$(RAYCASTING_DIR)/minimap_bonus.c \

SRC_BONUS	= $(addprefix $(SRC_DIR)/, $(_SRC_BONUS))
OBJ_BONUS	= $(SRC_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR_BONUS)%.o)
HEADER_BONUS	= $(addprefix $(INC_DIR_BONUS)/, $(NAME_BONUS).h)

#### Makefile work ####
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		@mkdir -p $(@D)		
		@$(CC) -c $(CFLAGS) -I$(LIB_DIR) -Imlx -I$(INC_DIR) $< -o $@

#### Bonus ####
$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c $(HEADER_BONUS)
		@mkdir -p $(@D)		
		@$(CC) -c $(CFLAGS) -I$(LIB_DIR) -Imlx -I$(INC_DIR_BONUS) $< -o $@
		
all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ) $(HEADER) $(INC_DIR)/parsing.h
		@echo "Baking $(LIB_DIR)..."
		@make -s -C $(LIB_DIR)
		@echo "Baking $(MLX_DIR)..."
		@make -s -C $(MLX_DIR)
		@echo "$(GREEN)OK!$(END)"
		@echo "Baking $(NAME)..."
		@$(CC) -I$(INC_DIR) -I$(LIB_DIR) -o $@ $^ $(LIB_DIR)/$(LIBNAME) $(MLXFLAGS) -Imlx $(CFLAGS)
		@echo "$(GREEN)OK!$(END)"
		@echo "$(BLUE)$(NAME) READY !$(END)"

bonus: $(NAME_BONUS)
		
$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS) $(INC_DIR_BONUS)/parsing_bonus.h
		@echo "Baking $(LIB_DIR)..."
		@make -s -C $(LIB_DIR)
		@echo "Baking $(MLX_DIR)..."
		@make -s -C $(MLX_DIR)
		@echo "$(GREEN)OK!$(END)"
		@echo "Baking $(NAME_BONUS)..."
		@$(CC) -I$(INC_DIR_BONUS) -I$(LIB_DIR) -o $@ $^ $(LIB_DIR)/$(LIBNAME) $(MLXFLAGS) -Imlx $(CFLAGS)
		@echo "$(GREEN)OK!$(END)"
		@echo "$(BLUE)$(NAME_BONUS) READY !$(END)"
		
clean:
		@echo "Removing objects..."
		@make clean -s -C $(LIB_DIR)
		@make clean -s -C $(MLX_DIR)
		@rm -rf $(OBJ_DIR)
		@rm -rf $(OBJ_DIR_BONUS)
		@echo "$(GREEN)Done!$(END)"
		
fclean: clean
		@echo "Cleaning everything..."
		@make fclean -s -C $(LIB_DIR)
		@make clean -s -C $(MLX_DIR)
		@rm -f $(NAME)
		@rm -f $(NAME_BONUS)
		@echo "$(GREEN)Done!$(END)"
		@echo "$(BLUE)Everything is clean!$(END)"
		
re: fclean all

.PHONY: all clean fclean re
