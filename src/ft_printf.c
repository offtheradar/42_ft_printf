/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:53 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/24 15:12:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

# define IS_VALID_TYPE(x) (x == 'S' || x == 's' || x == 'p' || x == 'D' \
				|| x == 'd' || x == 'i' || x == 'O' || \
				x == 'u' || x == 'U' || x == 'x' || x == 'X' \
				|| x == 'c' || x == 'C') ? 1 : 0

int		ft_printf(char *format, ...)
{
	va_list arg;
	t_desc info;
	int i;

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
	ft_printf("hello bob %s %s %c \n", "ann", "dude", 'k');
}
