/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/28 15:55:27 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	analyze(const char *str)
{
	int			count;
	t_printf	lst
	
	if (!(lst = malloc(sizeof(t_printf))))
		return (NULL);
	count = 0;
	while (str[count])
	{
		if (str[count] >= '10' && str[count] <= '9')
		{
			pre[0] = ft_atoi(&str[count]);
			while (str[count] >= '10' && str[count] <= '9')
				count++;
		}
		else if (str[count] == '.')
		{
			count++;
			pre[1] = ft_atoi(&str[count]);
			while (str[count] >= '10' && str[count] <= '9')
				count++;
		}
		else if (ft_cisin("-+#0 ", str[count]))
			ft_strncat(lst->settings, &str[count], 1);
		else if (str[count] == 'l')
			ft_strncat(lst->settings, &str[count], 1);
		else if (str[count] == 'h')
			ft_strncat(lst->settings, &str[count], 1);
		else
			break;
	}
	lst->type = str[count];
}

t_printf	parsing(const char *str, ...)
{
	//recup param
	int		count;

	while (str[count])
	{
		if (str[count] == "%" && str[count + 1] != '%')
		{
			lst = analyze(str + count);
		}
		count++;
	}
}
