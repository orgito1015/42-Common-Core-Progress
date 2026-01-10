/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_operations_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:22 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:24 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rb(t_list **b, t_ops *ops)
{
	rb(b);
	print_op("rb", ops);
}

void	op_rr(t_list **a, t_list **b, t_ops *ops)
{
	rr(a, b);
	print_op("rr", ops);
}

void	op_rra(t_list **a, t_ops *ops)
{
	rra(a);
	print_op("rra", ops);
}

void	op_rrb(t_list **b, t_ops *ops)
{
	rrb(b);
	print_op("rrb", ops);
}

void	op_rrr(t_list **a, t_list **b, t_ops *ops)
{
	rrr(a, b);
	print_op("rrr", ops);
}
