/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:32:51 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/26 16:45:00 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_split(char *s, char c)
{
	int			count;
	int			time;

	time = 0;
	count = 0;
	while (s[count] == c)
		count++;
	while (s[count] != '\0')
	{
		if (s[count] == c || !s[count + 1])
		{
			if (!s[count + 1])
				count++;
			time++;
			while (s[count] == c)
				count++;
		}
		else
			count++;
	}
	return (time);
}

static void		ft_count(int *count, int *counta)
{
	*counta = *counta + 1;
	*count = 0;
}

static char		**split(char **tab, char *s, char c)
{
	int			count;
	int			counta;

	count = 0;
	counta = 0;
	while (s[0] == c)
		s++;
	while (s[count])
	{
		if (s[count] == c || !s[count + 1])
		{
			if (!s[count + 1] && s[count] != c)
				count++;
			ft_putnbr(count);
			tab[counta] = ft_strnew(count);
			ft_strncpy(tab[counta], s, count);
			while (s[count] == c)
				count++;
			s = s + count;
			ft_count(&count, &counta);
		}
		else
			count++;
	}
	tab[counta] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;

	tab = NULL;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * nb_split((char*)s, c) + 1)))
		return (NULL);
	return (split(tab, (char*)s, c));
}
