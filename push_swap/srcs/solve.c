/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:44:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 23:45:50 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_a_to_b(t_stack *a, t_stack *b, t_list **solution)
{
	char	tmp[a->ac * 4];
	int		count;
	long	median;

	tmp[0] = '\0';
	count = get_count(a);
	median = MED;
	if (count > 11)
	{
		median = get_true_median(a);
	}
	else if (count > 2 && count <= 11)
	{
		median = get_special_median_a(a);
	}

	if (median != NO_MED)
	{
		split_from_med_a(a, b, (int)median, tmp); //
	}
	else
	{
		sort_a(a, count, tmp);
	}
	if (tmp[0])
	{
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
	}
	if (median == MED)
	{
		a->p[++(a->top)] = a->head;
		return (1);
	}
	return (0);
}

int sorted(t_stack *a)
{
	t_lstnum* tmp;
	tmp = a->head;

	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			return (0);
		}

		tmp = tmp->next;
	}
	return (1);
}

t_list	*solve(t_stack *a, t_stack *b)
{
	t_list	*solution;
	solution = ft_lstnew("\0", 1);
	while (!sorted(a) || b->head) 
	{
		if (!sorted(a))
		{
			while (split_a_to_b(a, b, &solution) == 0)
				;
		}
		b_to_a(a, b, &solution);
	}
	return (solution);
}