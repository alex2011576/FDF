/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:24:59 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 18:53:39 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

void	print_menu(t_map *matrix)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = matrix->mlx;
	win = matrix->mlx_win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "2D/3D: 5 or space");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: 4 and 6");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Scale:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "8 (UP)");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "2 (DOWN)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Full screen : f");
	mlx_string_put(mlx, win, 15, y += 40, TEXT_COLOR, "Close window: esc");
}
