/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:22:26 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/10 14:24:56 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprepend(char c, char *str)
{
	char	*cs;

	cs = ft_strnew(1);
	cs[0] = c;
	return (ft_strmerge(cs, str));
}
