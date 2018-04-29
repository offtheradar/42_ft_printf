/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:48:30 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/28 17:44:34 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	set_flags(char *str, int *i, t_desc *info)
{
    while (str[*i] && ft_strchr("#0+- ", str[*i]))
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
        (*i)++;
    }
}

void    set_len(char *str, int *i, t_desc *info)
{
    while (str[*i] && ft_strchr("hljz", str[*i]))
    {
        if (str[*i] == 'h' && str[*i + 1] && str[*i + 1] == 'h')
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
        (*i)++;
    }
}

void    set_width(char *str, int *i, t_desc *info)
{
    if (str[*i] && ft_isdigit(str[*i]))
    {
        info->min_f_width = ft_atoi((str + *i));
        while (str[*i] && ft_isdigit(str[*i]))
            (*i) += 1;
    }
}

void    set_precision(char *str, int *i, t_desc *info)
{
    if (str[*i] && str[*i] == '.')
	{
        info->precision = ft_atoi((str + *i + 1));
		(*i) += 1;
        while (str[*i] && ft_isdigit(str[*i]))
            (*i) += 1;
    }
}