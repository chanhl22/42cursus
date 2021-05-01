/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:26:47 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 19:12:47 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_abs2(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int			ft_len2(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa2(unsigned int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len2(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs2(n % 10);
		n = ft_abs2(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}

int			print_unsigned(unsigned int n, t_opt *opt)
{
	int		ret;
	char	*buf;

	if (opt->prec == 0 && n == 0)
		buf = strdup("");
	else if (opt->type == 'u')
		buf = ft_itoa2(n);
	buf = update_prec(buf, opt);
	buf = update_width(buf, opt, "");
	ret = putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
