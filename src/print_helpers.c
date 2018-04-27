/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:05:56 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/26 20:24:12 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_put_zero(int num_zero)
{
	while (num_zero)
	{
		ft_putchar('0');
		num_zero--;
	}
}

void			ft_put_space(int num_zero)
{
	while (num_zero)
	{
		ft_putchar(' ');
		num_zero--;
	}
}