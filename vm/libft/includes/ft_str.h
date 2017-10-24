/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:36:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/29 14:36:24 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
int					ft_strcont(const char *str, char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char**as);
void				ft_strclr(char*s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char*s, void(*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmerge(char *s1, char *s2);
char				*ft_strappend(char *s1, char c);
void				ft_strremove(char *str, char c);
void				ft_strreplace(char *str, char toreplace,
								char replacement);
char				*ft_strprepend(char c, char *str);
char				*ft_strtrim(char const *s);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strftrim(const char *str, int(*f)(int c));
int					ft_iswhitespace(int c);
char				*ft_strctrim(const char *s, int c);
char				*ft_strcmpr(const char *s, char c);
char				*ft_contstr(char **arr, const char *s);
char				*ft_strchrs(const char *s, int (*f)(char));
#endif
