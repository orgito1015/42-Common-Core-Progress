/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:21:00 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:21:02 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_helper(t_list *ptr, void (*del)(void *))
{
	if (ptr == NULL)
		return ;
	clear_helper(ptr->next, del);
	del(ptr->content);
	free(ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	clear_helper(*lst, del);
	*lst = NULL;
}
