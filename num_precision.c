/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:36:45 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:33:06 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*num_precision(char *str, t_printf *p_p)
{
	int		prec;
	char	*tmp;

	prec = p_p->precision;
	min3(p_p, str, &tmp);
	p_p->precision = prec;
	if (p_p->precision && p_p->precision > (int)ft_strlen(str))
	{
		min2(p_p, str, tmp);
		min4(p_p, str, &tmp);
		return (tmp);
	}
	else if (prec < (int)ft_strlen(str))
		str = min10(str, p_p);
	return (str);
}

char	*min10(char *str, t_printf *p_p)
{
	if (p_p->check)
		str = ft_strjoin("-", str);
	if (p_p->flag_hash
			&& (p_p->specificator == 'o'
				|| p_p->specificator == 'O')
			&& p_p->precision != 0 && str[0] != '0')
		str = ft_strjoin("0", str);
	if (p_p->flag_plus && !p_p->check
			&& p_p->flag_null && p_p->zero != 1)
		return (str);
	else if (p_p->flag_plus && !p_p->check
			&& p_p->flag_null && p_p->zero == 1)
		return (str);
	return (str);
}

char	*print_binary(t_printf *p_p, va_list ap)
{
	char					*str;
	unsigned long long int	nbr;

	nbr = get_unsigned_number(p_p, ap);
	str = ft_uns_itoa_base(nbr, 2);
	return (str);
}
