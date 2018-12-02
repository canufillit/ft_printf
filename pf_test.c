/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/02 15:35:52 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int nb = 123;
	char str[] = "123";
	void *addr;

	addr = malloc(12);
	ft_printf("\033[34;31m%%d:\n");
	ft_printf("%%d:   %d\n",	nb);
	ft_printf("%%+d:  %+d\n",	nb);
	ft_printf("%%0+d:  %0+d\n",	nb);
	ft_printf("%%-d:  %-d\n",	nb);
	ft_printf("%%0d:  %0d\n",	nb);
	ft_printf("%%.5d: %.5d\n", nb);
	ft_printf("%%.2d: %.2d\n", nb);
	ft_printf("%%5d:  %5d\n", nb);
	ft_printf("%%2d:  %2d\n", nb);

	ft_printf("\n\033[34;32m%%s:\n");
	ft_printf("%%s:   %s\n",	str);
	ft_printf("%%.2s: %.2s\n",	str);
	ft_printf("%%5.2s: |%5.2s|\n",str);
	ft_printf("%%2.2s: |%2.2s|\n",str);
	ft_printf("%%.5s: %.5s\n",	str);
	ft_printf("%%2s:  %2s\n",	str);
	ft_printf("%%5s:  %5s\n",	str);

	ft_printf("\n\033[34;33m%%p:\n");
	ft_printf("%%p:   %p\n",	str);

	ft_printf("%%x:   %x\n",	nb);
	ft_printf("%%x:   %x\n",	-nb);
	ft_printf("%%x:   %x\n",	-nb - 8 );
	ft_printf("%%x: %x\n", &str);
	ft_printf("%%x: %x\n", addr);
	printf("%%p:   %p\n", str);
	printf("%%p:   %p\n", addr);

	//ft_printf("%%u:   %+u\n",	nb);
/*	ft_printf("%%llu:   %llu\n",	nb);
	ft_printf("%%o:   %o\n",	nb);
	ft_printf("%%x:   %x\n",	nb);
	ft_printf("%%X:   %X\n",	nb);
	ft_printf("%%llx:   %llx\n",	nb);
	ft_printf("%%llX:   %llX\n",	nb);*/
/*	ft_printf("\n\033[34;33m%%hh:\n");
	ft_printf("%%hd:  %hd\n",	'a');
	ft_printf("%%hhd: %hhd\n",	'a');
	ft_printf("%%hi:  %hi\n",	'a');
	ft_printf("%%hhi: %hhi\n",	'a');
	ft_printf("%%ho:  %ho\n",	'a');
	ft_printf("%%hho: %hho\n",	'a');
	ft_printf("%%hu:  %hu\n",	'a');
	ft_printf("%%hhu: %hhu\n",	'a');
	ft_printf("%%hx:  %hx\n",	'a');
	ft_printf("%%hhx: %hhx\n",	'a');
	ft_printf("%%hX:  %hX\n",	'a');
	ft_printf("%%hhX: %hhX\n",	'a');

	ft_printf("\n\033[34;33m%%ll:\n");
	ft_printf("%%ld:  %ld\n",	'a');
	ft_printf("%%lld: %lld\n",	'a');
	ft_printf("%%li:  %li\n",	'a');
	ft_printf("%%lli: %lli\n",	'a');
	ft_printf("%%lo:  %lo\n",	'a');
	ft_printf("%%llo: %llo\n",	'a');
	ft_printf("%%lu:  %lu\n",	'a');
	ft_printf("%%llu: %llu\n",	'a');
	ft_printf("%%lx:  %lx\n",	'a');
	ft_printf("%%llx: %llx\n",	'a');
	ft_printf("%%lX:  %lX\n",	'a');
	ft_printf("%%llX: %llX\n",	'a');*/

}
