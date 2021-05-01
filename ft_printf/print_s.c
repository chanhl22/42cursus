/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:02:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 18:48:14 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *str, t_opt *opt)
{
	int		ret;
	char	*buf;
	char	*padding;
	char	*temp;

	if (str == NULL)
		str = "(null)";
	if (opt->prec > -1)
		buf = ft_substr(str, 0, opt->prec);
	else
		buf = ft_strdup(str);
	if (opt->width > (int)ft_strlen(buf))
	{
		padding = update_padding(opt->zero, opt->width - ft_strlen(buf));
		temp = update_rest(buf, padding, opt->minus);
		free(buf);
		buf = temp;
		free(padding);
	}
	ret = putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
