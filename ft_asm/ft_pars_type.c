/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:24:40 by apouchet          #+#    #+#             */
/*   Updated: 2017/09/18 16:24:41 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_pars_reg(t_comp *comp, char *str, int *val, int type)
{
	int i;

	i = 1;
	if (ft_atoi(&str[i]) > 16 && ft_atoi(&str[i]) >= 0)
		ft_exit(-2, comp);
	if (type != 1 && type != 3 && type != 5 && type != 7)
		ft_exit(-3, comp);
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i] != 32 && str[i] != '\t'
		&& str[i + 1] != COMMENT_CHAR)
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_exit(-2, comp);
	}
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i + 1] != COMMENT_CHAR)
		i++;
	i++;
	*val += 1;
	comp->binary = (comp->binary << 2) + 1;
	return (i);
}

int		ft_pars_ind(t_comp *comp, char *str, int *val, int type)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]) || (type != 4 && type != 5 &&
		type != 6 && type != 7) || str[i] == '+')
		ft_exit(-3, comp);
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i] != 32 && str[i] != '\t'
		&& str[i + 1] != COMMENT_CHAR)
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_exit(-3, comp);
	}
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i + 1] != COMMENT_CHAR)
		i++;
	i++;
	*val += 2;
	comp->binary = (comp->binary << 2) + 3;
	return (i);
}

int		ft_pars_dir(t_comp *comp, char *str, int type)
{
	int i;
	int mode;

	i = 1;
	mode = 0;
	if (type != 2 && type != 3 && type != 6 && type != 7)
		ft_exit(-3, comp);
	if (str[i] == LABEL_CHAR && str[i])
	{
		if (!(comp->label = (int*)realloc(comp->label, 4 * comp->nb_label + 2)))
			ft_exit(-1, comp);
		comp->label[comp->nb_label++] = comp->tmp_size;
		mode = 1;
		i++;
	}
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i] != 32 && str[i] != '\t'
		&& str[i + 1] != COMMENT_CHAR)
		((mode == 1 && ft_verif_name_lab(str[i])) || ft_isdigit(str[i]) ||
			(str[i] == 45 && ft_isdigit(str[i + 1]))) ? i++ : ft_exit(-3, comp);
	while (str[i] && str[i] != SEPARATOR_CHAR && str[i + 1] != COMMENT_CHAR)
		i++;
	comp->binary = (comp->binary << 2) + 2;
	return (++i);
}
