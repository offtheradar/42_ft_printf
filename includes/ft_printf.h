/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:57:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/25 16:57:14 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# define IS_VALID_TYPE(x) (x == 'S' || x == 's' || x == 'p' || x == 'D' \
				|| x == 'd' || x == 'i' || x == 'O' || \
				x == 'u' || x == 'U' || x == 'x' || x == 'X' \
				|| x == 'c' || x == 'C') ? 1 : 0

typedef struct	s_desc
{
	char	type;
	int		flag_hash;
	int		flag_zero;
	int		flag_neg;
	int		flag_plus;
	int		flag_space;
	int		len_hh;
	int		len_h;
	int		len_l;
	int		len_ll;
	int		len_j;
	int		len_z;
	int		min_f_width;
	int		precision;
}				t_desc;

int				ft_printf(char *format, ...);

void			handle_hex(t_desc info, va_list *arg);

void			handle_char(t_desc info, va_list *arg);

void			handle_int(t_desc info, va_list *arg);

void			handle_long(t_desc info, va_list *arg);

void			handle_string(t_desc info, va_list *arg);

void			handle_type(t_desc info, va_list *arg);

void			ft_parse_desc(char *str, int *i, t_desc *info);

void			format_type(t_desc *info);

void			init_descriptor(t_desc *info);

intmax_t		cast_uint_from_len(t_desc info, intmax_t i);

uintmax_t		cast_int_from_len(t_desc info, uintmax_t i);

void			ft_putnbr_int_base(intmax_t n, char *base_chars, intmax_t base);

void			ft_putnbr_uint_base(uintmax_t n, char *base_chars,
										uintmax_t base);

void			ft_putnbr_dispatch(intmax_t n, t_desc info);

void			handle_int(t_desc info, va_list *arg);

void			handle_uint(t_desc info, va_list *arg);
#endif
