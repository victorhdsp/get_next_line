/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:32:47 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/27 12:29:32 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	read_and_join(int fd, char **buffer)
{
	size_t	readed;
	char	*tmp;
	char	*result;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ft_memset(tmp, 0, BUFFER_SIZE + 1);
	readed = read(fd, tmp, BUFFER_SIZE);
	if (!tmp[0])
	{
		if (*buffer && !*buffer[0])
		{
			free(*buffer);
			*buffer = NULL;
		}
		if (!*buffer)
		{
			free (tmp);
			return (0);
		}
	}
	result = ft_strjoin(*buffer, tmp);
	if (*buffer)
		free(*buffer);
	free(tmp);
	*buffer = result;
	return (readed);
}

static char	*split_text(char	**buffer, size_t index)
{
	char	*line;
	char	*remainder;
	size_t	remainder_len;

	remainder_len = ft_strlen(*buffer) - index;
	index++;
	line = malloc((index + 1) * sizeof(char));
	ft_memset(line, 0, index + 1);
	ft_memcpy(line, *buffer, index);
	remainder = malloc((remainder_len + 1) * sizeof(char));
	ft_memset(remainder, 0, remainder_len + 1);
	ft_memcpy(remainder, *buffer + index, remainder_len);
	if (*buffer)
		free(*buffer);
	*buffer = remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		index;
	size_t		len;
	size_t		readed;
	static char	*buffer = NULL;

	index = 0;
	len = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (buffer && buffer[0])
		len = ft_strlen(buffer);
	readed = len;
	while (index <= len)
	{
		if (index == len)
		{
			readed = read_and_join(fd, &buffer);
			if (!buffer)
				break;
			len = ft_strlen(buffer);
		}

		if (buffer[index] == '\n' || readed == 0)
		{
			return (split_text(&buffer, index));
		}
		index++;
	}
	return (NULL);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*result;

	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	//result = get_next_line(fd);
	//printf("%s\n", result);
	//result = get_next_line(fd);
	//printf("%s\n", result);
	//free(result);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}*/