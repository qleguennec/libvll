/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_fmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:42:13 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 13:26:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll		*vll_fmap(t_vll *l, t_vll *(*f)(t_vll *))
{
	t_vll		*new;
	t_vll		*l1;
	t_vll_node	*n;
	t_vll_node	*m;

#if (VLL_VLL)
	if (IS_VLL(l))
	{
		new = vll_new();
		new->vll_vll = 1;
		n = l->head;
		m = NULL;
		while (n)
		{
			l1 = vll_fmap(n->p, f);
			m = vll_add_front(new, m, l1, 0);
			n = n->next;
		}
		return (new);
	}
#endif
	return (f(l));
}
