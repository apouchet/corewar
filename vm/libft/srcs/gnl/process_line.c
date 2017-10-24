/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:51:47 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 14:05:38 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				process_buffer(char *buffer, char **line, t_remain *remain)
{
	char		*newline;
	char		*old;

	if ((newline = ft_strchr(buffer, '\n')))
	{
		*line = ft_strmerge(*line, ft_strsub(buffer, 0, newline - buffer));
		old = remain->content;
		remain->content = ft_strdup(newline + 1);
		free(old);
		return (1);
	}
	if (*line)
		*line = ft_strmerge(*line, ft_strdup(buffer));
	else
		*line = buffer;
	ft_strdel(&remain->content);
	return (0);
}

int				read_fd(t_remain *remain, char **line, char **buffer)
{
	int				ret;

	while ((ret = read(remain->fd, *buffer, GNL_BUFF_SIZE)) > 0)
	{
		ret = process_buffer(*buffer, line, remain);
		ft_strdel(buffer);
		if (ret == 1)
			return (1);
		if ((*buffer = ft_strnew(GNL_BUFF_SIZE + 1)) == NULL)
			return (-1);
	}
	ft_strdel(buffer);
	if (ret == -1)
		return (-1);
	if (*line && !ft_strequ(*line, ""))
		return (1);
	return (0);
}

int				process_line(t_remain *remain, char **line)
{
	char			*buffer;

	*line = ft_strnew(0);
	if (remain->content)
	{
		if (process_buffer(remain->content, line, remain) == 1)
			return (1);
	}
	if ((buffer = ft_strnew(GNL_BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (read(remain->fd, buffer, 0) < 0)
		return (-1);
	return (read_fd(remain, line, &buffer));
}
