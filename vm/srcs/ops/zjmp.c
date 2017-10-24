/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:07:23 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/07 18:36:16 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	print(t_process *process, int *args)
{
	ft_printfnl("P %4d | zjmp %d %s", process->number, args[0],
			process->carry ? "OK" : "FAILED");
}

void		zjmp(t_vm *vm, t_process *process, t_op *op, int *args)
{
	(void)op;
	(void)vm;
	if ((vm->verbosity & 4) == 4)
		print(process, args);
	if (process->carry)
		process->pc = get_address(process->pc + (args[0] % IDX_MOD));
	else
		advance_pc(vm, process, 3);
}
