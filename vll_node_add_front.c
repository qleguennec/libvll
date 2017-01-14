/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:44:43 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/14 19:01:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

/*
 ** if n is a NULL pointer, new node is placed at the head
 ** if l does not contain n, behaviour is undefined
*/

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

void		vll_node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	node_add_front(l, n, new);
	if (!new->prev)
		l->head = new;
	if (!new->next)
		l->tail = new;
	++l->size;
}
