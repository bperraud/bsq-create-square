/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:59:31 by jboumal           #+#    #+#             */
/*   Updated: 2021/12/01 09:01:33 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	list_len(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int	ft_strlen_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}
