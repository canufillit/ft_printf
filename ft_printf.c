/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 17:18:05 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr(t_printf *lst)
{
	while (lst)
	{
		if (!lst->needconv)
			printf("var: %s\n",lst->var);
		else
		{
			printf("set: |%s|\n", lst->settings);
			printf("pre: %d.%d\n", lst->pre[0], lst->pre[1]);
			printf("siz: |%s|\n", lst->size);
			printf("typ: %c\n", lst->type);
		}
		printf("|||||||||||||||||\n");
		lst = lst->next;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	va_list		ap;

	lst = parser(format);
//	pr(lst);
	va_start(ap, format);
	pf_router(lst, ap);
	/*while (lst)
	{
		ft_putstr(lst->var);
		lst = lst->next;
	}*/
	return (1);
}
/*
int		main()
{
	printf("\x1B[31m");
	ft_printf("lolipop: %0+d %s\n", 1, "pour le bien\n");
	ft_printf("lolipop: %0+d%20.2s\n", 1, "pour le bien\n");
	printf("\x1B[32m");
	printf("lolipop: %0+d%20.2s", 1, "pour le bien\n");
	printf("\x1B[31m");
	ft_printf("lolipop: %hhd", 1);
	printf("\x1B[32m");
	ft_printf("lolipop: %+05.6lld", 1);
	printf("\x1B[33m");
	ft_printf("lolipop: %+05.6lldprout", 1);
	printf("\x1B[34m");
	ft_printf("lolipop: %+05.6lld%d", 1, 1);
}*/
