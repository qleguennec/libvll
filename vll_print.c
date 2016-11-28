/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:05:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 01:15:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"
#include <unistd.h>

void		vll_print(int fd, t_vll *l, int opts)
{
	t_vect	exp;

	vect_init(&exp);
	vll_export(l, &exp, VLL_DEF_DELIM, VLL_EXPORT_DELIM);
	write(fd, exp.data, exp.used);
	free(exp.data);
	if (opts & VLL_PRINT_NL)
		write(fd, "\n", 1);
}
