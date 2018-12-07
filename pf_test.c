/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/07 15:11:17 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int nb = 123;
//	char str[] = "123";
//	int i;
//	unsigned long ll;
//	float fl = 75.5;
//	void *addr = ft_strdup("d");
//	char *s = ft_strdup("d");
//
//	ft_printf("%p\n", &i);
//	ft_printf("%p\n", s);
//	ft_printf("%p\n", &ll);
//	ft_printf("%p\n", ft_printf);
//	ft_printf("%p\n", 0);
//	ft_printf("%%p:   %p\n",	str);
//	ft_printf("%%p:   %p\n", addr);
//	ft_printf("%%p:   %p\n", NULL);
//	ft_printf("{%%5p}: {%5p}", 0);
//	ft_printf("pf|%#.o %#.0o|\n", 0, 0);
//	ft_printf("pf|%.o %.0o|\n", 0, 0);
//
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
	ft_printf("%%5.d: {% 03d}\n", 0);
	ft_printf("%%5.d: %0.5d\n", -1);
	ft_printf("%%2.d: %0.2d\n", -1);
	ft_printf("%%-+10.5d: %-+10.5d\n", 4242);
	ft_printf("%% 5.5d: % 5.5d\n", 16);
	ft_printf("%% 5d: % 5d\n", 16);
	ft_printf("%%d: %d\n", -123);
	ft_printf("%%+d: %+d\n", 123);
	ft_printf("%%.d: %.d\n", nb);
	ft_printf("%d %d %d %d\n", 1, -2, 33, 42);
	ft_printf("%d\n", -8882);
//
//	ft_printf("\n\033[34;32m%%s:\n");
//	ft_printf("lol%s\n", "15");
//	ft_printf("%%.2s: %.2s\n",	str);
//	ft_printf("%%-15s: |%-15s|\n",	str);
//	ft_printf("%%5.2s: |%5.2s|\n",str);
//	ft_printf("%%2.2s: |%2.2s|\n",str);
//	ft_printf("%%.5s: %.5s\n",	str);
//	ft_printf("%%2s:  %2s\n",	str);
//	ft_printf("%%5s:  %5s\n",	str);
//
//	ft_printf("%");
//	ft_printf("\n\033[34;33m%%c:\n");
//	ft_printf("%%    %%: %     %\n");
//	ft_printf("%%5%%: %5%\n");
//	ft_printf("%%-5%%: %-5%\n");
//	ft_printf("%%.0%%: %.0%\n");
//	ft_printf("%%   %%: %   %\n", "test");
//
//	ft_printf("%%c: %c\n", 42);
//	ft_printf("%%c: %5c\n", 42);
//	ft_printf("%%5c: %5c\n", 42);
//	ft_printf("%%c: %c\n", 0);
//	ft_printf("%%c: %5c\n", 0);
//	ft_printf("%%5c: %5c\n", 0);
//
//	ft_printf("%%x:   %x\n",	nb);
//	ft_printf("%%x:   %x\n",	-nb);
//	ft_printf("%%x:   %x\n",	-nb - 8 );
//	ft_printf("%%x: %x\n", &str);
//	ft_printf("%%x: %x\n", addr);
//	ft_printf("%%x:   %x\n",	-nb - 8 );
//
//	ft_printf("\033[34;31m%%d:\n");
//	ft_printf("%5%\n");
//	ft_printf("%%f:   %f\n",	fl);
//	ft_printf("%%+f:  %+f\n",	fl);
//	ft_printf("%%0+f:  %0+f\n",	fl);
//	ft_printf("%%-f:  %-f\n",	fl);
//	ft_printf("%%0f:  %0f\n",	fl);
//	ft_printf("%%.5f: %.5f\n", fl);
//	ft_printf("%%.2f: %.2f\n", fl);
//	ft_printf("%%5f:  %5f\n", fl);
//	ft_printf("%%2f:  %2f\n", fl);
//	ft_printf("%%7.5#f:  %7.5#f\n", fl);
//	ft_printf("%%#f:  %#f\n", fl);
//	ft_printf("%%-10.5f: |%-10.5f|\n", 2500);
//	ft_printf("%%-10.5f: |%-10.5f|\n", 2500);
//	ft_printf("%%08f: %08f\n", 42);
//	ft_printf("%%5.f: %0.5f\n", -1);
//	ft_printf("%%2.f: %0.2f\n", -1);
//	ft_printf("%%-+10.5f: %-+10.5f\n", 4242);
//	ft_printf("%% 5.5f: % 5.5f\n", 16);
//	ft_printf("%% 5f: % 5f\n", 16);
//	ft_printf("%%f: %f\n", -123);
//	ft_printf("%%+f: %+f\n", 123);
//	ft_printf("%%.f: %.f\n", fl);
//	ft_printf("%f %f %f %f\n", 1, -2, 33, 42);
//	ft_printf("%f\n", -1444565444646.6465424242242);
//
//	ft_printf("%%b:\n");
//	ft_printf("%%b: %b\n", 123);
//
//	ft_printf("%jd\n", -4294967296);
//	ft_printf("%jx\n", -4294967296);
//	ft_printf("{%%03c}: {%03c}\n", 0);
//	ft_printf("{%%05s}: {%05s}\n", "abc");
//	ft_printf("ft%%4.s: %4.s\n", "42");
//	ft_printf("%%.0p, %%.p: %.0p, %.p\n", 0, 0);
//	ft_printf("%%.p, %%.0p: %.p, %.0p\n", 0, 0);
//
//	ft_printf("%%.0p: %.0p\n", addr, addr);
//	ft_printf("%%.p: %.p\n", addr, addr);
//	ft_printf("%%p: %p\n", addr, addr);
//	ft_printf("%%.5p: %.5p\n", addr, addr);
//	ft_printf("%%9.2p: %9.2p\n", 1234);
//	ft_printf("%%#.3o: %#.3o\n", 1);
//	ft_printf("%%#.3x: %#.3x\n", 1);
//	ft_printf("%%05o: %05o\n", 42);
//	ft_printf("%%015u: %015u\n", 4294967295);
//	ft_printf("%                        lllllllllllllllllllls\n", "abc");
}
