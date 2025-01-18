/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:20 by mesasaki          #+#    #+#             */
/*   Updated: 2025/01/18 17:31:26 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_joint(int fd, char *handOver);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_line_from_handover(char **handOver);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t len);

#endif