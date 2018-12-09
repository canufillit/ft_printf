/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_test.c                                                                */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/09 01:54:23 by Sawyerf                                  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

clock_t time1 = 0;
clock_t time2 = 0;
int		test = 0;

void	pf_print_s(char *s, char *var)
{
	int lol;
	int lol2;
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	pf_print_x(char *s, unsigned int var)
{
	int lol;
	int lol2;
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	pf_print_c(char *s, char var)
{
	int lol;
	int lol2;
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	pf_print_d(char *s, int var)
{
	int lol;
	int lol2;
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	pf_print_p(char *s,void *var)
{
	int lol;
	int lol2;
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
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
	clock_t t;
	
	test++;
	lol = 0;
	ft_printf("\x1b[0mft_printf: |");
	t = clock();
	lol = ft_printf(s, var);
	time1 += clock() - t;
	ft_printf("|\n");
	printf("   printf: |");
	t = clock();
	lol2 = printf(s, var);
	time2 += clock() - t;
	printf("|\n");
	if (lol != lol2)
		printf("\x1b[31m [ERROR] %s, %d != %d\x1b[0m\n", s, lol, lol2);
	else
		printf("\x1b[32m [GOOD] %s\x1b[0m\n", s);
}

void	test_d(int nb)
{
	pf_print_d("%d",		nb);
	pf_print_d("%+d",		nb);
	pf_print_d("%0+d",		nb);
	pf_print_d("%-d",		nb);
	pf_print_d("%0d",		nb);
	pf_print_d("%- .5d",	nb);
	pf_print_d("%- .5d",	nb);
	pf_print_d("% .2d",		nb);
	pf_print_d("%-5d", 		nb);
	pf_print_d("%2d", 		nb);
	pf_print_d("% 03d",		nb);
	pf_print_d("%-0.5d",	nb);
	pf_print_d("%0.5d",		nb);
	pf_print_d("%0.2d",		nb);
	pf_print_d("%-+10.5d",	nb);
	pf_print_d("% 5.5d",	nb);
	pf_print_d("% 5d",		nb);
	pf_print_d("%.d",		nb);
	pf_print_d("%0 +.d",	nb);
}

void	test_p(void *addr)
{
	pf_print_p("%p",		addr);
	pf_print_p("%30p",		addr);
	pf_print_p("%30.30p",	addr);
	pf_print_p("%0-50p",	addr);
	pf_print_p("%# 0-50p",	addr);
	pf_print_p("%5.2p",		addr);
	pf_print_p("% -5p", 	addr);
	pf_print_p("%0 -5p", 	addr);
	pf_print_p("%0 -.5p",	addr);
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
	pf_print_s("%s",		str);
	pf_print_s("%.2s",		str);
	pf_print_s("%-15s",		str);
	pf_print_s("%5.2s",		str);
	pf_print_s("%2.2s",		str);
	pf_print_s("%.5s",		str);
	pf_print_s("%2s",		str);
	pf_print_s("%5s.",		str);
}

void	test_c(char c){
	pf_print_c("%c",		c);
	pf_print_c("%5c", 		c);
	pf_print_c("%-5c", 		c);
	pf_print_c("% 05c",		c);
	pf_print_c("% 5c", 		c);
	pf_print_c("%.5c", 		c);
}

void	test_x(unsigned int nb){
	pf_print_x("%x",		nb);
	pf_print_x("%5x",		nb);
	pf_print_x("%5.5x",		nb);
	pf_print_x("%-05.x",	nb);
	pf_print_x("%- 5.x",	nb);
	pf_print_x("%+ 5.x",	nb);
	pf_print_x("%+ .x",		nb);
	pf_print_x("%.x",		nb);
}

int	main(int ac, char **av)
{
	int count;
	int max;

	if (ac > 1)
		max = ft_atoi(av[1]);
	else
		max = 1;
	count = 0;
	while (count++ < max)
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
		test_p(ft_printf);
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
	float t1 = ((float)time1)/CLOCKS_PER_SEC;
    float t2 = ((float)time2)/CLOCKS_PER_SEC;
	printf("for %d tests:\n", test);
	printf("[time] ft_printf = %f\n", t1);
	printf("[time]    printf = %f\n", t2);
	printf("[time]    %f\n", t1/t2);
	printf("[time]    %f\n", (t2/t1) * 100);
}
