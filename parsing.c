/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/28 15:11:35 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	parsing(const char *str, ...)
{
	//recup param
	int		count;

	while (str[count])
	{
		if (str[count] == "%" && str[count + 1] != '%')
				lst = analyze(str + count);
		count++;
	}
}
