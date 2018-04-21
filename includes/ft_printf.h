
#ifndef FT_PRINTF_H

typedef struct	s_desc
{
	char	type;
	int	flag_hash;
	int	flag_zero;
	int	flag_neg;
	int	flag_plus;
	int	flag_hh;
	int	flag_h;
	int	flag_l;
	int	flag_ll;
	int	flag_j;
	int	flag_z;
	int	min_f_width;
	int	precision;
}		t_desc;

#endif
