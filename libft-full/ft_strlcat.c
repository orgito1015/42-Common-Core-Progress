/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:39 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:23:41 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	space_left;

	j = 0;
	i = 0;
	src_len = ft_strlen(src);
	while (dst[j] != '\0' && j < size)
		++j;
	if (j == size)
		return (size + src_len);
	space_left = size - j - 1;
	while (src[i] != '\0' && (space_left - i) > 0)
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[j + i] = '\0';
	return (j + src_len);
}
