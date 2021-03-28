/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:00:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/03/28 15:01:06 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct	s_opt
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
}				t_opt;

int				ft_printf(const char *format, ...);

#endif
