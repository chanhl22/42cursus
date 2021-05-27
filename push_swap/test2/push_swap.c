/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:58:00 by aschukin          #+#    #+#             */
/*   Updated: 2021/05/27 21:08:03 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Frame A is filled with the stack A numbers.
** Turns on the do_write flag, which prints moves to the standard output.
** If stack A is not sorted, the solver function is called.
*/

static void	push_swap(t_frame *frame)
{
	fill_stack_a(frame);//a스택에 입력값을 채워넣는다. 
	frame->do_write = 1;
	if (!sorted(frame))
	{
		solver(frame);
		return ;
	}
}

/*
** Main creates frame to hold stack A and stack B by calling create_frame.
*/

int			main(int argc, char **argv)
{
	t_frame		*frame;//우선 프레임을 하나 만든다. 구조체 변수 선언

	frame = NULL;//구조체 변수 초기화
	if (argc < 2)//입력의 개수가 2개 미만이면 끝
		return (1);
	frame = create_frame(frame, argv);//frame 만들기, 스택a,b에 공간을 할당한다.
	push_swap(frame);//push_swap시작
	push_swap_free(frame);
	return (0);
}
