/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:56 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/05 19:08:42 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_dots *a, t_dots *b, t_map *param)
{
	a->x *= param->img->zoom;
	a->y *= param->img->zoom;
	b->x *= param->img->zoom;
	b->y *= param->img->zoom;
	a->z *= param->img->z_scale;
	b->z *= param->img->z_scale;
}

void	set_param(t_dots *a, t_dots *b, t_map *param)
{
	zoom(a, b, param);
	if (param->img->is_isometric)
	{
		isometric(a, param->img->angle);
		isometric(b, param->img->angle);
	}
	a->x += param->img->shift_x;
	a->y += param->img->shift_y;
	b->x += param->img->shift_x;
	b->y += param->img->shift_y;
}
