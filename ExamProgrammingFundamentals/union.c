#include <unistd.h>

int	ft_strlen(char *s1)
{
	int len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

static void	remove_from(char *s1, int len, char c, int start)
{
	int	i;

	i = start;
	while (i < len)
	{
		if (s1[i] == c)
			s1[i] = 0;
		i++;
	}
}

static void check_1(char *s1, char *s2, int len1, int len2)
{
	int i;

	i = 0;
	while (i < len1)
	{
		if (s1[i] != 0)
		{
			remove_from(s1, len1, s1[i], i + 1);
			remove_from(s2, len2, s1[i], 0);
			write(1, s1 + i, 1);
		}
		i = i + 1;
	}

}

void	ft_union(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	check_1(s1, s2, len1, len2);
	check_1(s2, s1, len2, len1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
