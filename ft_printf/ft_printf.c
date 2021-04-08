/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/08 21:33:20 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_fd(char c, int fd)
{
		return (write(fd, &c, 1));
}

int		putstr_fd(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void init_opt(t_opt	*opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->type = 0;
}

char 	*update_padding(int zero, int size)
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
	
	if ((opt->prec > -1) && (opt->prec > ft_strlen(buf)))
	{
		padding = update_padding(1, opt->prec - ft_strlen(buf));
		buf = update_rest(buf, padding, opt->minus);
	}
	return (buf);
}

char	*update_width(char *buf, t_opt *opt)
{
	char *padding;

	if ((opt->width > 0) && (opt->width > ft_strlen(buf)) && (opt->width > opt->prec))
	{
		padding = update_padding(opt->zero, opt->width - ft_strlen(buf));
		buf = update_rest(buf, padding, opt->minus);
	}
	else 
		buf = ft_strdup(buf);
	free(padding);
	return (buf);
}

int print_nbr(int n, t_opt *opt)
{
	char *buf;
	int ret;

	if (opt->prec == 0 && n == 0)
		buf = ft_strdup("");
	else
		buf = ft_itoa(n);
	buf = update_prec(buf ,opt);
	buf = update_width(buf, opt);
	ret = putstr_fd(buf);
	free(buf);
	return (ret);
}

int print_data(va_list ap, t_opt *opt)
{
	int ret;
	
	ret = 0;
	if (opt->type == 'd')
		ret += print_nbr(va_arg(ap, int), opt);
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
			opt->prec = va_arg(ap, int);
	}
}

void	check_format(char *format, va_list ap, t_opt *opt)
{
	int ret;

	ret = 0;
	if (*format == '-')
		opt->minus = 1;
	else if (*format == '0')
		opt->zero = 1;
	else if (*format == '.')
		opt->prec = 0;
	else if (ft_isdigit(*format) || *format == '*')
		check_width_prec(ap, *format, opt);
}

int	parsing(va_list ap, char *format)
{
	int result;
	t_opt *opt;

	result = 0;
	if (!(opt = malloc(sizeof(t_opt))))
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			result += putchar_fd(*format, 1);
			format++;
		}
		else
		{
			init_opt(opt);
			++format;
			while (*format && !ft_strchr(TYPE, *format))
			{
				check_format((char*)format, ap, opt);
				format++;
			}
			opt->type = *format++;
			result += print_data(ap, opt);
		}
	}
	free(opt);
	return (result);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int result;

	result = 0;
	va_start(ap, format);
	result = parsing(ap, (char *)format);
	va_end(ap);
	return (result);
}

int main() 
{
	int size = 0;
	int size2 = 0;

	size = printf("[%0*d]", -3, 5);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("[%0*d]", -3, 5);
	printf("\n%d\n", size2);

	size = printf("[%0*d]", -2, 123);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("[%0*d]", -2, 123);
	printf("\n%d\n", size2);
	

	/*
	size = printf("hello %0*d", 5, 1);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("hello %0*d", 5, 1);
	printf("\n%d\n", size2);
	
	size = printf("%9.5d", 123);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("%9.5d", 123);
	printf("\n%d\n", size2);

	size = printf("%-2d", 5);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("%-2d", 5);
	printf("\n%d\n", size2);

	size = printf("%-*d", -2, 123);
	printf("\n%d\n", size);
	fflush(stdout);
	size2 = ft_printf("%-*d", -2, 123);
	printf("\n%d\n", size2);
	*/

}


