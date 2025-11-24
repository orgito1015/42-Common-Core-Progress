/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:18:41 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:18:44 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	i = 0;
	while (is_whitespace(nptr[i]) && nptr[i] != '\0')
		++i;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0');
		++i;
	}
	return (num * sign);
}
