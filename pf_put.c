/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:56:00 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/06 18:45:49 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putstrr(char *str, char c)
{
	int count;

	count = 0;
	while (str[count])
	{
		if (str[count] == 42)
			ft_putchar(c);
		else
			ft_putchar(str[count]);
		count++;
	}
}

char	*pf_putchar(t_printf *lst, const char c)
{
	t_opt	opt;

	lst->var = ft_strnew(1);
	lst->var[0] = '*';
	opt = pf_optnew();
	opt.size = 1;
	if (lst->pre[0] > 1 && ft_cisin(lst->settings, '-'))
		opt.nb_spe = lst->pre[0] - 1;
	else if (lst->pre[0] > 1 && ft_cisin(lst->settings, '0'))
		opt.nb_0 = lst->pre[0] - 1;
	else if (lst->pre[0] > 1)
		opt.nb_sp = lst->pre[0] - 1;
	if (!(opt.tmp = ft_strnew(opt.size + opt.nb_spe + opt.nb_0 + opt.nb_sp)))
		return (NULL);
	lst->var = pf_options(lst, opt);
	pf_putstrr(lst->var, c);
	return (lst->var);
}

char 	*pf_retnull(t_printf *lst)
{
	lst->var = ft_strdup("(null)");
	ft_putstr(lst->var);
	return (lst->var);
}

char	*pf_putstr(t_printf *lst, const char *s)
{
	t_opt opt;

	opt = pf_optnew();
	if (!s && !lst->pre[2])
		return (pf_retnull(lst));
	else if (!s && lst->pre[2])
		s = ft_strdup("");
	opt.size = ft_strlen(s);
	if (lst->pre[1] < opt.size && lst->pre[2])
		opt.size = lst->pre[1];
	if (lst->pre[0] > opt.size && ft_cisin(lst->settings, '-'))
		opt.nb_spe = lst->pre[0] - opt.size;
	else if (lst->pre[0] > opt.size && ft_cisin(lst->settings, '0'))
		opt.nb_0 = lst->pre[0] - opt.size;
	else if (lst->pre[0] > opt.size)
		opt.nb_sp = lst->pre[0] - opt.size;
	if (!(opt.tmp = ft_strnew(opt.size + opt.nb_spe + opt.nb_0 + opt.nb_sp)))
		return (NULL);
	lst->var = (char*)s;
	pf_options(lst, opt);
	ft_putstr(lst->var);
	return (lst->var);
}

char	*pf_putaddr(t_printf *lst, void *addr)
{
	t_opt	opt;

	opt = pf_optnew();
	opt.nb_zero = 2;
	lst->var = utoa_base(lst, (unsigned long long)(addr), 16);
	opt.size = ft_strlen(lst->var);
	if (!lst->pre[1] && lst->pre[2] && lst->var[0] == '0')
		opt.size = 0;
	else if (lst->pre[1] > opt.size)
		opt.nb_0 = lst->pre[1] - opt.size;
	if (lst->pre[0] > opt.size + 2 && ft_cisin(lst->settings, '-'))
		opt.nb_spe = lst->pre[0] - opt.size - 2;
	else if (lst->pre[0] > opt.size + 2&& ft_cisin(lst->settings, '0'))
		opt.nb_0 = lst->pre[0] - opt.size - 2;
	else if (lst->pre[0] > opt.size + 2)
		opt.nb_sp = lst->pre[0] - opt.size - 2;
	if (!(opt.tmp = ft_strnew(opt.size + opt.nb_zero)))
		return (NULL);
	lst->var = pf_options(lst, opt);
	ft_strlower(lst->var);
	ft_putstr(lst->var);
	return (lst->var);
}
