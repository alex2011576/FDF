/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:35:38 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/26 17:28:07 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*buf;

	i = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	buf = ft_strcpy(buf, s1);
	return (buf);
}
