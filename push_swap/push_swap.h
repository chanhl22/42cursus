/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:55:25 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/19 16:02:10 by chanhlee         ###   ########.fr       */
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

void			first_str(t_stack *a, char *str);
void			second_str(t_stack *a, char *str);
t_lstnum		*add_num_to_struct(long long num);
void			lst_add_end(t_lstnum **back, t_lstnum *new_num);
void			add_to_list(t_stack *s, t_lstnum *new_num, char *str, int *i);

void			ft_error(void);
void			build_stack(t_stack *a, int ac, char **av);
int				check_double(t_stack *a);

void			swap(t_lstnum **stack);
void			push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end);
void			rotate(t_lstnum **head, t_lstnum **end);
void			reverse_rotate(t_lstnum **head, t_lstnum **end);

t_list			*solve(t_stack *a, t_stack *b);
int				get_count(t_stack *stack);
int				get_median(t_stack *a);

int				get_median_a(t_stack *a);
int				check_stack_a(t_stack *a, t_stack *b, t_list **solution);
void			case_three_a(t_stack *a, char *solution);
void			sort_a(t_stack *a, int count, char *solution);
int				check_a_ra(t_stack *a, char *solution, int med, int *rewind);
void			cal_stack_a(t_stack *a, t_stack *b, int med, char *solut);


int				get_median_b(t_stack *b);
void			check_stack_b(t_stack *a, t_stack *b, t_list **solution);
void			case_three_b(t_stack *b, char *tmp);
void			sort_b(t_stack *b, int count, char *tmp);
void			push_b(t_stack *b, t_stack *a, int count, char *tmp);
int				check_b_ra(t_stack *b, char *solution, int med, int *rewind);
void			cal_stack_b(t_stack *a, t_stack *b, int med, char *solut);

void			print_and_free(t_stack *a, t_list *solution);

#endif
