/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:47:37 by apouchet          #+#    #+#             */
/*   Updated: 2017/08/21 12:47:38 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_inv(unsigned nbr)
{
	unsigned char	tmp[4];
	int				i;

	i = 0;
	while (i < 4)
	{
		tmp[i++] = nbr & 0x000000ff;
		nbr = nbr >> 8;
	}
	nbr = 0;
	i = 0;
	while (i < 4)
		nbr = (nbr << 8) + tmp[i++];
	return (nbr);
}

void	ft_open_file(t_comp *comp, char *arg)
{
	int i;

	i = ft_strlen(arg);
	if (arg[i - 1] != 's' || arg[i - 2] != '.')
		ft_exit(3, comp);
	if ((comp->fdrd = open(arg, O_RDONLY)) == -1)
		ft_exit(3, comp);
	if (!(comp->file = (char*)malloc(sizeof(char) * (ft_strlen(arg) + 5))))
		ft_exit(-1, comp);
	comp->file = ft_strcpy(comp->file, arg);
	i--;
	comp->file[i] = '\0';
	comp->file = ft_strcat(comp->file, "cor");
	comp->file[ft_strlen(comp->file)] = '\0';
}

void	ft_write_file(t_comp comp, t_header head)
{
	int i;

	i = 0;
	comp.fdwr = open(comp.file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	head.prog_size = ft_inv(comp.tmp_size);
	head.magic = ft_inv(head.magic);
	write(comp.fdwr, &head, sizeof(t_header));
	while (i < comp.bin_size)
	{
		write(comp.fdwr, &comp.bin[0][i], comp.bin[1][i]);
		i++;
	}
}

void	ft_start_comp(t_comp *comp)
{
	if (!(comp->pos_link = (int*)malloc(sizeof(int) * 2)) ||
		!(comp->label = (int*)malloc(sizeof(int) * 2)) ||
		!(comp->codage = (int*)malloc(sizeof(int) * 2)) ||
		!(comp->link = (char**)malloc(sizeof(char*) * 2)) ||
		!(comp->bin[0] = (int*)malloc(sizeof(int) * 2)) ||
		!(comp->bin[1] = (int*)malloc(sizeof(int) * 2)))
		ft_exit(-1, comp);
	comp->tmp_size = 0;
	comp->nb_link = 0;
	comp->code = 0;
	comp->nb_label = 0;
	comp->ligne = 0;
	comp->bin_size = 0;
}

int		main(int argc, char **argv)
{
	t_op		op_tab[17];
	t_comp		comp;
	t_header	head;

	if (argc == 2)
	{
		ft_bzero(&head, sizeof(t_header));
		ft_bzero(&comp, sizeof(t_comp));
		ft_start_comp(&comp);
		recup(op_tab);
		ft_open_file(&comp, argv[1]);
		ft_header(&head, &comp);
		ft_read_cor(&comp, op_tab);
		close(comp.fdrd);
		ft_read_code(&comp, op_tab, argv[1]);
		if (comp.tmp_size < 1)
			ft_exit(5, &comp);
		ft_write_file(comp, head);
	}
	else
		ft_exit(3, &comp);
	ft_printf("Writing output program to %s\n", comp.file);
	return (0);
}
