/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:00:15 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 20:35:41 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	symbol_to_n(char c, t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->symbols[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	put_points(t_map *map, char **split)
{
	int		i;
	int		j;
	t_point	point;

	map->points = malloc(sizeof(point) * map->nb_points);
	if (!map->points)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i <= map->line)
	{
		j = -1;
		while (++j < map->col)
		{
			point.x = i - 1;
			point.y = j;
			point.symbol = symbol_to_n(split[i][j], map);
			map->points[(i - 1) * map->col + j] = point;
		}
	}
	return (1);
}

int	str_to_map(char *str, t_map *map)
{
	char	**split;
	int		i;
	int		size;

	split = ft_split(str, "\n");
	if (!check_map(split))
		return (0);
	size = ft_strlen(split[0]);
	map->symbols[0] = split[0][size - 3];
	map->symbols[1] = split[0][size - 2];
	map->symbols[2] = split[0][size - 1];
	split[0][size - 3] = '\0';
	map->line = ft_atoi(split[0]);
	i = 0;
	while (split[1][i])
		i++;
	map->col = i;
	map->nb_points = map->line * map-> col;
	if (!put_points(map, split))
		return (0);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (1);
}

char	*ft_add(char *str, char *tmp)
{
	char	*str2;
	int		size;

	size = ft_strlen(str);
	str2 = malloc((size + 2) * sizeof(char));
	if (!str2)
		exit (EXIT_FAILURE);
	ft_strcpy(str2, str);
	str2[size] = tmp[0];
	str2[size + 1] = '\0';
	free(str);
	return (str2);
}

int	parse(char *path, t_map *map)
{
	char	tmp[2];
	char	*str;
	int		fd;

	str = malloc(sizeof(char));
	if (!str)
		exit(EXIT_FAILURE);
	*str = '\0';
	if (path)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (put_error(1));
		while (read(fd, tmp, 1))
			str = ft_add(str, tmp);
		close(fd);
	}
	else
		str = standard_input_map();
	if (!str)
		return (0);
	if (!str_to_map(str, map))
		return (0);
	free(str);
	return (1);
}
