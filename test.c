/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 15:50:19 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int nb = 123;
	char str[] = "123";

	printf("\033[34;31m%%d:\n");
	printf("%%d:   %d\n",	nb);
	printf("%%+d:  %+d\n",	nb);
	printf("%%0+d:  %0+d\n",	nb);
	printf("%%-d:  %-d\n",	nb);
	printf("%%0d:  %0d\n",	nb);
	printf("%%.5d: %.5d\n", nb);
	printf("%%.2d: %.2d\n", nb);
	printf("%%5d:  %5d\n", nb);
	printf("%%2d:  %2d\n", nb);

	printf("\n\033[34;32m%%s:\n");
	printf("%%s:   %s\n",	str);
	printf("%%.2s: %.2s\n",	str);
	printf("%%.5s: %.5s\n",	str);
	printf("%%2s:  %2s\n",	str);
	printf("%%5s:  %5s\n",	str);

	printf("\n\033[34;33m%%p:\n");
	printf("%%p:   %p\n",	str);

	printf("%%x:   %x\n",	nb);
	printf("%%x:   %x\n",	-nb);
	printf("%%x:   %x\n",	-nb - 8 );

	//printf("%%u:   %+u\n",	nb);
/*	printf("%%llu:   %llu\n",	nb);
	printf("%%o:   %o\n",	nb);
	printf("%%x:   %x\n",	nb);
	printf("%%X:   %X\n",	nb);
	printf("%%llx:   %llx\n",	nb);
	printf("%%llX:   %llX\n",	nb);*/
/*	printf("\n\033[34;33m%%hh:\n");
	printf("%%hd:  %hd\n",	'a');
	printf("%%hhd: %hhd\n",	'a');
	printf("%%hi:  %hi\n",	'a');
	printf("%%hhi: %hhi\n",	'a');
	printf("%%ho:  %ho\n",	'a');
	printf("%%hho: %hho\n",	'a');
	printf("%%hu:  %hu\n",	'a');
	printf("%%hhu: %hhu\n",	'a');
	printf("%%hx:  %hx\n",	'a');
	printf("%%hhx: %hhx\n",	'a');
	printf("%%hX:  %hX\n",	'a');
	printf("%%hhX: %hhX\n",	'a');

	printf("\n\033[34;33m%%ll:\n");
	printf("%%ld:  %ld\n",	'a');
	printf("%%lld: %lld\n",	'a');
	printf("%%li:  %li\n",	'a');
	printf("%%lli: %lli\n",	'a');
	printf("%%lo:  %lo\n",	'a');
	printf("%%llo: %llo\n",	'a');
	printf("%%lu:  %lu\n",	'a');
	printf("%%llu: %llu\n",	'a');
	printf("%%lx:  %lx\n",	'a');
	printf("%%llx: %llx\n",	'a');
	printf("%%lX:  %lX\n",	'a');
	printf("%%llX: %llX\n",	'a');*/

}
