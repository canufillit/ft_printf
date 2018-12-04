/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/04 11:21:03 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*pf_addc(char *s, int n, char c)
{
	int count;

	count = 0;
	while (n > count)
	{
		s[count] = c;
		count++;
	}
	s[count] = '\0';
	return (s);
}

char	*add_base_prefix(t_printf *lst, char *s)
{
	if (ft_cisin(lst->settings, '#') && (lst->type == 'X' || lst->type == 'x') && *lst->var != '0')
		ft_strcat(s, "0X");
	else if (ft_cisin(lst->settings, '#') && lst->type == 'o')
		ft_strcat(s, "0");
	return (s);
}

t_opt	pf_len(t_printf *lst, t_opt opt, char c)
{
	opt.size = ft_strlen(lst->var) - ((ft_cisin(lst->var, '-')) ? 1 : 0);
//signe
	if (ft_cisin(lst->var, '-') && (lst->type == 'd' || lst->type == 'i'))
		ft_strcpy(opt.sign, "-");
	else if (ft_cisin(lst->settings, '+') && (lst->type == 'd' || lst->type == 'i'))
		ft_strcpy(opt.sign, "+");
// 0x/0
	if (ft_cisin(lst->settings, '#') && (lst->type == 'x' || lst->type == 'X') && *lst->var != '0')
		opt.nb_ext = 2;
	if (ft_cisin(lst->settings, '#') && lst->type == 'o')
		opt.nb_ext = 1;
// extra
	if (ft_cisin(lst->var, '-') || ft_cisin(lst->settings, '+'))
		opt.nb_ext++;
// '0'
	if (opt.size < lst->pre[1])
		opt.nb_0 = lst->pre[1] - opt.size;
// ' '
	if (opt.size + opt.nb_0 + opt.nb_ext < lst->pre[0] && (c == ' ' || ft_cisin(lst->settings, '-')))
		opt.nb_sp = lst->pre[0] - opt.size - opt.nb_0 - opt.nb_ext;
	else if (opt.size + opt.nb_0 + opt.nb_ext < lst->pre[0] && c == '0')
		opt.nb_0 = lst->pre[0] - opt.size - opt.nb_0 - opt.nb_ext;
	else if (ft_cisin(lst->settings, ' ') && !opt.sign[0] && lst->type != 'u')
		opt.nb_sp = 1;
// strnew
	if (!(opt.tmp = ft_strnew(opt.size + opt.nb_0 + opt.nb_sp + opt.nb_ext)))
		return (opt);
	return (opt);
}

void	pf_optnew(t_opt *lst)
{
	lst->tmp = NULL;
	lst->nb_sp = 0;
	lst->nb_0 = 0;
	lst->nb_ext = 0;
	lst->sign[0] = '\0';
}

char		*pf_options(t_printf *lst)
{
	char	c;
	t_opt	opt;

	pf_optnew(&opt);
	c = (ft_cisin(lst->settings, '0')) ? '0' : ' ';
	opt = pf_len(lst, opt, c);
// ajouter espace ou zero
	if (!ft_cisin(lst->settings, '-'))
		pf_addc(opt.tmp, opt.nb_sp, c);
// ajouter le signe
	if (opt.sign[0])
		ft_strcat(opt.tmp, opt.sign);
// ajouter 0x/0
	add_base_prefix(lst, opt.tmp);
// ajouter '0' (.nb)
	if (ft_cisin(lst->settings, '-'))
		pf_addc(opt.tmp + opt.nb_ext, opt.nb_0, '0');
	else
		pf_addc(opt.tmp + opt.nb_sp + opt.nb_ext, opt.nb_0, '0');
	if (lst->var[0] == '-')
		(lst->var)++;
	ft_strcat(opt.tmp, lst->var);
	if (ft_cisin(lst->settings, '-'))
		pf_addc(opt.tmp + opt.size + opt.nb_0 + opt.nb_ext, opt.nb_sp, ' ');
//	free(lst->var);
	lst->var = opt.tmp;
	free(opt.tmp);
	return (lst->var);
}
