/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:44:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 19:09:36 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_a_to_b(t_stack *a, t_stack *b, t_list **solution)
{
	//담을 수 있는 값이 rra\n로 4개가 최대이므로 *4를 함, 뒤에 나머지 값은 어떻게 되는지 확인해보자
	char	tmp[a->ac * 4]; //"pb\n", "rra\n", "ra\n" == possible command, that's why we use 4 byte for one number
	int		count;
	long	median;

	tmp[0] = '\0';//일단 \0을 담아줌
	count = get_count(a); //find number of a
	median = NO_MED; //2147483648

	//get middle number of a
	if (count > 11)
	{
		median = get_true_median(a); //sort stack and get middle number
	}
	else if (count > 2 && count <= 11)
	{
		median = get_special_median_a(a);
	}

	//아마도 무조건 어떤 미디안 값이 있을테고
	if (median != NO_MED)
	{
		split_from_med_a(a, b, (int)median, tmp); //
	}
	else
	{
		sort_a(a, count, tmp);
	}


    //temp에 값이 있다면 tmp를 리스트변수로 만들어서 솔루션에 합침
	//빈 솔루션에다가 리스트로 만든 솔루션을 옮겨담는다.
	if (tmp[0])
	{
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
	}

	//거의 med가 있을거라서 아마 안들어갈껄
	if (median == NO_MED)
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