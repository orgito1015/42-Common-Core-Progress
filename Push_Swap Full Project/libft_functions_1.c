/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:51 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:53 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
