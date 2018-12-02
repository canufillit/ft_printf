/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:56:00 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/02 19:13:49 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_addsp(char *s, int n)
{
	int count;

	count = 0;
	while (n > count)
	{
		s[count] = ' ';
		count++;
	}
	s[count] = '\0';
	return (s);
}

char	*pf_putstr(t_printf *lst, const char *s)
{
	char	*str;
	int		size;
	int		len;
	int		count;
	
	size = 0;
	count = 0;
	len = ft_strlen(s);
	if (lst->pre[1] < len && lst->pre[1] != 0)
		len = lst->pre[1];
	if (lst->pre[0] > len)
		size = lst->pre[0];
	else
		size = len;
	if (!(str = ft_strnew(size)))
		return NULL;
	if (ft_cisin(lst->settings, '-'))
	{
		pf_addsp(str + len, size - len);
		str = ft_strncpy(str, s, len);
	}
	else
	{
		str = pf_addsp(str, size - len);
		str = ft_strncat(str, s, len);
	}
	ft_putstr(str);
	return (str);
}

void	pf_putaddr(t_printf *lst, void *addr)
{
	char	*str;

	str = utoa_base(lst, (unsigned long long)(addr), 16);
	if (!(lst->var = ft_strnew(2 + ft_strlen(str))))
		return ;
	ft_strcpy(lst->var, "0x");
	ft_strcat(lst->var, ft_strlower(str));
	free(str);
	ft_putstr(lst->var);
}
