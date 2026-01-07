#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char c;

    if (ac == 2)
    {
        while (av[1][i])
        {
            c = av[1][i];
            if (c == 'z')
                c = 'a';
            else if (c == 'Z')
                c = 'A';
            else if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
                c++;
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
