/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:53:04 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/28 21:38:36 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_of_int(int num)
{
	int len;

	len = (num < 0) ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *str;
	int len;
	int sign;

	len = length_of_int(n);
	if (!(str = (char*)malloc(sizeof(char)*(len + 1))))
		return (NULL);
	str[len] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (len >= 0)
	{
		str[len] = n % 10 + '\0';
		n = n / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (c);
}
