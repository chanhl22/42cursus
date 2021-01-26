/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:08:38 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/26 21:55:02 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	int		i;

	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		if (big[i] == little[0])
			if (!ft_strncmp(big + i, little, little_len))
				return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
