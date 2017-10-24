/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 18:46:19 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 21:02:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isint(char *str)
{
	int			i;

	if (!ft_isdigit(str[0]) && !ft_strcont("+-", str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	if (i == 11 && ft_isdigit(str[0]))
		return (0);
	if (i == 11 && str[0] == '-')
		if (ft_strcmp(str + 1, "2147483648") > 0)
			return (0);
	if (i == 11 && str[0] == '+')
		if (ft_strcmp(str + 1, "2147483647") > 0)
			return (0);
	if (i == 10)
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	return (1);
}
