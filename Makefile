# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:00:11 by mdi-paol          #+#    #+#              #
#    Updated: 2023/01/18 23:43:00 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
PRINTF = Printf/libftprintf.a
GET_SRC = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
SRC = main.c map_converter.c window.c input.c image.c check_map.c movement.c animations.c check_map_wrong.c check_map_wall.c character_coordinates.c

FLAGS = -no-pie -Wall -Werror -Wextra -g
LINKS = -lm -lX11 -lXext
all : $(NAME)

$(NAME) : lf pf so_long

lf:
			@make -C libft

pf:
			@make -C Printf

so_long :
			gcc $(FLAGS) $(SRC) $(GET_SRC) $(MINILIBX) $(PRINTF) $(LIBFT) $(LINKS) -o $(NAME)

clean :		libclean
			rm -rf $(OBJ)

libclean :
			@make clean -C libft

fclean :	clean libfclean
			rm -rf $(NAME)

libfclean :
			@make fclean -C libft

re : fclean all
