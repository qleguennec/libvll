/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 00:40:04 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 04:00:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

static void	free_elems(t_vll_node *n)
{
	t_vll_node	*m;

	while (n)
	{
		vect_del(n->p);
		m = n->next;
		free(n);
		n = m;
	}
}

void		vll_free(t_vll *l)
{
	t_vll_node	*n;
	t_vll_node	*m;

	n = l->head;
	if (!n)
	{
		free(l);
		return ;
	}
#if (VLL_VLL)
	if (IS_VLL(l))
	{
		while (n)
		{
			vll_free(n->p);
			m = n->next;
			free(n);
			n = m;
		}
	}
#endif
	free_elems(n);
	free(l);
}
