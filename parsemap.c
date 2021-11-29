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

t_map	str_to_map(char *str)
{
	t_map	map;
	map. = str[0]
	while (*str)
	{
		
	}
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

t_map	*parse(char *path)
{
	char	tmp[2];
	char	*str;
	int		fd;

	str = malloc(sizeof(char));
	if (!str)
		return (0);
	*str = '\0';
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, tmp, 1))
	{
		str = ft_add(str, tmp);
		if (!str)
			return (0);
	}
	close(fd);
	split = ft_split(str, "\n");
	free(str);
	return (split);
}
