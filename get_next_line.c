/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:32:47 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/26 01:34:25 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *str)
{
	size_t	readed;
	char	buffer[1024];
	char	*result;
	size_t	index;

	index = 0;
	ft_memset(buffer, 0, 1024);
	readed = read(fd, buffer, BUFFER_SIZE);
	while (buffer[index] && buffer[index] != '\n' && index < readed)
		index++;
	result = ft_strjoin(str, buffer);
	free(str);
	if (buffer[index] == '\n' || !readed)
		return (result);
	return (read_file(fd, result));
}

char	*get_next_line(int fd)
{
	static char *result;

	result = malloc(1 * sizeof(char));
	result[0] = '\0';
	result = read_file(fd, result);
	printf("%s", result);
	return (result);
}