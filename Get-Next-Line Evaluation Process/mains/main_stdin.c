#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    char *line;
    while ((line = get_next_line(0)))
    {
        printf("stdin: %s", line);
        free(line);
    }
    return (0);
}
