/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:47:15 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/04 14:49:34 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_opt	pf_len(t_printf *lst, t_opt opt, char c)
{
	opt.size = ft_strlen(lst->var) - ((ft_cisin(lst->var, '-')) ? 1 : 0);
//signe
	if (ft_cisin(lst->var, '-')
		ft_strcpy(opt.sign, "-");
	else if (ft_cisin(lst->settings, '+'))
		ft_strcpy(opt.sign, "+");
// 0x/0
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
