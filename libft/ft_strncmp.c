/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:49:50 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/20 12:01:36 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1[i] != '\0' && s2[i] != '\0')
	{
		while (i < n && s1[i] == s2[i])
			i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
