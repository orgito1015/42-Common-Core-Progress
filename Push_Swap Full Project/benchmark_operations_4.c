/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_operations_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:04:28 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:04:30 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percent_fd(double value, int fd)
{
	int	int_part;
	int	dec_part;

	int_part = (int)value;
	dec_part = (int)((value - int_part) * 100);
	if (dec_part < 0)
		dec_part = -dec_part;
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (dec_part < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(dec_part, fd);
	ft_putchar_fd('%', fd);
}

static void	print_bench_header(double disorder, char *strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent_fd(disorder, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_bench_ps(t_ops *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_bench_rot(t_ops *ops)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	display_benchmark(double disorder, char *strategy, t_ops *ops)
{
	char	*strategy_name;

	strategy_name = get_strategy_description(strategy, disorder);
	print_bench_header(disorder, strategy_name);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ops->total, 2);
	ft_putchar_fd('\n', 2);
	print_bench_ps(ops);
	print_bench_rot(ops);
}
