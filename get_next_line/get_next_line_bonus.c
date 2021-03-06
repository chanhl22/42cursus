/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:21:33 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/06 15:22:08 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		is_newline(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		until_newline(char **backup, char **line, int i)
{
	char *temp;

	(*backup)[i] = '\0';
	*line = ft_strdup(*backup);
	temp = ft_strdup(*backup + i + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		finish_line(char **backup, char **line)
{
	int last_len;

	if (*backup && (last_len = is_newline(*backup)) >= 0)
	{
		return (until_newline(backup, line, last_len));
	}
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			nread;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[4999];
	int			i;

	if (fd < 0 || (BUFFER_SIZE <= 0) || !line)
		return (-1);
	while ((nread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nread] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((i = is_newline(backup[fd])) >= 0)
		{
			return (until_newline(&backup[fd], line, i));
		}
	}
	if (nread < 0)
		return (-1);
	return (finish_line(&backup[fd], line));
}
