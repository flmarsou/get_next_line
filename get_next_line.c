/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:12:19 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/21 08:37:58 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                             -=-  Free Var  -=-                             */
/*   This simple function centralizes and simplifies freeing buffer and/or    */
/*   stash in `read_line` and `get_stash`, avoiding repetitive free calls.    */
/*                                                                            */
/* ************************************************************************** */

static char	*free_var(char *buffer, char *stash)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

/* ************************************************************************** */
/*                            -=-  Get  Stash  -=-                            */
/*                                                                            */
/*   This function updates the stash by removing the line that has just been  */
/*   returned. It just moves the pointer past the newline and frees the old   */
/*   stash. If there is no newline, it frees the stash and returns NULL.      */
/*                                                                            */
/* ************************************************************************** */

static char	*get_stash(char *stash)
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
		return (free_var(NULL, stash));
	i++;
	temp_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash)));
	if (temp_stash == NULL)
		return (NULL);
	while (stash[i])
	{
		temp_stash[j] = stash[i];
		i++;
		j++;
	}
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

/* ************************************************************************** */
/*                             -=-  Get Line  -=-                             */
/*                                                                            */
/*   This function extracts the current line from the stash, up to and        */
/*   including the newline (if present). It allocates memory for the line     */
/*   copies it from the stash, and return the new line.                       */
/*                                                                            */
/* ************************************************************************** */

static char	*get_line(char *stash)
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
/*   This function reads from the file descriptor into the buffer until it    */
/*   meets a newline or the end of the file.                                  */
/*   It adds every read bytes from the buffer to the stash.                   */
/*                                                                            */
/* ************************************************************************** */

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_var(buffer, stash));
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (stash == NULL)
			return (free_var(buffer, NULL));
	}
	free(buffer);
	if (read_bytes == 0 && stash[read_bytes] == '\0')
		return (free_var(NULL, stash));
	return (stash);
}

/* ************************************************************************** */
/*                           -=-  Get Next Line  -=-                          */
/*                                                                            */
/*   This is the main function called by the user.                            */
/*   read_file	-> allocates and set the stash                                */
/*   get_line	-> extract the current line                                   */
/*   get_stash	-> update and free the stash for next call                    */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_strdup("");
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
	char	*color = "\033[1;4;91m%s\033[0m\n\n";

	// First Test
	int		fd1 = open("./testers/test1.txt", O_RDONLY);
	char	*line1 = get_next_line(fd1);

	printf(color, "test.txt file:");
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