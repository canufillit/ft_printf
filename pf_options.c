/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:48 by glavigno          #+#    #+#             */
/*   Updated: 2018/12/03 15:07:18 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*pf_addc(char *s, int n, char c)
{
	int count;

	count = 0;
	while (n > count)
	{
		s[count] = c;
		count++;
	}
	s[count] = '\0';
	return (s);
}

char		*pf_append(t_printf *lst, char c, int n)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (n <= (int)ft_strlen(lst->var))
		return (lst->var);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_strcpy(ptr, lst->var);
	i += ft_strlen(lst->var);
	len = n - ft_strlen(lst->var);
	while (len--)
		ptr[i++] = c;
	ft_strdel(&lst->var);
	return (ptr);
}

char		*pf_prepend(t_printf *lst, char c, int n)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (n <= (int)ft_strlen(lst->var))
		return (lst->var);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	len = n - ft_strlen(lst->var);
	while (len--)
		ptr[i++] = c;
	ft_strcat(&ptr[i], lst->var);
	ft_strdel(&lst->var);
	return (ptr);
}

char	*add_base_prefix(t_printf *lst, char *s)
{
	int count;
	
	count = 0;
	while (s[count])
	{
		if (s[count] == '0')
			break;
		count++;
	}
	if (ft_cisin(lst->settings, '#') && (lst->type == 'X' || lst->type == 'x') 
			&& *lst->var != '0')
	{
		s[count] = '0';
		s[count + 1] = 'X';
		s[count + 2] = '\0';
	}
	else if (ft_cisin(lst->settings, '#') && lst->type == 'o')
	{
		s[count] = '0';
		s[count + 1] = '\0';
	}
	return (s);
}

char	*pf_len(t_printf *lst, int *size, int *nb_sp, int *nb_0)
{
	char *tmp;

	*nb_0 = 0;
	*nb_sp = 0;
	*size = ft_strlen(lst->var);
	if (*size < lst->pre[1])
		*nb_0 = lst->pre[1] - *size;
	if (*size + *nb_0 < lst->pre[0])
		*nb_sp = lst->pre[0] - *size - *nb_0;
	if (!*nb_0 && ft_cisin(lst->settings, '#'))
	{
		if (lst->type == 'X' || lst->type == 'x')
		{
			*nb_sp -= 2;
			*nb_0 = 2;
		}	
		else
		{
			*nb_sp -= 1;
			*nb_0 = 1;
		}
		if (*nb_sp < 0)
			*nb_sp = 0;
	}
	if (!(tmp = ft_strnew(*size + *nb_0 + *nb_sp)))
		return (NULL);
	return (tmp);
}

char		*pf_options(t_printf *lst)
{
	char	*tmp;
	char	c;
	int		size;
	int		nb_0;
	int		nb_sp;

	c = (ft_cisin(lst->settings, '0')) ? '0' : ' ';
	tmp = pf_len(lst, &size, &nb_sp, &nb_0);
	if (!ft_cisin(lst->settings, '-'))
		pf_addc(tmp, nb_sp, c);
	if (ft_cisin(lst->settings, '+') && !ft_cisin(lst->var, '-'))
		tmp[nb_sp] = '+';
	if (ft_cisin(lst->settings, '-'))
		pf_addc(tmp, nb_0, '0');
	else
		pf_addc(tmp + nb_sp, nb_0, '0');
	add_base_prefix(lst, tmp);
	ft_strcat(tmp, lst->var);
	if (ft_cisin(lst->settings, '-'))
		pf_addc(tmp + size + nb_0, nb_sp, ' ');
	free(lst->var);
	lst->var = tmp;
	free(tmp);
	return (lst->var);
}
