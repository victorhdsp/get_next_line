/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:32:51 by vide-sou          #+#    #+#             */
/*   Updated: 2024/10/30 10:53:26 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s && s[index])
		index++;
	return (index);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			index;
	unsigned char	*s;

	index = 0;
	s = (unsigned char *)str;
	while (index < n)
	{
		s[index] = (unsigned char)c;
		index++;
	}
	return ((void *)s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	char	*fp;
	size_t	index;

	cdest = (char *)dest;
	csrc = (char *)src;
	fp = cdest;
	index = 0;
	if (!csrc && !cdest)
		return (NULL);
	while (index < n)
	{
		cdest[index] = csrc[index];
		index++;
	}
	return (fp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*result;
	char	*first_point;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 <= 0)
		return (NULL);
	result = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	ft_memset(result, 0, len_s1 + len_s2 + 1);
	first_point = result;
	if (result)
	{
		if (s1 && *s1)
			ft_memcpy(result, s1, len_s1);
		result += len_s1;
		if (s2 && *s2)
			ft_memcpy(result, s2, len_s2);
	}
	return (first_point);
}
