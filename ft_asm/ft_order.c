/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:17:12 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/21 18:17:13 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_init_pars(t_comp *comp, int *val, int *j, int a)
{
	*val = 1;
	*j = 0;
	comp->binary = 0;
	if (a == 1)
		(*val)++;
	if (!(comp->codage = (int*)realloc(comp->codage,
		sizeof(int) * comp->code + 2)))
		ft_exit(-1, comp);
	return (0);
}

static void		ft_end_pars(t_comp *comp, int has_pcode, int type)
{
	while (comp->binary < 64 && has_pcode != 0)
		comp->binary = comp->binary << 2;
	if (has_pcode == 1)
		comp->codage[comp->code++] = comp->binary;
	if (type != 0)
		ft_exit(-3, comp);
}

void			ft_pars_order(t_comp *comp, t_op *op, char *str, int nb)
{
	int	i;
	int j;
	int	val;

	i = ft_init_pars(comp, &val, &j, op[nb].has_pcode);
	while (str[i] && (size_t)i < ft_strlen(str))
	{
		i = ft_while_space(str, i);
		if (str[i] == 'r')
			i += ft_pars_reg(comp, &str[i], &val, op[nb].param[j++]);
		else if ((str[i] == 45 && ft_isdigit(str[i + 1])) || ft_isdigit(str[i]))
			i += ft_pars_ind(comp, &str[i], &val, op[nb].param[j++]);
		else if (str[i] == DIRECT_CHAR)
		{
			i += ft_pars_dir(comp, &str[i], op[nb].param[j++]);
			val += 4 - 2 * op[nb].has_idx;
		}
		else if (i >= 0 && (str[i] == COMMENT_CHAR ||
			str[i + 1] == COMMENT_CHAR))
			break ;
		else
			ft_exit(-3, comp);
	}
	ft_end_pars(comp, op[nb].has_pcode, op[nb].param[j]);
	comp->tmp_size += val;
}
