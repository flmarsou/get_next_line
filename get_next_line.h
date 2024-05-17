/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:12:10 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/17 09:57:44 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>	// write(), read()
# include <stdio.h>		// printf()
# include <stdlib.h>	// malloc(), free()
# include <fcntl.h>		// open()
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);

#endif
