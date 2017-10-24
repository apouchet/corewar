/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:16 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/15 11:06:16 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (!(res = (unsigned char)s1[i] - (unsigned char)s2[i]) && s1[i])
		i++;
	return (res);
}
