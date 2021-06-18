/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:42:27 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/18 22:57:02 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lstnum **stack)
{
	t_lstnum	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
}

void	push(t_lstnum **from, t_lstnum **to, t_lstnum **to_end)
{
	t_lstnum	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	(*from) = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	else
		*to_end = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
}

void	rotate(t_lstnum **head, t_lstnum **end)
{
	if (*head == NULL || *end == NULL)
		return ;
	(*end)->next = *head;
	(*head)->prev = *end;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*end = (*end)->next;
	(*end)->next = NULL;
}

void	reverse_rotate(t_lstnum **head, t_lstnum **end)
{
	if (*head == NULL || *end == NULL)
		return ;
	(*head)->prev = *end;
	(*end)->next = *head;
	*head = *end;
	(*end) = (*end)->prev;
	(*end)->next = NULL;
	(*head)->prev = NULL;
}