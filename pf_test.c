/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_test.c                                                                */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/08 20:18:09 by Sawyerf                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	pf_print(char *s,void *var)
{
	int lol;
	int lol2;

	ft_printf("\x1b[0mft_printf: |");
	lol = ft_printf(s, var);
	ft_printf("|\n");
	printf("   printf: |");
	lol2 = printf(s, var);
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	pf_print_f(char *s, float var)
{
	int lol;
	int lol2;

	ft_printf("\x1b[0mft_printf: |");
	lol = ft_printf(s, var);
	ft_printf("|\n");
	printf("   printf: |");
	lol2 = printf(s, var);
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	test_d(int nb)
{
	pf_print("%d",			nb);
	pf_print("%+d",			nb);
	pf_print("%0+d",		nb);
	pf_print("%-d",			nb);
	pf_print("%0d",			nb);
	pf_print("%- .5d",		nb);
	pf_print("%- .5d",		nb);
	pf_print("% .2d",		nb);
	pf_print("%-5d", 		nb);
	pf_print("%2d", 		nb);
	pf_print("% 03d",		nb);
	pf_print("%-0.5d",		nb);
	pf_print("%0.5d",		nb);
	pf_print("%0.2d",		nb);
	pf_print("%-+10.5d",	nb);
	pf_print("% 5.5d",		nb);
	pf_print("% 5d",		nb);
	pf_print("%.d",			nb);
	pf_print("%0 +.d",		nb);
}

void	test_p(void *addr)
{
	pf_print("%p",			addr);
	pf_print("%30p",		addr);
	pf_print("%30.30p",		addr);
	pf_print("%0-50p",		ft_printf);
	pf_print("%# 0-50p",	ft_printf);
	pf_print("%p",			0);
	pf_print("%p", 			NULL);
	pf_print("%5.2p",		0);
	pf_print("% -5p", 		NULL);
	pf_print("%0 -5p", 		NULL);
	pf_print("%0 -.5p",		NULL);
}

void	test_f(float fl)
{
	pf_print_f("%f",		fl);
	pf_print_f("%+f",		fl);
	pf_print_f("%0+f",		fl);
	pf_print_f("%-f",		fl);
	pf_print_f("%0f",		fl);
	pf_print_f("%.5f",		fl);
	pf_print_f("%.2f",		fl);
	pf_print_f("%5f",		fl);
	pf_print_f("%2f",		fl);
	pf_print_f("% 03f",		fl);
	pf_print_f("%0.5f", 	fl);
	pf_print_f("%0.2f", 	fl);
	pf_print_f("%-+10.5f",	fl);
	pf_print_f("% 5.5f",	fl);
	pf_print_f("% 5f",		fl);
	pf_print_f("%f",		fl);
	pf_print_f("%+f",		fl);
	pf_print_f("%.f",		fl);
	pf_print_f("%-10.5f",	fl);
	pf_print_f("%-10.5f", 	fl);
	pf_print_f("%08f", 		fl);
	pf_print_f("%0.5f", 	fl);
	pf_print_f("%0.2f", 	fl);
	pf_print_f("%-+10.5f",	fl);
	pf_print_f("% 5.5f", 	fl);
	pf_print_f("% 5f", 		fl);
	pf_print_f("%f", 		fl);
	pf_print_f("%+f", 		fl);
}

void	test_s(char *str){
	pf_print("%s",			str);
	pf_print("%.2s",		str);
	pf_print("%-15s",		str);
	pf_print("%5.2s",		str);
	pf_print("%2.2s",		str);
	pf_print("%.5s",		str);
	pf_print("%2s",			str);
	pf_print("%5s.",		str);
}

void	test_c(char c){
	pf_print("%c",			c);
	pf_print("%5c", 		c);
	pf_print("%-5c", 		c);
	pf_print("% 05c", 		c);
	pf_print("% 5c", 		c);
	pf_print("%.5c", 		c);
}

void	test_x(unsigned int nb){
	pf_print("%x",			nb);
	pf_print("%5x",			nb);
	pf_print("%5.5x",		nb);
	pf_print("%-05.x",		nb);
	pf_print("%- 5.x",		nb);
	pf_print("%+ 5.x",		nb);
	pf_print("%+ .x",		nb);
	pf_print("%.x",			nb);
}

int	main(void)
{
	//%d
	test_d(1232);
	test_d(-100);
	test_d(-2);
	//%s
	test_s("abc");
	test_s("");
	test_s(NULL);
	//%p
	test_p(ft_strdup("abc"));
//	test_p(ft_printf);
	test_p(NULL);
	//%f
	test_f(12313);
	test_f(0.0);
	test_f(0.00000000001);
	test_f(-0.00000000001);
	test_f(-1);
	//%c
	test_c(42);
	test_c(0);
	//%x
	test_x(42);
	test_x(0);
}
