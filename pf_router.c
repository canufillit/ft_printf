/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:37:11 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/29 16:50:00 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	pf_router_d(t_printf *lst)
{
	if (tmp->size[0] == '\0')
		ft_itoa(lst, va_arg(ap, int));
	else if (tmp->size[1] == 'l')
		ft_itoa(lst, va_arg(ap, long long));
	else if (tmp->size[0] == 'l')
		ft_itoa(lst, va_arg(ap, long));
	else if (tmp->size[1] == 'h')
		ft_itoa(lst, va_arg(ap, short short));
	else if (tmp->size[0] == 'h')
		ft_itoa(lst, va_arg(ap, short));
}

void	pf_router_u(t_printf *lst)
{
	if (tmp->size[0] == '\0')
		ft_utoa(lst, va_arg(ap, unsigned int));
	else if (tmp->size[1] == 'l')
		ft_utoa(lst, va_arg(ap, unsigned long long));
	else if (tmp->size[0] == 'l')
		ft_utoa(lst, va_arg(ap, unsigned long));
	else if (tmp->size[1] == 'h')
		ft_utoa(lst, va_arg(ap, unsigned short short));
	else if (tmp->size[0] == 'h')
		ft_utoa(lst, va_arg(ap, unsigned short));
}

void	*pf_router(t_printf *lst, va_list ap)
{
	t_printf	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->type == 's')
			ft_putstr(va_arg(ap, char*));
		else if (tmp->type == 'c')
			ft_putchar(va_arg(ap, char));
		else if (tmp->type == 'd' || tmp->type == 'i')
			pf_router_d(tmp);
		else if (tmp->type == 'u' || tmp->type == 'o' || tmp->type == 'x'
			|| tmp->type == 'X')
			pf_router_d(tmp);
		tmp = tmp->next;
	}
}
