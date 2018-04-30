/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/30 00:34:58 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(t_desc info, va_list *arg, t_strlen *len)
{
	char c;

	if (info.len_l)
		return (handle_wchar(info, arg, len));
	c = va_arg(*arg, int);
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putchar(c);
		ft_put_filler(' ', info.min_f_width - 1, len);
		(*len)++;
	}
	else if (info.min_f_width)
	{
		ft_put_filler(info.filler, info.min_f_width - 1, len);
		ft_putchar(c);
		(*len)++;
	}
	else
	{
		ft_putchar(c);
		(*len)++;
	}
}

void	handle_percent(t_desc info, va_list *arg, t_strlen *len)
{
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putchar('%');
		(*len) += info.min_f_width;
	}
	else if (info.min_f_width)
	{
		ft_put_filler(info.filler, info.min_f_width - 1, len);
		ft_putchar('%');
		(*len)++;
	}
	else
	{
		ft_putchar('%');
		(*len)++;
	}
}
