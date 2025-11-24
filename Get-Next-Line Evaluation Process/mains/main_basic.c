#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (printf("Usage: %s <file>\n", av[0]), 1);
    int   fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (perror("open"), 1);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
