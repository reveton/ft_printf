/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:25:02 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/17 15:27:34 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_chr(char c, t_printf *p_p)
{
	int tmp;

	if (p_p->width > 1)
	{
		tmp = p_p->width - 1;
		if (p_p->flag_minus == 1)
			ft_putcharc(c, p_p);
		while (tmp > 0)
		{
			if (p_p->flag_null == 1)
				ft_putcharc('0', p_p);
			else
				ft_putcharc(' ', p_p);
			tmp--;
		}
		if (p_p->flag_minus != 1)
			ft_putcharc(c, p_p);
	}
	else
		ft_putcharc(c, p_p);
}

int		print_chr(t_printf *p_p, va_list args)
{
	char c;

	if (p_p->specificator == 'c' && p_p->size != 2)
		c = (char)va_arg(args, int);
	else if (p_p->specificator == 'c' && p_p->size == 2)
		c = (char)va_arg(args, wint_t);
	else
		c = p_p->specificator;
	width_chr(c, p_p);
	return (0);
}
