/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:57:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 23:35:44 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

int				ft_printf(char *format, ...);

/*
**************************** Handle Descriptor *********************************
*/

void			handle_type(t_desc info, va_list *arg, t_strlen *len);

void			ft_parse_desc(char *str, int *i, t_desc *info, va_list *arg);

int				is_valid_type(char x);

void			format_type(t_desc *info);

void			init_descriptor(t_desc *info);

/*
**************************** Handle String & Char ******************************
*/

void			handle_char(t_desc info, va_list *arg, t_strlen *len);

void			handle_percent(t_desc info, va_list *arg, t_strlen *len);

void			handle_string(t_desc info, va_list *arg, t_strlen *len);

void			ft_putwchar(wchar_t c);

void			ft_putwstrn(wchar_t *s, int n);

void			ft_putwstr_w_filler(wchar_t *str, int len, t_desc info,
										t_strlen *str_len);

void			handle_wchar(t_desc info, va_list *arg, t_strlen *str_len);

void			handle_wstring(t_desc info, va_list *arg, t_strlen *str_len);

/*
**************************** Handle Int  ***************************************
*/

void			handle_int(t_desc info, va_list *arg, t_strlen *len);

void			handle_uint(t_desc info, va_list *arg, t_strlen *len);

uintmax_t		cast_uint_from_len(t_desc info, uintmax_t i);

intmax_t		cast_int_from_len(t_desc info, intmax_t i);

int				ft_num_len(intmax_t n);

int				ft_unum_len(uintmax_t n);

void			ft_putnbr_int_base(intmax_t n, char *base_chars, intmax_t base,
										t_strlen *len);

void			ft_putnbr_uint_base(uintmax_t n, char *base_chars,
										uintmax_t base, t_strlen *len);

void			ft_putnbr_dispatch(intmax_t n, t_desc info, t_strlen *len);

void			ft_print_num_flags(t_desc *info, t_strlen *len);
/*
****************************** Handle Flags ************************************
*/

void			ft_put_filler(char filler, int n, t_strlen *len);

void			set_flags(char *str, int *i, t_desc *info);

void			set_len(char *str, int *i, t_desc *info);

void			set_width(char *str, int *i, t_desc *info, va_list *arg);

void			set_precision(char *str, int *i, t_desc *info, va_list *arg);

#endif
