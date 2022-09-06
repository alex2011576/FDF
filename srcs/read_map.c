/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:01:33 by ashatalo          #+#    #+#             */
/*   Updated: 2022/04/06 20:06:56 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *line)
{
	int	i;
	int	words;
	int	inside;

	inside = 0;
	i = 0;
	words = 0;
	while (line[i])
	{
		if ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
			inside = 0;
		else
		{
			if (!inside)
			{
				inside = 1;
				words++;
			}
		}
		i++;
	}
	return (words);
}

t_map	memory_map(char *fname, int fd)
{
	t_map	matrix;
	int		height;
	int		width;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		exit(1);
	if (get_next_line(fd, &line) <= 0)
		exit(2);
	height = 1;
	width = count_width(line);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		if (count_width(line) != width)
			exit(2);
		free(line);
	}
	matrix.dots = (t_dots **)malloc(sizeof(t_dots *) * (height + 1));
	while (height--)
		matrix.dots[height] = (t_dots *)malloc(sizeof(t_dots) * width);
	close(fd);
	return (matrix);
}

void	put_dots(char *line, t_map *matrix, int y)
{
	char	**dots;
	int		x;

	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix->dots[y][x].z = ft_atoi(dots[x]);
		if (ft_strchr(dots[x], ','))
			matrix->dots[y][x].color = ft_atoi_hex(
					ft_strdup(ft_strchr(dots[x], ',') + 1));
		else
			matrix->dots[y][x].color = -1;
		matrix->dots[y][x].x = x;
		matrix->dots[y][x].y = y;
		if (matrix->zmax < matrix->dots[y][x].z)
			matrix->zmax = matrix->dots[y][x].z;
		if (matrix->zmin > matrix->dots[y][x].z)
			matrix->zmin = matrix->dots[y][x].z;
		matrix->dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix->dots[y][--x].is_last = 1;
}

t_map	read_map(char *fname)
{
	t_map	matrix;
	int		y;
	int		fd;
	char	*line;

	fd = 0;
	matrix = memory_map(fname, fd);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		exit(1);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		put_dots(line, &matrix, y++);
	free(line);
	matrix.dots[y] = NULL;
	close(fd);
	return (matrix);
}
