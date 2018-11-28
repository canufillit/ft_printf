/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/28 19:18:58 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	char		*str;

	lst = parsing(format);
	while (lst)
	{
		if (!lst->needconv)
			str = ft_strcat(str, lst->var);
		else
			str = ft_strcat(str, conv_format(lst));
		lst = lst->next;
	}
	ft_putstr(str);
}
