/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:53 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 21:01:32 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#define IS_VALID_CONV(x) (x == 'S' || x == 's' || x == 'p' || x == 'D' \
				|| x == 'd' || x == 'i' || x == 'O' || \
				x == 'u' || x == 'U' || x == 'x' || x == 'X' \
				x == 'c' || x == 'C') ? 1 : 0 

void		format_type(t_desc **info)
{
	if ((*info)->type == 'C' || (*info)->type == 'S')
		(*info)->flag == 1;
}

void		init_descriptor(t_desc **info)
{
	*info = (t_desc *)ft_memalloc(sizeof(t_desc));
	(*info)->type = 0;
	(*info)->flag_hash = 0;
	(*info)->flag_zero = 0;
	(*info)->flag_neg = 0;
	(*info)->flag_plus = 0;
	(*info)->flag_hh = 0;
	(*info)->flag_h = 0;
	(*info)->flag_l = 0;
	(*info)->flag_ll = 0;
	(*info)->flag_j = 0;
	(*info)->flag_z = 0;
	(*info)->min_f_width = 0;
	(*info)->precision = 0;
}

t_desc		*ft_parse_format_spec(const char **str, int *done, va_list arg)
{
	t_desc *info;

	init_descriptor(&info);
	while (!IS_VALID_TYPE(**str))
	{
		if (**str == '#')
			
	}
	if (!IS_VALID_TYPE(**str))
		//some kind of error
	else
	{
		descriptor->type = **str;
		format_type(&descriptor);
	}
		

}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int str_index;

	done = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			ft_parse_format_spec(&format, &done, arg);
		else
		{
			ft_putchar(*format);
			done++;
		}
		format++;
	}
	va_end(arg);
	return (done);
}
