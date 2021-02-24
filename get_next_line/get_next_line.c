/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:42:53 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/24 17:12:17 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 512

/*
int main()
{
   char buffer[BUFSIZE];
   int fd;
   ssize_t nread;
   long total = 0;
   char *backup:q

   if ((fd = open("test.txt", O_RDONLY)) == -1)
	   exit(1);
   while ((nread = read(fd, buffer, BUFSIZE)) > 0)
	   total += nread;
   close(fd);
   printf ("Number of characters in testfile : %ld\n", total);
   exit(0);
}
*/

int get_next_line(int fd, char **line)
{
	int nread;
	char buffer[BUFSIZE];

	if (fd < 0)
		return (-1);
	while ((nread = read(fd, buf, BUFSIZE)) > 0)
	{
		if (
	}

}
