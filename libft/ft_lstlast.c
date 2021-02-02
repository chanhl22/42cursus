/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:53:18 by chanhlee          #+#    #+#             */
/*   Updated: 2021/02/02 20:15:17 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)

{

		if (lst)

					while (lst->next)

									lst = lst->next;

			return (lst);

}

/*t_list *ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		lst = lst->next;
		if (lst == NULL)
			return (lst);
	}
	return (lst);
}*/
