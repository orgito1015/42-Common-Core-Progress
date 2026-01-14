#include <unistd.h>

int main(int ac, char **av)
{
    int i;
	int j;

    i=0;
	j=0;

	if(ac == 3)
        {
                while( av[1][i] && av[1][j])
                {
                        if(av[1][i] == av[1][j])
                        i++;
                j++;
                }
        }
	if( av[1][i]   == '\0')
                {
                        write(1, av[1], i);
                }


     write(1, "\n", 1);
     return 0;
}



