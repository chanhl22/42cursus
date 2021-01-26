/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:06:43 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/26 21:47:19 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	if (dest <= src)
	{
		i = 0;
		while (i < len)
		{
			dest_ptr[len] = src_ptr[len];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			dest_ptr[i] = src_ptr[i];
			i--;
		}
	}
	return (dest);
}
