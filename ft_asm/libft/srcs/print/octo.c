/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 23:33:03 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/25 01:12:03 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nb(long long int nb, int base)
{
	int						len;
	unsigned long long int	a;

	len = 1;
	a = nb;
	if (nb < 0)
		a = -nb;
	while (a >= (unsigned)base)
	{
		a = a / base;
		len++;
	}
	return (len);
}

static int	ft_nb_unsigned(unsigned long long int nb, unsigned int base)
{
	int						len;
	unsigned long long int	a;

	len = 1;
	a = nb;
	while (a >= base)
	{
		a = a / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(long long int nb, int base, int maj)
{
	int						i;
	unsigned long long int	n;
	char					*tab;

	i = ft_nb(nb, base);
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tab[i--] = '\0';
	n = nb;
	if (nb < 0)
		n = -nb;
	while (n >= (unsigned)base)
	{
		if (n % base < 10)
			tab[i--] = '0' + n % base;
		else
			tab[i--] = 'a' - 10 - (32 * maj) + n % base;
		n = n / base;
	}
	if (n % base < 10)
		tab[i] = '0' + n;
	else
		tab[i] = 'a' - 10 - (32 * maj) + n;
	return (tab);
}

char		*ft_itoa_unsigned_base(unsigned long long int nb, int base, int maj)
{
	int						i;
	unsigned long long int	n;
	char					*tab;

	i = ft_nb_unsigned(nb, base);
	if (!(tab = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tab[i--] = '\0';
	n = nb;
	while (n >= (unsigned)base)
	{
		if (n % base < 10)
			tab[i--] = '0' + n % base;
		else
			tab[i--] = 'a' - 10 - (32 * maj) + n % base;
		n = n / base;
	}
	if (n % base < 10)
		tab[i] = '0' + n;
	else
		tab[i] = 'a' - 10 - (32 * maj) + n;
	return (tab);
}
