/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:29 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:31 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*stack_a = second;
	second->prev = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*stack_b = second;
	second->prev = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
