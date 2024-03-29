/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_and_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:40:42 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/20 15:27:10 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lstnum	*add_num_to_struct(long long num)
{
	t_lstnum	*new_num;

	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	new_num = (t_lstnum*)ft_memalloc(sizeof(t_lstnum));
	new_num->n = num;
	new_num->next = NULL;
	return (new_num);
}

void		lst_add_end(t_lstnum **back, t_lstnum *new_num)
{
	t_lstnum	*tmp;

	if (*back == NULL)
		return ;
	tmp = *back;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_num;
	tmp = tmp->next;
	tmp->prev = *back;
	*back = tmp;
}

void		add_to_list(t_stack *s, t_lstnum *new_num, char *str, int *i)
{
	while (str[*i])
	{
		while (ft_isblank(str[*i]))
			(*i)++;
		if (str[*i] == '\0')
			break ;
		if (!ft_isdigit(str[*i]) && !ft_isblank(str[*i])
			&& str[*i] != '-' && str[*i] != '+' && str[*i] != '\0')
			ft_error();
		if (ft_isdigit(str[*i]) && !ft_isdigit(str[*i + 1])
			&& !ft_isblank(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		if ((str[*i] == '-' || str[*i] == '+')
			&& !ft_isdigit(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		new_num = add_num_to_struct(ft_atoill(&str[*i]));
		lst_add_end(&s->end, new_num);
		if (str[*i] == '-' || str[*i] == '+')
			(*i)++;
		while (ft_isdigit(str[*i]))
			(*i)++;
		if (str[*i] && !ft_isblank(str[*i]))
			ft_error();
	}
}

void		first_str(t_stack *a, char *str)
{
	int			i;
	t_lstnum	*new_num;

	new_num = NULL;
	i = 0;
	if (!str)
		return ;
	while (ft_isblank(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		ft_error();
	a->head->n = ft_atoill(&str[i]);
	if (a->head->n > INT_MAX || a->head->n < INT_MIN)
		ft_error();
	a->end = a->head;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isblank(str[i]))
		ft_error();
	add_to_list(a, new_num, str, &i);
}

void		second_str(t_stack *a, char *str)
{
	int			i;
	t_lstnum	*new_num;

	new_num = NULL;
	i = 0;
	if (!str)
		return ;
	add_to_list(a, new_num, str, &i);
}
