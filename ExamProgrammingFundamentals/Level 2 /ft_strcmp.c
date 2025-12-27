int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    // looping over both string while both of them are equal
    // and at least one of them is not finished
    while ((s1[i] || s2[i]) && s1[i] == s2[i])
        i++;
    // when we can't loop anymore, we return the substraction
    // of the last compared characters in both string, this will
    // result in either a negative, zero or positive value
    return (s1[i] - s2[i]);
}
