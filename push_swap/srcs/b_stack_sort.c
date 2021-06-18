/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:42:24 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 23:44:37 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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