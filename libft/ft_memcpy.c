/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:27:09 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 18:16:58 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char *src;
	unsigned char *dst;
	size_t i;

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
