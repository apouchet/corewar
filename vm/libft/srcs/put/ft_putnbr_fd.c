/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:59:26 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/17 19:59:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mn_putnbr_fd(int nb, int fd)
{
	if (nb > 0)
		nb = nb * -1;
	if (nb > -10)
	{
		nb *= -1;
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		mn_putnbr_fd(nb / 10, fd);
		mn_putnbr_fd(nb % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	mn_putnbr_fd(n, fd);
}
