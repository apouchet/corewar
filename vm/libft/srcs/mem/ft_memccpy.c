/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:14 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/15 11:32:23 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	unsigned int	i;
	int				cfound;

	i = 0;
	cfound = 0;
	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	while (i < n && !cfound)
	{
		if (source[i] == ((unsigned char)c))
			cfound = 1;
		destination[i] = source[i];
		i++;
	}
	if (cfound)
		return (&destination[i]);
	else
		return (NULL);
}
