/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:58:50 by oleka             #+#    #+#             */
/*   Updated: 2025/11/05 16:58:52 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_handle(char sp, va_list *args)
{
	if (sp == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (sp == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (sp == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (sp == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (sp == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (sp == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (sp == '%')
		return (ft_print_percent());
	else if (sp == 'd' || sp == 'i')
		return (ft_print_number(va_arg(*args, int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle(format[i], &args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
