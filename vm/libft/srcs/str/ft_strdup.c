/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:16 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/15 11:42:25 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t		len;
	char		*dup;

	len = ft_strlen(s);
	dup = (char*)malloc(len + 1);
	if (!dup)
		return (NULL);
	else
		ft_memcpy(dup, s, len + 1);
	return (dup);
}
