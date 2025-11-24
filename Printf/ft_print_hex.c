/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:58:09 by oleka             #+#    #+#             */
/*   Updated: 2025/11/05 16:58:12 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int uppercase)
{
	char	*hex_digits;
	int		count;

	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_hex(num / 16, uppercase);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}
