/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:03 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:05 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;
	int				size;

	size = ft_strlen(s);
	new = malloc(sizeof(char) * size + 1);
	if (!new)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
