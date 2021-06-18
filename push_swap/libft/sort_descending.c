/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_descending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:59:33 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:47:34 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_descending(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	size--;
	while (i < size)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}