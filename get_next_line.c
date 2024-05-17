/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:12:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/17 15:27:03 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                             -=-  Get Stash  -=-                            */
/*                                                                            */
/*   Sets the stash back to its starting point.                               */
/*                                                                            */
/* ************************************************************************** */

char	*get_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (!(stash[i] == '\n' || stash[i] == '\0'))
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i++;
	temp_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - 1 + 1));
	if (temp_stash == NULL)
		return (NULL);
	while (stash[i])
		temp_stash[j++] = stash[i++];
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

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
		{
			free(stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (stash == NULL)
			return (NULL);
	}
	if (read_bytes == 0 && stash[read_bytes] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

/* ************************************************************************** */
/*                           -=-  Get Next Line  -=-                          */
/*                                                                            */
/*   Main function that runs everthing, giving the values to our variables.   */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	stash = get_stash(stash);
	return (line);
}

/*
int	main(void)
{
	char	*color = "\n\033[1;4;91m%s\033[0m\n\n";

	// First Test
	int		fd1 = open("./testers/test1.txt", O_RDONLY);
	char	*line1 = get_next_line(fd1);

	printf(color, "test1.txt file:");
	while (line1)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
	close(fd1);

	// Second Test
	int		fd2 = open("./testers/test2.txt", O_RDONLY);
	char	*line2 = get_next_line(fd2);

	printf(color, "test2.txt file:");
	while (line2)
	{
		printf("%s", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	close(fd2);

	// Third Test
	int		fd3 = open("./testers/test3.txt", O_RDONLY);
	char	*line3 = get_next_line(fd3);

	printf(color, "test3.txt file:");
	while (line3)
	{
		printf("%s", line3);
		free(line3);
		line3 = get_next_line(fd3);
	}
	close(fd3);
	
	return (0);
}
*/