/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_core_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:38 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:40 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_array(int ac, char **av)
{
	char	**new_array;
	int		i;
	int		j;

	new_array = malloc(sizeof(char *) * ac);
	if (!new_array)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		new_array[j] = ft_strdup(av[i]);
		if (!new_array[j])
			return (NULL);
		i++;
		j++;
	}
	new_array[j] = NULL;
	return (new_array);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX)
			return (LONG_MAX);
		if (result * sign < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	return (result * sign);
}

int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_data	*data;

	while (*stack)
	{
		tmp = (*stack)->next;
		data = (t_data *)(*stack)->content;
		free(data);
		free(*stack);
		*stack = tmp;
	}
}

int	stack_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
