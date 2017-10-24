/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:17:46 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 16:31:59 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(t_btree*))
{
	if (root)
	{
		ft_btree_apply_infix(root->left, applyf);
		applyf(root);
		ft_btree_apply_infix(root->right, applyf);
	}
}
