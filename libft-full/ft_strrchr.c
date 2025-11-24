/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:19 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:22 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;

	found = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			found = ((char *)&s[i]);
		++i;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (found);
}
