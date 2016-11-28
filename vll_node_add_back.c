/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:05:54 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 13:30:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

/*
 * if n is a NULL pointer, new node is placed at the tail
 * if l does not contain n, behaviour is undefined
*/

#if (VLL_DLINK)
static void	node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	(void)l;
	new->next = n;
	new->prev = n ? n->prev : NULL;
	if (n)
	{
		if (n->prev)
			n->prev->next = new;
		n->prev = new;
	}
}
#else
static void	node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	t_vll_node	*m;

	m = l->head;
	new->next = n;
	while (m && m->next != n)
		m = m->next;
	if (m)
		m->next = new;
}
#endif

void		vll_node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	node_add_back(l, n, new);
#if (VLL_DLINK)
	if (!new->prev)
		l->head = new;
#endif
#if (VLL_TAIL)
	if (!new->next)
		l->tail = new;
#endif
#if (VLL_SIZE)
	++l->size;
#endif
}
