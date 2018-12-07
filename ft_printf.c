/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/07 15:16:12 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	t_printf	*tmp;
	va_list		ap;
	int			len;

	lst = parser(format);
	if (!lst)
		return (0);
	va_start(ap, format);
	len = pf_router(lst, ap);
	while (lst)
	{
		tmp = lst->next;
		if (lst->var)
			ft_strdel(&(lst->var));
		free(lst);
		lst = tmp;
	}
	return (len);
}
