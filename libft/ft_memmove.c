/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:06:43 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 23:23:25 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char*)dest)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	}
	return (dest);
}
