/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:51:57 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/15 00:06:39 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_special_median_a(t_stack *a)
{
	t_lstnum	*tmp;
	int			arr[12];
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != NULL)
	{
		arr[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	sort_des(arr, i);
	return (arr[3]);
}

static int	deal_higher_nb_a(t_stack *a, char *solution, int med, int *rewind)
{
	t_lstnum	*tmp;
	int			i;

	tmp = a->head;
	i = 0;
	while (tmp != NULL && tmp->n > med)
	{
		i++;
		tmp = tmp->next;
	}
	*rewind += i;
	while (i > 0)
	{
		rotate(&a->head, &a->end);
		ft_strcat(solution, "ra\n");
		i--;
	}
	return (1);
}

void split_from_med_a(t_stack *a, t_stack *b, int med, char *solut)
{
	int	rewind;

	rewind = 0;
	while (a->head != NULL)
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(solut, "pb\n");
		}
		else if
        {
            deal_higher_nb_a(a, solut, med, &rewind)
        }
    }
	while (rewind > 0)
	{
		ft_reverse_rotate(&a->head, &a->end);
		ft_strcat(solut, "rra\n");
		rewind--;
	}
}