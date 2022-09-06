/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:39:36 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 18:22:52 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	err_calculation(dx, dy)
{
	if (dx > dy)
		return (dx / 2);
	else
		return (-dy / 2);
}

static int	e2_neg_dx(int *err, int x0, int x1, int dy)
{
	*err -= dy;
	if (x0 < x1)
		x0++;
	else
		x0--;
	return (x0);
}

static int	e2_neg_dy(int *err, int y0, int y1, int dx)
{
	*err += dx;
	if (y0 < y1)
		y0++;
	else
		y0--;
	return (y0);
}

void	line(t_dots dots0, t_dots dots1, t_map matrix)
{
	t_delta	delta;
	int		err;
	int		e2;
	t_dots	start;

	set_param(&dots0, &dots1, &matrix);
	start = dots0;
	delta.dx = ft_abs(dots1.x - dots0.x);
	delta.dy = ft_abs(dots1.y - dots0.y);
	err = err_calculation(delta.dx, delta.dy);
	while (1)
	{
		if (dots0.x >= MENU_WIDTH && dots0.y >= 0 \
				&& dots0.x < matrix.win_x && dots0.y < matrix.win_y)
			my_mlx_pixel_put(matrix.img, dots0.x, dots0.y, \
					get_color(dots0, start, dots1, delta));
		if (dots0.x == dots1.x && dots0.y == dots1.y)
			break ;
		e2 = err;
		if (e2 > -delta.dx)
			dots0.x = e2_neg_dx(&err, dots0.x, dots1.x, delta.dy);
		if (e2 < delta.dy)
			dots0.y = e2_neg_dy(&err, dots0.y, dots1.y, delta.dx);
	}
}
