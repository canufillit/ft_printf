/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:06:58 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/02 17:39:07 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *s)
{
	int count;
	
	count = 0;
	while (s[count])
	{
		s[count] = ft_tolower(s[count]);
		count++;
	}
	return (s);
}
