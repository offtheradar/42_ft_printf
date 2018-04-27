/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:52:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/26 20:18:08 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

intmax_t		cast_uint_from_len(t_desc info, intmax_t i)
{
	if (info.len_hh)
		return ((unsigned char)i);
	if (info.len_h)
		return ((unsigned short int)i);
	if (info.len_l)
		return ((unsigned long int)i);
	if (info.len_ll)
		return ((unsigned long long int)i);
	if (info.len_j)
		return ((uintmax_t)i);
	if (info.len_z)
		return ((size_t)i);
	return ((unsigned int)i);
}

uintmax_t		cast_int_from_len(t_desc info, uintmax_t i)
{
	if (info.len_hh)
		return ((char)i);
	if (info.len_h)
		return ((short int)i);
	if (info.len_l)
		return ((long int)i);
	if (info.len_ll)
		return ((long long int)i);
	if (info.len_j)
		return ((intmax_t)i);
	if (info.len_z)
		return ((size_t)i);
	return ((int)i);
}

void			ft_putnbr_int_base(intmax_t n, char *base_chars, intmax_t base)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_int_base(-n, base_chars, base);
	}
	else if (n >= base)
	{
		ft_putnbr_int_base(n / base, base_chars, base);
		ft_putnbr_int_base(n % base, base_chars, base);
	}
	else
		ft_putchar(base_chars[n]);
}

void			ft_putnbr_uint_base(uintmax_t n, char *base_chars,
										uintmax_t base)
{
	if (n >= base)
	{
		ft_putnbr_uint_base(n / base, base_chars, base);
		ft_putnbr_uint_base(n % base, base_chars, base);
	}
	else
		ft_putchar(base_chars[n]);
}

void			ft_putnbr_dispatch(intmax_t n, t_desc info)
{
	if (info.type == 'o')
		ft_putnbr_uint_base(n, "01234567", 8);
	if (info.type == 'u')
		ft_putnbr_uint_base(n, "0123456789", 10);
	if (info.type == 'x' || info.type == 'p')
		ft_putnbr_uint_base(n, "0123456789abcdef", 16);
	if (info.type == 'X')
		ft_putnbr_uint_base(n, "0123456789ABCDEF", 16);
}

void			ft_print_num_flags(t_desc info)
{
	if (info.flag_hash)
	{
		if (info.type == 'o')
			ft_putchar('0');
		if (info.type == 'x')
			ft_putstr("0x");
		if (info.type == 'X')
			ft_putstr("0X");
	}
}

int				ft_num_len(intmax_t n)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void			handle_int(t_desc info, va_list *arg)
{
	intmax_t	i;
	int			num_len;

	i = cast_int_from_len(info, va_arg(*arg, intmax_t));
	num_len = ft_num_len(i);
	if (info.flag_plus)
	{
		if (i < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
	}
	ft_print_num_flags(info);
	if (!info.precision && info.min_f_width > num_len && info.flag_zero)
		ft_put_zero(info.min_f_width - num_len);
	if (!info.precision && info.min_f_width > num_len && !info.flag_zero &&
				!info.flag_neg)
		ft_put_space((int)(info.min_f_width - num_len));
	if (info.min_f_width > (info.precision - num_len) &&
		info.flag_zero && !info.flag_neg)
		ft_put_space((int)(info.min_f_width - (info.precision - num_len)));
	if (info.precision > num_len)
		ft_put_zero((int)(info.precision - num_len));
	ft_putnbr_int_base(i, "0123456789", 10);
	if (!info.precision && info.min_f_width > num_len && !info.flag_zero &&
			info.flag_neg)
		ft_put_space((int)(info.min_f_width - num_len));
	return ;
}

void			handle_uint(t_desc info, va_list *arg)
{
	uintmax_t 	i;
	int			num_len;

	i = cast_int_from_len(info, va_arg(*arg, uintmax_t));
	num_len = ft_num_len(i);
	ft_print_num_flags(info);
	if (info.precision > num_len)
		ft_put_zero((int)(info.precision - num_len));
	ft_putnbr_dispatch(i, info);
}