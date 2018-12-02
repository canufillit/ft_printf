/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/02 19:18:17 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*pf_append(t_printf *lst, char c, int n)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (n <= (int)ft_strlen(lst->var))
		return (lst->var);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_strcpy(ptr, lst->var);
	i += ft_strlen(lst->var);
	len = n - ft_strlen(lst->var);
	while (len--)
		ptr[i++] = c;
	ft_strdel(&lst->var);
	return (ptr);
}

char		*pf_prepend(t_printf *lst, char c, int n)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (n <= (int)ft_strlen(lst->var))
		return (lst->var);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	len = n - ft_strlen(lst->var);
	while (len--)
		ptr[i++] = c;
	ft_strcat(&ptr[i], lst->var);
	ft_strdel(&lst->var);
	return (ptr);
}

char		*pf_options(t_printf *lst)
{
	if (ft_cisin(lst->settings, '0') && lst->pre[1])
		lst->var = pf_prepend(lst, '0', lst->pre[1]);
	if (ft_cisin(lst->settings, ' ') && *lst->var != '-')
		lst->var = pf_prepend(lst, ' ', ft_strlen(lst->var) + 1);
	if (ft_cisin(lst->settings, '+') && *lst->var != '-' && lst->type == 'd')
		return (lst->var = pf_prepend(lst, '+', ft_strlen(lst->var) + 1));
	if (ft_cisin(lst->settings, '+') && ft_cisin(lst->settings, ' ') && *lst->var != '-')
		return (lst->var = pf_prepend(lst, '+', ft_strlen(lst->var) + 1));
	if (ft_cisin(lst->settings, '#') && (lst->type == 'X' || lst->type == 'x'))
	{
		lst->var[0] = '0';
		lst->var[1] = 'X';
	}
	if (ft_cisin(lst->settings, '#') && lst->type == 'o')
		lst->var[0] = '0';
	if (lst->pre[1])
		lst->var = pf_append(lst, ' ', lst->pre[1]);
	if (lst->pre[0])
		lst->var = pf_prepend(lst, ' ', lst->pre[0]);
	return (lst->var);		
}
