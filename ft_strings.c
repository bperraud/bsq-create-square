/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:58:38 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 09:00:08 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*s1 - *s2);
	else
		return (0);
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
