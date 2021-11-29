/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:16:56 by jboumal           #+#    #+#             */
/*   Updated: 2021/11/19 09:02:35 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	issspace(char *c)
{
	if (*c == ' ' || *c == '\f' || *c == '\n'
		|| *c == '\r' || *c == '\t' || *c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	negative;

	nb = 0;
	negative = 0;
	while (issspace(str))
		str ++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = (negative + 1) % 2;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str ++;
	}
	if (negative)
		return (-nb);
	else
		return (nb);
}
