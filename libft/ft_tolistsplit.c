/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolstsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:18:24 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/25 16:00:09 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tmpsplit(char const *s, size_t i, t_list **lst)
{
	t_list	*tmp;
	char	*a;

	a = ft_strsub(s, 0, i);
	tmp = ft_lstnew(a, i + 1);
	if (!tmp)
	{
		if (*lst)
			ft_lstdel(lst, &ft_lst_contentfree);
		else
			*lst = NULL;
	}
	if (!(*lst))
		*lst = tmp;
	else
		ft_lstadd_back(*lst, tmp);
}

t_list	*ft_tolistsplit(char const *s, char c)
{
	t_list	*lst;
	size_t	i;

	lst = NULL;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*(s + i) != c && *(s + i))
			i++;
		if (i != 0)
		{
			ft_tmpsplit(s, i, &lst);
			if (!lst)
				return (NULL);
		}
		s = s + i;
	}
	ft_lstadd_back(lst, NULL);
	return (lst);
}
