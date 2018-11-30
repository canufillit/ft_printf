/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:17:43 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/30 14:11:39 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*stoa_base(t_printf *lst, long long n, int b)
{
	unsigned long long	nb;
	int					i;

	i = 0;
	nb = (n < 0) ? (-n) : n; 
	i = (n < 0 && b == 10) ? 2 : 1;
	while (nb /= b)
		++i;
	nb = (n < 0) ? (-n) : n; 
	if (!(lst->var = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		lst->var[i] = (nb % b < 10) ? (nb % b + '0') : (nb % b + 'A' - 10);
		nb /= b;
	}
	if (i-- && n < 0 && b == 10)
		lst->var[i] = '-';
	return ((*lst)->var);
}

static char				*utoa_base(t_printf *lst, unsigned long long n, int b)
{
	unsigned long long	nb;
	int					i;

	i = 1;
	nb = n;
	while (nb /= b)
		++i;
	if (!(lst->var = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		lst->var[i] = (n % b < 10) ? (n % b + '0') : (n % b + 'A' - 10);
		n /= b;
	}
	return (lst->var);
}
