/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_desc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:56:14 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/28 21:44:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	handle_type(t_desc info, va_list *arg, t_strlen *len)
{
	if (info.type == 's' || info.type == 'S')
		handle_string(info, arg, len);
	if (info.type == '%')
		handle_percent(info, arg, len);
	if (info.type == 'c' || info.type == 'C')
		handle_char(info, arg, len);
	if (info.type == 'o' || info.type == 'u' || info.type == 'x' ||
		info.type == 'X' || info.type == 'p')
		handle_uint(info, arg, len);
	if (info.type == 'D' || info.type == 'O' || info.type == 'U' ||
		info.type == 'd' || info.type == 'i')
		handle_int(info, arg, len);
}

void	ft_parse_desc(char *str, int *i, t_desc *info)
{
	init_descriptor(info);
	set_flags(str, i, info);
	set_len(str, i, info);
	set_width(str, i, info);
	set_precision(str, i, info);
	if (is_valid_type(str[*i]))
		info->type = str[*i];
	format_type(info);
}

void		format_type(t_desc *info)
{
	if ((info)->type == 'C' || (info)->type == 'S' || info->type == 'p')
		(info)->len_l = 1;
	if (info->type == 'p')
		info->flag_hash = 1;
}

void		init_descriptor(t_desc *info)
{
	(info)->type = 0;
	(info)->flag_hash = 0;
	(info)->flag_zero = 0;
	(info)->flag_neg = 0;
	(info)->flag_plus = 0;
	(info)->len_hh = 0;
	(info)->len_h = 0;
	(info)->len_l = 0;
	(info)->len_ll = 0;
	(info)->len_j = 0;
	(info)->len_z = 0;
	(info)->min_f_width = 0;
	info->sign = 0;
	(info)->precision = 0;
	info->filler = ' ';
}

int		is_valid_type(char x)
{
	return ((x == 'S' || x == 's' || x == 'p' || x == 'D'
				|| x == 'd' || x == 'i' || x == 'O' ||
				x == 'u' || x == 'U' || x == 'x' || x == 'X'
				|| x == 'c' || x == 'C') ? 1 : 0);
}
