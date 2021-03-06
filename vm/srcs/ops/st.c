/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:58:53 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/07 20:46:31 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	print(t_process *process, int *args)
{
	ft_printfnl("P %4d | st r%d %d", process->number, args[0], args[1]);
}

void		st(t_vm *vm, t_process *process, t_op *op, int *args)
{
	int		reg;
	int		idx;
	int		val;

	reg = args[0];
	if (!is_reg_valid(reg))
		return ;
	val = get_reg_val(process, reg);
	if (op->args_types[1] == T_IND)
	{
		idx = args[1];
		set_int(vm, process->pc + (idx % IDX_MOD), val);
	}
	else if (op->args_types[1] == T_REG)
	{
		reg = args[1];
		if (!is_reg_valid(reg))
			return ;
		set_reg_val(process, reg, val);
	}
	if ((vm->verbosity & 4) == 4)
		print(process, args);
}
