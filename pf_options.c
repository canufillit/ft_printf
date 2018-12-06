/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/06 14:36:45 by apeyret          ###   ########.fr       */
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
	else if (ft_cisin(lst->settings, '#') && (lst->type == 'o' || lst->type == 'O') && (*lst->var != '0' || lst->pre[2]))
		ft_strcat(s, "0");
	return (s);
}

t_opt	pf_len(t_printf *lst, t_opt opt)
{
	char	c;

	c = (ft_cisin(lst->settings, '0') && !lst->pre[2]) ? '0' : ' ';
	opt.size = ft_strlen(lst->var) - ((ft_cisin(lst->var, '-')) ? 1 : 0);
	if (lst->pre[2] && lst->var[0] == '0')
		opt.size = 0;
//signe
	if (ft_cisin(lst->var, '-') && (lst->type == 'd' || lst->type == 'i'))
		ft_strcpy(opt.sign, "-");
	else if (ft_cisin(lst->settings, '+') && (lst->type == 'd' || lst->type == 'i'))
		ft_strcpy(opt.sign, "+");
// 0x/0
	if (ft_cisin(lst->settings, '#') && (lst->type == 'x' || lst->type == 'X'))//&& *lst->var != '0')
		opt.nb_zero = 2;
	if (ft_cisin(lst->settings, '#') && (lst->type == 'O' || lst->type == 'o'))// && *lst->var != '0')
		opt.nb_zero = 1;
// extra
	if (ft_cisin(lst->var, '-') || ft_cisin(lst->settings, '+'))
		opt.nb_sig = 1;
// '0'
	if (opt.size < lst->pre[1])
		opt.nb_0 = lst->pre[1] - opt.size;
// ' '
	if (opt.size + opt.nb_0 + opt.nb_sig + opt.nb_zero + opt.nb_p < lst->pre[0] && ft_cisin(lst->settings, '-'))
		opt.nb_spe = lst->pre[0] - opt.size - opt.nb_0 - opt.nb_sig - opt.nb_zero;
	else if (opt.size + opt.nb_0 + opt.nb_sig + opt.nb_zero + opt.nb_p < lst->pre[0] && c == ' ')
		opt.nb_sp = lst->pre[0] - opt.size - opt.nb_0 - opt.nb_sig - opt.nb_zero;
	else if (opt.size + opt.nb_0 + opt.nb_sig + opt.nb_zero + opt.nb_p < lst->pre[0] && c == '0')
		opt.nb_0 += lst->pre[0] - opt.size - opt.nb_sig + opt.nb_0 - opt.nb_p - opt.nb_zero;
	if (ft_cisin(lst->settings, ' ') && !opt.sign[0] && lst->type != 'u' && !opt.nb_sp)
	{
		if (c == '0')
			opt.nb_0--;
		opt.nb_p = 1;
	}
// strnew
	if (!(opt.tmp = ft_strnew(opt.size + opt.nb_0 + opt.nb_sp + opt.nb_p + opt.nb_zero + opt.nb_sig)))
		opt.tmp = NULL;
	return (opt);
}

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

char		*pf_options(t_printf *lst, t_opt opt)
{
// ajouter espace
	pf_addc(opt.tmp, opt.nb_sp + opt.nb_p, ' ');
// ajouter le signe
	ft_strcat(opt.tmp, opt.sign);
// ajouter 0x/0
	add_base_prefix(lst, opt.tmp);
// ajouter '0' (.nb)
	pf_addc(opt.tmp + opt.nb_sp + opt.nb_zero + opt.nb_p + opt.nb_sig, opt.nb_0, '0');
	if (lst->var[0] == '-')
		(lst->var)++;
	ft_strncat(opt.tmp, lst->var, opt.size);
	pf_addc(opt.tmp + opt.size + opt.nb_0 + opt.nb_sp + opt.nb_zero + opt.nb_p + opt.nb_sig, opt.nb_spe, ' ');
//	free(lst->var);
	lst->var = opt.tmp;
	free(opt.tmp);
	return (lst->var);
}
