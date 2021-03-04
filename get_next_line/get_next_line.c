/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:42:53 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/04 12:00:20 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 5

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

	if(!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
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

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	if (dest == NULL && source == NULL)
		return (NULL);
	src = (unsigned char *)source;
	dst = (unsigned char *)dest;
	while (i < num)
	{
		dst[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}

int is_newline(char *s)
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

/*int until_newline(**backup, **line)
{
	*line = ft_strdup(*backup);
}*/

int get_next_line(int fd, char **line)
{
	int nread;
	char buf[BUFSIZE];
	static char *backup[4999];

	if (fd < 0)
		return (-1);
	while ((nread = read(fd, buf, BUFSIZE)) > 0)
	{
		buf[nread] = '\0';
		backup[fd] = ft_strjoin(backup[fd],buf);
		if (is_newline(backup[fd]) >= 0)
		{
			*line = ft_strdup(backup[fd]);
			return (1);
			//return (utill_newline(&backup[fd],line));
		}
	}
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
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
