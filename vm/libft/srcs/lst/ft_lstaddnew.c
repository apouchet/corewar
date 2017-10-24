/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 20:13:18 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/07 20:15:09 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddnew(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	ft_lstadd(alst, new);
}
