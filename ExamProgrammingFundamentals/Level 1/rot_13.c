#include <unistd.h>

int			main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c <= 'Z' && c >= 'A')
				c = (c - 'A' + 13) % 26 + 'A';
			else if (c <= 'z' && c >= 'a')
				c = (c - 'a' + 13) % 26 + 'a';
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
