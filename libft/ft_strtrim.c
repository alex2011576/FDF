/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <ashatalo@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:12:59 by aleksei           #+#    #+#             */
/*   Updated: 2021/11/26 17:15:23 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (ft_strdup(""));
	while (*(s + i))
		i++;
	i--;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i--;
	str = ft_strsub(s, 0, (i + 1));
	if (!str)
		return (NULL);
	return (str);
}
