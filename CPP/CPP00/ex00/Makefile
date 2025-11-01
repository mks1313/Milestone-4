# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 11:53:16 by mmarinov          #+#    #+#              #
#    Updated: 2025/10/11 17:53:25 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#--- COLORS ---#

GREEN   = \033[0;92m
MAGENTA = \033[0;95m
RED     = \033[0;91m
YELLOW  = \033[0;93m
BLUE    = \033[0;94m
BR      = \033[0m


NAME = megaphone

CC     = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM     = rm -rf
OBJ_D  = obj
SRC    = megaphone.cpp

OBJ = $(SRC:%.cpp=$(OBJ_D)/%.o)


all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -- "$(YELLOW) $(NAME) created! $(BR)"

$(OBJ_D)/%.o: %.cpp
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA) Compiled: $<$(BR)"

clean:
	@$(RM) $(OBJ_D)
	@echo -- "$(BLUE) Cleaned up object files! $(BR)"

fclean: clean
	@$(RM) $(NAME)
	@echo -- "$(GREEN) Executable $(NAME) removed. $(BR)"

re: fclean all

.PHONY: all clean fclean re 
