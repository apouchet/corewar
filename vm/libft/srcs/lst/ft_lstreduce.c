/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 22:39:23 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:23:05 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_lstreduce(t_list *lst, void *(*f)(void*, void*, size_t))
{
	void		*res;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst->content);
	res = malloc(lst->content_size);
	ft_memcpy(res, lst->content, lst->content_size);
	while (lst->next)
	{
		res = f(res, lst->next->content, lst->next->content_size);
		lst = lst->next;
	}
	return (res);
}
