/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:33:51 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/28 21:49:17 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*result;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	if (!(result = (char*)malloc(sizeof(char) * (end - begin + 1))))
		return (NULL);
	i = 0;
	while (begin < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
