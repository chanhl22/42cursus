/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:43:32 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 19:02:22 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_opt(t_opt *opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->type = 0;
}

char	*update_padding(int zero, int size)
{
	char *padding;

	padding = ft_calloc(sizeof(char), size + 1);
	if (zero == 0)
		ft_memset(padding, ' ', size);
	else
		ft_memset(padding, '0', size);
	return (padding);
}

char	*update_rest(char *buf, char *padding, int minus)
{
	char *rest;

	if (minus == 0)
	{
		rest = ft_strjoin(padding, buf);
		return (rest);
	}
	else
	{
		rest = ft_strjoin(buf, padding);
		return (rest);
	}
}

char	*update_prec(char *buf, t_opt *opt)
{
	char *padding;
	char *temp;

	if ((opt->prec > -1) && (opt->prec > (int)ft_strlen(buf)))
	{
		padding = update_padding(1, opt->prec - ft_strlen(buf));
		temp = update_rest(buf, padding, 0);
		free(buf);
		buf = temp;
		free(padding);
	}
	return (buf);
}

char	*update_width(char *buf, t_opt *opt, char *sign)
{
	char	*padding;
	char	*temp;

	if ((opt->width > 0) &&
		(opt->width > (int)(ft_strlen(sign) + ft_strlen(buf)))
		&& (opt->width > opt->prec))
	{
		padding = update_padding(opt->zero,
					opt->width - ft_strlen(sign) - ft_strlen(buf));
		if (opt->zero > 0)
			padding = ft_strjoin_second(sign, padding);
		else
			buf = ft_strjoin_second(sign, buf);
		temp = update_rest(buf, padding, opt->minus);
		free(buf);
		buf = temp;
		free(padding);
	}
	else
		buf = ft_strjoin_second(sign, buf);
	return (buf);
}
