/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:12:08 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 17:58:10 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;
	unsigned char	c;

	ptr_str = (unsigned char*)ptr;
	c = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == c)
			return ((void*)ptr_str + i);
		i++;
	}
	return (NULL);
}
