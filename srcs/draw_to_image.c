/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:16:58 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 18:53:41 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

static void	draw_background(t_map matrix)
{
	int	*image;
	int	i;

	image = (int *)(matrix.img->addr);
	i = 0;
	while (i < matrix.win_y * matrix.win_x)
	{
		if (i % matrix.win_x < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		i++;
	}
}

void	draw(t_map matrix)
{
	int		y;
	int		x;

	draw_background(matrix);
	y = 0;
	while (matrix.dots[y])
	{
		x = 0;
		while (1)
		{
			if (matrix.dots[y + 1])
				line(matrix.dots[y][x], matrix.dots[y + 1][x], matrix);
			if (!matrix.dots[y][x].is_last)
				line(matrix.dots[y][x], matrix.dots[y][x + 1], matrix);
			if (matrix.dots[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(matrix.mlx, matrix.mlx_win, matrix.img->img, 0, 0);
	print_menu(&matrix);
}
