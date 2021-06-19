/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:58:28 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/19 15:59:14 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_stack(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_stack a;
	t_stack	b;
	t_list	*solution;
	int		count;

	if (argc < 2)
		return (0);
	build_stack(&a, argc, argv);
	b.head = NULL;
	b.end = NULL;
	count = count_stack(&a);
	if (!(a.p = malloc(sizeof(t_lstnum*) * count)) ||
	!(b.p = malloc(sizeof(t_lstnum*) * count)))
		exit(1);
	a.number_of_op = count;
	b.number_of_op = count;
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	solution = solve(&a, &b);
	print_and_free(&a, solution);
	return (0);
}
