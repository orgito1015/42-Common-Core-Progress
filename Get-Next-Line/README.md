*This project has been created as part of the 42 curriculum by Orgito Leka*

# Get Next Line

## Summary
The **Get Next Line** project is part of the 42 Common Core curriculum. Its purpose is to implement a function that reads a single line from a file descriptor (FD). This project aims to improve understanding of file I/O, static variables, memory management, and buffer handling in C.

---

## Objectives
- Learn how to manage multiple function calls while maintaining state between them.
- Understand and implement buffer-based reading with system calls (`read`).
- Manage dynamic memory allocation, string manipulation, and cleanup efficiently.
- Handle edge cases such as end-of-file (EOF) and reading errors.

---

## Mandatory Function
```c
char *get_next_line(int fd);
```

### Description
- Reads from a file descriptor **one line at a time**, including the newline character (`'\n'`) if present.
- Returns the **next line** each time it is called.
- Returns `NULL` when there is nothing more to read or in case of an error.

### Return Value
- The **next line** read from the file descriptor.
- `NULL` if there are no more lines or an error occurs.

### Files Included
```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

---

## Implementation Details

### Core Logic
Your implementation reads data from a file descriptor in chunks of `BUFFER_SIZE`, appending it to a static variable until a newline or EOF is found.

Key steps:
1. **Read into a buffer** using the `read()` system call.
2. **Join** the buffer to the stored line using a custom string join function.
3. **Extract** the line up to (and including) the newline.
4. **Store** the remainder for the next function call.

---

##  Algorithm Explanation
The **get_next_line** algorithm works through a combination of buffer reading, persistent storage, and line extraction. Below is a step-by-step explanation:

1. **Initialization** 
   A static variable `lines` stores leftover data from the previous call. This ensures that the function remembers what was read between calls.

2. **Buffer Allocation** 
   Allocate a temporary buffer of size `BUFFER_SIZE + 1` to store data read from the file descriptor.

3. **Reading Loop** 
   - While there is no newline character (`'\n'`) in the static variable, the function continues reading from the file descriptor. 
   - Each read appends data from the buffer to the static variable.

4. **Newline Detection** 
   - When a newline is found, extract the part of the string up to and including the newline. 
   - The remaining data (after the newline) is kept in the static variable for the next call.

5. **End of File or Error** 
   - If `read()` returns 0 (EOF), the remaining string is returned (if any). 
   - If `read()` returns -1 (error), all allocated memory is freed and `NULL` is returned.

6. **Return Value** 
   - Return the extracted line. 
   - On the next function call, the process continues with the leftover data.

### Visualization
```
[File Descriptor] --> [Buffer read (BUFFER_SIZE)] --> [Static storage] --> [Extract line] --> [Return]
```
Each call advances through the file, one line at a time, without losing context between calls.

---

## Example Usage
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

##  Compilation
To compile your `get_next_line` project:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can adjust the buffer size when compiling by defining `BUFFER_SIZE`.
For example:
```bash
gcc -D BUFFER_SIZE=10 ...
```

---

## Memory Management
- Every call to `get_next_line` allocates memory for the returned line.
- The caller is responsible for freeing it after use.
- The static variable persists between calls but is freed automatically when the program ends.

---

##  Error Handling
- If `read()` returns `-1`, the function returns `NULL`.
- If `BUFFER_SIZE <= 0` or `fd < 0`, the function returns `NULL` immediately.

---

##  Header File: `get_next_line.h`
```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t   ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);

#endif
```

---

##  Project Rules
- **No memory leaks** are tolerated.
- The function must work with **any valid file descriptor**.
- You are allowed to use only the following functions:
  - `read`, `malloc`, `free`, and basic libc functions.
- The code must compile with the **42 Norm** (`norminette`).

---

##  Tips
- Test with different file sizes and `BUFFER_SIZE` values.
- Handle files with and without a final newline.
- Test reading from standard input (`fd = 0`).

---

##  Example Output
**Input file (example.txt):**
```
Hello World
42 Network
Get Next Line
```

**Program output:**
```
Hello World
42 Network
Get Next Line
```

---

##  References
- 42 Project: *Get Next Line*
- Man pages: `man read`, `man malloc`, `man free`
- [42 Documentation Portal](https://projects.intra.42.fr/projects/get_next_line)


