/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:38:26 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 20:01:47 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_stack *stack)
{
	int			count;
	t_lstnum	*tmp;

	tmp = stack->head;
	count = 0;
	
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (!NULL && count == 3)
	{
		return (-1);
	}
	return (count);
}

int	get_true_median(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[a->ac];

	tmp = a->head;
	i = 0;
	while (tmp != NULL)
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_des(arr, i);
	return (arr[i / 2]);
}