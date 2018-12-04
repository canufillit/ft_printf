/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/04 11:28:09 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
//	int nb = 123;
//	char str[] = "123";
//	int i;
//	char *s;
//	unsigned long ll;
//
//
//	int nb2 = ft_printf("% Zoooo");
//	printf("%d\n", nb2);
//
//  %p
//	ft_printf("%p\n", &i);
//	ft_printf("%p\n", s);
//	ft_printf("%p\n", &ll);
//	ft_printf("%p\n", ft_printf);
//	ft_printf("%p\n", 0);
//	printf("\n\n");
//	printf("%p\n", &i);
//	printf("%p\n", s);
//	printf("%p\n", &ll);
//	printf("%p\n", ft_printf);
//	printf("%p\n", NULL);
//	ft_printf("%%p:   %p\n",	str);
//	ft_printf("%%p:   %p\n", addr);
//	ft_printf("%%p:   %p\n", NULL);
//	printf("%%p:   %p\n", NULL);
//	printf("%%p:   %p\n", str);
//	printf("%%p:   %p\n", addr);
//	ft_printf("{%%5p}: {%5p}", 0);
//
//	%d
//	ft_printf("\033[34;31m%%d:\n");
//	ft_printf("%5%\n");
//	ft_printf("%%d:   %d\n",	nb);
//	ft_printf("%%+d:  %+d\n",	nb);
//	ft_printf("%%0+d:  %0+d\n",	nb);
//	ft_printf("%%-d:  %-d\n",	nb);
//	ft_printf("%%0d:  %0d\n",	nb);
//	ft_printf("%%.5d: %.5d\n", nb);
//	ft_printf("%%.2d: %.2d\n", nb);
//	ft_printf("%%5d:  %5d\n", nb);
//	ft_printf("%%2d:  %2d\n", nb);
//	ft_printf("%%7.5#X:  %7.5#X\n", nb);
//	ft_printf("%%#x:  %#x\n", nb);
//	ft_printf("%%-10.5o: |%-10.5o|\n", 2500);
//	printf("%%-10.5o: |%-10.5o|\n", 2500);
//	ft_printf("%%08x: %08x\n", 42);
//	ft_printf("%%5.d: %0.5d\n", -1);
//	ft_printf("%%2.d: %0.2d\n", -1);
//	ft_printf("%%-+10.5d: %-+10.5d\n", 4242);
//	ft_printf("%% 5.5d: % 5.5d\n", 16);
//	ft_printf("%% 5d: % 5d\n", 16);
//	ft_printf("%%d: %d\n", -123);
//	ft_printf("%%+d: %+d\n", 123);
//	ft_printf("%%.d: %.d\n", nb);
ft_printf("%d %d %d %d\n", 1, -2, 33, 42);
//
//	%s
//	ft_printf("\n\033[34;32m%%s:\n");
//	ft_printf("%%s: %s\n",	"abc");
//	ft_printf("%%.2s: %.2s\n",	str);
//	ft_printf("%%-15s: |%-15s|\n",	str);
//	ft_printf("%%5.2s: |%5.2s|\n",str);
//	ft_printf("%%2.2s: |%2.2s|\n",str);
//	ft_printf("%%.5s: %.5s\n",	str);
//	ft_printf("%%2s:  %2s\n",	str);
//	ft_printf("%%5s:  %5s\n",	str);
//
//	%%
//	ft_printf("%");
//	ft_printf("\n\033[34;33m%%c:\n");
//	ft_printf("%%    %%: %     %\n");
//	ft_printf("%%5%%: %5%\n");
//	ft_printf("%%-5%%: %-5%\n");
//	ft_printf("%%.0%%: %.0%\n");
//	ft_printf("%%   %%: %   %\n", "test");
//
//	%c
//	ft_printf("%%c: %c\n", 42);
//	ft_printf("%%c: %5c\n", 42);
//	ft_printf("%%5c: %5c\n", 42);
//	ft_printf("%%c: %c\n", 0);
//	ft_printf("%%c: %5c\n", 0);
//	ft_printf("%%5c: %5c\n", 0);
//
//	%x
//	ft_printf("%%x:   %x\n",	nb);
//	ft_printf("%%x:   %x\n",	-nb);
//	ft_printf("%%x:   %x\n",	-nb - 8 );
//	ft_printf("%%x: %x\n", &str);
//	ft_printf("%%x: %x\n", addr);
//	ft_printf("%%x:   %x\n",	-nb - 8 );
//
//	%b
//	ft_printf("%%b:\n");
//	ft_printf("%%b: %b\n", 123);
ft_printf("%jd\n", -4294967296);
ft_printf("%jx\n", -4294967296);
printf("%jx\n",    -4294967296);
}
