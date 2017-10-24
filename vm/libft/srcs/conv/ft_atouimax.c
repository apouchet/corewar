/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouimax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:01:23 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 21:01:26 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_atouimax(const char *nptr)
{
	uintmax_t			res;
	int					i;

	i = 0;
	res = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res);
}
