/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:18:09 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/29 14:25:46 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t size)
{
	size_t	count;
	size_t	len;
	char	*str;

	len = 0;
	count = 0;
	if (size < (len = ft_strlen(s)))
		str = ft_strnew(size);
	else
		str = ft_strnew(len);
	while (str[count] && count < size)
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
