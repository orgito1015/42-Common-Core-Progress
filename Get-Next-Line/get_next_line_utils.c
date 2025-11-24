/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:35:28 by oleka             #+#    #+#             */
/*   Updated: 2025/11/12 11:35:31 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

int	ft_n_or_l(const char *s, char c)
{
	size_t	i;

	if (c == 'n')
	{
		if (!s)
			return (0);
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		if (!s)
			return (0);
		i = 0;
		while (s[i])
			i++;
		return (i);
	}
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s1;
	size_t	i;

	len = ft_n_or_l(s, 'l');
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_concatenate(char *file_content, char *buffer)
{
	size_t	len_fc;
	size_t	len_buf;
	char	*new_file_content;
	size_t	i;
	size_t	j;

	len_fc = ft_n_or_l(file_content, 'l');
	len_buf = ft_n_or_l(buffer, 'l');
	new_file_content = malloc(len_fc + len_buf + 1);
	if (!new_file_content)
		return (NULL);
	i = 0;
	if (file_content)
	{
		while (i < len_fc)
		{
			new_file_content[i] = file_content[i];
			i++;
		}
	}
	j = 0;
	while (j < len_buf)
		new_file_content[i++] = buffer[j++];
	new_file_content[i] = '\0';
	return (new_file_content);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_n_or_l(s, 'l');
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

t_lines	ft_zeroed(void)
{
	t_lines	lines;

	lines.line = NULL;
	lines.remainder = NULL;
	return (lines);
}
