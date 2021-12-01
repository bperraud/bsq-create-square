/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:07:38 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 20:30:33 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define BUF 50

typedef struct s_point
{
	int	x;
	int	y;
	int	symbol;
}	t_point;

typedef struct s_square
{
	t_point	start_point;
	int		size;
	int		index;
}	t_square;

typedef struct s_map
{
	t_point		*points;
	int			line;
	int			col;
	int			nb_points;
	char		symbols[3];
	t_square	bsq;
}	t_map;

//map function
int		is_empty_line(t_map map, int index, int nb);
void	print_map(t_map map);
void	write_bsq(t_map map);
void	write_line(t_map map, int index);
int		is_no_symbol_line(t_map map, int index, int nb);
int		is_index_in_map(t_map map, int index, int size);

//find_square
void	find_bsq(t_map *map);
int		try_nsquare(t_map map, int index, int size);

//string operations
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);
int		list_len(char **list);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strlen_input(char *str);

//file parsing function
int		parse(char *path, t_map *map);
int		check_map(char **split);

//create map file
char	*standard_input_map(void);
char	*create_map_file(int nb_line, char *line);

//check map
int		check_first_line(char *line);
int		check_map_core(char **split, int n, char *charset);
int		put_error(int i);
int		get_line_number(char *line);

//main
int		bsq(char *path);

#endif
