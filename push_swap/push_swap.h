/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:55:25 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:59:07 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MEDIAN 2147483648
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft/libft.h"

typedef struct	s_lstnum
{
	long			n;
	struct s_lstnum	*next;
	struct s_lstnum	*prev;
}				t_lstnum;

typedef struct	s_stack
{
	t_lstnum	*head;
	t_lstnum	*end;
	int			number_of_op;
	t_lstnum	**p;
	int			top;
}				t_stack;

void			parse_nb_from_first_str(t_stack *a, char *str);
void			parse_nb_from_second_str(t_stack *a, char *str);

void			ft_error(void);
void			build_stack(t_stack *a, int ac, char **av, int flag);
void			swap(t_lstnum **stack);
void			push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void			rotate(t_lstnum **head, t_lstnum **end);
void			reverse_rotate(t_lstnum **head, t_lstnum **end);

t_list			*solve(t_stack *a, t_stack *b);
int				get_count(t_stack *stack);
int				get_median(t_stack *a);
void			cal_stack_a(t_stack *a, t_stack *b, int med, char *solut);
int				get_median_a(t_stack *a);
void			sort_a(t_stack *a, int count, char *solution);
int				get_median_b(t_stack *b);
void			cal_stack_b(t_stack *a, t_stack *b, int med, char *solut);
void			sort_b(t_stack *b, int count, char *tmp);

#endif
