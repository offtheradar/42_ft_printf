/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:53:09 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/09 22:12:53 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_num_len(intmax_t n)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int				ft_unum_len(uintmax_t n, uintmax_t base)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
