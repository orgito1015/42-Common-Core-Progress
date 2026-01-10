/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_disorder_metrics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:47 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:49 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *arr, int size)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

double	compute_stack_disorder(t_list *stack)
{
	int		*arr;
	t_list	*tmp;
	int		i;
	double	disorder;

	if (!stack)
		return (0.0);
	arr = malloc(sizeof(int) * stack_size(stack));
	if (!arr)
		return (0.0);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = ((t_data *)tmp->content)->value;
		tmp = tmp->next;
	}
	disorder = compute_disorder(arr, i) * 100.0;
	free(arr);
	return (disorder);
}
