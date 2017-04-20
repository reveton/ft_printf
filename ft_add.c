/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:52:54 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/17 15:01:54 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharc(char c, t_printf *p_p)
{
	write(1, &c, 1);
	p_p->count++;
}

char	ft_putstrc(char const *s, t_printf *p_p)
{
	size_t i;

	i = 0;
	if (s[0] == '\0')
		return (-1);
	while (s[i])
	{
		ft_putcharc(s[i], p_p);
		i++;
	}
	return (0);
}

char	*ft_uns_itoa_base(unsigned long long value, int base)
{
	char				*str;
	int					i;
	unsigned long long	tmp;
	char				*b;

	b = "0123456789ABCDEF";
	i = 1;
	tmp = value;
	while (value /= base)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = b[tmp % base];
		tmp /= base;
	}
	return (str);
}

char	*ft_uns_itoa_base1(unsigned long long value, int base)
{
	char				*str;
	int					i;
	unsigned long long	tmp;
	char				*b;

	b = "0123456789abcdef";
	i = 1;
	tmp = value;
	while (value /= base)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = b[tmp % base];
		tmp /= base;
	}
	return (str);
}

void	otmena(t_printf *p_p)
{
	if (p_p->flag_plus == 1)
		p_p->flag_space = 0;
	if (p_p->flag_minus == 1)
		p_p->flag_null = 0;
	if (ft_strchr("pbdioOuxXUD", p_p->specificator))
	{
		if (p_p->precision != -1)
			p_p->flag_null = 0;
	}
}
