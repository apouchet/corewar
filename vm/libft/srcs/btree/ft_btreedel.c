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

void	ft_btreedel(t_btree **btree, void (*del)(void *, size_t))
{
	t_btree		*root;

	root = *btree;
	if (root)
	{
		ft_btreedel(&root->left, del);
		ft_btreedel(&root->right, del);
		if (del)
			del(root->content, root->content_size);
		free(root);
	}
}
