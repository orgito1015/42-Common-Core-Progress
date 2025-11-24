/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:31 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:33 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	s_len;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
