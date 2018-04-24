/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:53:18 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/24 15:13:21 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_string(t_desc info, va_list *arg)
{
	char *str;

	if (info.type == 's')
	{
		str = va_arg(*arg, char *);
		ft_putstr(str);
	}
}
