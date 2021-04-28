/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:18:54 by chanhlee          #+#    #+#             */
/*   Updated: 2021/04/28 22:54:30 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr(long long n, char *base, int base_count, char *result)
{
	char	*hex;

	if (n / base_count < base_count)
	{
		if (n / base_count != 0)
		{
			hex = ft_substr(base, n / base_count, 1);
			result = ft_strjoin(result, hex);
		}
	}
	else
	{
		result = ft_putnbr(n / base_count, base, base_count, result);
	}
	hex = ft_substr(base, n % base_count, 1);
	result = ft_strjoin(result, hex);
	return (result);
}

char	*ft_putnbr_base(long long n, char *base)
{
	char *result;
	int size_base = 0;

	while (base[size_base])
		size_base++;
	result = ft_calloc(sizeof(char), 1); 
	result = ft_putnbr(n, base, size_base, result);
	return (result);
}	

int	print_pointer(long long n, t_opt *opt)
{
	int ret;
	char *addr;

	if (n == 0 && opt->prec == 0)
		addr = ft_strdup("");
	else if (n == 0 && opt->prec == -1)
		addr = ft_strdup("0");
	else
		addr = ft_putnbr_base(n, "0123456789abcdef");
	addr = ft_strjoin("0x", addr);
	addr = update_prec(addr, opt);
	addr = update_width(addr, opt, "");
	ret = putstr_fd(addr, 1);
	free(addr);
	return (ret);
}
