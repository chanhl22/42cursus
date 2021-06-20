/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:37:05 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/20 15:24:22 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median_b(t_stack *b)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[7];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_ascending(arr, i);
	if (b->p[b->top])
		return (arr[1]);
	return (arr[2]);
}
