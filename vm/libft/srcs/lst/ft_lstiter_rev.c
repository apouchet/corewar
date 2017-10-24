/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:13:58 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 18:13:59 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void			ft_lstiter_rev(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	ft_lstiter_rev(lst->next, f);
	f(lst);
}
