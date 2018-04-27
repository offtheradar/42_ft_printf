/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_desc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:56:14 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/27 10:46:14 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	handle_type(t_desc info, va_list *arg)
{
	if (info.type == 's' || info.type == 'S')
		handle_string(info, arg);
	if (info.type == 'c' || info.type == 'C' || info.type == '%')
		handle_char(info, arg);
	if (info.type == 'o' || info.type == 'u' || info.type == 'x' ||
		info.type == 'X' || info.type == 'p')
		handle_uint(info, arg);
	if (info.type == 'D' || info.type == 'O' || info.type == 'U' ||
		info.type == 'd' || info.type == 'i')
		handle_int(info, arg);
}

void	ft_parse_desc(char *str, int *i, t_desc *info)
{
	init_descriptor(info);
	while (str[*i] && !IS_VALID_TYPE(str[*i]))
	{
		if (str[*i] == '#')
			info->flag_hash = 1;
		else if (str[*i] == '0')
			info->flag_zero = 1;
		else if (str[*i] == ' ')
			info->flag_space = 1;
		else if (str[*i] == '+')
			info->flag_plus = 1;
		else if (str[*i] == '-')
			info->flag_neg = 1;
		else if (str[*i] == 'h' && str[*i + 1] && str[*i + 1] == 'h')
			info->len_hh = 1;
		else if (str[*i] == 'h' && str[*i + 1] != 'h')
			info->len_h = 1;
		else if (str[*i] == 'l' && str[*i + 1] && str[*i + 1] == 'l')
			info->len_ll = 1;
		else if (str[*i] == 'l' && str[*i + 1] != 'l')
			info->len_l = 1;
		else if (str[*i] == 'j')
			info->len_j = 1;
		else if (str[*i] == 'z')
			info->len_z = 1;
		else if (str[*i] == '.')
		{
			info->precision = ft_atoi((str + *i + 1));
			(*i) += 1;
			while (str[*i] && ft_isdigit(str[*i]))
				(*i) += 1;
			*i -= 1;
		}
		else if (ft_isdigit(str[*i]) && str[*i] != '0')
		{
			info->min_f_width = ft_atoi((str + *i));
			while (str[*i] && ft_isdigit(str[*i]))
				(*i) += 1;
			*i -= 1;
		}
		(*i)++;
	}
	info->type = str[*i];
	format_type(info);
}

void		format_type(t_desc *info)
{
	if ((info)->type == 'C' || (info)->type == 'S')
		(info)->len_l = 1;
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
	(info)->precision = 0;
	info->filler = ' ';
}
