/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:27:09 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/18 13:57:37 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	char *src;
	char *dst;

	src = (char *)source;
	dst = (char *)dest;
	while (num--)
	{
		*dst++ = *src++;
	}
	return (dest);
}
