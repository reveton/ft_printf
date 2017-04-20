/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_null_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:27:52 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 18:11:02 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*create_struct(void)
{
	t_printf *p_p;

	p_p = (t_printf *)malloc(sizeof(t_printf));
	p_p->specificator = '\0';
	p_p->flag_minus = 0;
	p_p->flag_plus = 0;
	p_p->flag_space = 0;
	p_p->flag_null = 0;
	p_p->flag_hash = 0;
	p_p->width = 0;
	p_p->precision = -1;
	p_p->check = 0;
	p_p->size = 0;
	p_p->check_pr = 0;
	p_p->zero = 0;
	return (p_p);
}

void		null_struct(t_printf *p_p)
{
	p_p->specificator = '\0';
	p_p->flag_minus = 0;
	p_p->flag_plus = 0;
	p_p->flag_space = 0;
	p_p->flag_null = 0;
	p_p->flag_hash = 0;
	p_p->width = 0;
	p_p->precision = -1;
	p_p->size = 0;
	p_p->check = 0;
	p_p->check_pr = 0;
	p_p->zero = 0;
}

char		*min11(t_printf *p_p, char **str, unsigned long long int nbr)
{
	if (nbr != 0)
		*str = ft_uns_itoa_base(nbr, 8);
	else if (nbr == 0 && p_p->precision != -1 && !p_p->flag_hash)
		*str = ft_strdup("");
	else if (nbr == 0 && p_p->flag_hash)
		*str = ft_strdup("0");
	else
		*str = ft_uns_itoa_base(nbr, 8);
	return (*str);
}
