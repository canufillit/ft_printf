/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:37 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/30 11:12:56 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>

# include <limits.h>

typedef struct	s_printf
{
	int			needconv;	//si ya besoin d'appeler une fonction avant de l'add au str final
	char		*var;
	char		settings[5];	// -+#0<space>
	char		type;		// cspdiouxX
	int			pre[2];		// 5.6 
	char		size[2];	// h, hh, l, ll
	struct s_printf	*next;
}				t_printf;

typedef struct	s_fval
{
	char	c;
	char	*(*f)(t_printf);
}				t_fval;

/*t_fval tab[] = {{'c', pf_ctos},
				{'s', NULL},
				{'p', JSP},
				{'d', pf_itoa},
				{'i', pf_itoa},
				{'o', JSP},
				{'u', JSP},
				{'x', JSP},
				{'X', JSP}}*/

t_printf	*parser(const char *str, ...);
t_printf	*pf_router(t_printf *lst, va_list ap);
#endif
