/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:59:49 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/28 18:01:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		cast_uint_from_len(t_desc info, intmax_t i)
{
	if (info.len_hh)
		return ((unsigned char)i);
	if (info.len_h)
		return ((unsigned short int)i);
	if (info.len_l)
		return ((unsigned long int)i);
	if (info.len_ll)
		return ((unsigned long long int)i);
	if (info.len_j)
		return ((uintmax_t)i);
	if (info.len_z)
		return ((size_t)i);
	return ((unsigned int)i);
}

uintmax_t		cast_int_from_len(t_desc info, uintmax_t i)
{
	if (info.len_hh)
		return ((char)i);
	if (info.len_h)
		return ((short int)i);
	if (info.len_l)
		return ((long int)i);
	if (info.len_ll)
		return ((long long int)i);
	if (info.len_j)
		return ((intmax_t)i);
	if (info.len_z)
		return ((size_t)i);
	return ((int)i);
}
