/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:52:40 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/26 16:01:31 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*get_line(char **buffer, char **line)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (*(*buffer + i) != '\n' && *(*buffer + i) != '\0')
		i++;
	if (*(*buffer + i) == '\n')
	{
		i++;
		*line = ft_substr(*buffer, 0, i);
		res = ft_strdup(*buffer + i);
	}
	else
		*line = ft_strdup(*buffer);
	free_ptr(buffer);
	return (res);
}

static int	read_line(int fd, char **buff, char **buffer, char **line)
{
	int		byte;
	char	*temp;

	byte = 1;
	while (!ft_strchr(*buffer, '\n') && byte)
	{
		byte = read(fd, *buff, BUFFER_SIZE);
		(*buff)[byte] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, *buff);
		free(temp);
	}
	free_ptr(buff);
	*buffer = get_line(buffer, line);
	if (!(**line))
		free_ptr(line);
	return (byte);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*buff;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_strdup("");
	if (!read_line(fd, &buff, &buffer, &line) && !line)
		return (NULL);
	return (line);
}
