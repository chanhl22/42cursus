/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:14:50 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/30 15:27:19 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(int c, t_opt *opt)
{
	int ret;
	char *padding;

	ret = 0;
	if (opt->width > 0)
		padding = update_padding(opt->zero, opt->width - sizeof(char));
	else
		padding = ft_strdup("");
	if (opt->minus == 0)
	{
		ret = putstr_fd(padding, 1);
		ret += putchar_fd((char)c, 1);
	}
	else
	{
		ret = putchar_fd((char)c, 1);
		ret += putstr_fd(padding, 1);
	}
	free(padding);
	return (ret);
}
