/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:00:15 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 15:35:19 by jboumal          ###   ########.fr       */
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
		return (0);
	i = 0;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			point.x = j;
			point.y = i - 1;
			point.symbol = symbol_to_n(split[i][j], map);
			map->points[(i - 1) * map->line + j] = point;
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
	free (split);
	return (1);
}

char	*ft_add(char *str, char *tmp)
{
	char	*str2;
	int		size;

	size = ft_strlen(str);
	str2 = malloc((size + 2) * sizeof(char));
	if (!str2)
		return (0);
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
		return (0);
	*str = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, tmp, 1))
	{
		str = ft_add(str, tmp);
		if (!str)
			return (0);
	}
	close(fd);
	if (!str_to_map(str, map))
		return (0);
	free(str);
	return (1);
}
