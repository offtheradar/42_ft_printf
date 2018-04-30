/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar_wstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:13:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 17:47:40 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putwstrn(wchar_t *s, int n)
{
	if (!s || !n)
		return ;
	while (*s && n)
	{
		ft_putwchar(*s);
		n--;
		s++;
	}
}

void	ft_putwstr_w_filler(wchar_t *str, int len, t_desc info,
								t_strlen *str_len)
{
	if (info.min_f_width > len)
	{
		if (info.flag_neg)
		{
			ft_putwstrn(str, len);
			ft_put_filler(info.filler, info.min_f_width - len, str_len);
		}
		else
		{
			ft_put_filler(info.filler, info.min_f_width - len, str_len);
			ft_putwstrn(str, len);
		}
		*(str_len) += len;
	}
	else
	{
		ft_putwstrn(str, len);
	}
}

void	handle_wchar(t_desc info, va_list *arg, t_strlen *str_len)
{
	wchar_t c;

	c = va_arg(*arg, wchar_t);
	if (info.flag_zero)
		info.filler = '0';
	if (info.flag_neg)
	{
		ft_putwchar(c);
		ft_put_filler(' ', info.min_f_width - 1, str_len);
		(*str_len) += 1;
	}
	else if (info.min_f_width)
	{
		ft_put_filler(info.filler, info.min_f_width - 1, str_len);
		ft_putwchar(c);
		(*str_len) += 1;
	}
	else
	{
		ft_putwchar(c);
		(*str_len) += 1;
	}
}

void	handle_wstring(t_desc info, va_list *arg, t_strlen *str_len)
{
	wchar_t	*str;
	int		len;

	str = va_arg(*arg, wchar_t *);
	if (str)
		len = ft_wstrlen(str);
	else
	{
		ft_putstr("(null)");
		*(str_len) += 6;
		return ;
	}
	if (info.precision && info.precision < len)
		len = info.precision;
	ft_putwstr_w_filler(str, len, info, str_len);
}
