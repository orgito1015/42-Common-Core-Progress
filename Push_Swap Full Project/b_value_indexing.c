/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_value_indexing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:00 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:02 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*copy_and_sort(int *nums, int size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = nums[i];
		i++;
	}
	sort_int_array(sorted, size);
	return (sorted);
}

static int	*assign_indexes(int *nums, int *sorted, int size)
{
	int	*indexed;
	int	i;
	int	j;

	indexed = malloc(sizeof(int) * size);
	if (!indexed)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (nums[i] == sorted[j])
			{
				indexed[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (indexed);
}

void	assign_indexes_to_stack(t_list *stack, int *indexed)
{
	int		i;
	t_data	*d;

	i = 0;
	while (stack)
	{
		d = (t_data *)stack->content;
		d->index = indexed[i];
		stack = stack->next;
		i++;
	}
}

int	*index_array(int *nums, int size)
{
	int	*sorted;
	int	*indexed;

	sorted = copy_and_sort(nums, size);
	if (!sorted)
		return (NULL);
	indexed = assign_indexes(nums, sorted, size);
	free(sorted);
	return (indexed);
}
