#include <unistd.h>

int main(int ac, char *av[])
{
    if (ac == 4)
    {
        int i;
        
        i = 0;
        while (av[1][i])
        {

            if (av[1][i] == av[2][0])
                av[1][i] = av[3][0];

            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
