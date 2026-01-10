/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_radix_sorting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:02:44 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:02:46 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_list **a, t_list **b, int size, t_ops *ops)
{
	int		i;
	int		j;
	int		bit;
	t_data	*d;

	if (!a || !*a)
		return ;
	bit = get_max_bits(size);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j < size)
		{
			d = (t_data *)(*a)->content;
			if (((d->index >> i) & 1) == 0)
				op_pb(a, b, ops);
			else
				op_ra(a, ops);
			j++;
		}
		while (*b)
			op_pa(a, b, ops);
		i++;
	}
}
