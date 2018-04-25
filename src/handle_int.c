/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:52:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/25 10:49:46 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	if (info.type == 'd' || info.type == 'i')
		ft_putnbr_int_base(n, "0123456789", 10);
	if (info.type == 'o')
		ft_putnbr_uint_base(n, "01234567", 8);
	if (info.type == 'u')
		ft_putnbr_uint_base(n, "0123456789", 10);
	if (info.type == 'x')
		ft_putnbr_uint_base(n, "0123456789abcdef", 16);
	if (info.type == 'X')
		ft_putnbr_uint_base(n, "0123456789ABCDEF", 16);
}

void			handle_int(t_desc info, va_list *arg)
{
	intmax_t i;

	i = cast_int_from_len(info, va_arg(*arg, intmax_t));
	ft_putnbr_dispatch(i, info);
	return ;
}
