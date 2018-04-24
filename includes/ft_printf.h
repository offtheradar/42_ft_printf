/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:57:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/23 20:58:43 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# define IS_VALID_TYPE(x) (x == 'S' || x == 's' || x == 'p' || x == 'D' \
				|| x == 'd' || x == 'i' || x == 'O' || \
				x == 'u' || x == 'U' || x == 'x' || x == 'X' \
				|| x == 'c' || x == 'C') ? 1 : 0

typedef struct	s_desc
{
	char	type;
	int		flag_hash;
	int		flag_zero;
	int		flag_neg;
	int		flag_plus;
	int		flag_space;
	int		len_hh;
	int		len_h;
	int		len_l;
	int		len_ll;
	int		len_j;
	int		len_z;
	int		min_f_width;
	int		precision;
}		t_desc;

#endif
