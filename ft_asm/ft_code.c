/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:45:42 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/22 13:45:43 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_find_label(t_comp *comp, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j] && str[j] != ',' && str[j] != ' ' && str[j] != '\t')
		j++;
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 2))))
		ft_exit(-1, comp);
	tmp[0] = '\0';
	ft_strncat(tmp, &str[i], j);
	j++;
	while (i < comp->nb_link && ft_strncmp(tmp, comp->link[i], j))
		i++;
	free(tmp);
	if (i >= comp->nb_link)
	{
		ft_printf("Error : label '%s' not find\n", str);
		ft_exit(6, comp);
	}
	return (i);
}

void	wcode(t_comp *comp, int val, int size, int nb)
{
	if (nb == 1 && size != 1)
		val = val >> 16;
	if (!(comp->bin[0] = (int*)realloc(comp->bin[0], (sizeof(int) *
		(comp->bin_size + 2)))) || !(comp->bin[1] = (int*)realloc(comp->bin[1],
		(sizeof(int) * (comp->bin_size + 2)))))
		ft_exit(-1, comp);
	comp->bin[0][comp->bin_size] = val;
	comp->bin[1][comp->bin_size] = size;
	comp->bin_size++;
}

void	ft_pars_code(t_comp *comp, t_op *op, char *str, int nb)
{
	int i;

	i = 0;
	while (str[i])
	{
		i = ft_while_space(str, i);
		if (str[i] == 'r')
			wcode(comp, ft_atoi(&str[++i]), 1, op[nb].has_idx);
		else if ((str[i] == 45 && ft_isdigit(str[i + 1])) || ft_isdigit(str[i]))
			wcode(comp, (ft_inv(ft_atoi(&str[i++])) >> 16), 2, op[nb].has_idx);
		else if (str[i] == DIRECT_CHAR)
		{
			if (str[++i] == LABEL_CHAR)
				wcode(comp, ft_inv(comp->pos_link[ft_find_label(
					comp, &str[++i])] - comp->label[comp->nb_label++]), 4 - 2 *
					op[nb].has_idx, op[nb].has_idx);
			else
				wcode(comp, ft_inv(ft_atoi(&str[i])), 4 - 2 *
					op[nb].has_idx, op[nb].has_idx);
		}
		while (str[i] && str[i - 1] != ',' && str[i + 1] != COMMENT_CHAR)
			i++;
		if (str[i] == COMMENT_CHAR || str[i + 1] == COMMENT_CHAR)
			return ;
	}
}

void	ft_order_code(t_comp *comp, t_op *op, char *str)
{
	int nb;
	int	j;

	j = 0;
	while (str[j] && (str[j] != LABEL_CHAR &&
		str[j + 1] != DIRECT_CHAR) && str[j] != ' ')
		j++;
	if (str[j] && (str[j + 1] != DIRECT_CHAR && str[j] == LABEL_CHAR))
		j++;
	else
		j = 0;
	j = ft_while_space(str, j);
	nb = ft_find_order(op, &str[j]);
	if ((nb = ft_find_order(op, &str[j])) == -1)
		ft_exit(0, comp);
	while (str[j] && str[j] != ' ' && str[j] != '\t')
		j++;
	if (!str[j] || nb >= 16)
		return ;
	nb++;
	wcode(comp, nb, 1, 0);
	if (op[nb - 1].has_pcode == 1)
		wcode(comp, comp->codage[comp->code++], 1, 0);
	ft_pars_code(comp, op, &str[j], nb - 1);
}

void	ft_read_code(t_comp *comp, t_op *op, char *arg)
{
	char *line;

	comp->code = 0;
	comp->nb_label = 0;
	comp->pos = 0;
	comp->fdrd = open(arg, O_RDONLY);
	while (get_next_line(comp->fdrd, &line) > 0)
	{
		line = ft_strtrim_free(line);
		if (line != NULL && *line != '\0' && *line != COMMENT_CHAR)
			ft_order_code(comp, op, line);
		free(line);
	}
	free(line);
	return ;
}
