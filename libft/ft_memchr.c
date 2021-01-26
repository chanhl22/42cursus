/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:12:08 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/18 13:56:43 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = (unsigned char*)ptr;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)value)
			return ((void*)ptr_str + i);
	}
	return (NULL);
}
