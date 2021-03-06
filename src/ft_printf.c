/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:53 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/30 11:30:49 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	va_list		arg;
	t_desc		info;
	t_strlen	str_len;
	int			i;

	i = 0;
	str_len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_parse_desc(format, &(i), &info, &arg);
			handle_type(info, &arg, &str_len);
		}
		else if (format[i])
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (str_len + i);
}
