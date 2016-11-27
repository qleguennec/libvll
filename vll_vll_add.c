/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_vll_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:54:20 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 13:52:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_vll_add(t_vll *l, t_vll *new)
{
	t_vll_node	*n;

	n = vll_add_front(l, NULL, NULL, 0);
	n->data.used = (size_t)-1;
	n->data.total = sizeof(t_vll);
	n->data.data = new;
	return (n);
}
