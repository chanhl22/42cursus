/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:27:53 by aschukin          #+#    #+#             */
/*   Updated: 2021/05/28 07:21:31 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_stack(t_stack *stack)
{
	t_stack		*track_next;
	t_stack		*delete;
if (stack)
	{
		track_next = stack->next;
		while (track_next != stack)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}

static void		free_frame(t_frame *frame)
{
	if (frame)
	{
		if (frame->a)
			free_stack(frame->a);
		if (frame->b)
			free_stack(frame->b);
		if (frame->line)
			free(frame->line);
		if (frame->str)
			free(frame->str);
		free(frame);
	}
}

void			push_swap_free(t_frame *frame)
{
	free_frame(frame);
}
