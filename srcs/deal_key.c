/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:25:05 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 18:53:40 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_n_exit(t_map *matrix)
{
	int	y;

	y = 0;
	mlx_destroy_image(matrix->mlx, matrix->img->img);
	mlx_destroy_window(matrix->mlx, matrix->mlx_win);
	while (matrix->dots[y])
		free(matrix->dots[y++]);
	free(matrix->dots);
	exit(0);
}

static int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22);
}

static void	is_iso(t_map *matrix)
{
	if (matrix->img->is_isometric)
		matrix->img->is_isometric = 0;
	else
		matrix->img->is_isometric = 1;
}

void	do_key(int key, t_map *matrix)
{
	if (key == 24 || key == 69)
		matrix->img->zoom += 3;
	if (key == 27 || key == 78)
		matrix->img->zoom -= 3;
	if (key == 91 || key == 28)
		matrix->img->z_scale += 1;
	if (key == 84 || key == 19)
		matrix->img->z_scale -= 1;
	if (key == '~')
		matrix->img->shift_y -= 10;
	if (key == '}')
		matrix->img->shift_y += 10;
	if (key == '{')
		matrix->img->shift_x -= 10;
	if (key == '|')
		matrix->img->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		is_iso(matrix);
	if (key == 86 || key == 21)
		matrix->img->angle += 0.05;
	if (key == 88 || key == 22)
		matrix->img->angle -= 0.05;
}

int	deal_key(int key, t_map *matrix)
{
	if (is_key(key))
	{
		mlx_destroy_image(matrix->mlx, matrix->img->img);
		do_key(key, matrix);
		matrix->img->img = mlx_new_image(
				matrix->mlx, matrix->win_x, matrix->win_y);
		matrix->img->addr = mlx_get_data_addr(
				matrix->img->img, &matrix->img->bits_per_pixel,
				&matrix->img->line_length, &matrix->img->endian);
		draw(*matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
		destroy_n_exit(matrix);
	return (0);
}
