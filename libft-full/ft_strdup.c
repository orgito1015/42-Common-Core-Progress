/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:23 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:23:25 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		length;
	int		i;

	i = 0;
	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		++length;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (0);
	while (i < length)
	{
		new[i] = s[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
