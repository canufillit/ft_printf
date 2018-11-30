/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:17:43 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/30 11:59:43 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static char		*pf_signed_itoa_base(t_printf *lst, long long n, int base)
{
	char				*ptr;
	unsigned long long	nb;
	long long			length;
	int					i;

	(void)lst;
	i = 0;
	nb = (n < 0) ? (-n) : n; 
	length = nb;
	i = (n < 0 && base == 10) ? 2 : 1;
	while (length /= base)
		++i;
	if (!(ptr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		ptr[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base + 'A' - 10);
		nb /= base;
	}
	if (i && n < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}

static char		*pf_unsigned_itoa_base(t_printf *lst, unsigned long long n, int base)
{
	char				*ptr;
	unsigned long long	nb;
	int					i;

	(void)lst;
	i = 1;
	nb = n;
	while (nb /= base)
		++i;
	if (!(ptr = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		ptr[i] = (n % base < 10) ? (n % base + '0') : (n % base + 'A' - 10);
		n /= base;
	}
	return (ptr);
}

int		main(void)
{
	t_printf *test;
	test = malloc(sizeof(*test));

	printf("LONG MAX - BASE 8\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MAX, 8));
	printf("%lo\n", LONG_MAX);
	printf("---------------------------\n");

	printf("LONG MIN - BASE 8\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MIN, 8));
	printf("%lo\n", LONG_MIN);
	printf("---------------------------\n");

	printf("UNSIGNED LONG MIN - BASE 8\n");
	printf("---------------------------\n");
	printf("%s\n", pf_unsigned_itoa_base(test, ULONG_MAX, 8));
	printf("%lo\n", ULONG_MAX);
	printf("---------------------------\n");

	printf("LONG MAX - BASE 10\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MAX, 10));
	printf("%ld\n", LONG_MAX);
	printf("---------------------------\n");

	printf("LONG MIN - BASE 10\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MIN, 10));
	printf("%ld\n", LONG_MIN);
	printf("---------------------------\n");

	printf("UNSIGNED LONG MIN - BASE 10\n");
	printf("---------------------------\n");
	printf("%s\n", pf_unsigned_itoa_base(test, ULONG_MAX, 10));
	printf("%lu\n", ULONG_MAX);
	printf("---------------------------\n");

	printf("LONG MAX - BASE 16\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MAX, 16));
	printf("%lX\n", LONG_MAX);
	printf("---------------------------\n");

	printf("LONG MIN - BASE 16\n");
	printf("---------------------------\n");
	printf("%s\n", pf_signed_itoa_base(test, LONG_MIN, 16));
	printf("%lX\n", LONG_MIN);
	printf("---------------------------\n");

	printf("UNSIGNED LONG MIN - BASE 16\n");
	printf("---------------------------\n");
	printf("%s\n", pf_unsigned_itoa_base(test, ULONG_MAX, 16));
	printf("%lX\n", ULONG_MAX);
	printf("---------------------------\n");

	return (0);
}
