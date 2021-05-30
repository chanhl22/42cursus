/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:55:25 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/29 12:12:34 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include "libft/libft.h"

//연결 리스트의 노드 구조체
typedef struct s_lstnum
{
	long n;				   //데이터를 저정할 멤버
	struct s_lstnum *next; //다음 노드의 주소를 저장할 포인터
	struct s_lstnum *prev; //이전 노드의 주소를 저장할 포인터
} t_lstnum;

//스택 구조체
typedef struct s_stack
{
	t_lstnum *head; //스택의 첫번째 값
	t_lstnum *end;	//스택의 마지막 값
	int size;		//스택의 크기
} t_stack;

void build_stack(t_stack *a, int ac, char **av);
void parse_nb_from_first_str(t_stack *a, char *str);
void parse_nb_from_second_str(t_stack *a, char *str);
void ft_error(void);

#endif
