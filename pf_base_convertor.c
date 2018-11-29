/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base_convertor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:17:43 by glavigno          #+#    #+#             */
/*   Updated: 2018/11/29 16:44:40 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		malloc_extra_size(t_printf *list, int i)
{
	if ()			

}


char	*pf_itoa_base(t_printf *lst, long long n, int base)
{
	char		*ptr;
	long long	nb;
	short		length;
	short		i;

	nb = (n < 0) ? -n : n;
	length = nb;
	i = (n < 0 && base == 10) ? 2 : 1;
	while (length /= base)
		++i;
	lenght = i + malloc_extra_size(lst, i);
	if (!(ptr = ft_strnew(lenght)))
		return (NULL);
	while (i--)
	{
		if (lst->type == 'x')
			ptr[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base + 'a' - 10);
		else if (lst->type == 'X')
			ptr[i] = (nb % base < 10) ? (nb % base + '0') : (nb % base + 'A' - 10);
		nb /= base;
	}
	if (i && n < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}
