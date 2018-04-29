/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:57:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/28 18:54:29 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_desc
{
	char	type;
	char	sign;
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
	char	filler;
}				t_desc;

typedef	int		t_strlen;

int				is_valid_type(char x);

int				ft_printf(char *format, ...);

void			handle_hex(t_desc info, va_list *arg);

void			handle_char(t_desc info, va_list *arg);

void			handle_percent(t_desc info, va_list *arg);

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

void			ft_put_zero(int num_zero);

void			ft_put_space(int num_zero);

void			ft_put_filler(char filler, int n);

void			set_flags(char *str, int *i, t_desc *info);

void			set_len(char *str, int *i, t_desc *info);

void			set_width(char *str, int *i, t_desc *info);

void			set_precision(char *str, int *i, t_desc *info);

void			ft_print_num_flags(t_desc info);

/*
**************************** Handle Wide String & Char **************
*/

void			ft_putwchar(wchar_t c);

void			ft_putwstrn(wchar_t *s, int n);

void			ft_putwstr_w_filler(wchar_t *str, int len, t_desc info);

void			handle_wchar(t_desc info, va_list *arg);

void			handle_wstring(t_desc info, va_list *arg);

intmax_t		cast_uint_from_len(t_desc info, intmax_t i);

uintmax_t		cast_int_from_len(t_desc info, uintmax_t i);

int				ft_num_len(intmax_t n);

int				ft_unum_len(uintmax_t n);
#endif
