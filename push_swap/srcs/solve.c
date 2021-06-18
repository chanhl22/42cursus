/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:44:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:41:00 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack_a(t_stack *a, t_stack *b, t_list **solution)
{
	char	tmp[a->number_of_op * 4];
	int		count;
	long	median;

	tmp[0] = '\0';
	count = get_count(a);
	median = MEDIAN;
	if (count > 11)
		median = get_median(a);
	else if (count > 2 && count <= 11)
		median = get_median_a(a);
	if (median != MEDIAN)
		cal_stack_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
	if (median == MEDIAN)
	{
		a->p[++(a->top)] = a->head;
		return (1);
	}
	return (0);
}

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

void	push_b(t_stack *b, t_stack *a, int count, char *tmp)
{
	int	i;

	i = 0;
	if (count == -1)
		count = 3;
	while (i < count)
	{
		push(&b->head, &a->head, &a->end);
		ft_strcat(tmp, "pa\n");
		i++;
	}
}

void	check_stack_b(t_stack *a, t_stack *b, t_list **solution)
{
	char	tmp[a->number_of_op * 4];
	int		count;
	long	median;

	tmp[0] = '\0';
	count = get_count(b);
	median = MEDIAN;
	if (count > 6)
		median = get_median(b);
	else if (count > 2 && count <= 6)
		median = get_median_b(b);
	if (median != MEDIAN)
		cal_stack_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == MEDIAN)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
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
