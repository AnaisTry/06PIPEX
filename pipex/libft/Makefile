# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 17:09:20 by angassin          #+#    #+#              #
#    Updated: 2023/04/28 18:42:23 by angassin         ###   ########.fr        #
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

NAME		=	libft.a

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g 

#--------------------------------SOURCES----------------------------------------

SRCS		=	$(LIBC_SRC) $(42_SRC) $(LISTS_SRC) $(GNL_SRC) $(PRINTF_SRC)



LIBC		=	ft_isalpha.c ft_isdigit.c  ft_isalnum.c ft_isascii.c \
				ft_isprint.c  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_itoa.c ft_calloc.c \
				ft_strdup.c ft_strstr.c ft_atol.c 
LIBC_SRC	=	$(addprefix libc/, $(LIBC))

FT_42		=	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c  \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c  ft_putnbr_fd.c ft_nbrlen_base.c \
				ft_putnbr_base_fd.c ft_put_unbr_base_fd.c ft_unbrlen_base.c \
				ft_strrncmp.c ft_free_array.c
42_SRC		=	$(addprefix ft_42/, $(FT_42))	

FT_LISTS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c node_create.c node_handle.c
LISTS_SRC	=	$(addprefix ft_lists/, $(FT_LISTS))

GNL			=	get_next_line.c get_next_line_utils.c 
GNL_SRC		=	$(addprefix get_next_line/, $(GNL))

FT_PRINTF 	=	ft_printf.c eval.c padding.c print_char.c print_integer.c \
				print_unsigned.c print_address.c
PRINTF_SRC	=	$(addprefix ft_printf/, $(FT_PRINTF))	

OBJS 		=	$(SRCS:.c=.o)

#---------------------------------RULES-----------------------------------------

all:		$(NAME)

%o: %c
	@$(CC) $(CFLAGS) -Iincludes -c $< -o  $(<:.c=.o)

$(NAME):	$(OBJS)
	@echo $(CURSIVE)$(GRAY)"          - Compiling libft..." $(NONE)
	@echo $(CURSIVE)$(GRAY)"          - Generating $(NAME)..." $(NONE)
	@ar -rcs  $(NAME) $(OBJS)


	 
clean:
	@echo $(CURSIVE)$(GRAY)"          - Removing libft object files"... $(NONE)
	@$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
	@echo $(CURSIVE)$(GRAY)"          - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re