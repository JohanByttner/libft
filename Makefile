# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/05/06 01:44:55 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC_FILES =					\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlen.c			\
		ft_strdup.c			\
		ft_strcpy.c			\
		ft_strncpy.c		\
		ft_strlcpy.c		\
		ft_strcat.c			\
		ft_strncat.c		\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strstr.c			\
		ft_strnstr.c		\
		ft_strcmp.c			\
		ft_strncmp.c		\
		ft_atoi.c			\
		ft_strtol.c			\
		ft_islower.c		\
		ft_isupper.c		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_isspace.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_memalloc.c		\
		ft_memdel.c			\
		ft_strnew.c			\
		ft_strdel.c			\
		ft_strclr.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strequ.c			\
		ft_strnequ.c		\
		ft_strsub.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_strsplit.c		\
		ft_itoa.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putendl.c		\
		ft_putnbr.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_memadjust.c		\
		ft_dmax.c			\
		ft_dmin.c			\
		ft_memdup.c			\
		ft_lstlast.c		\
		ft_lstmerge.c		\
		ft_strskip.c		\
		ft_strisdigit.c		\
		ft_strarrclr.c		\
		get_next_line.c

INCLUDES = -I ./includes/
SRC_DIR=./srcs/
BUILD_DIR=./obj/

OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(BUILD_DIR), $(OBJ_FILES))

CC=gcc
CFLAGS=-Wall -Wextra -Werror -c -O1
AR=ar
ARFLAGS=rc
RM=rm -rf

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	TARGET_OS=Linux
else
	TARGET_OS=OSX
endif

.PHONY : all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	@echo Compiling for $(TARGET_OS)
	@echo "Making >> $(NAME) <<"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(BUILD_DIR)
	@-$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@echo "Removing objects in >> $(NAME) <<"
	@$(RM) $(OBJ) $(BUILD_DIR)

fclean:	clean
	@echo "Removing binaries in >> $(NAME) <<"
	@$(RM) $(NAME)

re: fclean all
