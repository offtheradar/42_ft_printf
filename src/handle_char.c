/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/24 12:53:50 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(t_desc info, va_list *arg)
{
	char c;

	c = va_arg(*arg, int);
	if (info->len_l)
		ft_putchar((wint_t)c);
	else
		ft_putchar((unsigned char)c);
	return ;
}
