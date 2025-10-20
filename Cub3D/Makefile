# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 15:08:55 by lgracia-          #+#    #+#              #
#    Updated: 2025/08/08 18:42:41 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g -O3 -fsanitize=address

NAME = cub3D

SRC = main.c utils.c error.c \
		parse/parse_file.c parse/parse_texture.c parse/parse_color.c \
		parse/parse_map.c parse/parse_map_first.c parse/parse_map_second.c \
		hooks/hooks.c  hooks/hooks_utils.c \
		clear/clear.c clear/clear_helper.c \
		ray_cast/draw.c ray_cast/ray_calc.c ray_cast/minimap.c \
		ray_cast/find_wall_hit.c ray_cast/init_dda.c

DSRC = $(addprefix src/, $(SRC))

DOBJ = obj

OBJ = $(addprefix $(DOBJ)/, $(SRC:.c=.o))

DEP = $(addprefix $(DOBJ)/, $(SRC:.c=.d))

LIBs = ./inc/libft/libft.a ./build/libmlx42.a -lm -lglfw

INC = -I ./inc -I ./MLX/include

all: make_lib dir $(NAME) 

dir:
	mkdir -p $(DOBJ)
	mkdir -p $(DOBJ)/parse
	mkdir -p $(DOBJ)/hooks
	mkdir -p $(DOBJ)/clear
	mkdir -p $(DOBJ)/ray_cast

make_lib:
	@$(MAKE) -C ./inc/libft
	@cmake -B build ./MLX
	@cmake --build build -j4

$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) $(LIBs) -o $(NAME)
	@echo "Compiled"

$(DOBJ)/%.o: src/%.c Makefile
	@cc $(FLAGS) $(INC) -MMD -o $@ -c $<

clean:
	@rm -rf $(DOBJ)
	@echo "Cleaned"

fclean: clean
	@rm -r ./build
	@$(MAKE) -C ./inc/libft fclean
	@rm $(NAME)
	@echo "Full cleaned"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
