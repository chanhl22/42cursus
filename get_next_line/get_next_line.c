/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:42:53 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/02 01:15:34 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 512

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int get_next_line(int fd, char **line)
{
	int nread;
	char buf[BUFSIZE]="a";

	if (fd < 0)
		return (-1);
	/*while ((nread = read(fd, buf, BUFSIZE)) > 0)
	{
		buf[nread] = '\0';
		*line = ft_strdup(buf);
	}*/
	*line = buf;
	return (0);
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("./test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		//free(line);
	}
	printf("%s\n", line);
	//free(line);
	return (0);
}
