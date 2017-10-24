/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:49:12 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/21 12:49:13 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_strcp(t_header *head, t_comp *comp, char *str, int mode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '"')
		j++;
	j++;
	while (mode == 0 && str[j] != '"' && str[j])
	{
		if (i > PROG_NAME_LENGTH)
			ft_exit(1, comp);
		head->prog_name[i++] = str[j++];
	}
	while (mode == 1 && str[j] != '"' && str[j])
	{
		if (i > COMMENT_LENGTH)
			ft_exit(2, comp);
		head->comment[i++] = str[j++];
	}
	if (mode == 0)
		head->prog_name[i] = '\0';
	if (mode == 1)
		head->comment[i] = '\0';
}

int		inv_magic(int magic)
{
	int tmp;

	tmp = magic;
	magic = tmp << 8;
	tmp = tmp >> 2;
	magic = magic << 2;
	magic += tmp << 8;
	return (magic);
}

void	ft_header(t_header *head, t_comp *comp)
{
	char	*line;
	int		stape;

	stape = 0;
	while (stape != 2 && get_next_line(comp->fdrd, &line) > 0)
	{
		line = ft_strtrim_free(line);
		comp->ligne++;
		if (line != NULL && ft_strncmp(line, NAME_CMD_STRING, 5) == 0)
		{
			stape++;
			ft_strcp(head, comp, line, 0);
		}
		if (line != NULL && ft_strncmp(line, COMMENT_CMD_STRING, 8) == 0)
		{
			stape++;
			ft_strcp(head, comp, line, 1);
		}
		free(line);
	}
	if (stape != 2)
		ft_exit(5, comp);
	head->magic = COREWAR_EXEC_MAGIC;
}
