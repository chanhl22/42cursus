/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:58:28 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/15 20:53:16 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_and_free(t_stack *a, t_list *solution)
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

static int	count_numbers(t_stack *a)
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

int			main(int ac, char **av)
{
	t_stack a;
	t_stack	b;
	t_list	*solution;
	int		count;

	if (ac < 2)
		return (0);
	build_stack(&a, ac, av, 0);
	b.head = NULL;
	b.end = NULL;
	count = count_numbers(&a);
	if (!(a.p = malloc(sizeof(t_lstnum*) * count)) ||
	!(b.p = malloc(sizeof(t_lstnum*) * count)))
		exit(1);
	a.ac = count;
	b.ac = count;
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	solution = solve(&a, &b);
	print_and_free(&a, solution);
	return (0);
}
