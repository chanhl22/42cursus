/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:05:35 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 19:11:46 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_first(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}

char	*ft_strjoin_second(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s2);
	return (str);
}

char	*ft_strjoin_third(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	free(s2);
	return (str);
}
