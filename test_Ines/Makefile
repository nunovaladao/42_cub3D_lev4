# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:52:53 by nsoares-          #+#    #+#              #
#    Updated: 2023/11/12 23:41:36 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc 
RM = rm -rf
LIBFT = ./libft/libft.a


# _________SOURCES____________

SOURCE_FILES = gnl/get_next_line.c gnl/get_next_line_utils.c \
				testParser.c \
				

OBJS_FILES = $(SOURCE_FILES:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# _________MESSAGE_____________

COMPILATION_START	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Compilation start...\n"

COMPILING_LIBFT	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Libft\n"

CUB3D_READY  =   echo "\n$(BOLD_YELLOW)cub3D ready! ✅ \n"

CLEANED		=	echo "\n$(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n$(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

RE          =   echo "\n$(BOLD_YELLOW)Re: $(NO_COLOR)Compilation restarted \n"

# __________RULES______________

all: compilation_start $(NAME)

$(NAME): $(OBJS_FILES)
		@ $(COMPILING_LIBFT)
		@ $(MAKE) -C ./libft
		$(CC) $(SOURCE_FILES) $(LIBFT) -o $(NAME)
		@ $(CUB3D_READY)

compilation_start:
	@ $(COMPILATION_START)

clean:
	@ $(RM) $(OBJS_FILES)
	@ cd libft && make clean
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(NAME)
	@ cd libft && make fclean
	@ $(FCLEANED)
		
re:	fclean all
	@ $(RE) 
