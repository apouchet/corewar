/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:31:35 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 20:56:15 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct	s_map
{
	void		*key;
	void		*value;
}				t_map;

void			*ft_mapget_lst(t_list *lst, void *key,
				int (*equ)(void*, void*));
#endif
