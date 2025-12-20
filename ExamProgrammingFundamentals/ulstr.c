#include <unistd.h>

int main(int ac, char *av[])
{
    /* checking the number of argument 
     */
    if (ac == 2)
    {
        int i;
        
        i = 0;
        /* looping over the whole string
         */
        while (av[1][i])
        {
            /* if the character is an upper-case letter
             * add 32 to it to get the corresponding lower-case
             * letter
             */
            if (av[1][i] >= 65 && av[1][i] <= 90)
                av[1][i] += 32;
            /* if the character is a lower-case letter
             * substract 32 from it to get the corresponding upper-case
             * letter
             */
            else if (av[1][i] >= 97 && av[1][i] <= 122)
                av[1][i] -= 32;
            /* we can then write the current character and 
             * increment i
             */
            write(1, &av[1][i], 1);
            i++;
        }
    }
    /* at the very end, we write a new line, that way if the number
     * of argument is not correct, we'll write a single newline
     */
    write(1, "\n", 1);
}
