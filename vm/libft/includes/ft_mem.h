/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:36:06 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/24 20:57:33 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_swap_ints(int *ptr1, int *ptr2);
void				ft_quicksort(void **array, int left, int right,
					int (*cmp)(const void *, const void *));
void				ft_swap(void **array, int i, int j);
size_t				ft_arrlen(void **arr);
void				ft_arrdel(void **arr);
#endif
