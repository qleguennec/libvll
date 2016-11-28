/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_vect_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:37:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 21:31:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

void		vll_vect_map(t_vll *l, void (*f)(t_vect *))
{
	t_vll_node	*n;

	n = l->head;
	if (!n)
		return ;
#if (VLL_VLL)
	if (IS_VLL(l))
	{
		while (n)
		{
			vll_vect_map(n->p, f);
			n = n->next;
		}
	}
#endif
	while (n)
	{
		f(n->p);
		n = n->next;
	}
}
