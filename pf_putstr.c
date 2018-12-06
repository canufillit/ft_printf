/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:56:00 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/06 14:38:24 by apeyret          ###   ########.fr       */
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

char	*pf_putchar(t_printf *lst, const char c)
{
	char	*tmp;

	if (!(tmp = ft_strdup("")))
		return (NULL);
	if (lst->pre[0])
		lst->pre[0]--;
	if (ft_cisin(lst->settings, '-'))
		ft_putchar(c);
	tmp = pf_putstr(lst, tmp);
	if (!ft_cisin(lst->settings, '-'))
		ft_putchar(c);
	if (!(lst->var = ft_strnew(ft_strlen(tmp) + 1)))
		return (NULL);
	lst->var = ft_memset(lst->var, 'l', ft_strlen(tmp) + 1);
	free(tmp);
	return (lst->var);
}

char	*pf_putstr(t_printf *lst, const char *s)
{
	char	*str;
	int		size;
	int		len;
	int		count;
	
	size = 0;
	count = 0;
	if (!s)
	{
		lst->var = ft_strdup("(null)");
		ft_putstr(lst->var);
		return (lst->var);
	}
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

char	*pf_putaddr(t_printf *lst, void *addr)
{
	char	*str;

	str = utoa_base(lst, (unsigned long long)(addr), 16);
	if (!(lst->var = ft_strnew(2 + ft_strlen(str))))
		return (NULL);
	ft_strcpy(lst->var, "0x");
	ft_strcat(lst->var, ft_strlower(str));
	free(str);
	pf_options(lst, pf_len(lst, pf_optnew()));
	ft_putstr(lst->var);
	return (lst->var);
}
