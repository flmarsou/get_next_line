/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:13:41 by flmarsou          #+#    #+#             */
/*   Updated: 2024/05/20 11:13:57 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>	// write(), read()
# include <stdio.h>		// printf()
# include <stdlib.h>	// malloc(), free()
# include <fcntl.h>		// open()

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);

#endif
