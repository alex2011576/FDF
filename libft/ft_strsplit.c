/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <ashatalo@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:15:26 by aleksei           #+#    #+#             */
/*   Updated: 2021/11/26 16:12:09 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const*s, char c)
{
	size_t	i;
	size_t	c_words;

	if (!s)
		return (0);
	c_words = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*(s + i) != c && *(s + i))
			i++;
		if (i != 0)
			c_words++;
		s = s + i;
	}
	return (c_words + 1);
}

static char	**ft_array_free(char ***ar, size_t last_index)
{
	while (last_index > 0)
		free((*ar)[last_index--]);
	free((*ar)[last_index]);
	free(*ar);
	*ar = NULL;
	return (NULL);
}

static char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	word_index;

	array = (char **)malloc(sizeof(char *) * ft_count_words(s, c));
	if (!array)
		return (NULL);
	word_index = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*(s + i) != c && *(s + i))
			i++;
		if (i != 0)
		{
			array[word_index++] = ft_strsub(s, 0, i);
			if (!array[word_index - 1])
				return (ft_array_free(&array, word_index - 1));
		}
		s = s + i;
	}
	array[word_index] = NULL;
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_split(s, c));
}
