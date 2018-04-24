/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:53:18 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/23 20:53:45 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_string(t_desc info, va_list *arg)
{
	char *str;

	str = va_arg(*arg, char *);
	ft_putstr(str);
}
