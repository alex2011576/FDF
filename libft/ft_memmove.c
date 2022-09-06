/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:33:04 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/24 09:37:37 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = n - 1;
	if (src >= dest)
		while (n--)
			((char *)dest)[i - n] = ((const char *)src)[i - n];
	else
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
	return ((char *)dest);
}
