/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:45:28 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/21 15:45:30 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_strtrim_free(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*a;

	i = 0;
	k = -1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		free((char*)s);
	if (!s[i])
		return (NULL);
	j = 0;
	while (s[i + j + 1])
		j++;
	while (s[i + j] == ' ' || s[i + j] == '\n' || s[i + j] == '\t')
		j--;
	if (!(a = (char*)malloc(sizeof(char) * ++j + 2)))
		return (NULL);
	while (k++ != j)
		a[k] = (char)s[i + k];
	a[j] = '\0';
	free((char*)s);
	return (a);
}

int		ft_find_order(t_op *op, char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != ' ' && str[j] != '\t')
		j++;
	while (i < 16 && ft_strncmp(str, op[i].name, j) != 0)
		i++;
	if (i >= 17)
		return (-1);
	return (i);
}

void	ft_link(t_comp *comp, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
		i++;
	if (!(comp->link[comp->nb_link] = (char*)malloc(sizeof(char) * (i + 3))) ||
		!(comp->link = (char**)realloc(comp->link, sizeof(char*) *
		(comp->nb_link + 3))) || !(comp->pos_link = (int*)realloc(comp->pos_link
		, sizeof(int) * (comp->nb_link + 3))))
		ft_exit(-1, comp);
	i = 0;
	while (str[i] != LABEL_CHAR)
	{
		if (ft_verif_name_lab(str[i]) == 0)
			ft_exit(5, comp);
		comp->link[comp->nb_link][i] = str[i];
		i++;
	}
	comp->pos_link[comp->nb_link] = comp->tmp_size;
	comp->link[comp->nb_link++][i] = '\0';
}

void	ft_order(t_comp *comp, t_op *op, char *str)
{
	int nb;
	int	j;

	j = 0;
	while (str[j] && (str[j] != LABEL_CHAR &&
		str[j + 1] != DIRECT_CHAR) && str[j] != ' ')
		j++;
	if (str[j] && (str[j + 1] != DIRECT_CHAR && str[j] == LABEL_CHAR))
	{
		j++;
		ft_link(comp, str);
	}
	else
		j = 0;
	j = ft_while_space(str, j);
	nb = ft_find_order(op, &str[j]);
	if ((nb = ft_find_order(op, &str[j])) == -1)
		ft_exit(0, comp);
	while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != COMMENT_CHAR)
		j++;
	if (!str[j])
		return ;
	if (str[j] && str[j] != COMMENT_CHAR)
		ft_pars_order(comp, op, &str[j], nb);
}

void	ft_read_cor(t_comp *comp, t_op *op)
{
	char	*line;
	int		end;

	end = 2;
	while ((end = get_next_line(comp->fdrd, &line)) > 0)
	{
		line = ft_strtrim_free(line);
		comp->ligne++;
		if (line != NULL && ft_verif_name_lab(line[0]) == 0 && *line != '\t' &&
			*line != ' ' && *line != COMMENT_CHAR && *line != '\0')
			ft_exit(-4, comp);
		if (line != NULL && *line != '\0' &&
			*line != COMMENT_CHAR && line[0] != '\n')
			ft_order(comp, op, line);
		free(line);
	}
	free(line);
}
