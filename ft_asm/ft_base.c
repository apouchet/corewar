/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:41:01 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/21 15:41:03 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void			recup(t_op *op_tab)
{
	int i;

	i = 0;
	while (i < 17)
	{
		op_tab[i] = g_op_tab[i];
		i++;
	}
}

int				ft_verif_name_lab(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	if (!LABEL_CHARS[i])
		return (0);
	return (0);
}

int				ft_while_space(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

void			ft_exit(int mode, t_comp *comp)
{
	if (mode < 1 && mode != -1)
	{
		ft_printf("Error line : %d -> ", comp->ligne);
		if (mode == 0)
			ft_printf("False instruction\n");
		if (mode == -2)
			ft_printf("Register value false\n");
		if (mode == -3)
			ft_printf("False parameter\n");
		if (mode == -4)
			ft_printf("Syntax error\n");
		if (mode == -5)
			ft_printf("Invalid label\n");
	}
	if (mode == -1)
		ft_printf("Malloc Error\n");
	if (mode == 1)
		ft_printf("Name more 128 caracter\n");
	if (mode == 2)
		ft_printf("Comment more 2048 caracter\n");
	if (mode == 3)
		ft_printf("Invalid Files\n");
	if (mode == 5)
		ft_printf("Missing instruction\n");
	exit(0);
}
