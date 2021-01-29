/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:57:19 by chanhlee          #+#    #+#             */
/*   Updated: 2021/01/29 15:28:59 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
