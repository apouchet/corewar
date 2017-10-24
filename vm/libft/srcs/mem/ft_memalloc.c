/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:18 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/17 18:59:18 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	unsigned char		*mem;
	unsigned int		i;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		mem[i++] = '\0';
	return ((void*)mem);
}
