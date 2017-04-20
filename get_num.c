/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:46:15 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/17 15:50:00 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			get_number(t_printf *p_p, va_list ap)
{
	long long int nbr;

	if (p_p->size == 1 && p_p->specificator != 'D')
		nbr = (signed char)va_arg(ap, int);
	else if (p_p->size == 6 && p_p->specificator != 'D')
		nbr = (short)va_arg(ap, int);
	else if (p_p->size == 2)
		nbr = (long)va_arg(ap, long int);
	else if (p_p->size == 3)
		nbr = (long long)va_arg(ap, long long int);
	else if (p_p->size == 4)
		nbr = (intmax_t)va_arg(ap, intmax_t);
	else if (p_p->size == 5)
		nbr = (ssize_t)va_arg(ap, ssize_t);
	else if (p_p->specificator == 'D')
		nbr = (long)va_arg(ap, long int);
	else
		nbr = (int)va_arg(ap, int);
	return (nbr);
}

unsigned long long	get_unsigned_number(t_printf *p_p, va_list ap)
{
	unsigned long long int nbr;

	if (p_p->size == 1 && p_p->specificator != 'O')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (p_p->size == 6)
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (p_p->size == 2)
		nbr = (unsigned long)va_arg(ap, unsigned long int);
	else if (p_p->size == 3)
		nbr = (unsigned long long)va_arg(ap, unsigned long long int);
	else if (p_p->size == 4 || p_p->specificator == 'p')
		nbr = (uintmax_t)va_arg(ap, uintmax_t);
	else if (p_p->size == 5)
		nbr = (size_t)va_arg(ap, size_t);
	else
		nbr = (unsigned int)va_arg(ap, unsigned int);
	return (nbr);
}
