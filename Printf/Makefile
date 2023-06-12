# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 15:27:35 by mdi-paol          #+#    #+#              #
#    Updated: 2022/10/27 16:51:29 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_checkformat.c ft_functions.c ft_functions1.c ft_itoa_base.c \
		ft_printf.c ft_functions2.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm -f
NAME =		libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
