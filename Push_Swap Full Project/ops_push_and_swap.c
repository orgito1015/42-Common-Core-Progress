/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_and_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:08 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:10 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*popped;

	if (!stack_b || !*stack_b)
		return ;
	popped = pop(stack_b);
	if (popped)
		push(stack_a, popped);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*popped;

	if (!stack_a || !*stack_a)
		return ;
	popped = pop(stack_a);
	if (popped)
		push(stack_b, popped);
}

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack_a = second;
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack_b = second;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
