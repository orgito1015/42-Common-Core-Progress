# Level 1 – Exam Programming Fundamentals - 42 Common Core Exam

This repository contains solutions for **Level 1** exercises of the **42 Common Core Exam**.  
Level 1 focuses on validating **C fundamentals**, **string manipulation**, and **basic algorithmic logic**, strictly following **42 Norm**.

## Exercises

- `first_word` – Print the first word of a string
- 
```mermaid
flowchart TD
    A([Start program])
    B[i = 0]
    C{ac == 2?}
    D[Read av[1]]
    E{Is av[1][i] whitespace?}
    F[i++ (skip spaces)]
    G{Is av[1][i] > whitespace?}
    H[write character]
    I[i++]
    N[Print newline]
    Z([Exit program])

    A --> B
    B --> C

    C -- No --> N
    N --> Z

    C -- Yes --> D
    D --> E

    E -- Yes --> F
    F --> E

    E -- No --> G

    G -- Yes --> H
    H --> I
    I --> G

    G -- No --> N

```
- `fizz_buzz` – Standard FizzBuzz logic  
- `ft_putstr` – Output a string to stdout  
- `ft_strcpy` – Copy a string  
- `ft_strlen` – Compute string length  
- `ft_swap` – Swap two integers  
- `repeat_alpha` – Repeat letters based on alphabet position  
- `rev_print` – Print a string in reverse  
- `rot_13` – Apply ROT13 cipher  
- `rotone` – Rotate characters by one  
- `search_and_replace` – Replace characters in a string  
- `ulstr` – Toggle uppercase and lowercase characters  

## Constraints

- Language: **C**
- Norminette compliant
- No forbidden functions
- Exam-oriented implementation

## Goal

This level prepares students for the **first Common Core exam** by covering essential logic patterns and string operations required to pass.

