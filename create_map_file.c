/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:14:24 by bperraud          #+#    #+#             */
/*   Updated: 2021/12/01 11:45:02 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_map_file(int nb_line, char *line)
{
	char	buf[BUF];
	int		fd;
	int		i;

	i = 0;
    fd = open("tmp.txt", O_RDWR | O_CREAT, 0777);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	while (i < nb_line)
	{
		read(STDIN_FILENO, buf, sizeof(buf));
		//str_len = ft_strlen_input(buf);
		if (!ft_strncmp(buf, "quit()\n", 6))
			exit(EXIT_SUCCESS);
		i++;
	}
	close(fd);
}

void	standard_input_map()
{
	char	buffer[50];
	char	*line;

	ft_putstr("Write map or quit() to exit\n");
	read(STDIN_FILENO, buffer, 50);
	buffer[ft_strlen_input(buffer) - 1] = '\0';
	if (!ft_strncmp(buffer, "quit()\n", 6))
		exit(EXIT_SUCCESS);
	line = ft_strdup(buffer);
	if (!line)
		exit(EXIT_SUCCESS);
	if (!check_first_line(buffer))
	{
		ft_putstr("map error\n");
		exit(EXIT_SUCCESS);
	}
	else
		create_map_file(get_line_number(buffer), line);
}
