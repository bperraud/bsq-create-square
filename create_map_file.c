/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:14:24 by bperraud          #+#    #+#             */
/*   Updated: 2021/12/01 20:29:36 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_conc(char *str, char *tmp)
{
	char	*str2;
	int		size;

	size = ft_strlen(str);
	str2 = malloc((size + ft_strlen(tmp) + 1) * sizeof(char));
	if (!str2)
		return (0);
	ft_strcpy(str2, str);
	ft_strcpy(str2 + size, tmp);
	size += ft_strlen(tmp);
	str2[size + 1] = '\0';
	free(str);
	return (str2);
}

char	*create_map_file(int nb_line, char *line)
{
	char	buf[1000];
	char	*str;
	int		i;
	int		n;

	i = 0;
	str = ft_strdup(line);
	str = ft_conc(str, "\n");
	while (i < nb_line)
	{
		buf[0] = '\0';
		n = read(STDIN_FILENO, buf, sizeof(buf));
		if (!ft_strncmp(buf, "quit()\n", 6))
			exit(EXIT_SUCCESS);
		buf[n] = '\0';
		str = ft_conc(str, buf);
		i++;
	}
	return (str);
}

char	*standard_input_map(void)
{
	char	buffer[50];
	char	*line;
	char	*str;

	ft_putstr("Write map or quit() to exit\n");
	read(STDIN_FILENO, buffer, 50);
	buffer[ft_strlen_input(buffer) - 1] = '\0';
	if (!ft_strncmp(buffer, "quit()\n", 6))
		exit(EXIT_SUCCESS);
	line = ft_strdup(buffer);
	if (!line)
		exit(EXIT_FAILURE);
	if (!check_first_line(buffer))
	{
		ft_putstr("map error\n");
		return (0);
	}
	else
		str = create_map_file(get_line_number(buffer), line);
	return (str);
}
