/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:57 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 15:01:03 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*ft_pushback(t_printf *lst, t_printf *add)
{
	t_printf *tmp;
	
	tmp = lst;
	if (!lst)
		return(add);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
	return (lst);
}

t_printf	*prnew(char *str)
{
	t_printf *lst;
	
	if (!(lst = malloc(sizeof(t_printf))))
		return (NULL);
	lst->next = NULL;
	lst->var = str;
	lst->needconv = 0;
	return (lst);
}

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
	
	if (!(lst = malloc(sizeof(t_printf))))
		return (NULL);
	lst->needconv = 1;
	lst->settings[0] = '\0';
	while (str[*count])
	{
		if (str[*count] >= '1' && str[*count] <= '9')
		{
			lst->pre[0] = ft_atoi(&str[*count]);
			while (str[*count + 1] >= '0' && str[*count + 1] <= '9')
				(*count)++;
			//printf("[bite]%c\n", str[*count]);
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
				lst = ft_pushback(lst, prnew(ft_strndup(str, count)));
			str += count + 1;
			count = 0;
			lst = ft_pushback(lst, analyze(str, &count));
			str += count + 1;
			count = -1;
		}
		count++;
	}
	if (count != 0)
		lst = ft_pushback(lst, prnew(ft_strndup(str, count)));
	return (lst);
}
