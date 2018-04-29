/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/28 16:42:38 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	handle_percent(t_desc info, va_list *arg)
{
	char c;

	if (info.len_l)
		return (handle_wchar(info, arg));
	c = va_arg(*arg, int);
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putchar('%');
		ft_put_filler(' ', info.min_f_width - 1);
	}
	else
	{
		ft_put_filler(info.filler, info.min_f_width - 1);
		ft_putchar('%');
	}
}
