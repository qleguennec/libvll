/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:05:43 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/12 11:38:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

t_vll_node		*vll_add_back(t_vll *l, t_vll_node *n, void *data, size_t size)
{
	t_vll_node	*new;

	if (IS_VLL(l))
		new = vll_node_new(data ? data : vll_new());
	else
		new = size == (size_t)-1
			? vll_node_new(data) : vll_vect_node_new(data, size);
	vll_node_add_back(l, n, new);
	return (new);
}
