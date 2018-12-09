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

void	pf_prdel(t_printf *lst)
{
	t_printf	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->var)
			ft_strdel(&(lst->var));
		free(lst);
		lst = tmp;
	}
}

void	ft_replace(char *s, char c1, char c2, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		if (s[count] == c1)
		{
			s[count] = c2;
			return ;
		}
		count++;
	}
}

char	*ret(t_printf *lst, int len)
{
	char	*s;
	char	*tmp;

	s = ft_strnew(len);
	tmp = s;
	while (lst)
	{
		if (!lst->needconv)
			ft_strcpy(tmp, lst->var);
		else
		{
			lst->opt.tmp = tmp;
			if (lst->type == 'c')
			{
				pf_options("*", lst->opt);
				ft_replace(tmp, '*', lst->var[0], lst->len);
			}
			else
				pf_options(lst->var, lst->opt);
			if (lst->type == 'x' || lst->type == 'p')
				ft_strlower(lst->opt.tmp);
		}
		tmp = tmp + lst->len;
		lst = lst->next;
	}
	return (s);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	va_list		ap;
	int			len;
	char		*s;


	lst = parser(format);
	if (!lst)
		return (0);
	va_start(ap, format);
	len = pf_router(lst, ap);
	s = ret(lst, len);
	write(1, s, len);
	free(s);
	pf_prdel(lst);
	return (len);
}
