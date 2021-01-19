/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:33:55 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/18 13:58:04 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int val, size_t size)
{
	size_t i;

	if (!dst)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		*(char*)(dst + i) = (char)val;
		i++;
	}
	return (dst);
}
