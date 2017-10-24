/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:06:17 by mnunnari          #+#    #+#             */
/*   Updated: 2017/04/15 13:31:29 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strstr_w(const char *haystack,
		const char *needle, const char *needlestart)
{
	if (*needle == 0)
		return ((char*)haystack);
	if (*haystack == 0)
		return (NULL);
	if (*haystack == *needle)
		if (ft_strstr_w(haystack + 1, needle + 1, needlestart)
				== haystack + 1)
			return ((char*)haystack);
	if (needle == needlestart)
		return (ft_strstr_w(haystack + 1, needle, needlestart));
	else
		return (NULL);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	return (ft_strstr_w(haystack, needle, needle));
}
