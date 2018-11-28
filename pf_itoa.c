/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:57:08 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/28 14:54:56 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		pf_intlen(t_printf *lst)
{
	int len;
	
	len = ft_intlen(lst->var);
	if (lst->pre > len)
		return (pre);
	return (len);
}

static char		*pf_itoa(t_printf *lst)
{
	char *str;
	
		
}
