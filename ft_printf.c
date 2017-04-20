/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:44:15 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:06:50 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_printf	*p_p;

	if (!format)
		return (-1);
	p_p = create_struct();
	va_start(args, format);
	print_args(format, p_p, args);
	va_end(args);
	return (p_p->count);
}

int		ft_parse(const char *format, t_printf *p_p, int i)
{
	char c;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i = parse_ft(format, p_p, i);
			otmena(p_p);
			if (p_p->specificator == '%' && !p_p->width)
				ft_putcharc('%', p_p);
			else if (p_p->specificator == '%' && p_p->width != 0)
			{
				c = '%';
				width_chr(c, p_p);
			}
			break ;
		}
		i++;
	}
	return (i);
}

int		print_args(const char *format, t_printf *p_p, va_list args)
{
	int i;

	i = 0;
	if (format[0] == '\0')
		ft_strdup("(null)");
	while (format[i])
	{
		if (format[i] == '%' && ft_strlen(format) == 1)
			return (0);
		if (format[i] == '%')
		{
			i = ft_parse(format, p_p, i);
			min(p_p, args);
		}
		else
			ft_putcharc(format[i], p_p);
		i++;
	}
	return (i);
}

void	min(t_printf *p_p, va_list args)
{
	char c;

	if (ft_strchr("C", p_p->specificator))
		p_p->specificator = (char)ft_tolower(p_p->specificator);
	if (p_p->specificator)
	{
		if (p_p->specificator == 'c')
			print_chr(p_p, args);
		else if (p_p->specificator == 's' || p_p->specificator == 'S')
			print_str(p_p, args);
		else if (ft_strchr("pbdioOuxXUD", p_p->specificator))
			print_number(p_p, args);
		else if (!ft_strchr("hlzjpbdioOuxXUDCcs%", p_p->specificator))
		{
			c = (p_p->specificator);
			width_chr(c, p_p);
		}
		null_struct(p_p);
	}
}
