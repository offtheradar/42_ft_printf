/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:05:56 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 18:04:20 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_print_num_flags(t_desc info, t_strlen *len)
{
	if (info.flag_hash)
	{
		if (info.type == 'o')
		{
			ft_putchar('0');
			(*len)++;
		}
		if (info.type == 'x' || info.type == 'p')
		{
			ft_putstr("0x");
			(*len) += 2;
		}
		if (info.type == 'X')
		{
			ft_putstr("0X");
			(*len) += 2;
		}
	}
}

void			ft_put_filler(char filler, int n, t_strlen *len)
{
	(*len) += n;
	while (n)
	{
		ft_putchar(filler);
		n--;
	}
}

void			ft_putnbr_int_base(intmax_t n, char *base_chars, intmax_t base,
										t_strlen *len)
{
	if (n < 0)
	{
		ft_putchar('-');
		(*len)++;
		ft_putnbr_int_base(-n, base_chars, base, len);
	}
	else if (n >= base)
	{
		ft_putnbr_int_base(n / base, base_chars, base, len);
		ft_putnbr_int_base(n % base, base_chars, base, len);
	}
	else
	{
		ft_putchar(base_chars[n]);
		(*len)++;
	}
}

void			ft_putnbr_uint_base(uintmax_t n, char *base_chars,
										uintmax_t base, t_strlen *len)
{
	if (n >= base)
	{
		ft_putnbr_uint_base(n / base, base_chars, base, len);
		ft_putnbr_uint_base(n % base, base_chars, base, len);
	}
	else
	{
		ft_putchar(base_chars[n]);
		(*len)++;
	}
}
