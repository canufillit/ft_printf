/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_test.c                                                                */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/08 18:18:32 by Sawyerf                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	pf_print(char *s,void *var)
{
	printf("\x1b[30m\n");
	int lol = ft_printf(s, var);
	printf("\n");
	int lol2 = printf(s, var);
	if (lol != lol2)
		printf("\n\x1b[31m ERROR %s, %d != %d\n", s, lol, lol2);
}

int	main(void)
{
	int nb = 123;
	char str[] = "123";
	int i;
	unsigned long ll;
	float fl = 75.5;
	void *addr = ft_strdup("d");
	char *s = ft_strdup("d");
	pf_print("%p", &i);
	pf_print("%p", s);
	pf_print("%p", &ll);
	pf_print("%p", ft_printf);
	pf_print("%p", 0);
	pf_print("%%p:   %p",	str);
	pf_print("%%p:   %p", addr);
	pf_print("%%p:   %p", NULL);
	pf_print("{%%5p}: {%5p}", 0);

	pf_print("%%d:   %d",	nb);
	pf_print("%%+d:  %+d",	nb);
	pf_print("%%0+d:  %0+d",	nb);
	pf_print("%%-d:  %-d",	nb);
	pf_print("%%0d:  %0d",	nb);
	pf_print("%%.5d: %.5d", nb);
	pf_print("%%.2d: %.2d", nb);
	pf_print("%%5d:  %5d", nb);
	pf_print("%%2d:  %2d", nb);
	pf_print("%%5.d: {% 03d}", 0);
	pf_print("%%5.d: %0.5d", -1);
	pf_print("%%2.d: %0.2d", -1);
	pf_print("%%-+10.5d: %-+10.5d", 4242);
	pf_print("%% 5.5d: % 5.5d", 16);
	pf_print("%% 5d: % 5d", 16);
	pf_print("%%d: %d", -123);
	pf_print("%%+d: %+d", 123);
	pf_print("%%.d: %.d", nb);
	pf_print("lol", -8882);

	pf_print("lol%s", "15");
	pf_print("%%.2s: %.2s",	str);
	pf_print("%%-15s: |%-15s|",	str);
	pf_print("%%5.2s: |%5.2s|",str);
	pf_print("%%2.2s: |%2.2s|",str);
	pf_print("%%.5s: %.5s",	str);
	pf_print("%%2s:  %2s",	str);
	pf_print("%%5.s:  %5s.",	NULL);

	pf_print("%%   %%: %   %", "test");

	pf_print("%%c: %c", 42);
	pf_print("%%c: %5c", 42);
	pf_print("%%5c: %5c", 42);
	pf_print("%%c: %c", 0);
	pf_print("%%c: %5c", 0);
	pf_print("%%5c: %5c", 0);

	pf_print("%%x:   %x",	nb);
	pf_print("%%x:   %x",	-nb);
	pf_print("%%x:   %x",	-nb - 8 );
	pf_print("%%x: %x", &str);
	pf_print("%%x: %x", addr);
	pf_print("%%x:   %x",	-nb - 8 );

	pf_print("%%-10.5f: |%-10.5f|", 2500);
	pf_print("%%-10.5f: |%-10.5f|", 2500);
	pf_print("%%08f: %08f", 42);
	pf_print("%%5.f: %0.5f", -1);
	pf_print("%%2.f: %0.2f", -1);
	pf_print("%%-+10.5f: %-+10.5f", 4242);
	pf_print("%% 5.5f: % 5.5f", 16);
	pf_print("%% 5f: % 5f", 16);
	pf_print("%%f: %f", -123);
	pf_print("%%+f: %+f", 123);


	pf_print("%jd", -4294967296);
	pf_print("%jx", -4294967296);
	pf_print("{%%03c}: {%03c}", 0);
	pf_print("{%%05s}: {%05s}", "abc");
	pf_print("ft%%4.s: %4.s", "42");

	pf_print("%%9.2p: %9.2p", 1234);
	pf_print("%%#.3o: %#.3o", 1);
	pf_print("%%#.3x: %#.3x", 1);
	pf_print("%%05o: %05o", 42);
	pf_print("%%015u: %015u", 4294967295);
	pf_print("%                        lllllllllllllllllllls", "abc");
	free(s);
	free(addr);
}
