/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_tail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:46:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 16:58:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_tail(t_vll *l)
{
	t_vll_node	*n;

#if (VLL_TAIL)
	return (l->tail);
#endif
	n = l->head;
	while (n && n->next)
		n = n->next;
	return (n);
}
