/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:38:26 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/20 15:24:39 by chanhlee         ###   ########.fr       */
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

int	get_median(t_stack *stack)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[stack->number_of_op];

	tmp = stack->head;
	i = 0;
	while (tmp != stack->p[stack->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_descending(arr, i);
	return (arr[i / 2]);
}
