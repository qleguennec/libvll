/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_vect_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:37:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 21:03:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

static void	apply
	(t_vll_node *n, t_vect *(*f)(t_vect *, void *ctxt), void *ctxt)
{
	t_vect		*v;

	while (n)
	{
		v = f(n->p, ctxt);
		if (v)
		{
			vect_del(n->p);
			n->p = v;
		}
		n = n->next;
	}
}

void		vll_vect_map
	(t_vll *l, t_vect *(*f)(t_vect *, void *ctxt), void *ctxt)
{
	t_vll_node	*n;

	n = l->head;
	if (!n)
		return ;
#if (VLL_VLL)
	if (IS_VLL(l))
	{
		while (n)
		{
			vll_vect_map(n->p, f, ctxt);
			n = n->next;
		}
	}
#endif
	apply(n, f, ctxt);
}
