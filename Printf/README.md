![alt text](printf.jpg)
*This project has been created as part of the 42 curriculum by Orgito Leka.*

# ft_printf

A tiny, dependency‑free reimplementation of `printf(3)` that formats and prints to standard output. The goal is to practice variadic functions and clean, extensible C design while following the 42 Norm.

## Description
`ft_printf` reproduces a subset of the C standard library `printf` conversions:

- `%c` — character
- `%s` — string
- `%p` — pointer in hex with `0x` prefix
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` — lowercase hexadecimal
- `%X` — uppercase hexadecimal
- `%%` — a literal percent character

The library exposes a single public entry point:

```c
int ft_printf(const char *format, ...);
```

## Build

Requirements: `cc`, `ar`, and a POSIX environment.

```bash
make            # builds libftprintf.a
make clean      # remove build artifacts
make fclean     # remove build artifacts and libftprintf.a
make re         # rebuild from scratch
```

The archive `libftprintf.a` is created at the repository root, as required.

## Usage

Link the archive and include the header:

```c
#include "ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s %d 0x%x %p %\n", "world", 42, 3735928559u, (void*)0x42);
    (void)count; // characters written
    return 0;
}
```

Compile the example (assuming `libftprintf.a` already built):

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -I. -o demo
./demo
```

## Design notes

- **Dispatcher helper**: A small, `static` helper maps a conversion specifier to the corresponding print routine. This keeps `ft_printf` short, readable, and under the Norm’s line limits.
- **Return value**: All print routines return the number of bytes written, aggregated by `ft_printf` to match `printf` semantics.
- **No buffering**: As required, there is no internal buffer layer; output goes directly through `write(2)`.
- **Pointer formatting**: Non‑NULL pointers are printed as `0x` followed by lowercase hexadecimal; `NULL` is printed as `(nil)`.

## Limitations

- Field width, precision, and flags (`-0#+ ` etc.) are intentionally **not** implemented.
- Locale and wide‑character handling are out of scope.

## Testing

You can add your own tests or use community testers. Example quick test:

```bash
cc -Wall -Wextra -Werror tests/smoke.c libftprintf.a -I. -o smoke && ./smoke
```

## Project Requirements Summary

- Language: C
- Build: `make` producing `libftprintf.a` at project root
- Conversions: `cspdiuxX%`
- External functions allowed: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- Norm compliance throughout the repository

## Repo layout

This repository keeps sources in the project root (no `src/` folder). The static library `libftprintf.a` is created at the repository root.

### .gitignore
Add the following to avoid committing build artifacts:

```
# build artifacts
*.o
*.a
obj/
a.out
```

## Resources & AI usage

- C standard library `printf(3)` man page
- Variadic functions: `stdarg.h`
- 42 subject PDF for `ft_printf` (rules and scope)

**AI usage disclosure**: AI assistance was used to help refactor the dispatcher function to comply with the 42 Norm’s line limits, identify potential edge cases (like a trailing `%`), and draft this README. All code was reviewed, understood, and tested by the author.

## Author

Orgito Leka — login: **oleka**
