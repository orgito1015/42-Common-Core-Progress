/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:08 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:10 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char c1, char c2)
{
	return ((unsigned char)c1 - (unsigned char)c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (ft_charcmp(s1[i], s2[i]));
		if (s1[i] == '\0')
			break ;
		++i;
	}
	return (0);
}
