/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:20:26 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:20:29 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		++c;
	}
	return (c);
}

static void	init_values(int n, int *size, int *sign, long *num)
{
	*sign = 0;
	*size = count(n);
	*num = n;
	if (*num < 0)
	{
		*num = *num * -1;
		*size = *size + 1;
		*sign = 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		size;
	int		sign;
	long	num;

	i = 0;
	init_values(n, &size, &sign, &num);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (num > 0)
	{
		str[size - i - 1] = (num % 10) + '0';
		num = num / 10;
		++i;
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	if (sign)
		str[0] = '-';
	return (str);
}
