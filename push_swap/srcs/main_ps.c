/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:58:28 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/30 18:14:49 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv) //  main 함수에 전달되는 데이터
{
	t_stack a; //a 스택
	t_stack b; //b 스택

	if (argc < 2) // 개수가 1일 때 예외처리
		return (0);
	//a 스택에 값을 다 넣어서 빌드함
	build_stack(&a, argc, argv);
	b.head = NULL;
	b.end = NULL;
	printf("%ld\n",a.head->n);
	printf("%ld\n",a.end->n);

	return (0);
}
