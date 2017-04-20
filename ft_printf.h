/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:15:53 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 18:10:47 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

typedef struct		s_printf
{
	int		width;
	int		precision;
	int		count;
	int		flag_hash;
	int		flag_minus;
	int		flag_null;
	int		flag_plus;
	int		flag_space;
	char	specificator;
	int		size;
	int		check;
	int		check_pr;
	int		zero;
}					t_printf;

int					ft_printf(const char *format, ...);
int					parse_ft(const char *format, t_printf *p_p, int i);
void				width_chr(char c, t_printf *p_p);
int					print_chr(t_printf *p_p, va_list args);
t_printf			*create_struct(void);
int					ft_parse(const char *format, t_printf *p_p, int i);
void				otmena(t_printf *p_p);
int					print_args(const char *format, t_printf *p_p, va_list args);
void				null_struct(t_printf *p_p);
void				print_str(t_printf *p_p, va_list args);
long long			get_number(t_printf *p_p, va_list ap);
void				print_number(t_printf *p_p, va_list ap);
unsigned long long	get_unsigned_number(t_printf *p_p, va_list ap);
char				*print_uns_decimal(t_printf *p_p, va_list ap);
char				*num_precision(char *str, t_printf *p_p);
void				ft_putcharc(char c, t_printf *p_p);
char				ft_putstrc(char const *s, t_printf *p_p);
char				*print_octimal(t_printf *p_p, va_list ap);
char				*print_hex(t_printf *p_p, va_list ap);
char				*convert_wstrtostr(wchar_t *str, int max_len);
char				*convert_winttostr(wint_t wint);
char				*generate_wint(wint_t wint, int len);
char				*print_binary(t_printf *p_p, va_list ap);
char				*ft_uns_itoa_base1(unsigned long long value, int base);
void				min(t_printf *p_p, va_list args);
char				*add_min_width(t_printf *p_p, char *str);
char				*ft_uns_itoa_base(unsigned long long value, int base);
char				*ft_uns_itoa_base1(unsigned long long value, int base);
void				min2(t_printf *p_p, char *str, char *tmp);
void				min3(t_printf *p_p, char *str, char **tmp);
void				min4(t_printf *p_p, char *str, char **tmp);
void				min5(t_printf *p_p, long long int *nbr);
void				min6(t_printf *p_p, long long int *nbr, char **str);
void				min7(t_printf *p_p, unsigned long long int *nbr,
										char **str);
void				min8(t_printf *p_p, char *str);
char				*print_decimal(t_printf *p_p, va_list ap);
void				parse_flags(char *format, int i, t_printf *p_p);
void				parse_width(char *format, int i, t_printf *p_p);
void				parse_precision(char *format, int i, t_printf *p_p);
int					parse_size_1(char *format, int i, t_printf *p_p);
int					parse_size_2(char *format, int i, t_printf *p_p);
int					parse_specif(char *format, t_printf *p_p, int i);
char				*min10(char *str, t_printf *p_p);
char				*min11(t_printf *p_p, char **str,
								unsigned long long int nbr);
char				*min15(t_printf *p_p, char **res, char **tmp, char *str);

#endif
