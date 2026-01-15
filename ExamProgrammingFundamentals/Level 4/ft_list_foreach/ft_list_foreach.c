#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list*		elem = begin_list;
	
	while (elem)
	{
		f(elem->data);
		elem = elem->next;
	}
}
