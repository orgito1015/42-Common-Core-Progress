/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:21:55 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:21:57 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		copy;
	size_t				i;
	const unsigned char	*array;

	array = (const unsigned char *)s;
	i = 0;
	copy = (unsigned char)c;
	while (i < n)
	{
		if (array[i] == copy)
			return ((void *)&array[i]);
		++i;
	}
	return (0);
}
