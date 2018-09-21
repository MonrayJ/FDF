# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 09:01:12 by mjacobs           #+#    #+#              #
#    Updated: 2018/08/20 09:37:13 by mjacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Wextra -Werror
OPTION = -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
SRC = main.c \
	  get_next_line/get_next_line.c \
	  draw.c \
	  readmap.c \
	  key_hook.c \
	  get_next_line/libft/libft.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTION) $(SRC) -o fdf

clean:
	rm -f $(NAME)

fclean: clean

re: clean all
