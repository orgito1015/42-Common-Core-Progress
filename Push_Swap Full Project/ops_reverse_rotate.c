/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:36 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:38 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*new_last;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
}

void	rrb(t_list **stack_b)
{
	t_list	*first;
	t_list	*new_last;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_b = last;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
