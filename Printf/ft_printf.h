/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:58:57 by oleka             #+#    #+#             */
/*   Updated: 2025/11/05 16:58:59 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Main function */
int		ft_printf(const char *format, ...);

/* Conversion functions */
int		ft_print_char(int c);
int		ft_print_percent(void);
int		ft_print_string(char *str);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, int uppercase);
int		ft_print_pointer(void *ptr);

/* Utility functions */
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif