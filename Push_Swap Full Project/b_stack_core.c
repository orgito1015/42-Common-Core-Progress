/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:03:54 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:03:57 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	push(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

t_list	*pop(t_list **lst)
{
	t_list	*current;

	if (!lst || !*lst)
		return (NULL);
	current = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	current->next = NULL;
	current->prev = NULL;
	return (current);
}

static int	create_and_push(t_list **stack_a, int n, int idx)
{
	t_data	*data;
	t_list	*node;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->value = n;
	data->index = idx;
	node = stack(data);
	if (!node)
	{
		free(data);
		return (1);
	}
	push(stack_a, node);
	return (0);
}

void	fill_stack(t_list **stack_a, int *nums, int size)
{
	int		*indexed;
	int		i;

	if (!stack_a || !nums || size <= 0)
		return ;
	indexed = index_array(nums, size);
	if (!indexed)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		if (create_and_push(stack_a, nums[i], indexed[i]))
			break ;
		i--;
	}
	free(indexed);
}
