/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_data_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:30:25 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 13:31:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

t_vll_node		*vll_data_add(t_vll *l, void *data)
{
	t_vll_node	*n;

	n = vll_node_new(data);
	return (vll_node_add(l, n));
}
