/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:54:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/24 15:08:01 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(t_desc info, va_list *arg)
{
	char c;

	if (info.type == 'c')
	{
		c = va_arg(*arg, int);
		ft_putchar((unsigned char)c);
	}
	return ;
}