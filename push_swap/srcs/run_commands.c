/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:42:27 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 21:04:41 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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