#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;

    if (ac == 3)
    {
        // check if all characters of av[1] appear in order in av[2]
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }

        // if we reached the end of av[1], all chars were matched
        if (av[1][i] == '\0')
            write(1, av[1], i);
    }

    write(1, "\n", 1);
    return 0;
}
