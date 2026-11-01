*This project has been created as part of the 42 curriculum by `tait-si`.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C function `printf()`. The goal is to learn how **variadic functions** work in C (`va_list`, `va_start`, `va_arg`, `va_end`) and to write clean, extensible code that parses a format string and prints formatted output.

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like the original `printf()`. As required by the subject, the buffer management of the original is not implemented.

### Supported conversions

| Conversion | Description                              |
|------------|------------------------------------------|
| `%c`       | Single character                         |
| `%s`       | String                                   |
| `%p`       | `void *` pointer in hexadecimal          |
| `%d` `%i`  | Signed decimal (base 10) number          |
| `%u`       | Unsigned decimal (base 10) number        |
| `%x` `%X`  | Hexadecimal, lowercase / uppercase       |
| `%%`       | Percent sign                             |

## Instructions

The project is compiled with `cc -Wall -Wextra -Werror`.

```bash
make         # builds libftprintf.a at the root of the repository
make clean   # removes object files
make fclean  # removes object files and libftprintf.a
make re      # rebuilds everything
```

Usage:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d!\n", "42", 42);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o test
```

## Algorithm and data structure

`ft_printf` reads the format string **once, from left to right**:

1. Initialize the `va_list` with `va_start`.
2. For each character: if it is not `%`, write it with `write`. If it is `%`, read the next character and call the matching handler (`c`, `s`, `p`, `d`/`i`, `u`, `x`, `X`, `%`).
3. Each handler gets its argument with `va_arg`, prints it, and returns the number of characters written.
4. The counts are added up, `va_end` is called, and the total is returned.

**Why this approach:**

- A single pass is simple and fast, and needs no intermediate storage.
- A dispatcher separates parsing from printing, so adding a conversion only requires a new handler and one new case.
- All number conversions share one base-conversion function, differing only in base, digit case and signedness.
- Special cases follow the original `printf()`: `(null)` for a `NULL` string and `(nil)` for a `NULL` pointer.

**Data structure:** none is needed. The state is only a `va_list`, an `int` counter, and the position in the format string. No dynamic allocation is used.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`

**Use of AI:** AI was used only as a learning aid, to understand how variadic functions work and to help write this README. All the code was written, understood and tested by me.