/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:44:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 23:51:44 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted(t_stack *a)
{
	t_lstnum	*tmp;

	tmp = a->head;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*solve(t_stack *a, t_stack *b)
{
	t_list	*solution;

	solution = ft_lstnew2("\0", 1);
	while (!sorted(a) || b->head)
	{
		if (!sorted(a))
		{
			while (check_stack_a(a, b, &solution) == 0)
				;
		}
		else
			a->p[++(a->top)] = a->head;
		check_stack_b(a, b, &solution);
	}
	return (solution);
}
