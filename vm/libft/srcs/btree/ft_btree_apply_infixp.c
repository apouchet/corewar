/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infixp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:29:49 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/22 20:49:09 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infixp(t_btree *root, void (*applyf)(t_btree*, void*),
		void *param)
{
	if (root)
	{
		ft_btree_apply_infixp(root->left, applyf, param);
		applyf(root, param);
		ft_btree_apply_infixp(root->right, applyf, param);
	}
}
