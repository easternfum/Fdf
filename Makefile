# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 09:39:56 by kfum              #+#    #+#              #
#    Updated: 2022/03/29 09:39:56 by kfum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fdf

# Directories
INC_PATH = ./include
SRC_PATH = ./src/

# Flags
CC = gcc
FLAGS = -Wall -Wextra -Werror
MINILIB = -I /usr/local/include -L /usr/local/lib -l mlx -l ft -framework OpenGL -framework Appkit
INC_LIB = -Llibft
CPPFLAGS = -I./ -I./libft

# Files to compile
FILES = angle color control fdf graphic projection rotation window

# Files
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FILES)))
INC = $(addprefix -I, $(INC_DIR))
LIB_MLX = libft/libft.a

all : $(NAME)

libft/libft.a :
	@echo "$(GREEN)Compiling libft...$(DEFAULT)"
	make -C libft/ all
	@echo "$(GREEN)Compilation done.\n$(DEFAULT)"
	@echo "$(GREEN)Compiling fdf...$(DEFAULT)"

$(NAME) : $(LIB_MLX) $(OBJS)
	$(CC) $^ -o $@ $(FLAGS) $(INC_LIB) $(MINILIB)
	@echo "$(GREEN)Compilation done.$(DEFAULT)"

clean :
	@echo "$(RED)Cleaning libft .o and .a files...$(DEFAULT)"
	make fclean -C libft
	@echo "$(GREEN)DONE.\n$(DEFAULT)"
	@echo "$(RED)Cleaning $(NAME) .o files...$(DEFAULT)"
	rm -f $(OBJS)
	@echo "$(GREEN)DONE.$(DEFAULT)"

fclean : clean
	@echo "$(RED)Deleting .fdf...$(DEFAULT)" 
	rm -f $(NAME)
	@echo "$(GREEN)DONE.$(DEFAULT)"

re : fclean all

.PHONY: all clean fclean re

# Output colors
DEFAULT	:=\033[0m
GREEN	:=\033[0;32m
RED		:=\033[0;31m
