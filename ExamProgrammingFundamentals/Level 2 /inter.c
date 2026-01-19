#include <unistd.h>

int ft_putchar(char c)
{
        write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i;
	i =0;
	int j;
	
    int seen[256] = {};

        if(ac == 3)
        {

                while(av[1][i])
                {
                        j=0;
                        while(av[2][j])
                        {
                                if(av[1][i] ==av[2][j] && !seen[(int)av[2][j]])
                                {
                                seen[(int)av[2][j]]=1;
                                ft_putchar(av[2][j]);

                                }
                                j++;
                        }
                        i++;
                }

        }
	ft_putchar('\n');
}





