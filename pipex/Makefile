# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:10:21 by angassin          #+#    #+#              #
#    Updated: 2023/05/03 08:12:27 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------COLORS------------------------------------------

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE='\033[1;94m'
RED='\033[1;91m'

#-------------------------------VARIABLES---------------------------------------

NAME		= pipex

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

DEBUG		= -g -fsanitize=address -fsanitize=undefined \
			  -fno-sanitize-recover=all	-fsanitize=float-divide-by-zero \
			  -fsanitize=float-cast-overflow -fno-sanitize=null \
			  -fno-sanitize=alignment

#--------------------------------SOURCES----------------------------------------

SRC			= $(PIPEX_SRC) $(UTILS_SRC)
SRC_BONUS	= $(BONUS_SRC) $(UTILS_SRC)

LIBFT_A 	= libft.a
LIBFT_DIR 	= libft/
LIBFT		= $(addprefix libft/, $(LIBFT_A))

PIPEX		= main.c pipex.c
PIPEX_SRC	= $(addprefix src/, $(PIPEX))

UTILS		= utils.c
UTILS_SRC	= $(addprefix utils/, $(UTILS))

BONUS		= main_bonus.c pipex.c
BONUS_SRC	= $(addprefix src/, $(BONUS))

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(SRC_BONUS:.c=.o)

#---------------------------------RULES-----------------------------------------

%o: %c
	@$(CC) $(CFLAGS) -Iincludes -c $< -o  $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

bonus : $(BONUS_OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Bonus compiled -"$(NONE)

exe: all
	@make -C ./ clean
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME) infile "ls -l" "wc -l" outfile
	@echo "\n     - Done -"

debug: $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all debug exe clean fclean re bonus
