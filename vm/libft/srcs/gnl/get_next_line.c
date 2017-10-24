/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:51:47 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 21:03:45 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_remain		*create_remain(t_list **remains, int fd)
{
	t_list			*remainsptr;
	t_remain		*remain;

	if (!(remain = (t_remain*)malloc(sizeof(t_remain))))
		return (NULL);
	remain->fd = fd;
	remain->content = NULL;
	if (!(remainsptr = ft_lstnew(remain, sizeof(t_remain))))
		return (NULL);
	if (*remains)
		ft_lstadd(remains, remainsptr);
	else
		*remains = remainsptr;
	free(remain);
	remain = (t_remain*)(*remains)->content;
	return (remain);
}

t_remain		*find_remain(t_list *remains, int fd)
{
	t_list			*remainsptr;
	t_remain		*remain;

	remain = NULL;
	if (remains)
	{
		remainsptr = remains;
		while (remainsptr && !remain)
		{
			remain = (t_remain*)remainsptr->content;
			if (!(remain->fd == fd))
				remain = NULL;
			remainsptr = remainsptr->next;
		}
	}
	return (remain);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*remains;
	t_remain		*remain;
	int				res;

	if (fd < 0 || !line)
		return (-1);
	remain = find_remain(remains, fd);
	if (!remain)
		remain = create_remain(&remains, fd);
	if (!remain)
		return (-1);
	res = (process_line(remain, line));
	return (res);
}
