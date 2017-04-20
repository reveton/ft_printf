/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:00:53 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 17:35:32 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*check_flag_null(char *str, char *tmp, t_printf *p_p)
{
	char	*res;

	if (p_p->flag_plus && !p_p->check)
		res = ft_strjoin(ft_strjoin("+", tmp + 1), str);
	else if (p_p->width && p_p->check)
		res = ft_strjoin(ft_strjoin("-", tmp), str + 1);
	else if (p_p->specificator == 'x' && p_p->flag_hash)
		res = ft_strjoin(ft_strjoin("0x", tmp + 2), str);
	else if (p_p->specificator == 'b')
		res = ft_strjoin(ft_strjoin("0b", tmp), str);
	else
		res = ft_strjoin(tmp, str);
	return (res);
}

char			*add_min_width(t_printf *p_p, char *str)
{
	char	*tmp;
	char	*res;
	int		i;

	if ((p_p->width > 0) && (p_p->width >= (int)ft_strlen(str)))
	{
		p_p->width = p_p->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)p_p->width);
		i = -1;
		while (++i < p_p->width)
		{
			if (p_p->flag_null && p_p->precision < 0)
				tmp[i] = '0';
			else
				tmp[i] = ' ';
		}
		tmp[i] = '\0';
		res = min15(p_p, &res, &tmp, str);
		return (res);
	}
	else if (p_p->width > 0 && (p_p->width < (int)ft_strlen(str)))
		if (p_p->flag_plus)
			str = ft_strjoin("+", str);
	return (str);
}

char			*min15(t_printf *p_p, char **res, char **tmp, char *str)
{
	if (p_p->flag_null)
		*res = check_flag_null(str, *tmp, p_p);
	else if (p_p->flag_minus && p_p->specificator != 'p')
		*res = ft_strjoin(str, *tmp);
	else if (p_p->specificator == 'p'
			&& p_p->precision != -1
			&& p_p->width && !p_p->flag_null)
		*res = ft_strjoin(*tmp + 2, ft_strjoin("0x", str));
	else if (p_p->specificator == 'p'
			&& p_p->precision == -1
			&& p_p->width && !p_p->flag_null && !p_p->flag_minus)
		*res = ft_strjoin(*tmp + 2, ft_strjoin("0x", str));
	else if (p_p->specificator == 'p'
			&& p_p->precision == -1
			&& !p_p->flag_null && p_p->flag_minus)
		*res = ft_strjoin(ft_strjoin("0x", str), *tmp + 2);
	else
		*res = ft_strjoin(*tmp, str);
	return (*res);
}
