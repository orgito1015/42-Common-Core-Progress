# 📚 Libft – 42 Common Core Project

Libft is the first project of the 42 curriculum.  
Its goal is to implement a personal C library containing a set of essential functions for memory handling, string manipulation, character checks, and linked list operations.  
This library will serve as a foundation for future 42 projects.

---

## 🚀 Overview

This project recreates many standard functions from the `<ctype.h>`, `<strings.h>`, `<string.h>`, and `<stdlib.h>` libraries, as well as additional utility functions and linked list helpers.

Libft trains you to:
- Understand low-level memory management  
- Work with pointers and arrays  
- Implement robust and reusable utility functions  
- Build a clean, well-documented C library

---

## 📁 Project Structure

```
libft/
│
├── libft.h
├── ft_*.c
├── Makefile
└── README.md
```

---

## 🔧 Compilation

To compile the library:

```
make
```

This will generate:

```
libft.a
```

To clean object files:

```
make clean
```

To clean everything:

```
make fclean
```

To recompile:

```
make re
```

---

## 🧪 Usage Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Hello Libft!");
    printf("%s
", str);
    free(str);
    return 0;
}
```

Compile with:

```
gcc main.c libft.a
```

---

## 🏆 Author

**Orgito Leka**  
42 Student – Libft Project  
GitHub: https://github.com/orgito1015
