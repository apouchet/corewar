/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:22:44 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:22:55 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*current;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
}
