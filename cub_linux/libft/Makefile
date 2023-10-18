# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 21:41:21 by nsoares-          #+#    #+#              #
#    Updated: 2023/03/19 19:59:15 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

INCLUDE = libft.h

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

SRC = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_cmp_num.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_atoll.c\
			ft_strcmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
			ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		    ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		    print_char.c print_hex.c print_int.c print_ptr.c ft_utoa.c\
			print_str.c print_unsigned.c ft_printf.c ft_gnl_strjoin.c ft_gnl_strchr.c \
			get_next_line.c solve_errors.c ft_split_new.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
	$(RM)	$(SRC:.c=.o)
	
fclean: clean
		$(RM)	$(NAME)
		
re:	fclean	$(NAME)

.SILENT:  