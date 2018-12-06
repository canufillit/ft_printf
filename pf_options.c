/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/06 18:43:04 by apeyret          ###   ########.fr       */
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

char	*add_base_prefix(t_printf *lst, t_opt opt, char *s)
{
	if (opt.nb_zero == 2)
		ft_strcat(s, "0X");
	else if (opt.nb_zero == 1)
		ft_strcat(s, "0");
	return (s);
}

char		*pf_options(t_printf *lst, t_opt opt)
{
// ajouter espace
	pf_addc(opt.tmp, opt.nb_sp + opt.nb_p, ' ');
// ajouter le signe
	ft_strcat(opt.tmp, opt.sign);
// ajouter 0x/0
	add_base_prefix(lst, opt, opt.tmp);
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
