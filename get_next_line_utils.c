/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:59:19 by mesasaki          #+#    #+#             */
/*   Updated: 2025/01/18 17:41:35 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char *s1, char *s2S);
size_t	ft_strlen(const char *str);

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	s = src;
	d = dst;
	if (dst == src)
		return (dst);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	c;

	i = -1;
	c = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	while (s2[c] != '\0')
		result[i++] = s2[c++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}

char	*ft_strdup(const char *string)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(string);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (string[i])
	{
		dst[i] = string[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	char	cchar;

	cchar = (char)c;
	while (*s != '\0')
	{
		if (*s == cchar)
			return ((char *)s);
		s++;
	}
	if (cchar == '\0')
		return ((char *)s);
	else
		return (NULL);
}
