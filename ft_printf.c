/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 18:05:14 by apeyret          ###   ########.fr       */
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
	return (1);
}
