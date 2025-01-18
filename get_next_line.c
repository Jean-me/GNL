/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:20 by mesasaki          #+#    #+#             */
/*   Updated: 2025/01/18 17:23:13 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_joint(int fd, char *handover);
char	*get_line_from_handover(char **handover);
char	*get_next_line(int fd);

char	*read_joint(int fd, char *handover)
{
	char	*tmp;
	ssize_t	bytesread;
	char	*new_handover;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	bytesread = read(fd, tmp, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[bytesread] = '\0';
	if (!handover)
		handover = ft_strdup("");
	new_handover = ft_strjoin(handover, tmp);
	free(handover);
	free(tmp);
	return (new_handover);
}

char	*get_line_from_handover(char **handover)
{
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!*handover)
		return (NULL);
	while ((*handover)[i] && (*handover)[i] != '\n')
		i++;
	if ((*handover)[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_memcpy(line, *handover, i + 1);
		line[i + 1] = '\0';
		tmp = ft_strdup(*handover + i + 1);
		free(*handover);
		*handover = tmp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*handover;
	char		*prev;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	while (!handover || !ft_strchr(handover, '\n'))
	{
		prev = handover;
		handover = read_joint(fd, handover);
		if (!handover)
			return (prev);
	}
	line = get_line_from_handover(&handover);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *return_str;

// 	fd = open("test.txt", O_RDONLY);
// 	// fd = 1;
// 	if (fd < 0)
// 		return (1);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力
// 	// free(return_str);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力
// 	// free(return_str);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力
// 	// free(return_str);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力
// 	// free(return_str);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力
// 	// free(return_str);
// 	// return_str = get_next_line(fd);
// 	// printf("%s", return_str); // 1文字出力 //
// 	// free(return_str);
// 	// int i = 0;
// 	while (return_str)
// 	{
// 		return_str = get_next_line(fd);
// 		printf("%s", return_str); // 1文字出力
// 		free(return_str);
// 		// i++;
// 	}

// 	close(fd);
// 	return (0);
// }