/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:40:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/01 15:40:59 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoimax(const char *nptr)
{
	int					neg_flag;
	intmax_t			res;
	int					i;

	i = 0;
	res = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	neg_flag = (*nptr == '-') ? -1 : 1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (i > 19 || res > 9223372036854775807)
		return ((neg_flag == 1) ? -1 : 0);
	return (neg_flag * res);
}
