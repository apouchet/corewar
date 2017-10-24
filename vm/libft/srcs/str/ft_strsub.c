/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:53 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/19 12:30:18 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*res;
	unsigned int		i;

	res = (char*)malloc(len + 1);
	if (!res || !s)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
