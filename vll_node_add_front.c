/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:44:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 01:54:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

/*
 * if n is a NULL pointer, new node is placed at the head
 * if l does not contain n, behaviour is undefined
*/

#if (VLL_DLINK)
static void	node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	(void)l;
	new->prev = n;
	new->next = n ? n->next : NULL;
	if (n)
	{
		if (n->next)
			n->next->prev = new;
		n->next = new;
	}
}

#else
static void	node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	if (n)
	{
		new->next = n->next;
		n->next = new;
	}
	else
		new->next = NULL;
}
#endif

void		vll_node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	node_add_front(l, n, new);
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
