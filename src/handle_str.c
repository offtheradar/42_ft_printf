/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:53:18 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/29 12:12:29 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstrn(char *s, int n)
{
	if (!s || !n)
		return ;
	while (*s && n)
	{
		ft_putchar(*s);
		n--;
		s++;
	}
}

void	ft_putstr_w_filler(char *str, int len, t_desc info, t_strlen *str_len)
{
	if (info.min_f_width > len)
	{
		if (info.flag_neg)
		{
			ft_putstrn(str, len);
			ft_put_filler(info.filler, info.min_f_width - len);
		}
		else
		{
			ft_put_filler(info.filler, info.min_f_width - len);
			ft_putstrn(str, len);
		}
		*(str_len) += info.min_f_width;
	}
	else
	{
		ft_putstrn(str, len);
		*(str_len) += len;
	}
}

void	handle_string(t_desc info, va_list *arg, t_strlen *str_len)
{
	char	*str;
	int		len;

	if (info.flag_zero && !info.flag_neg)
		info.filler = '0';
	if (info.len_l)
		return (handle_wstring(info, arg, str_len));
	str = va_arg(*arg, char *);
	if (str)
		len = ft_strlen(str);
	else
	{
		ft_putstr("(null)");
		*(str_len) += 6;
		return ;
	}
	if (info.precision && info.precision < len)
		len = info.precision;
	ft_putstr_w_filler(str, len, info, str_len);
}
