/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validate_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:27 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:29 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int_str(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_in_int_range(char *s)
{
	long	n;

	n = ft_atol(s);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int	validate_split_args(char **parts)
{
	int	k;

	k = 0;
	while (parts[k])
	{
		if (!is_valid_int_str(parts[k])
			|| !is_in_int_range(parts[k]))
			return (0);
		k++;
	}
	return (1);
}

int	validate_argv_args(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (!is_valid_int_str(argv[j])
			|| !is_in_int_range(argv[j]))
			return (0);
		j++;
	}
	return (1);
}
