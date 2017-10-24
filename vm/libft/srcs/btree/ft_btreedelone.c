/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 21:44:56 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/16 21:47:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreedelone(t_btree **btree, void (*del)(void *, size_t))
{
	if (*btree)
	{
		if (del)
			del((*btree)->content, (*btree)->content_size);
		free(*btree);
		*btree = NULL;
	}
}
