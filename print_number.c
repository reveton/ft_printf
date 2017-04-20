/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:02:42 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:59:39 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number(t_printf *p_p, va_list ap)
{
	char *str;

	str = ft_strdup("");
	if (p_p->specificator == 'd' ||
			p_p->specificator == 'i' || p_p->specificator == 'D')
		str = print_decimal(p_p, ap);
	else if (p_p->specificator == 'u' || p_p->specificator == 'U')
		str = print_uns_decimal(p_p, ap);
	else if (p_p->specificator == 'o' || p_p->specificator == 'O')
		str = print_octimal(p_p, ap);
	else if (p_p->specificator == 'x'
			|| p_p->specificator == 'p' || p_p->specificator == 'X')
		str = print_hex(p_p, ap);
	else if (p_p->specificator == 'b')
		str = print_binary(p_p, ap);
	str = num_precision(str, p_p);
	str = add_min_width(p_p, str);
	ft_putstrc(str, p_p);
	free(str);
}

char	*print_uns_decimal(t_printf *p_p, va_list ap)
{
	char					*str;
	unsigned long long int	nbr;

	nbr = 0;
	if (p_p->specificator == 'u')
		nbr = get_unsigned_number(p_p, ap);
	else if (p_p->specificator == 'U')
	{
		nbr = (unsigned long)va_arg(ap, unsigned long int);
		str = ft_uns_itoa_base((unsigned long)nbr, 10);
		return (str);
	}
	if (nbr == 0 && p_p->precision != -1)
		str = ft_strdup("");
	else
		str = ft_uns_itoa_base(nbr, 10);
	return (str);
}

char	*print_octimal(t_printf *p_p, va_list ap)
{
	char					*str;
	unsigned long long int	nbr;

	if (p_p->specificator == 'O' && p_p->size == 0)
	{
		nbr = (long)get_unsigned_number(p_p, ap);
		if (nbr == 0 && p_p->precision == 0 && !p_p->flag_hash)
			str = ft_strdup("");
		else if (nbr == 4294967295)
			str = ft_strdup("777777777777777777777");
		else
			str = ft_uns_itoa_base(nbr, 8);
		return (str);
	}
	else if (p_p->specificator == 'O' && p_p->size == 1)
		nbr = (unsigned int)get_unsigned_number(p_p, ap);
	else
		nbr = get_unsigned_number(p_p, ap);
	min11(p_p, &str, nbr);
	return (str);
}

char	*print_hex(t_printf *p_p, va_list ap)
{
	char					*str;
	unsigned long long int	nbr;

	nbr = get_unsigned_number(p_p, ap);
	if (nbr != 0)
		str = ft_uns_itoa_base1(nbr, 16);
	else if (nbr == 0 && p_p->precision)
		str = ft_strdup("0");
	min7(p_p, &nbr, &str);
	if (p_p->specificator == 'p'
			&& p_p->precision == -1
			&& !p_p->width && !p_p->flag_null)
		str = ft_strjoin("0x", str);
	else if (p_p->specificator == 'p'
			&& p_p->precision == 0
			&& !p_p->width && !p_p->flag_null)
		str = ft_strjoin("0x", str);
	else if (p_p->precision == 0 && nbr != 0)
		str = ft_strdup("");
	return (str);
}

char	*print_decimal(t_printf *p_p, va_list ap)
{
	char			*str;
	long long int	nbr;

	nbr = get_number(p_p, ap);
	if (nbr == 0)
		p_p->zero = 1;
	if (nbr == (long long)-9223372036854775808LLU)
		ft_strdup("9223372036854775808");
	else if (nbr < 0)
		min5(p_p, &nbr);
	str = ft_itoa_base(nbr, 10);
	min6(p_p, &nbr, &str);
	if (str[0] == '0' && p_p->precision != -1)
		str = ft_strdup("");
	return (str);
}
