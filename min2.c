/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:33:39 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:30:57 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min7(t_printf *p_p, unsigned long long int *nbr, char **str)
{
	if (p_p->specificator == 'X' && *nbr != 0)
	{
		*str = ft_uns_itoa_base(*nbr, 16);
		if (p_p->flag_hash && p_p->specificator == 'X' && !p_p->flag_null)
			*str = ft_strjoin("0X", *str);
	}
	else if (p_p->specificator == 'x' && *nbr != 0)
	{
		*str = ft_uns_itoa_base1(*nbr, 16);
		if (p_p->specificator == 'x' && p_p->flag_hash
				&& !p_p->flag_null && p_p->precision == -1)
			*str = ft_strjoin("0x", *str);
	}
}
