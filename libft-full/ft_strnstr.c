/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:13 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:15 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	small_len;

	i = 0;
	small_len = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (little[small_len] != '\0')
		++small_len;
	while (i + small_len <= len && big[i] != '\0')
	{
		if (ft_strncmp(little, big + i, small_len) == 0)
			return ((char *)(big + i));
		++i;
	}
	return (0);
}
