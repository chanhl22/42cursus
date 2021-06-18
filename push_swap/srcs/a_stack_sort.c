/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:10:46 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 23:21:12 by chanhlee         ###   ########.fr       */
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