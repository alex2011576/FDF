/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:06:38 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 19:41:05 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(const char *str)
{
	return (*str == '-' && ft_isdigit(*(str + 1)));
}

static int	is_hex(char a)
{
	if (ft_isdigit(a))
		return (1);
	if (a >= 'a' && a <= 'f')
		return (2);
	if (a >= 'A' && a <= 'F')
		return (3);
	return (0);
}

static int	calculate(const char *str)
{
	int	result;

	result = 0;
	while (is_hex(*str))
	{
		result *= 16;
		if (is_hex(*str) == 1)
			result += *str - '0';
		else if (is_hex(*str) == 2)
			result += *str - 'a' + 10;
		else
			result += *str - 'A' + 10;
		str++;
	}
	return (result);
}

int	ft_atoi_hex(const char *str)
{
	int	negative;
	int	result;

	negative = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (is_negative(str))
	{
		negative = -1;
		str++;
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	if (*str == '0')
	{
		if (*(str + 1) == 'x' || *(str + 1) == 'X')
			str = str + 2;
	}
	result = calculate(str);
	return (result * negative);
}
