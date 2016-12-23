/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_fmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:42:13 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/23 00:57:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll		*vll_fmap(t_vll *l, t_vll *(*f)(t_vll *, void *), void *ctxt)
{
	t_vll		*new;
	t_vll		*l1;
	t_vll_node	*n;
	t_vll_node	*m;

	if (IS_VLL(l))
	{
		new = vll_new();
		new->vll_vll = 1;
		n = l->head;
		m = NULL;
		while (n)
		{
			l1 = vll_fmap(n->p, f, ctxt);
			m = vll_add_front(new, m, l1, 0);
			n = n->next;
		}
		return (new);
	}
	return (f(l, ctxt));
}
