/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:11:27 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 16:30:06 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min2(t_printf *p_p, char *str, char *tmp)
{
	int i;

	i = 0;
	p_p->precision = p_p->precision - (int)ft_strlen(str);
	while (i < p_p->precision)
		tmp[i++] = '0';
	tmp[i] = '\0';
}

void	min3(t_printf *p_p, char *str, char **tmp)
{
	if (p_p->precision && (p_p->precision <= (int)ft_strlen(str)))
		p_p->check_pr = 1;
	else
		p_p->check_pr = 0;
	if (p_p->precision == -1)
	{
		p_p->precision = 0;
		*tmp = ft_strnew((size_t)p_p->precision);
	}
	else
		*tmp = ft_strnew((size_t)p_p->precision);
}

void	min4(t_printf *p_p, char *str, char **tmp)
{
	if (p_p->precision != -1 && p_p->specificator == 'p' && p_p->check_pr)
		*tmp = ft_strjoin("0x", ft_strjoin(str, *tmp));
	else if (p_p->precision != -1 && p_p->specificator == 'p' && !p_p->check_pr)
		*tmp = ft_strjoin("0x", ft_strjoin(*tmp, str));
	else if (p_p->check == 1 && !p_p->check_pr)
		*tmp = ft_strjoin(ft_strjoin("-", *tmp), str);
	else if (p_p->flag_hash && p_p->specificator == 'o' && p_p->precision == -1)
		*tmp = ft_strjoin(ft_strjoin("0", *tmp), str);
	else if (p_p->specificator == 'x' && p_p->flag_hash
			&& !p_p->flag_null && p_p->precision != -1)
		*tmp = ft_strjoin("0x", ft_strjoin(*tmp, str));
	else
		*tmp = ft_strjoin(*tmp, str);
}

void	min5(t_printf *p_p, long long int *nbr)
{
	*nbr *= -1;
	p_p->check = 1;
}

void	min6(t_printf *p_p, long long int *nbr, char **str)
{
	if (*nbr >= 0 && p_p->flag_plus
			&& p_p->check != 1
			&& p_p->specificator != 'o' && !p_p->flag_null
			&& p_p->precision == -1)
		*str = ft_strjoin("+", *str);
	else if (*nbr >= 0 && p_p->flag_plus && p_p->check != 1
			&& p_p->specificator != 'o'
			&& p_p->flag_null && p_p->precision == -1 && *str[0] != '0'
			&& p_p->specificator != 'd' && p_p->specificator != 'i')
		*str = ft_strjoin("+", *str);
	else if (*nbr >= 0 && p_p->flag_plus && p_p->check != 1
			&& p_p->specificator != 'o'
			&& !p_p->flag_null && p_p->precision != -1)
		*str = ft_strjoin("+0", *str);
	else if (p_p->flag_space && !p_p->check
			&& p_p->flag_null && p_p->width)
		*str = ft_strjoin(" 0", *str);
	else if (p_p->flag_space && !p_p->check
			&& !p_p->flag_null && !p_p->width)
		*str = ft_strjoin(" ", *str);
}
