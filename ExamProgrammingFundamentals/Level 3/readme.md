# Level 3 – Exam Programming Fundamentals - 42 Common Core Exam

This directory contains solutions for **Level 3** of the **Exam Programming Fundamentals**.  
Level 3 focuses on **dynamic memory allocation**, **linked list operations**, and **range generation algorithms**, following strict **42 Norm** rules.

## Exercises

- `ft_range` – Create an array of integers within a specified range
```
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
```

- `ft_list_size` – Count the number of elements in a linked list
```
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
```

## Constraints

- Language: **C**
- Norminette compliant
- No forbidden functions
- One file per exercise (plus header for ft_list_size)
- Exam-style implementations

## Goal

This level validates the ability to work with **dynamic memory allocation** using `malloc`, manipulate **linked lists**, and implement **range generation algorithms** required to pass the **Level 3 Common Core Exam**.

