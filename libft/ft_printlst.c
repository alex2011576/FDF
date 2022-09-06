/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:33:10 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/25 15:53:00 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list	*lst)
{
	if (!lst)
		ft_putendl("lst -> NULL");
	while (lst)
	{
		if (!(lst->content))
			ft_putendl("content -> NULL");
		else if (sizeof(*(lst->content)) != 1)
			ft_putendl("content is not string");
		else
			ft_putendl(lst->content);
		lst = lst->next;
	}
}
