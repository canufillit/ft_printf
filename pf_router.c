/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:37:11 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/02 15:56:58 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	pf_router_d(t_printf *lst, va_list ap)
{
	if (lst->size[0] == '\0')
		lst->var = stoa_base(lst, va_arg(ap, int), pf_base(lst->type));
	else if (lst->size[1] == 'l')
		lst->var = stoa_base(lst, va_arg(ap, int), pf_base(lst->type));
	else if (lst->size[0] == 'l')
		lst->var = stoa_base(lst, va_arg(ap, int), pf_base(lst->type));
	else if (lst->size[1] == 'h')
		lst->var = stoa_base(lst, va_arg(ap, int), pf_base(lst->type));
	else if (lst->size[0] == 'h')
		lst->var = stoa_base(lst, va_arg(ap, int), pf_base(lst->type));
	ft_putstr(pf_options(lst));
}

void	pf_router_u(t_printf *lst, va_list ap)
{
	if (lst->size[0] == '\0')
		lst->var = utoa_base(lst, va_arg(ap, unsigned int), pf_base(lst->type));
	else if (lst->size[1] == 'l')
		lst->var = utoa_base(lst, va_arg(ap, unsigned int), pf_base(lst->type));
	else if (lst->size[0] == 'l')
		lst->var = utoa_base(lst, va_arg(ap, unsigned int), pf_base(lst->type));
	else if (lst->size[1] == 'h')
		lst->var = utoa_base(lst, va_arg(ap, unsigned int), pf_base(lst->type));
	else if (lst->size[0] == 'h')
		lst->var = utoa_base(lst, va_arg(ap, unsigned int), pf_base(lst->type));
	ft_putstr(pf_options(lst));
}

void	pf_router(t_printf *lst, va_list ap)
{
	t_printf	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!tmp->needconv)
			ft_putstr(tmp->var);
		else if (tmp->type == 's')
			pf_putstr(tmp, va_arg(ap, char*));
		else if (tmp->type == 'c')
			ft_putchar(va_arg(ap, int));
		else if (tmp->type == 'd' || tmp->type == 'i')
			pf_router_d(tmp, ap);
		else if (tmp->type == 'u' || tmp->type == 'o' || tmp->type == 'x'
			|| tmp->type == 'X')
			pf_router_u(tmp, ap);
		else if (tmp->type == 'p')
			pf_putaddr(lst, va_arg(ap, void*));
		tmp = tmp->next;
	}
}
