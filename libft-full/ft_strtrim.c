/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:24:26 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:24:28 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	t_substr_data	data;

	if (!s1 || !set)
		return (0);
	data.s1_len = ft_strlen(s1);
	data.start = 0;
	data.end = data.s1_len;
	data.i = 0;
	data.str = NULL;
	while (ft_strchr(set, s1[data.start]) && s1[data.start] != '\0')
		++data.start;
	while (ft_strchr(set, s1[data.end - 1]) && data.end > data.start)
		--data.end;
	data.str = malloc(sizeof(char) * (data.end - data.start + 1));
	if (!data.str)
		return (0);
	while (data.i < data.end - data.start)
	{
		data.str[data.i] = s1[data.start + data.i];
		++data.i;
	}
	data.str[data.i] = '\0';
	return (data.str);
}
