/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/03 21:18:16 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr(t_printf *lst)
{
	while (lst)
	{
		if (!lst->needconv)
		{
			printf("\x1B[33m");
			printf("var: |%s|\n",lst->var);
		}
		else
		{
			printf("\x1B[32m");
			printf("var: |%s|\n",lst->var);
			printf("set: |%s|\n", lst->settings);
			printf("pre: %d.%d\n", lst->pre[0], lst->pre[1]);
			printf("siz: |%s|\n", lst->size);
			printf("typ: %c\n", lst->type);
		}
		printf("\x1B[31m|||||||||||||||||\x1B[0m\n");
		lst = lst->next;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	va_list		ap;

	lst = parser(format);
	if (!lst)
		return (0);
	va_start(ap, format);
	int nb = pf_router(lst, ap);
//	pr(lst);
//	printf("%d\n", nb);
	return (nb);
}
