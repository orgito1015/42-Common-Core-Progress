#include <unistd.h> // For the write() system call

int main(int ac, char **av)
{
    int i; // Loop counter for iterating through the string
    i = 0; // Start from the first character

    // Check if exactly 1 argument is provided (program name + 1)
    if (ac == 2)
    {
        // Skip all leading whitespace characters (space, tab, newline, etc.)
        while (av[1][i] && av[1][i] <= ' ')
            i++;

        // Print characters until the next whitespace or end of string
        while (av[1][i] > ' ')
            write(1, &av[1][i++], 1); // &av[1][i] gives the address of the character
    }

    // Print a newline at the end for proper formatting
    write(1, "\n", 1);

    return 0; // Return 0 to indicate successful execution
}
