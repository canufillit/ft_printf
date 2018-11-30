/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:57:09 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 17:00:36 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_pushback(t_printf *lst, t_printf *add)
{
	t_printf *tmp;
	
	tmp = lst;
	if (!lst)
		return(add);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
	return (lst);
}

t_printf	*pf_prnew(char *str, int needconv)
{
	t_printf *lst;
	
	if (!(lst = malloc(sizeof(t_printf))))
		return (NULL);
	lst->next = NULL;
	if (str)
		lst->var = str;
	lst->needconv = needconv;
	lst->settings[0] = '\0';
	lst->size[0] = '\0';
	lst->pre[0] = 0;
	lst->pre[1] = 0;
	return (lst);
}
