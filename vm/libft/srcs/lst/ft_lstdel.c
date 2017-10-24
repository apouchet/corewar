/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:14:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 17:02:57 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;

	if (!alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = temp;
	}
}
