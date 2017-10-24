/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:30:55 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 13:23:41 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strremove(char *str, char c)
{
	char		*ptr;

	while ((ptr = ft_strchr(str, c)))
		ft_memmove(ptr, ptr + 1, &str[ft_strlen(str)] - ptr);
}
