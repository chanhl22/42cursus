/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:58:28 by chanhlee          #+#    #+#             */
/*   Updated: 2021/06/14 17:13:37 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc < 2)
		return (0);
	build_stack(&a, argc, argv);
	b.head = NULL;
	b.end = NULL;

	solution = solve(&a, &b);
	print_and_free(&a, solution);
	
	return (0);
}
