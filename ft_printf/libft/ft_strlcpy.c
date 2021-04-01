/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:28:11 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 23:52:57 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t destsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dest == 0 || source == 0)
		return (0);
	if (destsize > 0)
	{
		while (source[j] && j < destsize - 1)
		{
			dest[j] = source[j];
			j++;
		}
		dest[j] = '\0';
	}
	while (source[i])
		i++;
	return (i);
}
