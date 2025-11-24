/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:23:12 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:23:14 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			count++;
		}
		++i;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	*copy_to_array(const char *s, int start, int end)
{
	int		size;
	char	*word;
	int		i;

	i = 0;
	size = end - start + 1;
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = s[start + i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		++i;
	}
	free(array);
}

static int	split_helper(const char *s, char c, t_split_data *data)
{
	while (s[data->i] != '\0')
	{
		if (s[data->i] != c && data->start == -1)
		{
			data->start = data->i;
		}
		else if (s[data->i] == c && data->start != -1)
		{
			data->array[data->count++] = copy_to_array(s, data->start,
					data->i - 1);
			if (!data->array[data->count - 1])
			{
				free_all(data->array, data->size);
				return (0);
			}
			data->start = -1;
		}
		data->i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	t_split_data	data;

	data.i = 0;
	data.start = -1;
	data.count = 0;
	data.size = count_words(s, c);
	data.array = malloc(sizeof(char *) * (data.size + 1));
	if (!data.array)
		return (0);
	if (!split_helper(s, c, &data))
		return (0);
	if (data.start != -1)
	{
		data.array[data.count++] = copy_to_array(s, data.start, data.i - 1);
		if (!data.array[data.count - 1])
		{
			free_all(data.array, data.size);
			return (0);
		}
	}
	data.array[data.count] = NULL;
	return (data.array);
}
