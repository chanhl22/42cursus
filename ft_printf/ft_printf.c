/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/01 20:36:13 by chanhlee         ###   ########.fr       */
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

char	*update_width(char *buf, t_opt *opt)
{
	char *padding;
	if(opt->zero > 0)
	{
		padding = ft_calloc(sizeof(char), opt->width - ft_strlen(buf) + 1);
		printf("hello: %c\n", *padding);
		buf = ft_strjoin(padding, buf);
	}
	return (buf);
	
}

int print_nbr(int n, t_opt *opt)
{
	char *buf;
	int ret;

	buf = ft_itoa(n);
	printf("hihi: %s\n",buf); // 1
	buf = update_width(buf, opt);
	ret = putstr_fd(buf);
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

void	check_width(va_list ap, char *format, t_opt *opt)
{
	opt->width = va_arg(ap, int);
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
	else if (*format == '*')
		check_width(ap, format, opt);
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
	int num = 123;
	int size = 0;

	size = printf("hello %0*d", 5, 1);
	printf("\n%d\n", size);
	fflush(stdout);
	ft_printf("hello %0*d", 5, 1);
	//ft_printf("%d", 123);
	//fflush(stdout);
	//printf("%d", 123);
	//printf("%d\n", size);
	/*printf("hi");
	ft_printf("hi");*/
	//printf("hello %0*d", 5, 1, "world");
	//ft_printf("hello %0*d", 5, 1, "world");
}
