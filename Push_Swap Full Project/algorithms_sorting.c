/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_sorting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:02:58 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:00 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_data	*cur;
	t_data	*next;

	while (stack && stack->next)
	{
		cur = (t_data *)stack->content;
		next = (t_data *)stack->next->content;
		if (cur->index > next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	find_min_pos(t_list *stack)
{
	int		pos;
	int		min_pos;
	int		min_index;
	t_data	*data;

	pos = 0;
	min_pos = 0;
	data = (t_data *)stack->content;
	min_index = data->index;
	while (stack)
	{
		data = (t_data *)stack->content;
		if (data->index < min_index)
		{
			min_index = data->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	bring_min_to_top(t_list **a, int min_pos, t_ops *ops)
{
	int	size;

	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			op_ra(a, ops);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			op_rra(a, ops);
	}
}

void	push_smallest_to_b(t_list **a, t_list **b, t_ops *ops)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	bring_min_to_top(a, min_pos, ops);
	op_pb(a, b, ops);
}
