/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:25 by apeyret           #+#    #+#             */
/*   Updated: 2018/11/27 15:09:39 by apeyret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int nb = 123;
	char str[] = "123";

	printf("\033[34;31m%%d:\n");
	printf("%%d:   %d\n",	nb);
	printf("%%d:   %i\n", 	nb);
	printf("%%+d:  %+d\n",	nb);
	printf("%%-d:  %-d\n",	nb);
	printf("%%0d:  %0d\n",	nb);
	printf("%%.5d: %.5d\n", nb);
	printf("%%.2d: %.2d\n", nb);

	printf("\n\033[34;32m%%s:\n");
	printf("%%s:   %s\n",	str);
	printf("%%.2s: %.2s\n",	str);
	printf("%%.5s: %.5s\n",	str);

	printf("\n\033[34;33m%%:\n");
}
