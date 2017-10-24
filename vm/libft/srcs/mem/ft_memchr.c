/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:15 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/15 11:31:29 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		chr;
	unsigned int		i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n && str[i] != chr)
		i++;
	if (i != n)
		return (&str[i]);
	else
		return (NULL);
}
