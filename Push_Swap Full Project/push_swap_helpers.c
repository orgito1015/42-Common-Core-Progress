/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:41 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:43 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_flag(char *arg)
{
	return (ft_strncmp(arg, "--simple", 9) == 0
		|| ft_strncmp(arg, "--medium", 9) == 0
		|| ft_strncmp(arg, "--complex", 10) == 0
		|| ft_strncmp(arg, "--adaptive", 11) == 0);
}

static int	is_bench_flag(char *arg)
{
	return (ft_strncmp(arg, "--bench", 8) == 0);
}

void	handle_flags(int argc, char **argv, t_ctx *ctx)
{
	if (ctx->i < argc && is_bench_flag(argv[ctx->i]))
	{
		ctx->bench = 1;
		ctx->i++;
	}
	if (ctx->i < argc && is_strategy_flag(argv[ctx->i]))
	{
		ctx->strategy = argv[ctx->i];
		ctx->i++;
	}
}

int	parse_and_validate(int argc, char **argv, t_ctx *ctx)
{
	char	**parts;
	int		nargc;
	char	**nargv;

	nargc = argc - ctx->i + 1;
	nargv = argv + ctx->i - 1;
	ctx->nums = parse_args(nargc, nargv, &ctx->size);
	if (!ctx->nums)
		return (0);
	if (nargc == 2)
	{
		parts = ft_split(nargv[1], ' ');
		if (!parts)
			return (free(ctx->nums), 0);
		if (!validate_split_args(parts))
			return (free_split(parts), free(ctx->nums), 0);
		free_split(parts);
		return (1);
	}
	if (!validate_argv_args(nargc, nargv))
		return (free(ctx->nums), 0);
	return (1);
}
