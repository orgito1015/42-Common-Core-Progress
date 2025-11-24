# Get Next Line – Evaluation Toolkit

This repository is a **GitHub-ready template** for evaluating 42 `get_next_line` projects.

It is meant for **evaluators**, not students.  
You plug in the **student’s project path** when compiling and use this toolkit to run tests.

---

## 🔧 What’s in this repo?

```text
.
├── README.md              # How to use this toolkit
├── mains/                 # C mains used to test GNL
│   ├── main_basic.c       # Read from a file
│   ├── main_fd.c          # Invalid FD test
│   ├── main_stdin.c       # Read from stdin
│   └── main_custom_sep.c  # For live-coding (custom separator, Q7)
└── tests/                 # Text files for testing
    ├── empty.txt
    ├── short.txt
    ├── long.txt
    ├── long2k.txt
    ├── no_newline.txt
    ├── multi_empty.txt
    ├── multi_long.txt
    ├── multi_short.txt
```

No scripts, no Python, no sudo.  
Just `cc`, the `mains/`, the `tests/`, and this README.

---

## 🧱 0. Assumptions

In the examples below:

- This toolkit repo is at: `~/Get-Next-Line-Evaluation-Process`
- The student repo is at: `~/student-gnl`

You can change these paths to whatever you use in evaluation.

---

## 1. Q1 – Preliminaries

In the **student’s repo**:

- Make sure the project exists
- Student is present
- If project is missing or obviously broken → **grade 0, stop**

No commands needed here.

---

## 2. Q2 – Check the student’s README.md

In the student’s `README.md`, manually check:

- First line format (as required by your subject)
- Has sections:
  - Description
  - Instructions (compilation / run)
  - Resources + AI usage
  - Library description
  - Algorithm explanation

This step is **manual only**.

---

## 3. Q3 – Norminette

In the student’s repo:

```bash
cd ~/student-gnl
norminette
```

If **any error** appears:

- According to the rules, the evaluation stops here  
- You may still talk about code, but do not grade further

---

## 4. Q4 – Compilation (basic + BUFFER_SIZE variants)

Now use this toolkit with the student’s code.

From this toolkit repo:

```bash
cd ~/Get-Next-Line-Evaluation-Process
```

### 4.1 Compile with `BUFFER_SIZE = 42`

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_basic.c    -o gnl_42
```

If this fails → **compilation issue**, evaluation stops.

### 4.2 Compile with other `BUFFER_SIZE` values

Repeat for small / large sizes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_basic.c    -o gnl_1

cc -Wall -Wextra -Werror -D BUFFER_SIZE=7    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_basic.c    -o gnl_7

cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_basic.c    -o gnl_1000
```

Now you have for example:

- `gnl_1`
- `gnl_7`
- `gnl_42`
- `gnl_1000`

---

## 5. Q5 – Error Management (invalid FD)

Compile the invalid-FD tester:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_fd.c    -o gnl_fd
```

Run it:

```bash
./gnl_fd
```

`main_fd.c` calls `get_next_line(42)`.

You check:

- It does **not crash**
- It returns `NULL` (you’ll usually see `(null)` printed)

If behavior is clearly wrong → their error management is bad.

---

## 6. Q6 – Functional Tests

### 6.1 Test with prepared files

Use `gnl_42` (or any compiled binary):

```bash
./gnl_42 tests/empty.txt
./gnl_42 tests/short.txt
./gnl_42 tests/long.txt
./gnl_42 tests/long2k.txt
./gnl_42 tests/no_newline.txt
./gnl_42 tests/multi_empty.txt
./gnl_42 tests/multi_short.txt
./gnl_42 tests/multi_long.txt
```

You verify:

- Output lines match the file  
- Lines that had `\n` still end with `\n`  
- Last line without newline is still returned correctly  
- No extra line printed after EOF  
- No infinite loops or crashes

You can repeat the same tests with `gnl_1`, `gnl_7`, `gnl_1000` to see behavior under different `BUFFER_SIZE`.

### 6.2 Test stdin

Compile stdin tester:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_stdin.c    -o gnl_stdin
```

Run:

```bash
./gnl_stdin
```

Type:

```text
hello
world
<Ctrl+D> (or Ctrl+Z + Enter on Windows)
```

Check:

- Each typed line is echoed back
- Program exits correctly at EOF

### 6.3 Long line check

`tests/long2k.txt` already contains a line >2000 characters:

```bash
./gnl_42 tests/long2k.txt
```

You can also manually extend this file if you want even longer lines.

---

## 7. Q7 – Live Coding (Custom Separator)

This step is manual / interactive.

1. Ask the student:

> “Please modify your `get_next_line` (or add a new function) so that it uses a **custom separator** (for example `'|'`) instead of `\n`.”

2. Give them up to **10 minutes**.

3. After they add something like:

```c
char *get_next_until(int fd, char sep);
```

You can adapt `mains/main_custom_sep.c` to test it, for example:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("tests/multi_short.txt", O_RDONLY);
    if (fd < 0)
        return (perror("open"), 1);
    char *line;
    while ((line = get_next_until(fd, '|')))
    {
        printf("%s
", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_custom_sep.c    -o gnl_custom

./gnl_custom
```

Goal: student proves they can understand and extend their code.

---

## 🔁 Quick Cheat Sheet

Minimal commands you will really use in most evaluations:

```bash
# 1) Norminette (student repo)
cd ~/student-gnl
norminette

# 2) Basic compile with BUFFER_SIZE 42
cd ~/Get-Next-Line-Evaluation-Process
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_basic.c -o gnl_42

# 3) Run a few tests
./gnl_42 tests/short.txt
./gnl_42 tests/no_newline.txt
./gnl_42 tests/multi_long.txt

# 4) Invalid FD test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_fd.c -o gnl_fd

./gnl_fd

# 5) stdin test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_stdin.c -o gnl_stdin

./gnl_stdin
```

This template is ready to be pushed as a GitHub repository and reused in every `get_next_line` evaluation.
