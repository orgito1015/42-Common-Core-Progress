/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:43 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:46 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*copy_word(char const *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	fill_array(char **arr, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			arr[i++] = copy_word(s, len);
			s += len;
		}
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	fill_array(arr, s, c);
	return (arr);
}
