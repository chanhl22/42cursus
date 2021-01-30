/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:54:08 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/30 14:31:55 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!del || lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
