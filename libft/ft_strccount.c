/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:45:10 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/22 16:58:02 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strccount(char *str, char c)
{
	int	count;
	int nb;

	count = 0;
	nb = 0;
	while (str[count])
	{
		if (str[count] == c)
			nb++;
		count++;
	}
	return (nb);
}
