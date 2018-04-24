/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:52:48 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/24 15:11:26 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_int(t_desc info, va_list *arg)
{
	int i;

	if (info.type == 'd')
	{
		i = va_arg(*arg, int);
		ft_putnbr(i);
	}
	return ;
}
