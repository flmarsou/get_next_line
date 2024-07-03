# 🦊 What is get_next_line?

Reading a line on a fd is way too tedious...

The aim of this project is to code a function that returns a line read from a file descriptor. Returns the following line when called again.

# ⚒️ Compilation

1. Remove the comment from the main function in `get_next_line.c`.
2. Run `cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`, you can set the BUFFER_SIZE's value to your heart's content.
3. Run with `./a.out`.

# ✨ Summary

|     |     |
| --- | --- |
| Function name | get_next_line |
| Prototype | char *get_next_line(int fd); |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| External functs. | read, malloc, free |
| Description | Write a function which returns a line read from a file descriptor |

# 📑 List of Files

- [x] [`get_next_line.c`](https://github.com/flmarsou/2.2-get_next_line/blob/main/get_next_line.c) - Main file.
- [x] [`get_next_line_utils.c`](https://github.com/flmarsou/2.2-get_next_line/blob/main/get_next_line.c) - External functions.
- [x] [`get_next_line.h`](https://github.com/flmarsou/2.2-get_next_line/blob/main/get_next_line.c) - Header file.
