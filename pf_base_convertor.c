/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:17:43 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/29 13:32:51 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*pf_itoa_base(t_printf *lst, long long n, int base)
{
	char		*ptr;
	long long	nb;
	int		length;
	int		i;

	nb = (n < 0) ? -n : n;
	length = nb;
	i = (n < 0) ? 2 : 1;
	while (length /= base)
		++i;
	if (!(ptr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		if (lst->type == 'x')
			ptr[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base + 'a' - 10);
		else if (lst->type == 'X')
			ptr[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base + 'A' - 10);
		nb /= base;
	}
	if (i && n < 0)
		ptr[0] = '-';
	return (ptr);
}

int		main(void)
{
	t_printf *test;

	test = malloc(sizeof(*test));

	test->type = 'X';
	printf("%s\n", pf_itoa_base(test, 4779, 16));

	return (0);
}
