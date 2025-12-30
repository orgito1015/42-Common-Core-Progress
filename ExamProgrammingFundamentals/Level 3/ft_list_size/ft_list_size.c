#include "ft_list.h"

int				ft_list_size(t_list *begin_list)
{
	t_list*		elem = begin_list;
	int			i = 0;
	
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return i;
}
