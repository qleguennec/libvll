/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_fmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:42:13 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 21:30:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll		*vll_fmap(t_vll *l, t_vll *(*f)(t_vll *))
{
	t_vll		*new;
	t_vll_node	*n;
	t_vll_node	*m;

	n = l->head;
	if (!n)
		return (NULL);
	new = f(l);
#if (VLL_VLL)
	if (IS_VLL(l))
	{
		new->vll_vll = 1;
		m = NULL;
		while (n)
		{
			m = vll_add_front(new, m, vll_fmap(n->p, f), 0);
			n = n->next;
		}
	}
#endif
	return (new);
}
