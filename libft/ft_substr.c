/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:40:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/04 15:40:24 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (j < len && i >= start)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
