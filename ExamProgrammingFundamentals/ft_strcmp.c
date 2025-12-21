#include <unistd.h>

/*
 * Compares two strings character by character.
 * Returns:
 *  - 0 if strings are equal
 *  - A positive value if s1 > s2
 *  - A negative value if s1 < s2
 */
int strcmp(char *s1, char *s2)
{
    int i;

    /* Initialize index to start from the first character */
    i = 0;

    /*
     * Loop while characters are equal
     * and the end of the first string is not reached
     */
    while (s1[i] == s2[i] && s1[i])
        i++;

    /*
     * Return the difference between the first
     * non-matching characters
     */
    return (s1[i] - s2[i]);
}
