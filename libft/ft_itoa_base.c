/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:43:47 by afomenko          #+#    #+#             */
/*   Updated: 2017/04/20 17:44:20 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(long long value, int b, char *result, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (value <= -b || b <= value)
		aux(value / b, b, result, i);
	result[(*i)++] = base[value % b];
}

char		*ft_itoa_base(long long value, int base)
{
	long long	v;
	long long	tmp;
	int			len;
	int			i;
	char		*result;

	if (value == (long long)-9223372036854775808LLU)
		return (ft_strdup("-9223372036854775808"));
	tmp = value;
	len = 1;
	while ((tmp /= base))
		len++;
	v = value;
	if (v < 0)
	{
		len = base == 10 ? len + 1 : len;
		v = -v;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (value < 0 && base == 10)
		result[i++] = '-';
	aux(v, base, result, &i);
	result[i] = '\0';
	return (result);
}
