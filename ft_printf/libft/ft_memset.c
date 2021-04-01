/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:33:55 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 11:14:49 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int val, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char*)dst;
	i = 0;
	while (i < size)
	{
		*(ptr + i) = (unsigned char)val;
		i++;
	}
	return (dst);
}
