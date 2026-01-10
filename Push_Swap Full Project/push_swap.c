/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:46 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:48 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_context(t_ctx *ctx)
{
	ft_bzero(&ctx->ops, sizeof(t_ops));
	ctx->a = NULL;
	ctx->b = NULL;
	ctx->nums = NULL;
	ctx->size = 0;
	ctx->i = 1;
	ctx->bench = 0;
	ctx->strategy = "--adaptive";
}

static void	run_sort(t_ctx *ctx)
{
	if (ft_strncmp(ctx->strategy, "--simple", 9) == 0)
		selection_sort(&ctx->a, &ctx->b, &ctx->ops);
	else if (ft_strncmp(ctx->strategy, "--medium", 9) == 0)
		medium_sort(&ctx->a, &ctx->b, &ctx->ops);
	else if (ft_strncmp(ctx->strategy, "--complex", 10) == 0)
		radix_sort(&ctx->a, &ctx->b,
			stack_size(ctx->a), &ctx->ops);
	else
		adaptive_sort(&ctx->a, &ctx->b,
			ctx->disorder, &ctx->ops);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		return (0);
	init_context(&ctx);
	handle_flags(argc, argv, &ctx);
	if (!parse_and_validate(argc, argv, &ctx))
		return (write(2, "Error\n", 6), 1);
	ctx.disorder = compute_disorder(ctx.nums, ctx.size);
	fill_stack(&ctx.a, ctx.nums, ctx.size);
	free(ctx.nums);
	if (!ctx.a || is_sorted(ctx.a))
		return (free_stack(&ctx.a), 0);
	run_sort(&ctx);
	if (ctx.bench)
		display_benchmark(ctx.disorder * 100.0, ctx.strategy, &ctx.ops);
	return (free_stack(&ctx.a), free_stack(&ctx.b), 0);
}
