/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:46 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/17 18:59:46 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*str;
	unsigned int		i;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
