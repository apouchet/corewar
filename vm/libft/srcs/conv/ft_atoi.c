/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/19 13:05:00 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int					neg_flag;
	unsigned long long	res;
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
	return (neg_flag * (int)res);
}
