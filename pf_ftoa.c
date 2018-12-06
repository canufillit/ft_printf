/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:04:34 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/06 18:23:38 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_pow(unsigned long n, int pow)
{
	unsigned long	total;

	total = n;
	if (!pow)
		return (1);
	if (pow == 1)
		return (n);
	while (--pow)
		total *= n;
	return (total);
}

void	copy(char *ptr, int *i, unsigned long ipart, unsigned long n)
{
	while (n)
	{
		ptr[(*i)++] = (ipart / n) + '0';
		ipart %= n;
		n /= 10;
	}
}

int		len_cal(long nb, int base)
{
	int		i;

	i = 1;
	while (nb /= base)
		++i;
	return (i);
}

char	*pf_ftoa_exep(t_printf *lst, double n)
{
	long	ipart;
	int		len;
	int		i;
	int 	pre;

	pre = (lst->pre[1]) ? lst->pre[1] : 0;
	ipart = (long)n;
	len = len_cal(((n < 0) ? -ipart : ipart), 10);
	ipart = ((ipart % ft_pow(10, len)) > 5) ? ipart + 1 : ipart;
	if (!(lst->var = (n < 0) ? ft_strnew(len + pre + 1) : ft_strnew(len + pre + 2)))
		return (NULL);
	i = 0;
	if (n < 0)
		lst->var[i++] = '-';
	copy(lst->var, &i, ipart, ft_pow(10, len - 1));
	return (lst->var);
}

char	*pf_ftoa(t_printf *lst, double n)
{
	long	ipart;
	double	dpart;
	int		len;
	int		i;
	int 	pre;

	pre = (lst->pre[1]) ? lst->pre[1] : FLT_DIG;
	ipart = (long)n;
	dpart = n - (long double)ipart;
	ipart = (n < 0) ? -ipart : ipart;
	dpart = (n < 0) ? -dpart : dpart;
	dpart *= ft_pow(10, pre);
	len = len_cal(((n < 0) ? -ipart : ipart), 10);
	if (!(lst->var = (n < 0) ? ft_strnew(len + pre + 1) : ft_strnew(len + pre + 2)))
		return (NULL);
	i = 0;
	if (n < 0)
		lst->var[i++] = '-';
	copy(lst->var, &i, ipart, ft_pow(10, len - 1));
	lst->var[i++] = '.';
	dpart = ((long)((dpart - (long)dpart) * 10) > 5) ? dpart + 1 : dpart;
	copy(lst->var, &i, dpart, ft_pow(10, pre - 1));
	return (lst->var);
}
