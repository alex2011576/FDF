/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <ashatalo@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:48:27 by aleksei           #+#    #+#             */
/*   Updated: 2021/11/16 20:47:51 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l_s1;
	size_t	l_s2;

	i = ft_strlen(s1);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	if (n < i)
		return (n + l_s2);
	while (*s2 && i < (n - 1))
	{
		*(s1 + i) = *s2;
		s2++;
		i++;
	}
	*(s1 + i) = '\0';
	return (l_s1 + l_s2);
}
