/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:57:09 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/07 12:46:00 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_base			g_base[] =	{
				{'d', 10},
				{'D', 10},
				{'x', 16},
				{'X', 16},
				{'o', 8},
				{'O', 8},
				{'u', 10},
				{'U', 10},
				{'i', 10},
				{'b', 2},
				{'\0', 0}
};

t_opt	pf_optnew()
{
	t_opt opt;

	opt.tmp = NULL;
	opt.nb_sig = 0;
	opt.nb_zero = 0;
	opt.nb_p = 0;
	opt.nb_sp = 0;
	opt.nb_0 = 0;
	opt.size = 0;
	opt.nb_spe = 0;
	opt.sign[0] = '\0';
	return (opt);
}

t_printf		*ft_pushback(t_printf *lst, t_printf *add)
{
	t_printf *tmp;
	
	if (!add)
		return (lst);
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
	else
		lst->var = NULL;
	lst->needconv = needconv;
	lst->settings[0] = '\0';
	lst->size[0] = '\0';
	lst->pre[0] = 0;
	lst->pre[1] = 0;
	lst->pre[2] = 0;
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