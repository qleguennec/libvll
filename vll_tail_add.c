/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_tail_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:54:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 17:05:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void		vll_tail_add(t_vll *l, void *data, size_t size)
{
	t_vll_node	*tail;
	t_vll_node	*new;

	MALLOC_SIZEOF(new);
	tail = vll_tail(l);
	new->next = NULL;
#if (VLL_DLINK)
	new->prev = tail;
#endif
	vect_init(&new->data);
	vect_add(&new->data, data, size);
#if (VLL_TAIL)
	if (l->head == l->tail)
		l->head = new;
	l->tail = new;
#endif
#if (VLL_SIZE)
	++l->size;
#endif
}
