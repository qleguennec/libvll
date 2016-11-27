/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:38:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 22:20:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

/*
 * see vll_import for details
*/

#define ADD(c) vect_mset_end(v, c, 1)

static void	export_data(t_vect *src, t_vect *v, char *delim, int opts)
{
	if (opts & VLL_EXPORT_DELIM)
		ADD(delim[3]);
	vect_add(v, src->data, src->used);
	if (opts & VLL_EXPORT_DELIM)
		ADD(delim[3]);
}

static void	export(t_vll *l, t_vect *v, char *delim, int opts)
{
	t_vll_node	*n;

	n = l->head;
#if (VLL_VLL)
	if (IS_VLL(l))
		vll_vll_export(l, v, delim, opts);
#endif
	ADD(delim[0]);
	while (n)
	{
		export_data(n->p, v, delim, opts);
		n = n->next;
		if (n)
		{
			ADD(delim[2]);
			ADD(' ');
		}
	}
	ADD(delim[1]);
}

void		vll_export(t_vll *l, t_vect *v, char *delim, int opts)
{
	export(l, v, delim, opts);
	if (opts & VLL_EXPORT_STR)
		ADD('\0');
}
