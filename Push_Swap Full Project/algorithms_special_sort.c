/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_special_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:10 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:12 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a, t_ops *ops)
{
	t_data	*first;
	t_data	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = (t_data *)(*a)->content;
	second = (t_data *)(*a)->next->content;
	if (first->index > second->index)
		op_sa(a, ops);
}

static void	sort_three_cases(t_list **a, t_three *t, t_ops *ops)
{
	if (t->d1->index < t->d2->index && t->d2->index < t->d3->index)
		return ;
	else if (t->d1->index > t->d2->index && t->d2->index < t->d3->index
		&& t->d1->index < t->d3->index)
		op_sa(a, ops);
	else if (t->d1->index > t->d2->index
		&& t->d2->index > t->d3->index)
	{
		op_sa(a, ops);
		op_rra(a, ops);
	}
	else if (t->d1->index > t->d2->index && t->d2->index < t->d3->index
		&& t->d1->index > t->d3->index)
		op_ra(a, ops);
	else if (t->d1->index < t->d2->index && t->d2->index > t->d3->index
		&& t->d1->index < t->d3->index)
	{
		op_sa(a, ops);
		op_ra(a, ops);
	}
	else if (t->d1->index < t->d2->index && t->d2->index > t->d3->index
		&& t->d1->index > t->d3->index)
		op_rra(a, ops);
}

void	sort_three(t_list **a, t_ops *ops)
{
	t_three	t;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	t.d1 = (t_data *)(*a)->content;
	t.d2 = (t_data *)(*a)->next->content;
	t.d3 = (t_data *)(*a)->next->next->content;
	sort_three_cases(a, &t, ops);
}

void	sort_four(t_list **a, t_list **b, t_ops *ops)
{
	if (is_sorted(*a))
		return ;
	push_smallest_to_b(a, b, ops);
	sort_three(a, ops);
	op_pa(a, b, ops);
}

void	sort_five(t_list **a, t_list **b, t_ops *ops)
{
	t_data	*d1;
	t_data	*d2;

	if (is_sorted(*a))
		return ;
	push_smallest_to_b(a, b, ops);
	push_smallest_to_b(a, b, ops);
	sort_three(a, ops);
	d1 = (t_data *)(*b)->content;
	d2 = (t_data *)(*b)->next->content;
	if (d1->index < d2->index)
		op_sb(b, ops);
	op_pa(a, b, ops);
	op_pa(a, b, ops);
}
