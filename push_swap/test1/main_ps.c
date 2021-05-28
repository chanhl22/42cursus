/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:05:21 by hopham            #+#    #+#             */
/*   Updated: 2021/05/28 07:37:22 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_and_free(t_stack *a, t_list *solution)
{
	t_lstnum *tmp;
	t_list *tmp_solution;
	t_list *tmp2;

	tmp_solution = solution;
	while (solution)
	{
		ft_putstr((char *)solution->content);
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
		ft_memdel((void **)tmp_solution);
	}
}

static int count_numbers(t_stack *a)
{
	t_lstnum *tmp;
	int i;

	i = 0;
	tmp = a->head; //head를 temp에 넣고
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int main(int ac, char **av) //  main 함수에 전달되는 데이터
{
	t_stack a;		  //a 스택
	t_stack b;		  //b 스택
	t_list *solution; //우리가 출력해야할 솔루션
	int count;		  // 입력 받은 숫자의 개수를 저장하기 위한 변수

	if (ac < 2) // 개수가 1일 때 예외처리
		return (0);
	//a 스택에 값을 다 넣어서 빌드함
	build_stack(&a, ac, av, 0);
	b.head = NULL;
	b.end = NULL;
	count = count_numbers(&a); //a스택의 개수 저장
	//heap공간을 만들어준다. count만큼 노드를 만든 것임
	if (!(a.p = malloc(sizeof(t_lstnum *) * count)) ||
		!(b.p = malloc(sizeof(t_lstnum *) * count)))
		exit(1);
	//스택의 크기 저장
	a.ac = count;
	b.ac = count;
	//스택 a와 b의 top의 값, top은 0이니까 0으로 초기화
	a.top = 0;
	b.top = 0;
	//??
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	//71~83이 왜 있는거지??
	solution = solve(&a, &b);
	print_and_free(&a, solution);
	return (0);
}
