/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:00:15 by jboumal           #+#    #+#             */
/*   Updated: 2021/11/29 16:49:00 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	put_data(t_map *map, char **split)
{
	int	i;
	int	size;
	
	size = ft_strlen(split[0]);
	map->symbols[0] = split[0][size - 3];
	map->symbols[1] = split[0][size - 2];
	map->symbols[2] = split[0][size - 1];
	split[0][size - 3] = '\0';
	map->col = atoi(split[0]);
	i = 0;
	while(split[i])
	{
		
		i++;
	}
}

int	str_to_map(char *str, t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(str, "\n");
	if (!split)
		return (0);
	i = 0;
	printf("%s\n", split[i]);
	while (split[++i])
	{
		printf("%s\n", split[i]);
	}
	map->line = i;
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
