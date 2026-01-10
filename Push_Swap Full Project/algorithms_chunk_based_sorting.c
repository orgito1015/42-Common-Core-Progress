/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_chunk_based_sorting.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:01:53 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:02:34 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_list *node)
{
	t_data	*data;

	if (!node)
		return (0);
	data = (t_data *)node->content;
	return (data->index);
}

static int	int_sqrt(int n)
{
	int	k;

	if (n <= 0)
		return (0);
	k = 1;
	while ((k + 1) * (k + 1) <= n)
		k++;
	return (k);
}

static void	push_chunks_to_b(t_list **a, t_list **b, int size, t_ops *ops)
{
	int	chunk_size;
	int	current_max;
	int	pushed;
	int	idx;

	chunk_size = int_sqrt(size);
	if (chunk_size < 1)
		chunk_size = 1;
	current_max = chunk_size - 1;
	pushed = 0;
	while (pushed < size)
	{
		idx = get_index(*a);
		if (idx <= current_max)
		{
			op_pb(a, b, ops);
			pushed++;
			if (idx < current_max - chunk_size / 2)
				op_rb(b, ops);
			if (pushed > current_max && current_max < size - 1)
				current_max += chunk_size;
		}
		else
			op_ra(a, ops);
	}
}

static int	find_max_position(t_list *b)
{
	int		max_index;
	int		pos;
	int		i;
	t_data	*data;

	if (!b)
		return (0);
	data = (t_data *)b->content;
	max_index = data->index;
	pos = 0;
	i = 0;
	while (b)
	{
		data = (t_data *)b->content;
		if (data->index > max_index)
		{
			max_index = data->index;
			pos = i;
		}
		i++;
		b = b->next;
	}
	return (pos);
}

void	medium_sort(t_list **a, t_list **b, t_ops *ops)
{
	int	size;
	int	pos;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		selection_sort(a, b, ops);
		return ;
	}
	push_chunks_to_b(a, b, size, ops);
	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_position(*b);
		rotate_b_to_top(b, pos, size, ops);
		op_pa(a, b, ops);
	}
}
