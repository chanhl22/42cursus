/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:09 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/29 12:11:37 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

//스택에 중복 값이 있는지 확인
static int check_double(t_stack *a)
{
	t_lstnum *tmp1;
	t_lstnum *tmp2;
	int num;

	tmp1 = a->head;
	while (tmp1)
	{
		num = tmp1->n;
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (num == tmp2->next->n)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void build_stack(t_stack *a, int ac, char **av)
{
	int i;

	i = 2;
	a->head = ft_memalloc(sizeof(t_lstnum)); //스택 a의 head를 만듦, head는 값을 저장하지 않고 연결리스트의 기준점 역할을 함
	//하지만 우리가 만들 것은 양방향 연결리스트!
	parse_nb_from_first_str(a, av[1]); //왜 1을 받지? 실행파일 이름으로 실행했다면 argv[0]에는 실행파일 이름이 들어간다.
	while (i < ac)
	{
		parse_nb_from_second_str(a, av[i]); //1다음부터 값을 받는다.
		i++;
	}
	if (!(check_double(a))) // 스택에 중복값이 있는지 확인
		ft_error();
}
