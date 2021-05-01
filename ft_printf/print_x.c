/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:36:47 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 08:28:11 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_16(unsigned int n, t_opt *opt)
{
	int		ret;
	char	*buf;

	buf = "";
	if (opt->prec == 0 && n == 0)
		buf = "";
	else if (opt->type == 'x')
		buf = ft_putnbr_base(n, "0123456789abcdef");
	else if (opt->type == 'X')
		buf = ft_putnbr_base(n, "0123456789ABCDEF");
	buf = update_prec(buf, opt);
	buf = update_width(buf, opt, "");
	ret = putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
