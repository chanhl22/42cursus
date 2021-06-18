/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:37:05 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:57:38 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median_b(t_stack *b)
{
	t_lstnum	*tmp;
	int			i;
	int			arr[7];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_ascending(arr, i);
	if (b->p[b->top])
		return (arr[1]);
	return (arr[2]);
}

static int	check_b_ra(t_stack *b, char *solution, int med, int *rewind)
{
	t_lstnum	*tmp;
	int			i;

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top] && tmp->n <= med)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp == b->p[b->top])
		return (0);
	*rewind += i;
	while (i > 0)
	{
		rotate(&b->head, &b->end);
		ft_strcat(solution, "rb\n");
		i--;
	}
	return (1);
}

void		cal_stack_b(t_stack *a, t_stack *b, int med, char *solut)
{
	int	rewind;

	rewind = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->n > med)
		{
			push(&b->head, &a->head, &a->end);
			ft_strcat(solut, "pa\n");
		}
		else if (check_b_ra(b, solut, med, &rewind) == 0)
			break ;
	}
	while (b->p[b->top] && rewind > 0)
	{
		reverse_rotate(&b->head, &b->end);
		ft_strcat(solut, "rrb\n");
		rewind--;
	}
}

static void	three_case_nb_b(t_stack *b, char *tmp)
{
	while (!(b->head->next->n > b->head->next->next->n
			&& b->head->n > b->head->next->next->n))
	{
		if (b->head->next->n < b->head->next->next->n
			&& b->head->next->n < b->head->n)
		{
			reverse_rotate(&b->head, &b->end);
			ft_strcat(tmp, "rrb\n");
		}
		else
		{
			rotate(&b->head, &b->end);
			ft_strcat(tmp, "rb\n");
		}
	}
	if (b->head->n >= b->head->next->n)
		return ;
	swap(&b->head);
	ft_strcat(tmp, "sb\n");
}

void		sort_b(t_stack *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->n < b->head->next->n)
		{
			swap(&b->head);
			ft_strcat(tmp, "sb\n");
		}
		return ;
	}
	three_case_nb_b(b, tmp);
}