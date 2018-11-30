/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:57:09 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 17:51:58 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_base g_base[] =	{{'d', 10},
					{'x', 16},
					{'X', 16},
					{'o', 8},
					{'u', 10},
					{'i', 10},
					{'\0', 0}};

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

int			pf_base(char c)
{
	int count;
	
	count = 0;
	while (g_base[count].base != 0)
	{
		if (g_base[count].type == c)
		{
			return (g_base[count].base);
		}
		count++;
	}
	return (10);
}
