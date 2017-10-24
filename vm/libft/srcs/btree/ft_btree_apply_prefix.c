/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:54:14 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:25:20 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(t_btree*))
{
	if (root)
	{
		applyf(root);
		ft_btree_apply_prefix(root->left, applyf);
		ft_btree_apply_prefix(root->right, applyf);
	}
}
