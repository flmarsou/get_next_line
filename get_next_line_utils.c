/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:12:51 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/17 10:02:58 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, char target)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == target)
		{
			return (str + i);
		}
		i++;
	}
	if (target == str[i])
	{
		return (str + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (ret == NULL)
	{
		return (NULL);
	}
	while (stash[i])
	{
		ret[i] = stash[i];
		i++;
	}
	while (buffer[j])
	{
		ret[i + j] = buffer[j];
		j++;
	}
	ret[i + j] = '\0';
	free(stash);
	return (ret);
}

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
