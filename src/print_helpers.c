/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:05:56 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 11:51:10 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_print_num_flags(t_desc info)
{
	if (info.flag_hash)
	{
		if (info.type == 'o')
			ft_putchar('0');
		if (info.type == 'x' || info.type == 'p')
			ft_putstr("0x");
		if (info.type == 'X')
			ft_putstr("0X");
	}
}

void			ft_put_filler(char filler, int n)
{
	while (n)
	{
		ft_putchar(filler);
		n--;
	}
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
