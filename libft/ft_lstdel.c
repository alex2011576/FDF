/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:58 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/22 18:54:56 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*tempn;

	temp = *alst;
	while (temp)
	{
		tempn = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = tempn;
	}
	*alst = NULL;
}
