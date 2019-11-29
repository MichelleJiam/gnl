/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:06:55 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/29 14:21:26 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	int i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

int		havenewline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		checkbuffers(char *temp)
{
	if (temp)
		if ((havenewline(temp)) >= 0)
			return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			readbuf[BUFFER_SIZE + 1];
	static char		*temp[MAX_FD];

	if (fd < 0 || line == NULL)
		return (-1);
	if ((checkbuffers(temp[fd])))
		return (makeline(line, &temp[fd], '\n'));
	else
		ret = read(fd, readbuf, BUFFER_SIZE);
	if (ret <= 0 && !temp[fd])
	{
		if (ret == 0)
			*line = ft_strndup("", 1);
		return (ret == 0 ? 0 : -1);
	}
	readbuf[ret] = '\0';
	if (maketemp(&temp[fd], readbuf) < 0)
		return (-1);
	if (ret == 0)
		return (makeline(line, &temp[fd], '\0'));
	else if ((havenewline(temp[fd])) >= 0)
		return (makeline(line, &temp[fd], '\n'));
	else
		return (get_next_line(fd, line));
}
