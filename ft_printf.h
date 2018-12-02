/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:31:37 by apeyret           #+#    #+#             */
/*   Updated: 2018/12/02 17:09:05 by glavigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>

# include <limits.h> // enlever

typedef struct	s_printf
{
	int			needconv;	//si ya besoin d'appeler une fonction avant de l'add au str final
	char		*var;
	char		settings[5];// -+#0<space>
	char		type;		// cspdiouxX
	int			pre[2];		// 5.6 
	char		size[2];	// h, hh, l, ll
	struct s_printf	*next;
}				t_printf;

typedef struct	s_base
{
	char		type;
	int			base;
}				t_base;

t_printf		*parser(const char *str);
int				pf_router(t_printf *lst, va_list ap);
char			*utoa_base(t_printf *lst, unsigned long long n, int b);
char			*stoa_base(t_printf *lst, long long n, int b);
char			*pf_options(t_printf *lst);
int				ft_cisin(char *s, char c);
char			*pf_putstr(t_printf *lst, const char *s);
int				ft_printf(const char *format, ...);
t_printf		*ft_pushback(t_printf *lst, t_printf *add);
t_printf		*pf_prnew(char *str, int needconv);
int				pf_base(char c);
#endif
