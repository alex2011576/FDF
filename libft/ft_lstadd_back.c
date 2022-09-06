/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:45:15 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/23 19:48:57 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
