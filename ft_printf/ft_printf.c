/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/30 16:51:03 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_data(va_list ap, t_opt *opt)
{
	int		ret;

	ret = 0;
	if (opt->type == 'd' || opt->type == 'i')
		ret += print_nbr(va_arg(ap, int), opt);
	else if (opt->type == 'c')
		ret += print_char(va_arg(ap, int), opt);
	else if (opt->type == 's')
		ret += print_string(va_arg(ap, char *), opt);
	else if (opt->type == 'p')
		ret += print_pointer(va_arg(ap, long long), opt);
	else if (opt->type == '%')
		ret += print_char('%', opt);
	else if (opt->type == 'u')
		ret += print_unsigned(va_arg(ap, unsigned int), opt);
	else if (opt->type == 'x' || opt->type == 'X')
		ret += print_16(va_arg(ap, unsigned int), opt);
	return (ret);
}

void	check_width_prec(va_list ap, char format, t_opt *opt)
{
	if (ft_isdigit(format))
	{
		if (opt->prec == -1)
			opt->width = opt->width * 10 + format - '0';
		else
			opt->prec = opt->prec * 10 + format - '0';
	}
	else if (format == '*')
	{
		if (opt->prec == -1)
		{
			opt->width = va_arg(ap, int);
			if (opt->width < 0)
			{
				opt->minus = 1;
				opt->width *= -1;
				opt->zero = 0;
			}
		}
		else
		{
			if ((opt->prec = va_arg(ap, int)) < 0)
				opt->prec = -1;
		}
	}
}

void	check_format(char *format, va_list ap, t_opt *opt)
{
	int		ret;

	ret = 0;
	if (*format == '-')
		opt->minus = 1;
	else if (*format == '0' && opt->width == 0
			&& opt->minus == 0 && opt->prec == -1)
		opt->zero = 1;
	else if (*format == '.')
		opt->prec = 0;
	else if (ft_isdigit(*format) || *format == '*')
		check_width_prec(ap, *format, opt);
}

int		parsing(va_list ap, char *format)
{
	int		result;
	t_opt	*opt;

	result = 0;
	if (!(opt = malloc(sizeof(t_opt))))
		return (-1);
	while (*format)
	{
		if (*format != '%')
			result += putchar_fd(*format++, 1);
		else
		{
			init_opt(opt);
			++format;
			while (*format && !ft_strchr(TYPE, *format))
				check_format((char*)format++, ap, opt);
			opt->type = *format++;
			if ((opt->prec >= 0 || opt->minus > 0) && opt->type != '%')
				opt->zero = 0;
			result += print_data(ap, opt);
		}
	}
	free(opt);
	return (result);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, format);
	result = parsing(ap, (char *)format);
	va_end(ap);
	return (result);
}
