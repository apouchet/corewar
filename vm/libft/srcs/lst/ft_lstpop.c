/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:22:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:22:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_lstpop(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	if (!current)
		return (NULL);
	if (!current->next)
	{
		*lst = NULL;
		return (current);
	}
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	return (tmp);
}
