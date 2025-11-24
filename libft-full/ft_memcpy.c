/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:22:09 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:22:11 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*first;
	char		*second;

	first = (const char *)src;
	second = (char *)dest;
	i = 0;
	while (i < n)
	{
		second[i] = first[i];
		++i;
	}
	return (dest);
}
