/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee </var/mail/chanhlee>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:17:18 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/27 15:14:09 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	char *res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (s1[end -1] && ft_strchr(set, s1[end-1]))
	{
		if(end -1 < 1)
			break;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	if(!(res = (char*)malloc(sizeof(char)*(end - start +1))))
		return(NULL);
	ft_strlcpy(res,s1+start,end-start+1);
	return (res);
}
