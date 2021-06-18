/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:51:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:57:19 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median_a(t_stack *a)
{
	t_lstnum	*tmp;
	int			arr[12];
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_descending(arr, i);
	if (a->p[a->top])
		return (arr[2]);
	return (arr[3]);
}

static void	three_nb_case(t_stack *a, char *solution)
{
	while (!(a->head->next->n < a->head->next->next->n
			&& a->head->n < a->head->next->next->n))
	{
		if (a->head->next->n > a->head->next->next->n
			&& a->head->next->n > a->head->n)
		{
			reverse_rotate(&a->head, &a->end);
			ft_strcat(solution, "rra\n");
		}
		else
		{
			rotate(&a->head, &a->end);
			ft_strcat(solution, "ra\n");
		}
	}
	if (a->head->n < a->head->next->n)
		return ;
	swap(&a->head);
	ft_strcat(solution, "sa\n");
}

void		sort_a(t_stack *a, int count, char *solution)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->n > a->head->next->n)
		{
			swap(&a->head);
			ft_strcat(solution, "sa\n");
		}
		return ;
	}
	three_nb_case(a, solution);
}

static int	check_a_ra(t_stack *a, char *solution, int med, int *rewind)
{
	t_lstnum	*tmp;
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top] && tmp->n > med)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp == a->p[a->top])
		return (0);
	*rewind += i;
	while (i > 0)
	{
		rotate(&a->head, &a->end);
		ft_strcat(solution, "ra\n");
		i--;
	}
	return (1);
}

void		cal_stack_a(t_stack *a, t_stack *b, int med, char *solut)
{
	int	rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(solut, "pb\n");
		}
		else if (check_a_ra(a, solut, med, &rewind) == 0)
			break ;
	}
	while (a->p[a->top] && rewind > 0)
	{
		reverse_rotate(&a->head, &a->end);
		ft_strcat(solut, "rra\n");
		rewind--;
	}
}