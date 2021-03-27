/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/27 23:28:45 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
		write(fd, &c, 1);
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
			ft_putchar_fd(*format, 1);
			result++;
			format++;
		}
		else
		{
			++format;
			if (*format == 'd')
			{
				int num = va_arg(ap, int);
			}
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
	ft_printf("%d", num);
	printf("\n=======\n");
	printf("hi");
	printf("\n-------\n");
	ft_printf("hi");
	printf("\n");
}

