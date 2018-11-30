/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/30 15:47:50 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*pf_options(t_printf *lst)
{
	int		save;
	int		len;
	char	*ptr;

	save = ft_strlen(lst->var);
	len = save;
	if (ft_cisin(lst->settings, '0'))
	{
		if (lst->pre[0])
			len = (lst->pre[0] > save) ? (lst->pre[0]) : save; 
	}
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (save-- && len--)
		ptr[len] = lst->var[save]; 
	while (--len >= 0)
	{
		ptr[len] = '0';
		if (!len && ft_cisin(lst->settings, '+'))
			ptr[len] = '+';
	}
	return (ptr);		
}
