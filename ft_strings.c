#include "header.h"

int	list_len(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*s;
	char	*dup;
	int		size;

	size = 0;
	s = src;
	while (*s++)
		size ++;
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (0);
	s = dup;
	while (*src)
	{
		*s = *src;
		src ++;
		s ++;
	}
	*s = '\0';
	return (dup);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str ++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*d;

	d = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (d);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str += 1;
	}
}
