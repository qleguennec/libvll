/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:01:53 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/23 01:07:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll.h"

void	*vll_node(t_vll *l, size_t n)
{
	size_t		n1;
	t_vll_node	*m;

	if (n >= l->size)
		return (NULL);
	if (n < l->size / 2)
	{
		m = m->head;
		while (n)
		{
			m = m->next;
			n--;
		}
	}
	else
	{
		m = m->last;
		n1 = l->size;
		while (n1 > n)
		{
			m = m->prev;
			n1--;
		}
	}
	return (m);
}
