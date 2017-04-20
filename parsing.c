/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:38:11 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 17:40:32 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_ft(const char *format, t_printf *p_p, int i)
{
	int	zero;

	zero = 0;
	if (format[i] == '%')
	{
		i++;
		while (format[i])
		{
			if (format[i] == '0' && !ft_isdigit(format[i - 1])
					&& !zero && !p_p->width && format[i - 1] != '.')
			{
				p_p->flag_null = 1;
				zero = 1;
			}
			parse_flags((char *)format, i, p_p);
			parse_width((char *)format, i, p_p);
			parse_precision((char *)format, i, p_p);
			i = parse_size_1((char *)format, i, p_p);
			i = parse_size_2((char *)format, i, p_p);
			if (parse_specif((char *)format, p_p, i))
				break ;
			i++;
		}
	}
	return (i);
}

int		parse_specif(char *format, t_printf *p_p, int i)
{
	if (ft_isalpha(format[i]))
	{
		p_p->specificator = format[i];
		return (1);
	}
	else if (format[i] == '%')
	{
		p_p->specificator = format[i];
		return (1);
	}
	return (0);
}

void	parse_flags(char *format, int i, t_printf *p_p)
{
	if (format[i] == '+')
		p_p->flag_plus = 1;
	if (format[i] == '-')
		p_p->flag_minus = 1;
	if (format[i] == '#')
		p_p->flag_hash = 1;
	if (format[i] == ' ')
		p_p->flag_space = 1;
}

void	parse_width(char *format, int i, t_printf *p_p)
{
	if (ft_isdigit(format[i]) && !p_p->width && format[i - 1] != '.')
		p_p->width = ft_atoi(format + i);
}

void	parse_precision(char *format, int i, t_printf *p_p)
{
	if (format[i] == '.')
	{
		i++;
		p_p->precision = 0;
		if (ft_isdigit(format[i]))
			p_p->precision = ft_atoi(format + i);
	}
}
