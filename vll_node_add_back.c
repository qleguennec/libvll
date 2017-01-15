/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:05:54 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/15 17:18:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

/*
** if n is a NULL pointer, new node is placed at the tail
** if l does not contain n, behaviour is undefined
*/

void		vll_node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new)
{
	new->next = n;
	new->prev = n ? n->prev : NULL;
	if (n)
	{
		if (n->prev)
			n->prev->next = new;
		n->prev = new;
	}
	if (!new->prev)
		l->head = new;
	if (!new->next)
		l->tail = new;
	l->size++;
}
