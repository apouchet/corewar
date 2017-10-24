/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:35:29 by mnunnari          #+#    #+#             */
/*   Updated: 2017/07/08 20:21:51 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddnew(t_list **alst, void *content,
					size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstiter_rev(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpush(t_list **alst, t_list *new);
t_list				*ft_lstpop(t_list **lst);
t_list				*ft_lstshift(t_list **lst);
void				*ft_lstreduce(t_list *lst,
					void *(*f)(void*, void*, size_t));
size_t				ft_lstlen(t_list *list);
t_list				*ft_lsttail(t_list *lst);
t_list				*ft_lstat(t_list *lst, int i);
void				ft_lstpushnew(t_list **alst, void *content,
					size_t content_size);
void				ft_lstremoveif(t_list **lst, void (*del)(void *, size_t),
					int (*f)(void*, void*), void *param);
#endif
