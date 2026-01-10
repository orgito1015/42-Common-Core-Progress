/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:08 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:10 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_op(char *op, t_ops *ops)
{
	if (!op || !ops)
		return ;
	if (ft_strncmp(op, "sa", 3) == 0)
		ops->sa++;
	else if (ft_strncmp(op, "sb", 3) == 0)
		ops->sb++;
	else if (ft_strncmp(op, "ss", 3) == 0)
		ops->ss++;
	else if (ft_strncmp(op, "pa", 3) == 0)
		ops->pa++;
	else if (ft_strncmp(op, "pb", 3) == 0)
		ops->pb++;
	else if (ft_strncmp(op, "ra", 3) == 0)
		ops->ra++;
	else if (ft_strncmp(op, "rb", 3) == 0)
		ops->rb++;
	else if (ft_strncmp(op, "rr", 3) == 0)
		ops->rr++;
	else if (ft_strncmp(op, "rra", 3) == 0)
		ops->rra++;
	else if (ft_strncmp(op, "rrb", 3) == 0)
		ops->rrb++;
	else if (ft_strncmp(op, "rrr", 3) == 0)
		ops->rrr++;
}

void	increment_total(char *op, t_ops *ops)
{
	if (!op || !ops)
		return ;
	else
		ops->total++;
}

void	print_op(char *op, t_ops *ops)
{
	ft_putstr_fd(op, 1);
	ft_putchar_fd('\n', 1);
	increment_op(op, ops);
	increment_total(op, ops);
}

char	*get_strategy_description(char *strategy_flag, double disorder)
{
	if (!strategy_flag || !*strategy_flag
		|| ft_strncmp(strategy_flag, "--adaptive", 11) == 0)
	{
		if (disorder < 20.0)
			return ("Adaptive / O(n)");
		else if (disorder < 50.0)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(n log n)");
	}
	else if (ft_strncmp(strategy_flag, "--simple", 9) == 0)
		return ("Simple / O(n^2)");
	else if (ft_strncmp(strategy_flag, "--medium", 9) == 0)
		return ("Medium / O(n√n)");
	else if (ft_strncmp(strategy_flag, "--complex", 10) == 0)
		return ("Complex / O(n log n)");
	else
		return ("Unknown Strategy");
}

void	op_pb(t_list **a, t_list **b, t_ops *ops)
{
	pb(a, b);
	print_op("pb", ops);
}
