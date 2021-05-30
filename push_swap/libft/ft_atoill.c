/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:07:25 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/30 18:07:30 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoill(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					p;

	i = 0;
	p = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		p = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * p;
	return (nb);
}
