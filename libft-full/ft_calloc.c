/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:19:25 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:19:27 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t				i;
	size_t				total;
	unsigned char		*init;

	i = 0;
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (0);
	total = nmemb * size;
	init = malloc(total);
	if (!init)
		return (0);
	while (i < total)
	{
		init[i] = 0;
		++i;
	}
	return ((void *)init);
}
