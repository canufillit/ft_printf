/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/06 18:26:05 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cisin(char *s, char c)
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

int		pf_passnb(const char *str, int *count)
{
	int tmp;

	tmp = ft_atoi(&str[*count]);
	if (!(str[*count] >= '0' && str[*count] <= '9'))
	{
		(*count)--;
		return (tmp);
	}
	while (str[*count + 1] >= '0' && str[*count + 1] <= '9')
		(*count)++;
	return (tmp);
}

t_printf	*analyze(const char *str, int *count)
{
	t_printf	*lst;

	lst = pf_prnew(NULL, 1);
	while (str[*count])
	{
		if (str[*count] >= '1' && str[*count] <= '9')
			lst->pre[0] = pf_passnb(str, count);
		else if (str[*count] == '.')
		{
			(*count)++;
			lst->pre[2] = 1;
			lst->pre[1] = pf_passnb(str, count);
		}
		else if (ft_cisin("-+#0 ", str[*count]))
		{
			if (!ft_cisin(lst->settings, str[*count]))
				ft_strncat(lst->settings, &str[*count], 1);
		}
		else if (ft_cisin("lhzj", str[*count]))
		{
			if (ft_strlen(lst->size) < 2)
				ft_strncat(lst->size, &str[*count], 1);
		}
		else
			break ;
		(*count)++;
	}
	if (!str[*count])
		return (NULL);
	lst->type = str[*count];
	return (lst);
}

t_printf	*parser(const char *str)
{
	int			count;
	t_printf	*lst;
	t_printf	*tmp;

	lst = NULL;
	count = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			if (!str[count + 1])
				return (NULL);
			if (count)
				lst = ft_pushback(lst, pf_prnew(ft_strndup(str, count), 0));
			str += count + 1;
			count = 0;
			if (!(tmp = analyze(str, &count)))
				return (NULL);
			lst = ft_pushback(lst, tmp);
			str += count + 1;
			count = -1;
		}
		count++;
	}
	if (count != 0)
		lst = ft_pushback(lst, pf_prnew(ft_strndup(str, count), 0));
	return (lst);
}
