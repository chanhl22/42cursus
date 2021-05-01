/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:00:36 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/01 19:12:06 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

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
int				putchar_fd(char c, int fd);
int				putstr_fd(char *s, int fd);
void			init_opt(t_opt *opt);
char			*update_padding(int zero, int size);
char			*update_rest(char *buf, char *padding, int minus);
char			*update_prec(char *buf, t_opt *opt);
char			*update_width(char *buf, t_opt *opt, char *sign);
int				print_nbr(int n, t_opt *opt);
int				print_data(va_list ap, t_opt *opt);
void			check_width_prec(va_list ap, char format, t_opt *opt);
void			check_format(char *format, va_list ap, t_opt *opt);
int				parsing(va_list ap, char *format);

int				print_char(int c, t_opt *opt);
int				putstr_fd(char *s, int fd);

int				print_string(char *str, t_opt *opt);

int				print_pointer(long long n, t_opt *opt);
char			*ft_putnbr_base(long long n, char *base);
char			*ft_putnbr(long long n, char *base,
						int base_count, char *result);

int				print_unsigned(unsigned int n, t_opt *opt);

int				print_16(unsigned int n, t_opt *opt);
char			*ft_itoa2(unsigned int n);
int				ft_len2(long int nbr);
long int		ft_abs2(long int nbr);

char			*ft_strjoin_first(char *s1, char *s2);
char			*ft_strjoin_second(char *s1, char *s2);
char			*ft_strjoin_third(char *s1, char *s2);

#endif
