/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:42:53 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/05 20:09:58 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	*backup = temp;
	return (1);
}

int		finish_line(char **backup, char **line)
{
	if (*backup)
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

	if (fd < 0 || (BUFFER_SIZE <= 0))
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
	return (finish_line(&backup[fd], line));
}

/*int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("./test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}*/
