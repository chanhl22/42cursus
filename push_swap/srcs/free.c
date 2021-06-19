/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:58:45 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/19 15:59:27 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_and_free(t_stack *a, t_list *solution)
{
	t_lstnum	*tmp;
	t_list		*tmp_solution;
	t_list		*tmp2;

	tmp_solution = solution;
	while (solution)
	{
		ft_putstr((char*)solution->content);
		solution = solution->next;
	}
	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (tmp_solution)
	{
		tmp2 = tmp_solution;
		tmp_solution = tmp_solution->next;
		ft_memdel((void**)tmp_solution);
	}
}