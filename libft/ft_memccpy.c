/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:22:02 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/18 13:56:00 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!dest || !src)
		return (null);
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return ((void*)dest + i + 1);
		i++;
	}
	return (NULL);
}
