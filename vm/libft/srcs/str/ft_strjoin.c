/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:40 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/19 11:26:50 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len_s1;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2);
	res = ft_strnew(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, s1, len_s1);
	ft_strcat(res, s2);
	return (res);
}
