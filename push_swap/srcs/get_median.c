/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:38:26 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:48:17 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_stack *stack)
{
	int			count;
	t_lstnum	*tmp;

	tmp = stack->head;
	count = 0;
	while (tmp != stack->p[stack->top])
	{
		count++;
		tmp = tmp->next;
	}
	if (!stack->p[stack->top] && count == 3)
		return (-1);
	return (count);
}

int	get_median(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[a->number_of_op];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_descending(arr, i);
	return (arr[i / 2]);
}