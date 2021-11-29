/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:06:22 by jboumal           #+#    #+#             */
/*   Updated: 2021/11/28 11:05:09 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_separator(char *c, char *charset)
{
	while (*charset)
	{
		if (*c == *charset)
			return (1);
		charset ++;
	}
	return (0);
}

int	n_str(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str && !is_separator(str, charset))
	{
		i++;
		str ++;
	}
	return (i);
}

int	n_words(char *str, char *charset)
{
	int	new;
	int	n;

	new = 1;
	n = 0;
	while (*str)
	{
		if (new && !is_separator(str, charset))
		{
			new = 0;
			n += 1;
		}
		if (is_separator(str, charset))
			new = 1;
		str ++;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	int		n;
	char	**split;
	char	*s;
	char	**tsplit;

	n = n_words(str, charset);
	split = malloc((n + 1) * sizeof(char *));
	tsplit = split;
	while (--n >= 0)
	{
		while (is_separator (str, charset))
			str++;
		*tsplit = malloc(sizeof(char) * (n_str(str, charset) + 1));
		s = *tsplit;
		while (n_str(str, charset))
			*s++ = *str++;
		*s = '\0';
		tsplit++;
	}
	*tsplit = 0;
	return (split);
}
