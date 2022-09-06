/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:23:44 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/24 12:48:19 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (needle[i] == haystack[i] && needle[i] && (i < len))
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
