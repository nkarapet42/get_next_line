/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:59:34 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:15 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*get_line(char **buffers, char **line)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (*(*buffers + i) != '\n' && *(*buffers + i) != '\0')
		i++;
	if (*(*buffers + i) == '\n')
	{
		i++;
		*line = ft_substr(*buffers, 0, i);
		res = ft_strdup(*buffers + i);
	}
	else
		*line = ft_strdup(*buffers);
	free_ptr(buffers);
	return (res);
}

static int	read_line(int fd, char **buff, char **buffers, char **line)
{
	int		byte;
	char	*temp;

	byte = 1;
	while (!ft_strchr(*buffers, '\n') && byte)
	{
		byte = read(fd, *buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free_ptr(buffers);
			free_ptr(buff);
			return (-1);
		}
		(*buff)[byte] = '\0';
		temp = *buffers;
		*buffers = ft_strjoin(temp, *buff);
		free(temp);
	}
	free_ptr(buff);
	*buffers = get_line(buffers, line);
	if (!(**line))
		free_ptr(line);
	return (byte);
}

char	*get_next_line(int fd)
{
	static char	*buffers[OPEN_MAX];
	char		*buff;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = ft_strdup("");
	if (read_line(fd, &buff, &buffers[fd], &line) == -1 || !line)
		return (NULL);
	return (line);
}
