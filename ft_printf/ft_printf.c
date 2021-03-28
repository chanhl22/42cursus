/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/28 10:31:28 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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

int	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int result;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			result += ft_putchar_fd(*format, 1);
			format++;
		}
		else
		{
			++format;
			if (*format == 'c')
			{
				result += ft_putnbr_fd(va_arg(ap, int), 1);
			}
			format++;
		}
	}
	va_end(ap);
	return (result);
}

int main() 
{
	int num = 123;
	
	printf("%d", num);
	printf("\n-------\n");
	ft_printf("%c", num);
	printf("\n=======\n");
	printf("hi");
	printf("\n-------\n");
	ft_printf("hi");
	printf("\n");
}

