/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:52:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/09 22:18:30 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void			ft_putnbr_dispatch(intmax_t n, t_desc info, t_strlen *len)
{
	if (info.type == 'o')
		ft_putnbr_uint_base(n, "01234567", 8, len);
	if (info.type == 'u')
		ft_putnbr_uint_base(n, "0123456789", 10, len);
	if (info.type == 'x' || info.type == 'p')
		ft_putnbr_uint_base(n, "0123456789abcdef", 16, len);
	if (info.type == 'X')
		ft_putnbr_uint_base(n, "0123456789ABCDEF", 16, len);
}

void			ft_print_front_padding(t_desc info, int num_len, t_strlen *len)
{
	int pad_size;

	pad_size = 0;
	if (info.min_f_width || info.precision)
	{
		if ((info.type == 'x' || info.type == 'X' || info.type == 'p') &&
			info.min_f_width)
			info.min_f_width -= 2;
		if (info.precision && info.min_f_width > info.precision
				&& info.precision > num_len)
			pad_size = info.min_f_width - info.precision;
		else if (info.precision && info.min_f_width && info.precision > num_len)
			pad_size = info.min_f_width - num_len;
		if (!info.flag_neg && pad_size)
			ft_put_filler(info.filler, pad_size, len);
	}
	ft_print_num_flags(&info, len);
	if (info.min_f_width || info.precision)
	{
		while (info.precision >= num_len)
		{
			ft_putchar('0');
			(*len)++;
			info.precision--;
		}
	}
}

void			ft_print_back_padding(t_desc info, int num_len, t_strlen *len)
{
	int pad_size;

	pad_size = 0;
	if (info.precision && info.precision > num_len)
		pad_size = info.min_f_width - info.precision;
	else
		pad_size = info.min_f_width - num_len;
	if (info.flag_neg)
		ft_put_filler(' ', pad_size, len);
}

void			handle_int(t_desc info, va_list *arg, t_strlen *len)
{
	intmax_t	i;
	uintmax_t	u;
	int			num_len;

	i = cast_int_from_len(info, va_arg(*arg, intmax_t));
	info.filler = (info.flag_zero && !info.precision) ? '0' : ' ';
	if (i < 0)
	{
		u = i * -1;
		info.sign = '-';
	}
	else
	{
		u = i;
		info.sign = '+';
	}
	num_len = ft_unum_len(u, 10);
	ft_print_front_padding(info, num_len, len);
	ft_putnbr_int_base(i, "0123456789", 10, len);
	if (info.min_f_width || info.precision)
		ft_print_back_padding(info, num_len, len);
	return ;
}

void			handle_uint(t_desc info, va_list *arg, t_strlen *len)
{
	uintmax_t	i;
	uintmax_t	base;
	int			num_len;

	if (info.type == 'o' || info.type == 'O')
		base = 8;
	else if (info.type == 'x' || info.type == 'X')
		base = 16;
	else
		base = 10;
	i = cast_int_from_len(info, va_arg(*arg, uintmax_t));
	num_len = ft_unum_len(i, 8);
	ft_print_front_padding(info, num_len, len);
	ft_putnbr_dispatch(i, info, len);
	if (info.min_f_width || info.precision)
		ft_print_back_padding(info, num_len, len);
}
