# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 18:08:37 by mmarinov          #+#    #+#              #
#    Updated: 2025/10/18 18:09:19 by mmarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

# ==== Project ====
NAME      := phonebook

# ==== Compiler & Flags ====
CXX       := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98 -pedantic-errors
INC       := -Iinc
DEPFLAGS  := -MMD -MP
RM        := rm -rf

# ==== Dirs ====
SRC_D     := src
OBJ_D     := objs

# ==== Sources (mecánico) ====
SRCS      := main.cpp \
             PhoneBook.cpp \
             Contact.cpp

# ==== Objects / Deps ====
OBJS      := $(SRCS:%.cpp=$(OBJ_D)/%.o)
DEPS      := $(OBJS:.o=.d)

# ==== Default ====
all: $(NAME)

# ==== Link ====
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@printf "Built: %s\n" "$(NAME)"

# ==== Compile ====
$(OBJ_D)/%.o: $(SRC_D)/%.cpp | $(OBJ_D)
	@$(CXX) $(CXXFLAGS) $(INC) $(DEPFLAGS) -c $< -o $@
	@printf "Compiled: %s\n" "$<"

$(OBJ_D):
	@mkdir -p $(OBJ_D)

# ==== Convenience ====
debug: CXXFLAGS += -g3 -fsanitize=address
debug: fclean $(NAME)

clean:
	@$(RM) $(OBJ_D)
	@printf "Cleaned objects\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Removed binary: %s\n" "$(NAME)"

re: fclean all

.PHONY: all clean fclean re debug

# ==== Auto deps ====
-include $(DEPS)
