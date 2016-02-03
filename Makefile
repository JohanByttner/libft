# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/03 11:32:28 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c		\
		ft_memchr.c ft_memcmp.c											\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c	\
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c	\
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c				\
		ft_atoi.c ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c	\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c				\
		ft_tolower.c													\
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c	\
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c	\
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c				\
		ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c	\
		ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c		\
		ft_putnbr_fd.c													\
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c	\
		ft_lstmap.c	\
		ft_memadjust.c	\
		ft_dmax.c ft_dmin.c \
		ft_memdup.c	\
		ft_lstlast.c ft_lstmerge.c
ROOTDIR=./
LIBDIR=$(ROOTDIR)./
BINDIR=$(ROOTDIR)./
INCDIR=$(ROOTDIR)includes/
BUILDDIR=$(ROOTDIR)./
DIR=./

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -c -g
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRC)
	$(AR) $(ARFLAGS) $(LIBDIR)$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all

tb: all fclean
