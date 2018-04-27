/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/26 20:52:28 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_wchar(t_desc info, va_list *arg)
{
	wchar_t c;

	c = va_arg(*arg, wchar_t);
	if (info.flag_zero && !info.flag_neg)
		ft_put_zero(info.min_f_width - 1);
	if (info.min_f_width && !info.flag_zero && !info.flag_neg)
		ft_put_space(info.min_f_width - 1);
	ft_putchar(c);
	if (info.min_f_width && !info.flag_zero && info.flag_neg)
		ft_put_space(info.min_f_width - 1);
}

void	handle_char(t_desc info, va_list *arg)
{
	char c;

	if (info.len_l)
		return (handle_wchar(info, arg));
	c = va_arg(*arg, int);
	if (info.flag_zero && !info.flag_neg)
		ft_put_zero(info.min_f_width - 1);
	if (info.min_f_width && !info.flag_zero && !info.flag_neg)
		ft_put_space(info.min_f_width - 1);
	ft_putchar(c);
	if (info.min_f_width && !info.flag_zero && info.flag_neg)
		ft_put_space(info.min_f_width - 1);
}