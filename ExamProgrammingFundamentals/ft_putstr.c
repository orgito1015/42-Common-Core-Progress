#include <unistd.h>

void	ft_putstr(char *str)
{
	size_t i = 0;
	while (str[i])
	{
		i++;
	}
	write(1, str, i);
}
