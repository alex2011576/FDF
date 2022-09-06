/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:15 by jlehtine          #+#    #+#             */
/*   Updated: 2022/04/06 20:04:34 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define WX 1920
# define WY 1080
# define MENU_WIDTH 250

typedef struct s_dots
{
	int		x;
	int		y;
	int		z;
	int		is_last;
	int		color;
}				t_dots;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			zoom;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
}				t_data;

typedef struct s_map
{
	t_dots		**dots;
	t_data		*img;
	int			win_x;
	int			win_y;
	int			zmax;
	int			zmin;
	void		*mlx;
	void		*mlx_win;
}				t_map;

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_delta {
	int	dx;
	int	dy;
}				t_delta;

t_map	read_map(char *fname);
void	draw(t_map matrix);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_param(t_dots *a, t_dots *b, t_map *param);
void	isometric(t_dots *dot, double angle);
int		deal_key(int key, t_map *matrix);
int		get_default_color(int z, t_map map);
void	new_window(int key, t_map *matrix);
void	line(t_dots dots0, t_dots dots1, t_map matrix);
int		get_color(t_dots current, t_dots start, t_dots end, t_delta delta);
double	percent(int start, int end, int current);
void	print_menu(t_map *matrix);

#endif
