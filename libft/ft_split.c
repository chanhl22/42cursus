/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:52:43 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/03 15:17:27 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_of_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*make_word(char *res, char const *s, int j, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
	{
		res[i] = s[j - word_len];
		i++;
		word_len--;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split2(char **word, char const *s, char c, int num)
{
	int		i;
	int		j;
	int		word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		if (!(word[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (NULL);
		make_word(word[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	word[i] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		num;

	if (s == NULL)
		return (NULL);
	num = number_of_word(s, c);
	if (!(word = (char**)malloc(sizeof(char*) * (num + 1))))
		return (NULL);
	ft_split2(word, s, c, num);
	return (word);
}
