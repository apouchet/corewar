/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:33:18 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/04 17:33:20 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_lsttail(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
