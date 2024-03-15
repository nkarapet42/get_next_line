/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:54:09 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/18 22:15:14 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char)c)
			return ((char *) &str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &str[i]);
	return ((void *) 0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	size_t	str_len;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	str_len = end - start;
	if (end > start)
	{
		if (str_len > end)
			str = (char *) malloc(sizeof(char) * (end + 1));
		else
			str = (char *) malloc(sizeof(char) * (str_len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s[start], end + 1);
	}
	else
		str = ft_strdup("");
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s1_len + s2_len + 1);
	return (str);
}
