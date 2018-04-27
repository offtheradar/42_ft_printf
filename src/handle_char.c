/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/27 15:57:24 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_wchar(t_desc info, va_list *arg)
{
	wchar_t c;

	c = va_arg(*arg, wchar_t);
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putchar(c);
		ft_put_filler(' ', info.min_f_width - 1);
	}
	else
	{
		ft_put_filler(info.filler, info.min_f_width - 1);
		ft_putchar(c);
	}
}

void	handle_char(t_desc info, va_list *arg)
{
	char c;

	if (info.len_l)
		return (handle_wchar(info, arg));
	c = va_arg(*arg, int);
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putchar(c);
		ft_put_filler(' ', info.min_f_width - 1);
	}
	else
	{
		ft_put_filler(info.filler, info.min_f_width - 1);
		ft_putchar(c);
	}
}
