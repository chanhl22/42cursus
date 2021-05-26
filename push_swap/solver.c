/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:17:11 by hopham            #+#    #+#             */
/*   Updated: 2021/05/26 20:38:18 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//정렬되지 않은 a가 있다면 쪼개서 b로 보냄
int		split_a_to_b(t_stack *a, t_stack *b, t_list **solution)
{
	char	tmp[a->ac * 4];//??
	int		count;
	long	median;

	tmp[0] = '\0';//tmp0에 널을 집어넣음
	count = get_count(a);
	median = NO_MED;
	if (count > 11)
		median = get_true_median(a);
	else if (count > 2 && count <= 11)
		median = get_special_median_a(a);
	if (median != NO_MED)
		split_from_med_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
	if (median == NO_MED)
	{
		a->p[++(a->top)] = a->head;
		return (1);
	}
	return (0);
}

//a스택 정렬
int		sorted(t_stack *a)
{
	t_lstnum	*tmp;// temp변수

	tmp = a->head;//head를 담는다.
	while (tmp && tmp->next)//head가 null이 아니거나, next노드가 null이 아니라면
	{
		if (tmp->n > tmp->next->n)//만약 head의 데이터가 next노드의 데이터보다 크다면
			return (0);
		tmp = tmp->next;//위의 조건을 만족시키지 않는다면 next노드를 tmp에 담아서 반복한다.
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

void	b_to_a(t_stack *a, t_stack *b, t_list **solution)
{
	char	tmp[a->ac * 4];
	int		count;
	long	median;

	tmp[0] = '\0';
	count = get_count(b);
	median = NO_MED;
	if (count > 6)
		median = get_true_median(b);
	else if (count > 2 && count <= 6)
		median = get_special_median_b(b);
	if (median != NO_MED)
		split_from_med_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == NO_MED)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(solution, ft_lstnew_str(tmp));
}

t_list	*solve(t_stack *a, t_stack *b)
{
	t_list	*solution;

	solution = ft_lstnew("\0", 1);
	//정렬되어있다면 1, 아니면 0
	//a스택이 정렬이 안되어있거나, b스택의 head가 null이 아니거나
	while (!sorted(a) || b->head)
	{
		//만약 a가 정렬되지 않았다면
		if (!sorted(a))
		{
			while (split_a_to_b(a, b, &solution) == 0)
				;
		}
		//정렬되어있다면, b head가 null이라면
		//아마 필요 없을듯?
		else
			a->p[++(a->top)] = a->head;
		b_to_a(a, b, &solution);
	}
	return (solution);
}
