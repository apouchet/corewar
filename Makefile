# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 15:10:40 by apouchet          #+#    #+#              #
#    Updated: 2017/10/07 17:01:01 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_corewar

all : $(NAME)

$(NAME) :
	make -C ft_asm
	cp ft_asm/asm ./asm
	make -C vm
	cp vm/corewar_vm ./corewar

clean :
	make clean -C ft_asm
	make clean -C vm

fclean :
	make fclean -C ft_asm
	rm -f asm
	make fclean -C vm
	rm -f corewar

re : fclean $(NAME)
