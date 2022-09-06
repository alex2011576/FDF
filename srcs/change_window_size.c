/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:41 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 18:34:47 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	full_screen(t_map *matrix)
{
	static int	old_x;
	static int	old_y;

	if (matrix->win_x != 2560)
	{
		old_x = matrix->win_x;
		old_y = matrix->win_y;
	}
	if (matrix->win_x == 2560)
		matrix->win_x = old_x;
	else
		matrix->win_x = 2560;
	if (matrix->win_y == 1400)
		matrix->win_y = old_y;
	else
		matrix->win_y = 1400;
}

void	new_window(int key, t_map *matrix)
{
	mlx_destroy_image(matrix->mlx, matrix->img->img);
	mlx_destroy_window(matrix->mlx, matrix->mlx_win);
	if (key == 3)
		full_screen(matrix);
	matrix->mlx = mlx_init();
	matrix->mlx_win = mlx_new_window(
			matrix->mlx, matrix->win_x, matrix->win_y, "FDF");
	matrix->img->img = mlx_new_image(
			matrix->mlx, matrix->win_x, matrix->win_y);
	matrix->img->addr = mlx_get_data_addr(
			matrix->img->img, &matrix->img->bits_per_pixel,
			&matrix->img->line_length, &matrix->img->endian);
	draw(*matrix);
	mlx_hook(matrix->mlx_win, 2, 0, deal_key, matrix);
	mlx_loop(matrix->mlx);
}
