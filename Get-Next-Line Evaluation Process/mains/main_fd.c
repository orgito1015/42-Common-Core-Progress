#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line = get_next_line(42);
    printf("invalid fd result: %s\n", line);
    return (0);
}
