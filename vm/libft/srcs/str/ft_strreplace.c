/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:45:52 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:23:48 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strreplace(char *str, char toreplace, char replacement)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == toreplace)
			str[i] = replacement;
		i++;
	}
}
