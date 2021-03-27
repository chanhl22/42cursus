/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:27:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/27 17:34:38 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"

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
			format++;
		}
		else
		{
			find_format(++format, ap);
			if (*format == 'd')
			{
				//result = va_arg(ap, int);
				//printf("%c\n", va_arg(ap, int));
				//printf("%d\n", ch);
				int result = va_arg(ap, int);
				//printf("%d", number);
			}
		}
		else 
		{
			printf("if outside");
		}
		format++;
	}
	va_end(ap);
	return (result);
}

int main() 
{
	int num = 123;
	
	printf("%d\n", num);
	ft_printf("%d", num);
}

