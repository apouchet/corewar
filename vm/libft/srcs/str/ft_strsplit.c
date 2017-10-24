/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:51 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/05 17:52:17 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		words(const char *s, char c)
{
	size_t		words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		s++;
	}
	return (words);
}

static void			loop(char *str, char **res,
		char c, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		z;

	i = 0;
	j = 0;
	z = 0;
	while (z < size)
	{
		if (str[i] == c || str[i] == '\0')
		{
			res[z++] = ft_strsub(str, j, i - j);
			while (str[i] == c)
				i++;
			j = i;
		}
		i++;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char		**res;
	char		*str;
	size_t		size;

	if (!s)
		return (NULL);
	if (*s)
		str = ft_strctrim(s, c);
	else
		str = ft_strdup(s);
	if (!str)
		return (NULL);
	size = words(str, c);
	res = (char**)malloc(sizeof(char*) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	loop(str, res, c, size);
	free(str);
	return (res);
}
