/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:00:16 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/23 01:08:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void	*vll_elem(t_vll *l, size_t n)
{
	t_vll_node	*m;

	m = vll_node(l, n);
	return (m->p);
}
