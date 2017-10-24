/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:59:35 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 20:59:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_lstpushnew(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	ft_lstpush(alst, new);
}
