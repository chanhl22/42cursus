/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/28 22:17:08 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
		return (write(fd, &c, 1));
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int ret;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		ret = 10;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ret += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char*)(str + i));
	return (NULL);
}

void init_opt(t_opt	*opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->type = 0;
}

int print_data(va_list ap, t_opt *opt)
{
	int ret;
	char type;

	ret = 0;
	type = opt->type;
	if (type == 'd')
		ret += ft_putnbr_fd(va_arg(ap, int), 1);
	printf("test : %d\n", ret);
	return (ret);
}

int find_format(char *format, va_list ap)
{
	t_opt	*opt;
	int ret;


	ret = 0;
	init_opt(opt);
	while (!ft_strchr(TYPE, *format) && *format != '\0')
	{
		format++;
	}
	opt->type = *format;
	ret += print_data(ap, opt);
	printf("test1 : %d\n", ret);
	return (ret);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int result;

	result = 0;
	va_start(ap, format);
	//printf("adfsdaf");
	while (*format)
	{
		if (*format != '%')
		{
			result += ft_putchar_fd(*format, 1);
			format++;
		}
		else
		{
			result += find_format((char *)++format, ap);
		}
	}
	va_end(ap);
	return (result);
}

int main() 
{
	int num = 123;
	
	ft_printf("%d", num);
	fflush(stdout);
	printf("%d", num);
	/*printf("hi");
	ft_printf("hi");*/
	//printf("hello %0*d", 5, 1, "world");
	//ft_printf("hello %0*d", 5, 1, "world");
}

