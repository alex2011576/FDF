/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <ashatalo@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:06:55 by aleksei           #+#    #+#             */
/*   Updated: 2021/12/10 15:24:22 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(char **buff, const int fd)
{
	int		ret;
	char	*str;
	char	*tmp;

	str = ft_strnew(BUFF_SIZE);
	if (!str)
		return (-1);
	ret = read(fd, str, BUFF_SIZE);
	if (ret > 0)
	{
		if (!(*buff))
			*buff = ft_strdup(str);
		else
		{
			tmp = ft_strjoin(*buff, str);
			ft_strdel(&str);
			if (!tmp)
				return (-1);
			ft_strdel(buff);
			*buff = tmp;
		}
	}
	if (str)
		ft_strdel(&str);
	return (ret);
}

static int	ft_moveline(char **buff, char **line, char *str)
{
	int	len;

	len = 0;
	while ((*buff + len) != str)
		len++;
	*line = ft_strsub(*buff, 0, len);
	if (!(*line))
	{
		ft_strdel(buff);
		return (-1);
	}
	if (*(str + 1))
	{
		str = ft_strdup(str + 1);
		ft_strdel(buff);
		if (!str)
		{
			ft_strdel(line);
			return (-1);
		}
		*buff = str;
	}
	else
		ft_strdel(buff);
	return (1);
}

static int	ft_returnline(char **buff, char **line)
{
	char	*str;
	int		ret;

	ret = 1;
	str = ft_strchr(*buff, '\n');
	if (!str)
	{
		*line = ft_strdup(*buff);
		if (!(*line))
			ret = -1;
		ft_strdel(buff);
	}
	else
		ret = ft_moveline(buff, line, str);
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff[FD_SIZE];
	int			ret;

	ret = 1;
	if (!line || fd >= FD_SIZE || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((!buff[fd] || !(ft_strchr(buff[fd], '\n'))) && ret > 0)
		ret = ft_read_line(&buff[fd], fd);
	if (ret < 0)
	{
		*line = NULL;
		if (buff[fd])
			ft_strdel(&buff[fd]);
		return (ret);
	}
	if (ret == 0 && !buff[fd])
	{
		*line = NULL;
		return (0);
	}
	ret = ft_returnline(&buff[fd], line);
	return (ret);
}
