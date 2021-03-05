/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:43:06 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:36 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

int				get_next_line(int fd, char **line);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dest, const void *source, size_t num);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
