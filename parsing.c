/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/28 18:31:09 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_cisin(char *s, char c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (1);
		count++;
	}
	return (0);
}

t_printf	analyze(const char *str)
{
	int			count;
	t_printf	*lst;
	
	if (!(lst = malloc(sizeof(t_printf))))
		return (NULL);
	count = 0;
	while (str[count])
	{
		if (str[count] >= '1' && str[count] <= '9')
		{
			lst->pre[0] = ft_atoi(&str[count]);
			count++;
			while (str[count] >= '0' && str[count] <= '9')
				count++;
		}
		else if (str[count] == '.')
		{
			count++;
			lst->pre[1] = ft_atoi(&str[count]);
			count++;
			while (str[count] >= '0' && str[count] <= '9')
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
	int			count;
	t_printf	*lst;
	t_printf	*tmp;

	while (str[count])
	{
		if (str[count] == '%' && str[count + 1] != '%')
		{
			if (!(tmp = malloc(sizeof(t_printf))))
				return (NULL);
			lst = pushback(analyze(str + count));
		}
		count++;
	}
}
