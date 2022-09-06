/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:22:08 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 19:22:16 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Prints the ASCII values of the mem area
 */
void	ft_memprint(const void *mem, size_t size)
{
	const unsigned char	*pmem;

	pmem = (const unsigned char *)mem;
	while (size--)
	{
		ft_putnbr((int)*pmem);
		ft_putchar(' ');
		pmem++;
	}
}
