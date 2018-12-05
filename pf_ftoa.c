/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:04:34 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/05 20:10:41 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr[size] = '\0';
	while (size--)
		ptr[size] = '\0';
	return (ptr);
}

int		ft_pow(int n, int pow)
{
	if (!pow)
		return (1);
	if (pow == 1)
		return (n);
	while (--pow)
		n *= 10;
	return (n);
}

void	icopy(char *ptr, int *i, int ipart, int n)
{
	printf("%d   %d    %d\n", *i, ipart, n);
	while (ipart && n)
	{
		ptr[(*i)++] = (ipart / n) + '0';
		ipart %= n;
		n /= 10;
	}
}

char	*pf_ftoa(float n, int p)
{
	char	*ptr;
	int		ipart;
	float	fpart;
	int		nb;
	int		len;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	len = 1;
	nb = (n < 0) ? -ipart : ipart;
	ipart = (n < 0) ? -ipart : ipart;
	fpart = (n < 0) ? -fpart : fpart;
	while (nb /= 10)
		++len;
	if (!(ptr = (n < 0) ? ft_strnew(len + p + 1) : ft_strnew(len + p + 2)))
		return (NULL);
	i = 0;
	if (n < 0)
		ptr[i++] = '-';
	icopy(ptr, &i, ipart, ft_pow(10, len - 1));
	ptr[i++] = '.';
	icopy(ptr, &i, (int)(fpart * ft_pow(10, p)), ft_pow(10, p - 1));
	return (ptr);
}

int		main(void)
{
	printf("%s\n", pf_ftoa(-123.5432, 3));
	return (0);
}
