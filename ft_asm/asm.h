/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:34:51 by apouchet          #+#    #+#             */
/*   Updated: 2017/10/07 14:34:53 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft/lib.h"
# include "../op.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct	s_comp
{
	int			fdrd;
	int			fdwr;
	char		*file;
	char		**link;
	int			*pos_link;
	int			nb_link;
	int			*label;
	int			nb_label;
	int			binary;
	int			tmp_size;
	int			*codage;
	int			code;
	int			pos;
	int			ligne;
	int			*bin[2];
	int			bin_size;
}				t_comp;

char			*ft_strtrim_free(char const *s);

int				ft_pars_reg(t_comp *comp, char *str, int *val, int type);

int				ft_pars_ind(t_comp *comp, char *str, int *val, int type);

int				ft_pars_dir(t_comp *comp, char *str, int type);

int				ft_verif_name_lab(char c);

int				ft_inv(unsigned nbr);

int				ft_find_order(t_op *op, char *str);

void			ft_read_code(t_comp *comp, t_op *op, char *arg);

void			ft_code(t_comp *comp, t_op *op, char *str);

void			ft_pars_order(t_comp *comp, t_op *op, char *str, int nb);

void			ft_read_cor(t_comp *comp, t_op *op);

void			recup(t_op *op_tab);

void			ft_header(t_header *head, t_comp *comp);

int				ft_existe_com(int i, char *str, t_op *op_tab);

void			ft_re(t_op *op_tab, t_header *head, int	fd);

void			ft_affich_header(t_header *head, t_comp *comp);

int				ft_while_space(char *str, int i);

void			ft_exit(int	mode, t_comp *comp);

#endif
