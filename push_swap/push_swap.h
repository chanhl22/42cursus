/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:12:02 by HoangPham         #+#    #+#             */
/*   Updated: 2021/05/25 22:39:26 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NO_MED 2147483648
# define BRED "\033[1;31m"
# define BBLUE "\033[1;34m"
# define DEFAULT "\033[0m"

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//연결 리스트의 노드 구조체
typedef struct	s_lstnum
{
	long			n;	//데이터를 저정할 멤버
	struct s_lstnum	*next;	//다음 노드의 주소를 저장할 포인터
	struct s_lstnum	*prev;	//이전 노드의 주소를 저장할 포인터
}				t_lstnum;

//스택 구조체
typedef struct	s_stack
{
	t_lstnum	*head;	//스택의 첫번째 값
	t_lstnum	*end;	//스택의 마지막 값
	t_lstnum	**p;	//??
	int			top;	//스택의 top값
	int			ac;	//스택의 크기
}				t_stack;

void			parse_nb_from_first_str(t_stack *a, char *str);
void			parse_nb_from_second_str(t_stack *a, char *str);
void			print_stacks(t_lstnum *a, t_lstnum *b);

void			ft_error(void);
void			build_stack(t_stack *a, int ac, char **av, int flag);
void			swapper(t_stack *a, t_stack *b, char *line, int *flag);
void			swap(t_lstnum **stack);
void			push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void			ft_rotate(t_lstnum **head, t_lstnum **end);
void			rotater(t_stack *a, t_stack *b, char *line, int *flag);
void			ft_reverse_rotate(t_lstnum **head, t_lstnum **end);
void			reverse_rotater(t_stack *a, t_stack *b, char *line, int *flag);

t_list			*solve(t_stack *a, t_stack *b);
int				get_count(t_stack *stack);
int				get_true_median(t_stack *a);
void			split_from_med_a(t_stack *a, t_stack *b, int med, char *solut);
int				get_special_median_a(t_stack *a);
void			sort_a(t_stack *a, int count, char *solution);
int				get_special_median_b(t_stack *b);
void			split_from_med_b(t_stack *a, t_stack *b, int med, char *solut);
void			sort_b(t_stack *b, int count, char *tmp);

#endif
