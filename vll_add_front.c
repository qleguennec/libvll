/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:01:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 13:46:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_add_front(t_vll *l, t_vll_node *n, void *data, size_t size)
{
	t_vll_node	*new;

	new = vll_node_new(data, size);
	vll_node_add_front(l, n, new);
	return (new);
}
