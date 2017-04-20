/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:36:51 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:58:02 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_size_1(char *format, int i, t_printf *p_p)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		p_p->size = 1;
		i += 2;
	}
	if (format[i] == 'h')
	{
		p_p->size = 6;
		i++;
	}
	if (format[i] == 'l' && format[i + 1] != 'l')
	{
		p_p->size = 2;
		i++;
	}
	if (format[i] == 'l' && format[i + 1] == 'l')
	{
		p_p->size = 3;
		i += 2;
	}
	return (i);
}

int		parse_size_2(char *format, int i, t_printf *p_p)
{
	if (format[i] == 'j')
	{
		p_p->size = 4;
		i++;
	}
	if (format[i] == 'z')
	{
		p_p->size = 5;
		i++;
	}
	return (i);
}
