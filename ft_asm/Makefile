# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 15:42:31 by apouchet          #+#    #+#              #
#    Updated: 2017/10/07 16:51:03 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = asm

SRC = ./ft_asm.c ./ft_base.c ./header.c ./ft_read_cor.c ./ft_order.c ./ft_code.c ./ft_pars_type.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

make_lib :
	make -C libft

$(NAME) : make_lib $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean $(NAME)

norm :
	norminette $(SRC)
