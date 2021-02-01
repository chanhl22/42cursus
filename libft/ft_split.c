/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:52:43 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/01 09:58:37 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_of_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	if (*s == '\0')
		return (0);
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int length_of_word(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char **ft_split(char const *s, char c)
{
	char **word;
	int i;
	int num;
	int len;

	num = number_of_word(s,c);
	i = 0;
	word = (char**)malloc(sizeof(char) * (num + 1));
	while (i < num)
	{
		while (*s == c)
			s++;
		len = length_of_word(s,c);
		word[i] = (char*)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(word[i], s, len + 1);
		i++;
	}
	word[i] = NULL;
	return (word);
}
