/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:39:28 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/22 21:00:29 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeadd(t_btree **root, t_btree *new,
					int (*cmpf)(t_btree*, t_btree*))
{
	if (*root == NULL)
		*root = new;
	else if (cmpf(new, *root) < 0)
		ft_btreeadd(&((*root)->left), new, cmpf);
	else
		ft_btreeadd(&((*root)->right), new, cmpf);
}
