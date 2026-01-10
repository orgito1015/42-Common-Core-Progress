/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:14 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:16 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_list **a, t_list **b, t_ops *ops)
{
	pa(a, b);
	print_op("pa", ops);
}

void	op_sa(t_list **a, t_ops *ops)
{
	sa(a);
	print_op("sa", ops);
}

void	op_sb(t_list **b, t_ops *ops)
{
	sb(b);
	print_op("sb", ops);
}

void	op_ss(t_list **a, t_list **b, t_ops *ops)
{
	ss(a, b);
	print_op("ss", ops);
}

void	op_ra(t_list **a, t_ops *ops)
{
	ra(a);
	print_op("ra", ops);
}
