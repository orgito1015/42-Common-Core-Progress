/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_adaptive_sort_strategy.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:01:05 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:01:09 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_list **stack_a, t_list **stack_b,
		double disorder, t_ops *ops)
{
	int	size;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 5)
	{
		simple_sort(stack_a, stack_b, ops);
		return ;
	}
	if (disorder < 0.2)
		selection_sort(stack_a, stack_b, ops);
	else if (disorder < 0.5)
		medium_sort(stack_a, stack_b, ops);
	else
		radix_sort(stack_a, stack_b, size, ops);
}
