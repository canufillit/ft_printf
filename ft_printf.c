/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:22:48 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/27 15:34:42 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(const char *format, ...)
{
	t_printf	*lst;
	char		*str;

	lst = parsing(format);
	if (!(str = ft_strnew(ft_printlen(lst))))
		return ("ON EST LA");
	while (lst)
	{
		if (!lst-conv)
			str = ft_strcat(str, lst->raw);
		else
			str = ft_strcat(str, conv_format(lst));
		lst = lst->next;
	}
	ft_putstr(str);
}
