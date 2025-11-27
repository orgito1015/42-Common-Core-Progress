void ft_swap(int *a, int *b)
{
    /* we have to declare a temporary variable
     * to make a swap between 2 variables
     */
    int x;
    // set our temporary variable to be equal to the value of *a
    x = *a;
    // set the value of *a to be equal to the value of *b
    *a = *b;
    // set the value of *b to be equal to the value of x
    *b = x;
}
