/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuintmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:01:49 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 21:02:44 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isuintmax(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 20)
		return (0);
	if (i == 20 && ft_strcmp(str, "18446744073709551615") > 0)
		return (0);
	return (1);
}
