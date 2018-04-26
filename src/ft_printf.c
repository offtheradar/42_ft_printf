/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:53 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/25 17:58:02 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	va_list	arg;
	t_desc	info;
	int		i;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_parse_desc(format, &i, &info);
			handle_type(info, &arg);
		}
		else if (format[i])
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (i);
}

int		main(void)
{
	ft_printf("hello bob %s %s %c %.5d \n", "ann", "dude", 'k', 500);
	printf("%.5d", 500);
}
