/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:01:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 04:23:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_add_front(t_vll *l, t_vll_node *n, void *data, size_t size)
{
	t_vll_node	*new;

#if (VLL_VLL)
	if (IS_VLL(l))
		new = vll_node_new(data ? data : vll_new());
	else
		new = vll_vect_node_new(data, size);
#else
	new = vll_vect_node_new(data, size);
#endif
	vll_node_add_front(l, n, new);
	return (new);
}
