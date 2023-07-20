# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franck <franck@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:54:22 by icario            #+#    #+#              #
#    Updated: 2023/07/20 02:20:35 by franck           ###   ########.fr        #
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
#MLXFLAGS	= -L mlx -lm -lmlx -lXext -lX11

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libft
MLX_DIR = mlx

PARSING_DIR	= parsing

PARSING	= free_double_tab.c \
			get_map.c \
			parsing.c \
			split_file_map.c \
			check_map.c \

SRC_PARSING	= $(addprefix $(PARSING_DIR)/, $(PARSING))

_SRC	= main.c \
		$(SRC_PARSING) \

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