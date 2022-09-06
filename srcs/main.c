/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:18:30 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 20:03:44 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_default_color(t_map *matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix->dots[y])
	{
		x = 0;
		while (1)
		{
			if (matrix->dots[y][x].color == -1)
				matrix->dots[y][x].color = get_default_color(
						matrix->dots[y][x].z, *matrix);
			if (matrix->dots[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}

static void	set_default(t_map *matrix)
{
	matrix->win_x = WX;
	matrix->win_y = WY;
	matrix->img->zoom = 20;
	matrix->img->z_scale = 1;
	matrix->img->is_isometric = 1;
	matrix->img->angle = 0.523599;
	matrix->img->shift_x = matrix->win_x / 3;
	matrix->img->shift_y = matrix->win_y / 3;
	matrix->mlx = mlx_init();
	matrix->mlx_win = mlx_new_window(matrix->mlx,
			matrix->win_x, matrix->win_y, "FDF");
	matrix->img->img = mlx_new_image(
			matrix->mlx, matrix->win_x, matrix->win_y);
	matrix->img->addr = mlx_get_data_addr(
			matrix->img->img, &matrix->img->bits_per_pixel,
			&matrix->img->line_length, &matrix->img->endian);
	set_default_color(matrix);
}

int	main(int argc, char **argv)
{
	t_map	matrix;
	t_data	img;

	if (argc != 2)
		exit(0);
	matrix = read_map(argv[1]);
	matrix.img = &img;
	set_default(&matrix);
	draw(matrix);
	mlx_hook(matrix.mlx_win, 2, 0, deal_key, &matrix);
	mlx_loop(matrix.mlx);
	return (0);
}
