/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:52:43 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/02 17:22:57 by chanhlee         ###   ########.fr       */
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
	int j;

	num = number_of_word(s,c);
	i = 0;
	if (!(word = (char**)malloc(sizeof(char) * (num + 1))))
		return (NULL);
	j = 0;
	while (i < num)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		word[i] = ft_substr(s, j, length_of_word(s,c));
		while (s[j] != '\0' && s[j] != c)
			j++;
		//word[i] = (char*)malloc(sizeof(char) * (len + 1));
		//ft_strlcpy(word[i], s, len + 1);
		i++;
	}
	word[i] = NULL;
	return (word);
}
