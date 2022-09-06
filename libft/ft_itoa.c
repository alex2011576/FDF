/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <ashatalo@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:15:17 by aleksei           #+#    #+#             */
/*   Updated: 2021/11/26 15:28:00 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -1 * n;
	}
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	str = ft_strnew(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		str[i++] = '-';
	}
	while (i < size)
	{
		str[--size] = (char)((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}
