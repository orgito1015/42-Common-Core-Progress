/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:58:23 by oleka             #+#    #+#             */
/*   Updated: 2025/11/05 16:58:26 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_ull(unsigned long long n)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		count += hex_ull(n / 16);
	}
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int					count;
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count = 2;
		count += hex_ull(addr);
		return (count);
	}
}
