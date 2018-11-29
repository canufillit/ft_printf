/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/29 15:17:26 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	va_list		ap;

	lst = parser(format);
	va_start(ap, format);
	lst = pf_router(lst, ap);
	/*while (lst)
	{
		ft_putstr(lst->var);
		lst = lst->next;
	}*/
	return (1);
}
