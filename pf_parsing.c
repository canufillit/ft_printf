/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 17:17:23 by apeyret          ###   ########.fr       */
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

t_printf	*analyze(const char *str, int *count)
{
	t_printf	*lst;

	lst = pf_prnew(NULL, 1);
	while (str[*count])
	{
		if (str[*count] >= '1' && str[*count] <= '9')
		{
			lst->pre[0] = ft_atoi(&str[*count]);
			while (str[*count + 1] >= '0' && str[*count + 1] <= '9')
				(*count)++;
		}
		else if (str[*count] == '.')
		{
			(*count)++;
			lst->pre[1] = ft_atoi(&str[*count]);
			while (str[*count + 1] >= '0' && str[*count + 1] <= '9')
				(*count)++;
		}
		else if (ft_cisin("-+#0 ", str[*count]))
			ft_strncat(lst->settings, &str[*count], 1);
		else if (str[*count] == 'l')
			ft_strncat(lst->size, &str[*count], 1);
		else if (str[*count] == 'h')
			ft_strncat(lst->size, &str[*count], 1);
		else
			break;
		(*count)++;
	}
	lst->type = str[*count];
	return (lst);
}

t_printf	*parser(const char *str)
{
	int			count;
	t_printf	*lst;

	lst = NULL;
	count = 0;
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1] != '%')
		{
			if (count)
				lst = ft_pushback(lst, pf_prnew(ft_strndup(str, count), 0));
			str += count + 1;
			count = 0;
			lst = ft_pushback(lst, analyze(str, &count));
			str += count + 1;
			count = -1;
		}
		else if (str[count] == '%' && str[count + 1]  == '%')
		{
			lst = ft_pushback(lst, pf_prnew(ft_strndup(str, count + 1), 0));
			str += count + 2;
			count = 0;
		}
		count++;
	}
	if (count != 0)
		lst = ft_pushback(lst, pf_prnew(ft_strndup(str, count), 0));
	return (lst);
}
