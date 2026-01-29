char *ft_strrev(char *str)
{
    int start;  
    int end;    
    int temp;    

    if (!str)
        return (NULL);

    start = 0;
    end = 0;
    while (str[end])  
        end++;    
    end--;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}
