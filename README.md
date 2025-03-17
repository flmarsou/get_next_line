# 🦊 What is get_next_line?

The objective of this project is to create a function that reads a single line from a **file descriptor (fd)**. \
The function will then return the next line each time it is called, returning NULL once it has nothing left to read.

It helps you understand how to use **open**, **read**, **close**, and **file descriptors**. Making it an essential function for later projects.

# ⚒️ Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>					// open
#include <stdio.h>					// read, close

int	main(void)
{
	int	fd = open("example.txt", O_RDONLY);	// Opens file descriptor
	char	*line = get_next_line(fd);		// Stores the first line

	while (line)
	{
		printf("%s", line);			// Prints current line
		free(line);				// Frees current line
		line = get_next_line(fd);		// Gets Next Line
	}

	close(fd);					// Closes file descriptor
	return (0);
}
```
