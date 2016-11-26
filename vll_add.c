/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:23:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 17:05:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void		vll_add(t_vll *l, void *data, size_t size)
{
	t_vll_node	*new;

	MALLOC_SIZEOF(new);
#if (VLL_LINK)
	new->prev =  NULL;
#endif
	new->next = l->head;
	vect_init(&new->data);
	vect_add(&new->data, data, size);
#if (VLL_TAIL)
	if (l->head == l->tail)
		l->tail = new;
#endif
	l->head = new;
#if (VLL_SIZE)
	++l->size;
#endif
}
