# Level 1 – Exam Programming Fundamentals - 42 Common Core Exam

This repository contains solutions for **Level 1** exercises of the **42 Common Core Exam**.  
Level 1 focuses on validating **C fundamentals**, **string manipulation**, and **basic algorithmic logic**, strictly following **42 Norm**.

## Exercises

- `first_word` – Print the first word of a string
```
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

This program takes exactly one command-line argument and prints the first word of that argument to the standard output (usually the terminal). A "word" here is defined as a sequence of non-whitespace characters. After printing the first word, it outputs a newline character.
Detailed Explanation
1. Included Header

#include <unistd.h> // For the write() system call

    The program uses the write() system call to output characters.
    unistd.h provides the declaration for write().

2. main Function Signature

int main(int ac, char **av)

    ac (argument count) holds the number of command-line arguments.
    av (argument vector) is an array of strings representing the arguments.
    av[0] is the program name.
    av[1] is the first argument passed by the user.

3. Variable Initialization

int i;
i = 0;

    i is used as an index to iterate through the characters of the input string (av[1]).

4. Argument Count Check

if (ac == 2)

    The program proceeds only if exactly one argument is provided (excluding the program name).
    This prevents errors like accessing av[1] when no argument is given.

5. Skipping Leading Whitespace

while (av[1][i] && av[1][i] <= ' ')
    i++;

    This loop skips all leading whitespace characters.
    Whitespace characters are those with ASCII values less than or equal to space ' ' (ASCII 32).
    The condition av[1][i] ensures the loop stops at the end of the string ('\0').

6. Printing the First Word

while (av[1][i] > ' ')
    write(1, &av[1][i++], 1);

    This loop prints characters one by one until it encounters a whitespace or the end of the string.
    write(1, &av[1][i], 1) writes a single character to file descriptor 1 (standard output).
    i++ increments the index after each character is printed.

7. Printing a Newline

write(1, "\n", 1);

    Prints a newline character after the first word, ensuring output formatting is clean.

8. Return Statement

return 0;

    Indicates successful program termination.

Key Programming Concepts and Patterns

    Command-line argument handling: The program checks the number of arguments before processing.
    Character iteration: Uses a loop with an index to traverse a string.
    Whitespace handling: Skips leading whitespace and stops printing at the next whitespace.
    System call for output: Uses write() instead of printf(), which is a lower-level and more efficient way to output characters.
    Robustness: The program avoids undefined behavior by checking argument count.

Potential Improvements

    Whitespace Definition:
        The code treats any character with ASCII value <= ' ' as whitespace, which includes control characters.
        Using isspace() from <ctype.h> would be more precise and readable.

    Error Handling:
        The program silently does nothing if the argument count is not 2.
        It could print a usage message or an error to inform the user.

    Use of write() vs printf():
        While write() is efficient, printf() is more readable and flexible for beginners.
        For educational purposes, printf() might be preferred.

Alternative Approach Using printf() and isspace()

#include <stdio.h>
#include <ctype.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] && isspace(av[1][i]))
            i++;

        while (av[1][i] && !isspace(av[1][i]))
            putchar(av[1][i++]);
    }
    putchar('\n');
    return 0;
}

    This version is more readable and uses standard library functions for whitespace checking and output.

Summary

    The program extracts and prints the first word from the first command-line argument.
    It demonstrates basic string traversal, argument handling, and low-level output.
    It is a simple yet effective example of parsing input and controlling output in C.
```
 
- `ft_putstr` – Output a string to stdout
```
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);
```
  
- `ft_strcpy` – Copy a string
```
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
```
  
- `ft_strlen` – Compute string length
```
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
```
- `ft_swap` – Swap two integers
```
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
```
- `rot_13` – Apply ROT13 cipher
```
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.
```
- `rotone` – Rotate characters by one
```
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.
```
- `search_and_replace` – Replace characters in a string
```
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.
```
- `ulstr` – Toggle uppercase and lowercase characters
```
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.
```

## Constraints

- Language: **C**
- Norminette compliant
- No forbidden functions
- Exam-oriented implementation

## Goal

This level prepares students for the **first Common Core exam** by covering essential logic patterns and string operations required to pass.

