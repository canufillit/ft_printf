/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_test.c                                                                */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/08 19:43:29 by Sawyerf                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	pf_print(char *s,void *var)
{
	int lol;
	int lol2;
	char *s1;
	char *s2;

	s1 = ft_strnew(100);
	ft_printf("\x1b[0mft_printf: |");
	lol = ft_printf(s, var);
	ft_printf("|\n");
	printf("   printf: |");
	lol2 = printf(s, var);
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD]\x1b[0m\n");
}

void	pf_print_f(char *s, float var)
{
	int lol;
	int lol2;

	ft_printf("\x1b[0mft_printf: |");
	lol = ft_printf(s, var);
	printf("|\n   printf: |");
	lol2 = printf(s, var);
	if (lol != lol2)
		printf("|\n\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("|\n\x1b[32m [GOOD]\x1b[0m\n");
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

	pf_print("%p",			&i);
	pf_print("%p",			s);
	pf_print("%p",			&ll);
	pf_print("%p",			ft_printf);
	pf_print("%p",			0);
	pf_print("%p", 			str);
	pf_print("%p",			addr);
	pf_print("%p", 			NULL);
	pf_print("%5p", 		0);

	pf_print("%d",			nb);
	pf_print("%+d",			nb);
	pf_print("%0+d",		nb);
	pf_print("%-d",			nb);
	pf_print("%0d",			nb);
	pf_print("%.5d",		nb);
	pf_print("%.2d",		nb);
	pf_print("%5d", 		nb);
	pf_print("%2d", 		nb);
	pf_print("% 03d",		0);
	pf_print("%0.5d",		-1);
	pf_print("%0.2d",		-1);
	pf_print("%-+10.5d",	4242);
	pf_print("% 5.5d",		16);
	pf_print("% 5d",		16);
	pf_print("%d",			-123);
	pf_print("%+d",			123);
	pf_print("%.d",			nb);
	pf_print("lol",			-8882);

	pf_print_f("%f",		fl);
	pf_print_f("%+f",		fl);
	pf_print_f("%0+f",		fl);
	pf_print_f("%-f",		fl);
	pf_print_f("%0f",		fl);
	pf_print_f("%.5f",		fl);
	pf_print_f("%.2f",		fl);
	pf_print_f("%5f",		fl);
	pf_print_f("%2f",		fl);
	pf_print_f("% 03f}",	fl);
	pf_print_f("%0.5f", 	fl);
	pf_print_f("%0.2f", 	fl);
	pf_print_f("%-+10.5f",	fl);
	pf_print_f("% 5.5f",	fl);
	pf_print_f("% 5f",		fl);
	pf_print_f("%f",		fl);
	pf_print_f("%+f",		fl);
	pf_print_f("%.f",		fl);
	pf_print_f("lol", 		-8882);

	pf_print("lol%s",		"15");
	pf_print("%.2s",		str);
	pf_print("%-15s",		str);
	pf_print("%5.2s",		str);
	pf_print("%2.2s",		str);
	pf_print("%.5s",		str);
	pf_print("%2s",			str);
	pf_print("%5s.",		NULL);

	pf_print("%   %",		"test");

	pf_print("%c",			42);
	pf_print("%5c", 		42);
	pf_print("%5c", 		42);
	pf_print("%c", 			0);
	pf_print("%5c", 		0);
	pf_print("%5c", 		0);

	pf_print("%x",			nb);
	pf_print("%x",			-nb);
	pf_print("%x",			-nb - 8 );
	pf_print("%x",			&str);
	pf_print("%x",			addr);
	pf_print("%x",			-nb - 8 );

	pf_print("%-10.5f|",	2500);
	pf_print("%-10.5f|", 	2500);
	pf_print("%08f", 		42);
	pf_print("%0.5f", 		-1);
	pf_print("%0.2f", 		-1);
	pf_print("%-+10.5f",	4242);
	pf_print("% 5.5f", 		16);
	pf_print("% 5f", 		16);
	pf_print("%f", 			-123);
	pf_print("%+f", 		123);


	pf_print("%jd",			-4294967296);
	pf_print("%jx",			-4294967296);
	pf_print("{%03c}",		0);
	pf_print("{%05s}",		"abc");
	pf_print("%4.s",		"42");

	pf_print("%9.2p",		1234);
	pf_print("%#.3o",		1);
	pf_print("%#.3x",		1);
	pf_print("%05o",		42);
	pf_print("%015u",		4294967295);
	pf_print("%                        lllllllllllllllllllls", "abc");
	free(s);
	free(addr);
}
