char *ft_strrev(char *str)
{
    int start;   // index from the beginning of the string (left side)
    int end;     // index from the end of the string (right side)
    int temp;    // temporary variable used to swap characters

    // 1) Safety check: if the pointer is NULL, we can't read/write anything
    if (!str)
        return (NULL);

    // 2) Start reversing from the first character
    start = 0;

    // 3) First, find the length of the string by moving 'end' to the '\0'
    end = 0;
    while (str[end])   // while current character is not '\0'
        end++;         // move to next character

    // 4) Now 'end' is at the position of '\0' (one past the last character)
    //    So we move back one step to point to the last real character
    end--;

    // 5) Swap characters from the outside moving inward
    //    Stop when start meets or passes end (middle reached)
    while (start < end)
    {
        // 6) Save the left character in temp
        temp = str[start];

        // 7) Put the right character into the left position
        str[start] = str[end];

        // 8) Put the saved left character into the right position
        str[end] = temp;

        // 9) Move start forward and end backward (toward the center)
        start++;
        end--;
    }

    // 10) Return the same pointer (string is now reversed in-place)
    return (str);
}
