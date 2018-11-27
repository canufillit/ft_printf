/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:37 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/27 16:04:23 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include "libft.h"

typedef struct	s_printf
{
	char		*raw;
	char		type;
	int			pre;
	char		*flags;
	struct s_printf	*next;
}				t_printf;

typedef struct	s_fval
{
	char	c;
	char	*(*f)(t_printf);
}				t_fval;

t_fval tab[] = {{'c', pf_ctos},
				{'s', NULL},
				{'p', JSP},
				{'d', pf_itoa},
				{'i', pf_itoa},
				{'o', JSP},
				{'u', JSP},
				{'x', JSP},
				{'X', JSP}}
#endif
