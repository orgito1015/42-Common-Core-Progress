#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc == 1)
    {
        // No file given → read from stdin
        printf("Reading from STDIN (Ctrl+D to stop):\n");
        fd = 0;
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return 1;
        }
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }

    if (argc > 1)
        close(fd);

    return 0;
}
