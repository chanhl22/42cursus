/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:11:50 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/21 17:21:18 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *prt;

	ptr = (void*)malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
