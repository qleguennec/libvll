/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:00:14 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 17:04:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

static  void	cpy(t_vll *dest, t_vll_node *ns)
{
	t_vect		*v;
	t_vll_node	*nd;

	nd = NULL;
	while (ns)
	{
		v = ns->p;
		nd = vll_add_front(dest, nd, v->data, v->used);
		ns = ns->next;
	}
}

void			vll_dup(t_vll *dest, t_vll *src)
{
	t_vll_node	*nd;
	t_vll_node	*ns;

	if (!(ns = src->head))
		return ;
	nd = NULL;
#if (VLL_VLL)
	if (IS_VLL(src))
	{
		dest->vll_vll = 1;
		while (ns)
		{
			nd = vll_add_front(dest, nd, ns->p, 0);
			vll_dup(nd->p, ns->p);
			ns = ns->next;
		}
	}
	else
		cpy(dest, ns);
#else
	cpy(dest, ns);
#endif
}
