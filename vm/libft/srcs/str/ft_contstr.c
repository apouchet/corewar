/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:18:15 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/11 21:12:48 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_contstr(char **arr, const char *s)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strequ(arr[i], s))
			return (arr[i]);
		i++;
	}
	return (NULL);
}
