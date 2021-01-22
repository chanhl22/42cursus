/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:40:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/22 21:25:06 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *prt;
	
	if(s == NULL)
		return (NULL);
	prt = (char*)malloc(sizeof(*s)*(len + 1));
	if(str == NULL)
		return (NULL);
	i = 0;
	while(i < len)
	{
		prt[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (ptr);
}
