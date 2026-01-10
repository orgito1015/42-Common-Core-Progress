/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_simple_sorting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:02:51 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:02:53 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_list *a)
{
	int		min_index;
	int		pos;
	int		i;
	t_data	*data;

	if (!a)
		return (0);
	data = (t_data *)a->content;
	min_index = data->index;
	pos = 0;
	i = 0;
	while (a)
	{
		data = (t_data *)a->content;
		if (data->index < min_index)
		{
			min_index = data->index;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

void	rotate_b_to_top(t_list **b, int pos, int size, t_ops *ops)
{
	if (pos <= size / 2)
	{
		while (pos--)
			op_rb(b, ops);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			op_rrb(b, ops);
	}
}

static void	rotate_to_top(t_list **a, int pos, int size, t_ops *ops)
{
	if (pos <= size / 2)
	{
		while (pos--)
			op_ra(a, ops);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			op_rra(a, ops);
	}
}

void	selection_sort(t_list **a, t_list **b, t_ops *ops)
{
	int	size;
	int	min_pos;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	while (size > 0)
	{
		min_pos = find_min_position(*a);
		rotate_to_top(a, min_pos, size, ops);
		op_pb(a, b, ops);
		size--;
	}
	while (*b)
		op_pa(a, b, ops);
}

void	simple_sort(t_list **a, t_list **b, t_ops *ops)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size == 2)
		sort_two(a, ops);
	else if (size == 3)
		sort_three(a, ops);
	else if (size == 4)
		sort_four(a, b, ops);
	else if (size == 5)
		sort_five(a, b, ops);
}
