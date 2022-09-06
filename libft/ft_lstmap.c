/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:32:54 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/25 14:23:33 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	if (lst->next)
	{
		new->next = ft_lstmap(lst->next, f);
		if (!new->next)
		{
			ft_lstdelone(&new, &ft_lst_contentfree);
			return (NULL);
		}
	}
	return (new);
}
