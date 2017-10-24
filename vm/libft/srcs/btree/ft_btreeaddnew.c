/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeaddnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:38:05 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/22 20:53:04 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeaddnew(t_btree **root, void *content, size_t content_size,
					int (*cmpf)(t_btree*, t_btree*))
{
	t_btree		*new;

	new = ft_btreenew(content, content_size);
	ft_btreeadd(root, new, cmpf);
}
