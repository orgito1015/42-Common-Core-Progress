/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:59 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:01 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*word;
	char	*ptr;

	if (!src)
		return (NULL);
	word = (char *)malloc(ft_strlen(src) + 1);
	if (!word)
		return (NULL);
	ptr = word;
	while (*src)
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\0';
	return (word);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
