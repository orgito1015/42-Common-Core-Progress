/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:16 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:18 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	return (i);
}

static int	fill_nums(int *nums, char **parts, int size)
{
	int		i;
	long	val;

	i = 0;
	while (i < size)
	{
		val = ft_atol(parts[i]);
		nums[i] = (int)val;
		i++;
	}
	return (0);
}

static int	*alloc_and_fill(char **parts, int *size)
{
	int		*nums;

	*size = count_parts(parts);
	nums = malloc(sizeof(int) * (*size));
	if (!nums)
		return (NULL);
	fill_nums(nums, parts, *size);
	return (nums);
}

int	*parse_single_arg(char *arg, int *size)
{
	char	**parts;
	int		*nums;

	parts = ft_split(arg, ' ');
	if (!parts)
		return (NULL);
	nums = alloc_and_fill(parts, size);
	if (!nums)
	{
		free_split(parts);
		return (NULL);
	}
	free_split(parts);
	return (nums);
}
