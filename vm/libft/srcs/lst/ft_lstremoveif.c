/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:44:56 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/07 20:00:56 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_remove(void (*del)(void *, size_t), t_list *current,
						t_list **prev, t_list *next)
{
	if (del)
		del(current->content, current->content_size);
	free(current);
	if (*prev)
		(*prev)->next = next;
}

void			ft_lstremoveif(t_list **lst, void (*del)(void *, size_t),
				int (*f)(void*, void*), void *param)
{
	t_list *current;
	t_list *prev;
	t_list *next;

	if (!lst)
		return ;
	prev = NULL;
	current = *lst;
	while (current)
	{
		next = current->next;
		if (f(current->content, param))
		{
			if (current == *lst)
				*lst = current->next;
			else
				ft_remove(del, current, &prev, next);
		}
		else
			prev = current;
		current = next;
	}
}
