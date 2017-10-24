/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strftrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/19 12:32:07 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strftrim(const char *s, int (*f)(int c))
{
	char	*res;
	int		i;
	int		j;

	res = ft_strnew(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (f(s[i]))
		i++;
	j = ft_strlen(s) - 1;
	while (f(s[j]))
		j--;
	while (j >= i)
	{
		res[j - i] = s[j];
		j--;
	}
	res = ft_strdup(res);
	return (res);
}
