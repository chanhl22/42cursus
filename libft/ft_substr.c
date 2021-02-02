/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:40:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/02 11:04:22 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	if (start < (unsigned int)len)
	{
		while (i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
