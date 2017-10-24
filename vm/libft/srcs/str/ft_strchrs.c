/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:09:17 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/26 21:09:36 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchrs(const char *s, int (*f)(char))
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (f(s[i]))
			return ((char *)(s + i));
		i++;
	}
	if (f(s[i]))
		return ((char *)(s + i));
	return (NULL);
}
