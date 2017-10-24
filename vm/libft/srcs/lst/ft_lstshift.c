/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:23:17 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:23:19 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_lstshift(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return (NULL);
	*lst = tmp->next;
	tmp->next = NULL;
	return (tmp);
}
