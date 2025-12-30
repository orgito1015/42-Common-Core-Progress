#include <stdlib.h>

static int	my_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		len;

	len = my_ft_strlen(str);
	ret = malloc(sizeof(*ret) * (len + 1));
	if (ret == 0)
		return (ret);
	ret[len] = 0;
	while (len > 0)
	{
		ret[len - 1] = str[len - 1];
		len = len - 1;
	}
	return (ret);
}

int		*ft_range(int start, int end)
{
	int	step = (start > end ? -1 : 1);
	int	size = (start > end ? start - end + 1 : end - start + 1);
	int	*ret = malloc(sizeof(*ret) * size);
	int	i;

	for (i = 0; i < size; i++)
	{
		ret[i] = start;
		start += step;
	}
	return (ret);
}
