/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:42:00 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/31 20:42:01 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(void **array, int left, int right,
		int (*cmp)(const void *, const void *))
{
	int	q;
	int	j;

	q = left;
	j = left;
	while (j < right)
	{
		if (cmp(array[j], array[right]) <= 0)
			ft_swap(array, j, q++);
		j++;
	}
	ft_swap(array, q, right);
	return (q);
}

void		ft_quicksort(void **array, int left, int right,
		int (*cmp)(const void *, const void *))
{
	int	i;

	if (left < right)
	{
		i = partition(array, left, right, cmp);
		ft_quicksort(array, left, i - 1, cmp);
		ft_quicksort(array, i + 1, right, cmp);
	}
}
