/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:12:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/17 11:01:36 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_stash(char *stash)
// {
	
// }

/* ************************************************************************** */
/*                             -=-  Get Line  -=-                             */
/*                                                                            */
/*   Copies the content of *stash into an allocated *line until it meets a    */
/*   '\n' or '\0' character.                                                  */
/*                                                                            */
/* ************************************************************************** */

char	*get_line(char *stash)
{
	unsigned int	i;
	char			*line;

	i = 0;
	while (!(stash[i] == '\n' || stash[i] == '\0'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* ************************************************************************** */
/*                            -=-  Read  Line  -=-                            */
/*                                                                            */
/*   Goes through the file with read() and gives a number of bytes to an      */
/*   allocated *buffer.                                                       */
/*   Then gives the content of *buffer to *stash (a static backup).           */
/*                                                                            */
/* ************************************************************************** */

char	*read_line(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (stash == NULL)
		stash = strdup("");
	stash = read_line(fd, stash);
	line = get_line(stash);
	// stash = get_stash(stash);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("./testers/test1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
