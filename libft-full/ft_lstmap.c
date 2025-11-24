/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:21:34 by oleka             #+#    #+#             */
/*   Updated: 2025/11/03 17:21:36 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new->next = ft_lstmap(lst->next, f, del);
	return (new);
}
