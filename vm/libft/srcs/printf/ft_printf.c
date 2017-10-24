/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 17:39:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/09/30 19:37:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int g_res;
extern int g_fd;

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			res;

	g_fd = fd;
	g_res = 0;
	va_start(ap, format);
	do_print(format, ap);
	va_end(ap);
	res = g_res;
	return (res);
}

int				ft_printfnl(const char *format, ...)
{
	va_list		ap;
	int			res;

	g_res = 0;
	g_fd = 1;
	va_start(ap, format);
	do_print(format, ap);
	ft_printf_putchar('\n');
	va_end(ap);
	res = g_res;
	return (res);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;

	g_res = 0;
	g_fd = 1;
	va_start(ap, format);
	do_print(format, ap);
	va_end(ap);
	res = g_res;
	return (res);
}

void			ft_err(int exit_code, const char *format, ...)
{
	va_list		ap;

	g_res = 0;
	g_fd = 2;
	va_start(ap, format);
	do_print(format, ap);
	ft_printf_putchar('\n');
	va_end(ap);
	if (exit_code != -1)
		exit(exit_code);
}
