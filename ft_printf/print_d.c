/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:42:02 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 19:24:46 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int		putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int		print_nbr(int n, t_opt *opt)
{
	char	*buf;
	int		ret;
	char	*sign;

	sign = "";
	if (opt->prec == 0 && n == 0)
		buf = strdup("");
	else if (n < 0)
	{
		sign = "-";
		buf = ft_itoa((long long)n * -1);
	}
	else
		buf = ft_itoa(n);
	buf = update_prec(buf, opt);
	buf = update_width(buf, opt, sign);
	ret = putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
