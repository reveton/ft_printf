/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:11:00 by ohrechyn          #+#    #+#             */
/*   Updated: 2016/12/15 15:28:25 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help_itoa(int *tmp, int *tmp2, size_t *i, int n)
{
	*tmp = n;
	*tmp2 = n;
	*i = 1;
	while (*tmp /= 10)
		*i = *i + 1;
}

char		*ft_itoa(int n)
{
	size_t	i;
	char	*src;
	int		tmp;
	int		tmp2;

	help_itoa(&tmp, &tmp2, &i, n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (tmp2 < 0)
	{
		n *= -1;
		i++;
	}
	if ((src = (char *)malloc((sizeof(char) * i) + 1)) == 0)
		return (0);
	src[i] = '\0';
	while (i--)
	{
		if (i == 0 && tmp2 < 0)
			src[i] = '-';
		else
			src[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (src);
}
