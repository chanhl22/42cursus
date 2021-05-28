/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:58:28 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/28 21:11:23 by chanhlee         ###   ########.fr       */
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

int main(int argc, char **argv) //  main 함수에 전달되는 데이터
{
	t_stack a; //a 스택
	t_stack b; //b 스택
	int count; // 입력 받은 숫자의 개수를 저장하기 위한 변수

	if (argc < 2) // 개수가 1일 때 예외처리
		return (0);
	//a 스택에 값을 다 넣어서 빌드함
	build_stack(&a, argc, argv, 0);
	b.head = NULL;
	b.end = NULL;
	return (0);
}
