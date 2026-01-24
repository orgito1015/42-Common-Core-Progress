#include <unistd.h> // For the write() system call

int main(int ac, char *av[])
{
    // Check if exactly 3 arguments are provided (program name + 3)
    if (ac == 4)
    {
        int i; // Loop counter for iterating through the string
        
        i = 0; // Start from the first character of av[1] (the input string)
        
        // Loop through each character of the string until we reach '\0' (end of string)
        while (av[1][i] && av[2][1] == '\0' && av[3][1] == '\0')
        {
            // If the current character matches the target character (av[2][0])
            if (av[1][i] == av[2][0])
                av[1][i] = av[3][0];  // Replace it with the new character (av[3][0])

            // Print the current character to standard output
            write(1, &av[1][i], 1);

            i++; // Move to the next character
        }
    }

    // Print a newline at the end for proper formatting
    write(1, "\n", 1);

    return 0; // Return 0 to indicate successful execution
}
