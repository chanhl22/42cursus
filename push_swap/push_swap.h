/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:55:25 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 19:49:12 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define MED 2147483648

#include "libft/libft.h"

//연결 리스트의 노드 구조체
typedef struct	s_lstnum
{
	long n;
	struct s_lstnum *next;
	struct s_lstnum *prev;
}				t_lstnum;

typedef struct	s_stack
{
	t_lstnum	*head;
	t_lstnum	*end;
	int			size;
	int			ac;
}				t_stack;

void build_stack(t_stack *a, int ac, char **av);
void parse_nb_from_first_str(t_stack *a, char *str);
void parse_nb_from_second_str(t_stack *a, char *str);
void ft_error(void);

#endif
