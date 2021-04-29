/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:53:04 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/29 21:57:28 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		length_of_int(long long num)
{
	int len;

	len = (num <= 0) ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int		ft_abs(long long num)
{
	return ((num < 0) ? -num : num);
}

char	*ft_itoa(long long n)
{
	char	*str;
	int		len;
	int		sign;

	len = length_of_int(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	sign = (n < 0) ? -1 : 1;
	while (len >= 0)
	{
		str[len] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
