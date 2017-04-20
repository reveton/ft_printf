/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:21:42 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/17 15:24:37 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_precision(char *str, t_printf *p_p)
{
	int		i;
	char	*tmp;

	i = 0;
	if (p_p->precision >= 0 && (p_p->precision < (int)ft_strlen(str)))
	{
		tmp = ft_strnew((size_t)p_p->precision);
		while (i < p_p->precision)
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (str);
}

char	*str_width(char *str, t_printf *p_p)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((p_p->width > 0) && (p_p->width > (int)ft_strlen(str)))
	{
		p_p->width = p_p->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)p_p->width);
		while (i < p_p->width)
		{
			if (p_p->flag_null == 1)
				tmp[i] = '0';
			else
				tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		if (p_p->flag_minus == 1)
			str = ft_strjoin(str, tmp);
		else
			str = ft_strjoin(tmp, str);
		free(tmp);
	}
	return (str);
}

void	print_str(t_printf *p_p, va_list arg)
{
	char *str;

	if (p_p->size == 2)
		str = convert_wstrtostr(va_arg(arg, wchar_t *), p_p->precision);
	else
		str = va_arg(arg, char *);
	if (!str)
		str = ft_strdup("(null)");
	if (str == NULL)
		str = ft_strdup("(null)");
	else if (p_p->specificator == 'S' && str[0] != '\0')
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = str_precision(str, p_p);
	str = str_width(str, p_p);
	ft_putstrc(str, p_p);
}
