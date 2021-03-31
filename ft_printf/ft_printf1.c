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

int print_data(va_list ap, char *format)
{
	int ret;
	char type;

	ret = 0;
	type = *format;
	//printf("%c\n", *format);
	if (type == 'd')
		ret += ft_putnbr_fd(va_arg(ap, int), 1);
	return (ret);
}
  
int find_format(char *format, va_list ap)
{
	int ret;
	
	ret = 0;
	while (!ft_strchr(TYPE, *format) && *format != '\0')
	{
		format++;
	}
	ret += print_data(ap, format);
	return (ret);
}

void		init_opt(t_opt *opt)
{
	opt->minus = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->type = 0;
}

int parsing(va_list ap, char *format)
{
	int result;
	t_opt *opt;

	result = 0;
	if (!(opt = malloc(sizeof(t_opt))))
		return (-1);
	init_opt(opt);
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
			format++;
		}
	}
	free(opt);
	return (result);
}

int	ft_printf(const char *format, ...)
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

	ft_printf("%d", num);
	fflush(stdout);
	printf("%d", num);
}
