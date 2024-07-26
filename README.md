# 🦊 What is get_next_line?

The objective of this project is to create a function that reads a single line from a **file descriptor (fd)**. \
The function will then return the next line each time it is called, returning NULL once it has nothing left to read.

It helps you understand how to use **open**, **read**, **close**, and **file descriptors**. Making it an essential function for later projects.

# ⚒️ Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>		// open
#include <stdio.h>		// read, close

int	main(void)
{
	int	fd = open("example.txt", O_RDONLY);	// Path to the file descriptor.
	char	*line = get_next_line(fd);		// Stores the first line.

	while (line)
	{
		printf("%s", line);		// Prints current line.
		free(line);			// Frees current line.
		line = get_next_line(fd);	// Gets Next Line.
	}

	close(fd);
	return (0);
}
```

# ✨ Summary

|     |     |
| --- | --- |
| Function name | get_next_line |
| Prototype | char *get_next_line(int fd); |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| External functs. | read, malloc, free |
| Description | Write a function which returns a line read from a file descriptor |

# 📑 List of Files

- [x] [`get_next_line.c`](https://github.com/flmarsou/get_next_line/blob/main/get_next_line.c) - Main file.
- [x] [`get_next_line_utils.c`](https://github.com/flmarsou/get_next_line/blob/main/get_next_line_utils.c) - External functions.
- [x] [`get_next_line.h`](https://github.com/flmarsou/get_next_line/blob/main/get_next_line.h) - Header file.
