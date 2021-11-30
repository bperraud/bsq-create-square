#include "header.h"

int	put_error(void)
{
	ft_putstr("map error\n");
	return (0);
}

int	check_map_core(char **split, int n, char *charset)
{
	int	i;
	int	j;
	int	len;
	
	if (n != (list_len(split) - 1))
		return (0);	
	i = 0;
	len = ft_strlen(split[1]);
	while (++i <= n)
	{
		j = -1;
		if (ft_strlen(split[i]) != len)
			return (0);
		while (split[i][++j])
		{
			if (split[i][j] != charset[0] || split[i][j] != charset[1])
				return (1);
		}
	}
	return (1);
}

int	check_first_line(char *line)
{
	int		i;
	int		n;

	n = ft_strlen(line);
	if (n < 4)
		return (0);
	n -= 3;
	if (line[n] == line[n + 1])
		return (0);
	if (line[n] == line[n + 2])
		return (0);
	if (line[n + 1] == line[n + 2])
		return (0);
	i = -1;
	while (++i < n)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
	}
	return (n);
}

int	check_map(char **split)
{
	int		n;
	char	charset[3];
	char	*nbr;

	if (!split)
		return (0);
	n = check_first_line(split[0]);
	if (!n)
		return (put_error());
	nbr = ft_strdup(split[0]);
	if (!nbr)
		return (0);
	nbr[n] = '\0';
	n = ft_atoi(nbr);
	charset[0] = split[0][ft_strlen(nbr)];
	charset[1] = split[0][ft_strlen(nbr) + 1];
	charset[2] = split[0][ft_strlen(nbr) + 2];
	free(nbr);
	if (!check_map_core(split, n, charset))
		return (put_error());
	return (1);
}