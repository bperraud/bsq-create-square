/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:23:14 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 11:42:32 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	bsq(char *path)
{
    t_map	*map;

    map = malloc(sizeof(*map));
    if (!map)
        return (0);
    if (!parse(path, map))
        exit(EXIT_FAILURE);
    map->bsq.size = 0;
    map->bsq.start_point.x = -1;
    map->bsq.start_point.y = -1;
    map->bsq.index = -1;
    printf("\n");
    find_bsq(map);
    write_bsq(*map);
    print_map(*map);
    free(map->points);
    free(map);
    return (1);
}

int	wrong_path(char *path)
{
    free(path);
    return (0);
}

int	main(int argc, char **argv)
{
    char	*path;
    int		i;

    if (argc == 1)
    {
        standard_input_map(1);
        path = ft_strdup("tmp.txt");
        if (!path)
            return (wrong_path(path));
        if (!bsq(path))
            return (wrong_path(path));
    }
    i = 1;
    while (i < argc)
    {
        path = ft_strdup(argv[i]);
        if (!path)
            return (wrong_path(path));
        if (!bsq(path))
            return (wrong_path(path));
        write(1, "\n", 1);
        i++;
        free(path);
    }
    return (0);
}