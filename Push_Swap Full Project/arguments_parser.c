/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:22 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:24 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_multi_args(int argc, char **argv, int *size)
{
	int		*nums;
	long	val;
	int		i;

	*size = argc - 1;
	nums = malloc(sizeof(int) * (*size));
	if (!nums)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		val = ft_atol(argv[i + 1]);
		nums[i] = (int)val;
		i++;
	}
	return (nums);
}

static int	*validate_nums(int *nums, int size)
{
	if (!nums)
		return (NULL);
	if (!check_duplicate(nums, size))
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}

int	*parse_args(int argc, char **argv, int *size)
{
	int	*nums;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		nums = parse_single_arg(argv[1], size);
	else
		nums = parse_multi_args(argc, argv, size);
	return (validate_nums(nums, *size));
}

void	free_split(char **parts)
{
	int	i;

	if (!parts)
		return ;
	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}
