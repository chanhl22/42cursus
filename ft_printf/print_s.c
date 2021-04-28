/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:02:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/28 22:34:18 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_opt *opt)
{
	int ret;
	char *arg;
	char *padding;

	if (str == NULL)
		str = "(null)";	
	if (opt->prec > -1)
		arg = ft_substr(str, 0, opt->prec);
	else
		arg = ft_strdup(str);
	if (opt->width > (int)ft_strlen(arg))
	{
		padding = update_padding(opt->zero, opt->width - ft_strlen(arg));
		arg = update_rest(arg, padding, opt->minus);
		free(padding);
	}
	ret = putstr_fd(arg, 1);
	free(arg);
	return (ret);
}
