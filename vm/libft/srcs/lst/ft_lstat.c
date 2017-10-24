/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:56:58 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/04 18:04:02 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstat(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst && i != index)
	{
		lst = lst->next;
		i++;
	}
	if (i == index)
		return (lst);
	else
		return (NULL);
}
