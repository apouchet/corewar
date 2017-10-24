/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:14:22 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 20:59:58 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content, size_t content_size)
{
	t_list		*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content_size = 0;
	if (content == NULL)
		new->content = NULL;
	else if (content_size == 0)
		new->content = content;
	else
	{
		new->content = malloc(content_size);
		if (!new->content)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
