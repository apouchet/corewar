/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:14:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/19 13:09:43 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*node;
	t_list		*res;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	res = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = f(lst);
		node = node->next;
	}
	return (res);
}
